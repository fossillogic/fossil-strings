/*
 * -----------------------------------------------------------------------------
 * Project: Fossil Logic
 *
 * This file is part of the Fossil Logic project, which aims to develop high-
 * performance, cross-platform applications and libraries. The code contained
 * herein is subject to the terms and conditions defined in the project license.
 *
 * Author: Michael Gene Brockus (Dreamer)
 *
 * Copyright (C) 2024 Fossil Logic. All rights reserved.
 * -----------------------------------------------------------------------------
 */
#include "fossil/string/bstring.h"

// Helper function to calculate the number of digits in an integer
int _bstr_num_digits(long long num) {
    int count = 0;
    if (num == 0) return 1; // Handle special case for zero
    if (num < 0) {
        count++; // Account for negative sign
        num = -num; // Convert negative number to positive
    }
    while (num > 0) {
        count++;
        num /= 10;
    }
    return count;
}

bstring fossil_bstr_create(const_bstring str) {
    if (!str) {
        return NULL; // Validate input to prevent NULL pointer dereference
    }
    return (bstring)fossil_bstr_strdup((const char *)str); // Allocate memory and copy string using strdup
}

void fossil_bstr_erase(bstring str) {
    if (str) {
        free(str); // Free memory allocated for the byte string
        str = NULL; // Reset the pointer to NULL
    }
}

size_t fossil_bstr_length(const_bstring str) {
    if (!str) {
        return 0;
    }
    return strlen((const char *)str); // Calculate byte string length using strlen
}

bstring fossil_bstr_format(const_bstring format, ...) {
    if (!format) {
        return NULL; // Input validation
    }

    va_list args, args_copy;
    va_start(args, format);
    va_copy(args_copy, args);

    // Calculate required size
    int size = vsnprintf(NULL, 0, (const char *)format, args);
    va_end(args);

    if (size < 0) {
        return NULL; // Error handling
    }

    bstring buffer = malloc((size_t)size + 1);
    if (!buffer) {
        return NULL; // Memory management
    }

    vsnprintf((char *)buffer, (size_t)size + 1, (const char *)format, args_copy);
    va_end(args_copy);

    return buffer;
}

bstring fossil_bstr_format_phone(const_bstring phone) {
    if (!phone || fossil_bstr_length(phone) != 10) {
        return NULL;
    }

    return fossil_bstr_format(BSTR("(%c%c%c) %c%c%c-%c%c%c%c"),
                            phone[0], phone[1], phone[2],
                            phone[3], phone[4], phone[5],
                            phone[6], phone[7], phone[8], phone[9]);
}

bstring fossil_bstr_format_date(const_bstring date) {
    if (!date || fossil_bstr_length(date) != 8) {
        return NULL;
    }

    return fossil_bstr_format(BSTR("%c%c/%c%c/%c%c%c%c"),
                            date[0], date[1],
                            date[2], date[3],
                            date[4], date[5], date[6], date[7]);
}

bstring fossil_bstr_format_time(const_bstring time) {
    if (!time || fossil_bstr_length(time) != 6) {
        return NULL;
    }

    return fossil_bstr_format(BSTR("%c%c:%c%c:%c%c"),
                            time[0], time[1],
                            time[2], time[3],
                            time[4], time[5]);
}

bstring fossil_bstr_format_currency(const_bstring currency) {
    if (!currency) {
        return NULL;
    }

    return fossil_bstr_format(BSTR("$%s"), currency);
}

bstring fossil_bstr_format_percentage(const_bstring percentage) {
    if (!percentage) {
        return NULL;
    }

    return fossil_bstr_format(BSTR("%s%%"), percentage);
}

bstring fossil_bstr_format_postal_code(const_bstring postal_code) {
    if (!postal_code || fossil_bstr_length(postal_code) != 5) {
        return NULL;
    }

    return fossil_bstr_format(BSTR("%c%c%c%c%c"),
                            postal_code[0], postal_code[1],
                            postal_code[2], postal_code[3],
                            postal_code[4]);
}

