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
#include "fossil/string/cstring.h"

// Helper function to calculate the number of digits in an integer
int _cstr_num_digits(long long num) {
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

cstring fossil_cstr_create(const_cstring str) {
    if (!str) {
        return NULL; // Validate input to prevent NULL pointer dereference
    }
    return fossil_cstr_strdup(str); // Allocate memory and copy string using strdup
}

void fossil_cstr_erase(cstring str) {
    if (str) {
        free(str); // Free memory allocated by strdup
        str = NULL; // Reset the pointer to NULL
    }
}

size_t fossil_cstr_length(const_cstring str) {
    if (!str) {
        return 0;
    }
    return strlen(str); // Calculate string length using strlen
}

cstring fossil_cstr_format(const_cstring format, ...) {
    if (!format) {
        return NULL; // Input validation
    }

    va_list args, args_copy;
    va_start(args, format);
    va_copy(args_copy, args);

    // Calculate required size
    int size = vsnprintf(NULL, 0, format, args);
    va_end(args);

    if (size < 0) {
        return NULL; // Error handling
    }

    cstring buffer = malloc((size_t)size + 1);
    if (!buffer) {
        return NULL; // Memory management
    }

    vsnprintf(buffer, (size_t)size + 1, format, args_copy);
    va_end(args_copy);

    return buffer;
}

cstring fossil_cstr_format_phone(const_cstring phone) {
    if (!phone || strlen(phone) != 10) {
        return NULL;
    }

    return fossil_cstr_format("(%c%c%c) %c%c%c-%c%c%c%c",
                            phone[0], phone[1], phone[2],
                            phone[3], phone[4], phone[5],
                            phone[6], phone[7], phone[8], phone[9]);
}

cstring fossil_cstr_format_date(const_cstring date) {
    if (!date || strlen(date) != 8) {
        return NULL;
    }

    return fossil_cstr_format("%c%c/%c%c/%c%c%c%c",
                            date[0], date[1],
                            date[2], date[3],
                            date[4], date[5], date[6], date[7]);
}

cstring fossil_cstr_format_time(const_cstring time) {
    if (!time || strlen(time) != 6) {
        return NULL;
    }

    return fossil_cstr_format("%c%c:%c%c:%c%c",
                            time[0], time[1],
                            time[2], time[3],
                            time[4], time[5]);
}

cstring fossil_cstr_format_currency(const_cstring currency) {
    if (!currency) {
        return NULL;
    }

    return fossil_cstr_format("$%s", currency);
}

cstring fossil_cstr_format_percentage(const_cstring percentage) {
    if (!percentage) {
        return NULL;
    }

    return fossil_cstr_format("%s%%", percentage);
}

cstring fossil_cstr_format_postal_code(const_cstring postal_code) {
    if (!postal_code || strlen(postal_code) != 5) {
        return NULL;
    }

    return fossil_cstr_format("%c%c%c%c%c",
                            postal_code[0], postal_code[1],
                            postal_code[2], postal_code[3],
                            postal_code[4]);
}

cstring fossil_cstr_format_ssn(const_cstring ssn) {
    if (!ssn || strlen(ssn) != 9) {
        return NULL;
    }

    return fossil_cstr_format("%c%c%c-%c%c-%c%c%c%c",
                            ssn[0], ssn[1], ssn[2],
                            ssn[3], ssn[4],
                            ssn[5], ssn[6], ssn[7], ssn[8]);
}

int fossil_cstr_compare(const_cstring str1, const_cstring str2) {
    if (!str1 || !str2) {
        return -1;
    }
    return strcmp(str1, str2);
}

cstring fossil_cstr_copy(cstring dest, const_cstring src) {
    if (!dest || !src) {
        return NULL;
    }
    size_t src_len = fossil_cstr_length(src);
    if (src_len >= strlen(dest)) {
        return NULL; // buffer overflow prevention
    }
    return strcpy(dest, src);
}

cstring fossil_cstr_concat(cstring dest, const_cstring src) {
    if (!dest || !src) {
        return NULL;
    }
    size_t dest_len = fossil_cstr_length(dest);
    size_t src_len = fossil_cstr_length(src);
    if (dest_len + src_len >= strlen(dest)) {
        return NULL; // buffer overflow prevention
    }
    return strcat(dest, src);
}

const_cstring fossil_cstr_find(const_cstring str, cletter ch) {
    if (!str) {
        return NULL;
    }
    return strchr(str, ch);
}

const_cstring fossil_cstr_reverse(const_cstring str) {
    if (!str) {
        return NULL;
    }
    size_t len = fossil_cstr_length(str);
    cstring rev = malloc(len + 1);
    if (!rev) {
        return NULL;
    }
    for (size_t i = 0; i < len; i++) {
        rev[i] = str[len - i - 1];
    }
    rev[len] = '\0';
    return rev;
}

void fossil_cstr_erase_splits(cstrings splits) {
    if (!splits) {
        return;
    }
    for (size_t i = 0; splits[i] != NULL; i++) {
        free(splits[i]);
    }
    free(splits);
}

cstrings fossil_cstr_split(const_cstring str, cletter delimiter) {
    if (!str) {
        return NULL;
    }
    size_t len = fossil_cstr_length(str);
    size_t count = 1;
    
    // Count the number of splits
    for (size_t i = 0; i < len; i++) {
        if (str[i] == delimiter) {
            count++;
        }
    }
    
    // Allocate memory for the array of strings
    cstrings splits = malloc((count + 1) * sizeof(cstring));
    if (!splits) {
        return NULL;
    }
    
    size_t start = 0;
    size_t index = 0;
    
    // Populate the array of strings
    for (size_t i = 0; i <= len; i++) {
        if (str[i] == delimiter || str[i] == '\0') {
            size_t sublen = i - start;
            splits[index] = malloc(sublen + 1);
            if (!splits[index]) {
                fossil_cstr_erase_splits(splits);
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

cstring fossil_cstr_strdup(const_cstring str) {
    if (!str) {
        return NULL;
    }
    size_t len = fossil_cstr_length(str);
    cstring dup = malloc(len + 1);
    if (!dup) {
        return NULL;
    }
    return strcpy(dup, str);
}

cstring fossil_cstr_substr(const_cstring str, size_t start, size_t len) {
    if (str == NULL) return NULL;

    size_t str_len = strlen(str);

    if (start >= str_len) return NULL;

    if (start + len > str_len) {
        len = str_len - start;
    }

    cstring substr = (cstring)malloc(len + 1);
    if (substr == NULL) {
        // Handle memory allocation failure
        return NULL;
    }

    strncpy(substr, str + start, len);
    substr[len] = '\0';

    return substr;
}

// Read a substring of length 'len' from the string starting at position 'pos'
cstring fossil_cstrstream_read(const_cstring str, size_t *pos, size_t len) {
    if (!str || *pos >= strlen(str) || len == 0) {
        return NULL; // Invalid input or end of string reached, or zero length
    }
    cstring buffer = fossil_cstr_substr(str + *pos, 0, len);
    if (!buffer) {
        return NULL; // Memory allocation failure
    }
    *pos += strlen(buffer); // Move position by the length of the read substring
    return buffer;
}

// Read a line from the string starting at position 'pos' and update 'end_pos'
cstring fossil_cstrstream_read_line(cstring str, size_t *pos, size_t *end_pos) {
    if (!str || *pos >= strlen(str) || !end_pos) {
        return NULL; // Invalid input or end of string reached
    }
    size_t start = *pos;
    while (str[*pos] && str[*pos] != '\n') {
        (*pos)++;
    }
    cstring buffer = fossil_cstr_substr(str, start, *pos - start);
    if (!buffer) {
        return NULL; // Memory allocation failure
    }
    if (str[*pos] == '\n') {
        (*pos)++;
    }
    *end_pos = *pos;
    return buffer;
}

// Write the source string to the destination starting at position 'pos'
void fossil_cstrstream_write(cstring dest, size_t *pos, const_cstring src) {
    if (!dest || !src) {
        return; // Invalid input
    }
    size_t destLen = strlen(dest);
    size_t srcLen = strlen(src);
    if (*pos + srcLen >= destLen) {
        return; // Writing would exceed buffer size
    }
    fossil_cstr_copy(dest + *pos, src); // Copy source string to destination buffer
    *pos += srcLen; // Move position by the length of the written substring
}

// Append the source string to the destination starting at position 'pos'
void fossil_cstrstream_append(cstring dest, size_t *pos, const_cstring src) {
    if (!dest || !src) {
        return; // Invalid input
    }
    size_t srcLen = strlen(src);
    dest = realloc(dest, *pos + srcLen + 1);
    if (!dest) {
        return; // Memory allocation failure
    }
    fossil_cstr_copy(dest + *pos, src); // Copy source string to destination buffer
    *pos += srcLen; // Move position by the length of the appended substring
    dest[*pos] = '\0'; // Null-terminate the destination buffer
}

// Set the stream position to 'offset'
void fossil_cstrstream_seek(size_t *pos, size_t offset) {
    *pos = offset;
}

// Return the current stream position
size_t fossil_cstrstream_tell(const_cstring str, size_t pos) {
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

// Convert integer to string
cstring fossil_cstr_from_int(int num) {
    int digits = _cstr_num_digits(num);
    cstring str = malloc(digits + 1); // Allocate memory dynamically
    if (!str) {
        return NULL; // Return NULL if memory allocation fails
    }
    snprintf(str, digits + 1, "%d", num); // Use snprintf with dynamically calculated buffer size
    return str;
}

// Convert long to string
cstring fossil_cstr_from_long(long num) {
    int digits = _cstr_num_digits(num);
    cstring str = malloc(digits + 1); // Allocate memory dynamically
    if (!str) {
        return NULL; // Return NULL if memory allocation fails
    }
    snprintf(str, digits + 1, "%ld", num); // Use snprintf with dynamically calculated buffer size
    return str;
}

// Convert long long to string
cstring fossil_cstr_from_llong(long long num) {
    int digits = _cstr_num_digits(num);
    cstring str = malloc(digits + 1); // Allocate memory dynamically
    if (!str) {
        return NULL; // Return NULL if memory allocation fails
    }
    snprintf(str, digits + 1, "%ld", (long int)num); // Use snprintf with dynamically calculated buffer size
    return str;
}

// Convert unsigned long to string
cstring fossil_cstr_from_ulong(unsigned long num) {
    int digits = _cstr_num_digits(num);
    cstring str = malloc(digits + 1); // Allocate memory dynamically
    if (!str) {
        return NULL; // Return NULL if memory allocation fails
    }
    snprintf(str, digits + 1, "%lu", num); // Use snprintf with dynamically calculated buffer size
    return str;
}

// Convert unsigned long long to string
cstring fossil_cstr_from_ullong(unsigned long long num) {
    int digits = _cstr_num_digits(num);
    cstring str = malloc(digits + 1); // Allocate memory dynamically
    if (!str) {
        return NULL; // Return NULL if memory allocation fails
    }
    snprintf(str, digits + 1, "%lu", (long unsigned int)num); // Use snprintf with dynamically calculated buffer size
    return str;
}

cstring fossil_cstr_from_double(double num) {
    // Decide the maximum possible length of the string
    int max_length = 50; // Arbitrarily chosen

    // Allocate memory for the string
    cstring str = malloc(max_length);
    if (!str) {
        return NULL; // Return NULL if memory allocation fails
    }

    // Convert the double to string
    int written = snprintf(str, max_length, "%lf", num);
    if (written < 0 || written >= max_length) {
        free(str); // Free the allocated memory
        return NULL; // Return NULL if snprintf failed or buffer overflow
    }

    return str;
}

// Convert string to integer
int fossil_cstr_to_int(const_cstring str) {
    if (str == NULL || *str == '\0') {
        return 0; // Handle invalid input (NULL pointer or empty string)
    }

    char *endptr;
    errno = 0;
    long result = strtol(str, &endptr, 10);
    if (errno == ERANGE || *endptr != '\0' || result > INT_MAX || result < INT_MIN) {
        // Handle conversion error or overflow/underflow
        return 0; // Return a default value or indicate error
    }

    return (int)result;
}

// Convert string to floating point number
double fossil_cstr_to_double(const_cstring str) {
    if (str == NULL || *str == '\0') {
        return 0.0; // Handle invalid input (NULL pointer or empty string)
    }

    char *endptr;
    errno = 0;
    double result = strtod(str, &endptr);
    if (errno == ERANGE || *endptr != '\0') {
        // Handle conversion error
        return 0.0; // Return a default value or indicate error
    }

    return result;
}

// Convert string to long integer
long fossil_cstr_to_long(const_cstring str) {
    if (str == NULL || *str == '\0') {
        return 0; // Handle invalid input (NULL pointer or empty string)
    }

    char *endptr;
    errno = 0;
    long result = strtol(str, &endptr, 10);
    if (errno == ERANGE || *endptr != '\0') {
        // Handle conversion error
        return 0; // Return a default value or indicate error
    }

    return result;
}

// Convert string to unsigned long integer
unsigned long fossil_cstr_to_ulong(const_cstring str) {
    if (str == NULL || *str == '\0') {
        return 0; // Handle invalid input (NULL pointer or empty string)
    }

    char *endptr;
    errno = 0;
    unsigned long result = strtoul(str, &endptr, 10);
    if (errno == ERANGE || *endptr != '\0') {
        // Handle conversion error
        return 0; // Return a default value or indicate error
    }

    return result;
}

// Convert string to long long integer
long long fossil_cstr_to_llong(const_cstring str) {
    if (str == NULL || *str == '\0') {
        return 0; // Handle invalid input (NULL pointer or empty string)
    }

    char *endptr;
    errno = 0;
    long long result = strtoll(str, &endptr, 10);
    if (errno == ERANGE || *endptr != '\0') {
        // Handle conversion error
        return 0; // Return a default value or indicate error
    }

    return result;
}

unsigned long long fossil_cstr_to_ullong(const_cstring str) {
    if (str == NULL || *str == '\0') {
        return 0; // Handle invalid input (NULL pointer or empty string)
    }

    char *endptr;
    errno = 0;
    unsigned long long result = strtoull(str, &endptr, 10);
    if (errno == ERANGE || *endptr != '\0') {
        // Handle conversion error
        return 0; // Return a default value or indicate error
    }

    return result;
}