bstring fossil_bstr_format_ssn(const_bstring ssn) {
    if (!ssn || fossil_bstr_length(ssn) != 9) {
        return NULL;
    }

    return fossil_bstr_format(BSTR("%c%c%c-%c%c-%c%c%c%c"),
                            ssn[0], ssn[1], ssn[2],
                            ssn[3], ssn[4],
                            ssn[5], ssn[6], ssn[7], ssn[8]);
}

int fossil_bstr_compare(const_bstring str1, const_bstring str2) {
    return (str1 && str2) ? memcmp(str1, str2, fossil_bstr_length(str1) + 1) : -1;
}

bstring fossil_bstr_copy(bstring dest, const_bstring src) {
    return (dest && src) ? (bstring)memcpy(dest, src, fossil_bstr_length(src) + 1) : NULL;
}

bstring fossil_bstr_concat(bstring dest, const_bstring src) {
    if (!dest || !src) {
        return NULL;
    }
    size_t dest_len = fossil_bstr_length(dest);
    size_t src_len = fossil_bstr_length(src);
    bstring new_dest = realloc(dest, dest_len + src_len + 1);
    if (!new_dest) {
        return NULL;
    }
    memcpy(new_dest + dest_len, src, src_len + 1);
    return new_dest;
}

const_bstring fossil_bstr_find(const_bstring str, bletter ch) {
    return str ? memchr(str, ch, fossil_bstr_length(str)) : NULL;
}

const_bstring fossil_bstr_reverse(const_bstring str) {
    if (!str) {
        return NULL;
    }
    size_t len = fossil_bstr_length(str);
    bstring rev = malloc(len + 1);
    if (!rev) {
        return NULL;
    }
    for (size_t i = 0; i < len; i++) {
        rev[i] = str[len - i - 1];
    }
    rev[len] = '\0';
    return rev;
}

void fossil_bstr_erase_splits(bstrings splits) {
    if (!splits) {
        return;
    }
    for (size_t i = 0; splits[i] != NULL; i++) {
        free(splits[i]);
    }
    free(splits);
}

bstrings fossil_bstr_split(const_bstring str, bletter delimiter) {
    if (!str) {
        return NULL;
    }
    size_t len = fossil_bstr_length(str);
    size_t count = 1;
    
    // Count the number of splits
    for (size_t i = 0; i < len; i++) {
        if (str[i] == delimiter) {
            count++;
        }
    }
    
    // Allocate memory for the array of byte strings
    bstrings splits = malloc((count + 1) * sizeof(bstring));
    if (!splits) {
        return NULL;
    }
    
    size_t start = 0;
    size_t index = 0;
    
    // Populate the array of byte strings
    for (size_t i = 0; i <= len; i++) {
        if (str[i] == delimiter || str[i] == '\0') {
            size_t sublen = i - start;
            splits[index] = malloc(sublen + 1);
            if (!splits[index]) {
                fossil_bstr_erase_splits((bstrings)splits);
                return NULL;
            }
            memcpy(splits[index], str + start, sublen);
            splits[index][sublen] = '\0';
            start = i + 1;
            index++;
        }
    }
    
    splits[count] = NULL;
    return splits;
}

bstring fossil_bstr_strdup(const_bstring str) {
    if (!str) {
        return NULL;
    }
    size_t len = fossil_bstr_length(str);
    bstring dup = malloc(len + 1);
    if (!dup) {
        return NULL;
    }
    return (bstring)memcpy(dup, str, len + 1);
}

bstring fossil_bstr_substr(const_bstring str, size_t start, size_t len) {
    // Check if the input string is NULL
    if (str == NULL) return NULL;

    // Get the length of the input string
    size_t str_len = fossil_bstr_length(str);

    // Check if the starting index is out of bounds
    if (start >= str_len) return NULL;

    // Adjust the length if the specified substring extends beyond the input string's length
    if (start + len > str_len) {
        len = str_len - start;
    }

    // Allocate memory for the substring
    bstring substr = fossil_bstr_create(str);
    if (substr == NULL) {
        // Handle memory allocation failure
        return NULL;
    }

    // Copy the substring using the provided fossil_bstr_copy function
    fossil_bstr_copy(substr, str + start);

    // Return the substring
    return substr;
}

// Read a substring of length 'len' from the string starting at position 'pos'
bstring fossil_bstrstream_read(const_bstring str, size_t *pos, size_t len) {
    if (!str || *pos >= fossil_bstr_length(str) || len == 0) {
        return NULL; // Invalid input or end of string reached, or zero length
    }
    bstring buffer = fossil_bstr_substr(str, *pos, len);
    if (!buffer) {
        return NULL; // Memory allocation failure
    }
    *pos += fossil_bstr_length(buffer); // Move position by the length of the read substring
    return buffer;
}

// Read a line from the string starting at position 'pos' and update 'end_pos'
bstring fossil_bstrstream_read_line(const_bstring str, size_t *pos, size_t *end_pos) {
    if (!str || *pos >= fossil_bstr_length(str) || !end_pos) {
        return NULL; // Invalid input or end of string reached
    }
    size_t start = *pos;
    while (*pos < fossil_bstr_length(str) && fossil_bletter_at(str, *pos) != '\n') {
        (*pos)++;
    }
    bstring buffer = fossil_bstr_substr(str, start, *pos - start);
    if (!buffer) {
        return NULL; // Memory allocation failure
    }
    if (*pos < fossil_bstr_length(str) && fossil_bletter_at(str, *pos) == '\n') {
        (*pos)++;
    }
    *end_pos = *pos;
    return buffer;
}

// Write the source string to the destination starting at position 'pos'
void fossil_bstrstream_write(bstring dest, size_t *pos, const_bstring src) {
    if (!dest || !src) {
        return; // Invalid input
    }
    size_t destLen = fossil_bstr_length(dest);
    size_t srcLen = fossil_bstr_length(src);
    if (*pos + srcLen >= destLen) {
        return; // Writing would exceed buffer size
    }
    fossil_bstr_copy(dest + *pos, src); // Copy source string to destination buffer
    *pos += srcLen; // Move position by the length of the written substring
}

// Append the source string to the destination starting at position 'pos'
void fossil_bstrstream_append(bstring dest, size_t *pos, const_bstring src) {
    if (!dest || !src) {
        return; // Invalid input
    }
    size_t srcLen = fossil_bstr_length(src);
    fossil_bstr_copy(dest + *pos, src); // Copy source string to destination at specified position
    *pos += srcLen; // Move position by the length of the appended substring
}

// Set the stream position to 'offset'
void fossil_bstrstream_seek(size_t *pos, size_t offset) {
    *pos = offset;
}

// Return the current stream position
size_t fossil_bstrstream_tell(const_bstring str, size_t pos) {
    // Ensure the string is not NULL
    if (str == NULL) {
        // Handle the error, e.g., by returning a special value or by using an assertion
        return (size_t)-1;
    }

    // Get the length of the string
    size_t length = 0;
    while (str[length] != '\0') {
        length++;
    }

    // Check if pos is within the string bounds
    if (pos >= length) {
        // Handle the error, e.g., by returning a special value or by using an assertion
        return (size_t)-1;
    }
    return pos;
}

bstring fossil_bstr_from_int(int num) {
    int digits = _bstr_num_digits(num);
    bstring str = malloc(digits + 1); // Allocate memory dynamically
    if (!str) {
        return NULL; // Return NULL if memory allocation fails
    }
    snprintf((char *)str, digits + 1, "%d", num); // Use snprintf with dynamically calculated buffer size
    return str;
}

bstring fossil_bstr_from_long(long num) {
    int digits = _bstr_num_digits(num);
    bstring str = malloc(digits + 1); // Allocate memory dynamically
    if (!str) {
        return NULL; // Return NULL if memory allocation fails
    }
    snprintf((char *)str, digits + 1, "%ld", num); // Use snprintf with dynamically calculated buffer size
    return str;
}

bstring fossil_bstr_from_llong(long long num) {
    int digits = _bstr_num_digits(num);
    bstring str = malloc(digits + 1); // Allocate memory dynamically
    if (!str) {
        return NULL; // Return NULL if memory allocation fails
    }
    snprintf((char *)str, digits + 1, "%ld", (long int)num); // Use snprintf with dynamically calculated buffer size
    return str;
}

bstring fossil_bstr_from_ulong(unsigned long num) {
    int digits = _bstr_num_digits(num);
    bstring str = malloc(digits + 1); // Allocate memory dynamically
    if (!str) {
        return NULL; // Return NULL if memory allocation fails
    }
    snprintf((char *)str, digits + 1, "%lu", num); // Use snprintf with dynamically calculated buffer size
    return str;
}

bstring fossil_bstr_from_ullong(unsigned long long num) {
    int digits = _bstr_num_digits(num);
    bstring str = malloc(digits + 1); // Allocate memory dynamically
    if (!str) {
        return NULL; // Return NULL if memory allocation fails
    }
    snprintf((char *)str, digits + 1, "%lu", (long unsigned int)num); // Use snprintf with dynamically calculated buffer size
    return str;
}

bstring fossil_bstr_from_double(double num) {
    // Decide the maximum possible length of the string
    int max_length = 50; // Arbitrarily chosen

    // Allocate memory for the string
    bstring str = malloc(max_length);
    if (!str) {
        return NULL; // Return NULL if memory allocation fails
    }

    // Convert the double to string
    int written = snprintf((char *)str, max_length, "%lf", num);
    if (written < 0 || written >= max_length) {
        free(str); // Free the allocated memory
        return NULL; // Return NULL if snprintf failed or buffer overflow
    }

    return str;
}

int fossil_bstr_to_int(const_bstring str) {
    if (str == NULL || *str == '\0') {
        return 0; // Handle invalid input (NULL pointer or empty string)
    }

    char *endptr;
    errno = 0;
    long result = strtol((const char *)str, &endptr, 10);
    if (errno == ERANGE || *endptr != '\0' || result > INT_MAX || result < INT_MIN) {
        // Handle conversion error or overflow/underflow
        return 0; // Return a default value or indicate error
    }

    return (int)result;
}

double fossil_bstr_to_double(const_bstring str) {
    if (str == NULL || *str == '\0') {
        return 0.0; // Handle invalid input (NULL pointer or empty string)
    }

    char *endptr;
    errno = 0;
    double result = strtod((const char *)str, &endptr);
    if (errno == ERANGE || *endptr != '\0') {
        // Handle conversion error
        return 0.0; // Return a default value or indicate error
    }

    return result;
}

long fossil_bstr_to_long(const_bstring str) {
    if (str == NULL || *str == '\0') {
        return 0; // Handle invalid input (NULL pointer or empty string)
    }

    char *endptr;
    errno = 0;
    long result = strtol((const char *)str, &endptr, 10);
    if (errno == ERANGE || *endptr != '\0') {
        // Handle conversion error
        return 0; // Return a default value or indicate error
    }

    return result;
}

unsigned long fossil_bstr_to_ulong(const_bstring str) {
    if (str == NULL || *str == '\0') {
        return 0; // Handle invalid input (NULL pointer or empty string)
    }

    char *endptr;
    errno = 0;
    unsigned long result = strtoul((const char *)str, &endptr, 10);
    if (errno == ERANGE || *endptr != '\0') {
        // Handle conversion error
        return 0; // Return a default value or indicate error
    }

    return result;
}

long long fossil_bstr_to_llong(const_bstring str) {
    if (str == NULL || *str == '\0') {
        return 0; // Handle invalid input (NULL pointer or empty string)
    }

    char *endptr;
    errno = 0;
    long long result = strtoll((const char *)str, &endptr, 10);
    if (errno == ERANGE || *endptr != '\0') {
        // Handle conversion error
        return 0; // Return a default value or indicate error
    }

    return result;
}

unsigned long long fossil_bstr_to_ullong(const_bstring str) {
    if (str == NULL || *str == '\0') {
        return 0; // Handle invalid input (NULL pointer or empty string)
    }

    char *endptr;
    errno = 0;
    unsigned long long result = strtoull((const char *)str, &endptr, 10);
    if (errno == ERANGE || *endptr != '\0') {
        // Handle conversion error
        return 0; // Return a default value or indicate error
    }

    return result;
}
