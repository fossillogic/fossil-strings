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
#include "fossil/string/wstring.h"

// Helper function to calculate the number of digits in an integer
int _wstr_num_digits(long long num) {
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

// String library functions
wstring fossil_wstr_create(const_wstring str) {
    if (str == NULL) {
        return NULL;
    }

    size_t len = wcslen(str);
    wstring new_str = (wstring)malloc((len + 1) * sizeof(wletter));
    
    if (new_str == NULL) {
        // Handle memory allocation failure
        return NULL;
    }

    wcscpy(new_str, str);
    return new_str;
}

void fossil_wstr_erase(wstring str) {
    if (str != NULL) {
        free(str);
    }
}

size_t fossil_wstr_length(const_wstring str) {
    if (str == NULL) {
        return 0;
    }

    return wcslen(str);
}

wstring fossil_wstr_format(const_wstring format, ...) {
    if (!format) {
        return NULL; // Input validation
    }

    va_list args, args_copy;
    va_start(args, format);
    va_copy(args_copy, args);

    // Calculate required size
    int size = vswprintf(NULL, 0, (const wchar_t *)format, args);
    va_end(args);

    if (size < 0) {
        return NULL; // Error handling
    }

    wstring buffer = malloc((size_t)size * sizeof(wchar_t) + sizeof(wchar_t));
    if (!buffer) {
        return NULL; // Memory management
    }

    vswprintf((wchar_t *)buffer, (size_t)size + 1, (const wchar_t *)format, args_copy);
    va_end(args_copy);

    return buffer;
}

wstring fossil_wstr_format_phone(const_wstring phone) {
    if (!phone || wcslen(phone) != 10) {
        return NULL;
    }

    return fossil_wstr_format(L"(%c%c%c) %c%c%c-%c%c%c%c",
                            phone[0], phone[1], phone[2],
                            phone[3], phone[4], phone[5],
                            phone[6], phone[7], phone[8], phone[9]);
}

wstring fossil_wstr_format_date(const_wstring date) {
    if (!date || wcslen(date) != 8) {
        return NULL;
    }

    return fossil_wstr_format(L"%c%c/%c%c/%c%c%c%c",
                            date[0], date[1],
                            date[2], date[3],
                            date[4], date[5], date[6], date[7]);
}

wstring fossil_wstr_format_time(const_wstring time) {
    if (!time || wcslen(time) != 6) {
        return NULL;
    }

    return fossil_wstr_format(L"%c%c:%c%c:%c%c",
                            time[0], time[1],
                            time[2], time[3],
                            time[4], time[5]);
}

wstring fossil_wstr_format_currency(const_wstring currency) {
    if (!currency) {
        return NULL;
    }

    return fossil_wstr_format(L"$%s", currency);
}

wstring fossil_wstr_format_percentage(const_wstring percentage) {
    if (!percentage) {
        return NULL;
    }

    return fossil_wstr_format(L"%s%%", percentage);
}

wstring fossil_wstr_format_postal_code(const_wstring postal_code) {
    if (!postal_code || wcslen(postal_code) != 5) {
        return NULL;
    }

    return fossil_wstr_format(L"%c%c%c%c%c",
                            postal_code[0], postal_code[1],
                            postal_code[2], postal_code[3],
                            postal_code[4]);
}

wstring fossil_wstr_format_ssn(const_wstring ssn) {
    if (!ssn || wcslen(ssn) != 9) {
        return NULL;
    }

    return fossil_wstr_format(L"%c%c%c-%c%c-%c%c%c%c",
                            ssn[0], ssn[1], ssn[2],
                            ssn[3], ssn[4],
                            ssn[5], ssn[6], ssn[7], ssn[8]);
}

int fossil_wstr_compare(const_wstring str1, const_wstring str2) {
    if (str1 == NULL || str2 == NULL) {
        return (str1 == NULL && str2 == NULL) ? 0 : (str1 == NULL) ? -1 : 1;
    }

    return wcscmp(str1, str2);
}

wstring fossil_wstr_copy(wstring dest, const_wstring src) {
    if (src == NULL) {
        return dest;
    }

    size_t len = wcslen(src);
    if (dest == NULL) {
        dest = (wstring)malloc((len + 1) * sizeof(wletter));
        if (dest == NULL) {
            return NULL; // Memory allocation failed
        }
    }

    wcscpy(dest, src);
    return dest;
}

wstring fossil_wstr_concat(wstring dest, const_wstring src) {
    if (src == NULL) {
        return dest;
    }

    size_t dest_len = (dest != NULL) ? wcslen(dest) : 0;
    size_t src_len = wcslen(src);
    wstring new_str = (wstring)realloc(dest, (dest_len + src_len + 1) * sizeof(wletter));
    
    if (new_str == NULL) {
        return NULL; // Memory allocation failed
    }

    wcscat(new_str, src);
    return new_str;
}

const_wstring fossil_wstr_find(const_wstring str, wletter ch) {
    if (str == NULL) {
        return NULL;
    }

    return wcschr(str, ch);
}

const_wstring fossil_wstr_reverse(const_wstring str) {
    if (str == NULL) {
        return NULL;
    }

    size_t len = wcslen(str);
    wstring rev_str = (wstring)malloc((len + 1) * sizeof(wletter));
    
    if (rev_str == NULL) {
        return NULL; // Memory allocation failed
    }

    for (size_t i = 0; i < len; i++) {
        rev_str[i] = str[len - 1 - i];
    }
    rev_str[len] = L'\0';

    return rev_str;
}

wstrings fossil_wstr_split(const_wstring str, wletter delimiter) {
    if (str == NULL) {
        return NULL;
    }

    size_t len = wcslen(str);
    wstrings splits = (wstrings)malloc((len + 1) * sizeof(wstring));
    
    if (splits == NULL) {
        return NULL; // Memory allocation failed
    }

    size_t count = 0;
    const_wstring start = str;
    for (size_t i = 0; i <= len; i++) {
        if (str[i] == delimiter || str[i] == L'\0') {
            size_t sub_len = &str[i] - start;
            splits[count] = (wstring)malloc((sub_len + 1) * sizeof(wletter));
            
            if (splits[count] == NULL) {
                fossil_wstr_erase_splits(splits);
                return NULL; // Memory allocation failed
            }

            wcsncpy(splits[count], start, sub_len);
            splits[count][sub_len] = L'\0';
            count++;
            start = &str[i + 1];
        }
    }
    splits[count] = NULL;

    return splits;
}

wstring fossil_wstr_strdup(const_wstring str) {
    return fossil_wstr_copy(NULL, str);
}

wstring fossil_wstr_substr(const_wstring str, size_t start, size_t len) {
    if (str == NULL) {
        return NULL;
    }

    size_t str_len = wcslen(str);
    if (start >= str_len) {
        return NULL; // Start index out of range
    }

    if (start + len > str_len) {
        len = str_len - start;
    }

    wstring substr = (wstring)malloc((len + 1) * sizeof(wletter));
    if (substr == NULL) {
        return NULL; // Memory allocation failed
    }

    wcsncpy(substr, &str[start], len);
    substr[len] = L'\0';

    return substr;
}

void fossil_wstr_erase_splits(wstrings splits) {
    if (splits == NULL) {
        return;
    }

    for (size_t i = 0; splits[i] != NULL; i++) {
        free(splits[i]);
    }
    free(splits);
}

// Read a substring of length 'len' from the string starting at position 'pos'
wstring fossil_wstrstream_read(const_wstring str, size_t *pos, size_t len) {
    if (!str || *pos >= fossil_wstr_length(str) || len == 0) {
        return NULL; // Invalid input or end of string reached, or zero length
    }
    wstring buffer = fossil_wstr_substr(str, *pos, len);
    if (!buffer) {
        return NULL; // Memory allocation failure
    }
    *pos += fossil_wstr_length(buffer); // Move position by the length of the read substring
    return buffer;
}

// Read a line from the string starting at position 'pos' and update 'end_pos'
wstring fossil_wstrstream_read_line(wstring str, size_t *pos, size_t *end_pos) {
    if (!str || *pos >= fossil_wstr_length(str) || !end_pos) {
        return NULL; // Invalid input or end of string reached
    }
    size_t start = *pos;
    while (*pos < fossil_wstr_length(str) && fossil_wletter_at(str, *pos) != L'\n') {
        (*pos)++;
    }
    wstring buffer = fossil_wstr_substr(str, start, *pos - start);
    if (!buffer) {
        return NULL; // Memory allocation failure
    }
    if (*pos < fossil_wstr_length(str) && fossil_wletter_at(str, *pos) == L'\n') {
        (*pos)++;
    }
    *end_pos = *pos;
    return buffer;
}

// Write the source string to the destination starting at position 'pos'
void fossil_wstrstream_write(wstring dest, size_t *pos, const_wstring src) {
    if (!dest || !src) {
        return; // Invalid input
    }
    size_t destLen = fossil_wstr_length(dest);
    size_t srcLen = fossil_wstr_length(src);
    if (*pos + srcLen >= destLen) {
        return; // Writing would exceed buffer size
    }
    fossil_wstr_copy(dest + *pos, src); // Copy source string to destination buffer
    *pos += srcLen; // Move position by the length of the written substring
}

// Append the source string to the destination starting at position 'pos'
void fossil_wstrstream_append(wstring dest, size_t *pos, const_wstring src) {
    if (!dest || !src) {
        return; // Invalid input
    }
    size_t srcLen = fossil_wstr_length(src);
    fossil_wstr_copy(dest + *pos, src); // Copy source string to destination at specified position
    *pos += srcLen; // Move position by the length of the appended substring
}

// Set the stream position to 'offset'
void fossil_wstrstream_seek(size_t *pos, size_t offset) {
    *pos = offset;
}

// Return the current stream position
size_t fossil_wstrstream_tell(const_wstring str, size_t pos) {
    // Ensure the string is not NULL
    if (str == NULL) {
        // Handle the error, e.g., by returning a special value or by using an assertion
        return (size_t)-1;
    }

    // Get the length of the wide string
    size_t length = 0;
    while (str[length] != L'\0') {
        length++;
    }

    // Check if pos is within the string bounds
    if (pos >= length) {
        // Handle the error, e.g., by returning a special value or by using an assertion
        return (size_t)-1;
    }
    return pos;
}

// Convert integer to wide string
wstring fossil_wstr_from_int(int num) {
    int digits = _wstr_num_digits(num);
    wstring str = (wstring)malloc((digits + 1) * sizeof(wchar_t)); // Allocate memory dynamically
    if (!str) {
        return NULL; // Return NULL if memory allocation fails
    }
    swprintf(str, digits + 1, L"%d", num); // Use swprintf with dynamically calculated buffer size
    return str;
}

// Convert long to wide string
wstring fossil_wstr_from_long(long num) {
    int digits = _wstr_num_digits(num);
    wstring str = (wstring)malloc((digits + 1) * sizeof(wchar_t)); // Allocate memory dynamically
    if (!str) {
        return NULL; // Return NULL if memory allocation fails
    }
    swprintf(str, digits + 1, L"%ld", num); // Use swprintf with dynamically calculated buffer size
    return str;
}

// Convert long long to wide string
wstring fossil_wstr_from_llong(long long num) {
    int digits = _wstr_num_digits(num);
    wstring str = (wstring)malloc((digits + 1) * sizeof(wchar_t)); // Allocate memory dynamically
    if (!str) {
        return NULL; // Return NULL if memory allocation fails
    }
    swprintf(str, digits + 1, L"%ld", (long int)num); // Use swprintf with dynamically calculated buffer size
    return str;
}

// Convert unsigned long to wide string
wstring fossil_wstr_from_ulong(unsigned long num) {
    int digits = _wstr_num_digits(num);
    wstring str = (wstring)malloc((digits + 1) * sizeof(wchar_t)); // Allocate memory dynamically
    if (!str) {
        return NULL; // Return NULL if memory allocation fails
    }
    swprintf(str, digits + 1, L"%lu", num); // Use swprintf with dynamically calculated buffer size
    return str;
}

// Convert unsigned long long to wide string
wstring fossil_wstr_from_ullong(unsigned long long num) {
    int digits = _wstr_num_digits(num);
    wstring str = (wstring)malloc((digits + 1) * sizeof(wchar_t)); // Allocate memory dynamically
    if (!str) {
        return NULL; // Return NULL if memory allocation fails
    }
    swprintf(str, digits + 1, L"%lu", (long unsigned int)num); // Use swprintf with dynamically calculated buffer size
    return str;
}

wstring fossil_wstr_from_double(double num) {
    // Decide the maximum possible length of the string
    int max_length = 50; // Arbitrarily chosen

    // Allocate memory for the string
    wstring str = malloc(max_length * sizeof(wchar_t));
    if (!str) {
        return NULL; // Return NULL if memory allocation fails
    }

    // Convert the double to string
    int written = swprintf(str, max_length, L"%lf", (long unsigned int)num);
    if (written < 0 || written >= max_length) {
        free(str); // Free the allocated memory
        return NULL; // Return NULL if swprintf failed or buffer overflow
    }

    return str;
}

// Convert string to integer
int fossil_wstr_to_int(const_wstring str) {
    if (str == NULL || *str == L'\0') {
        return 0; // Handle invalid input (NULL pointer or empty string)
    }

    wchar_t *endptr;
    errno = 0;
    long result = wcstol(str, &endptr, 10);
    if (errno == ERANGE || *endptr != L'\0' || result > INT_MAX || result < INT_MIN) {
        // Handle conversion error or overflow/underflow
        return 0; // Return a default value or indicate error
    }

    return (int)result;
}

// Convert string to floating point number
double fossil_wstr_to_double(const_wstring str) {
    if (str == NULL || *str == L'\0') {
        return 0.0; // Handle invalid input (NULL pointer or empty string)
    }

    wchar_t *endptr;
    errno = 0;
    double result = wcstod(str, &endptr);
    if (errno == ERANGE || *endptr != L'\0') {
        // Handle conversion error
        return 0.0; // Return a default value or indicate error
    }

    return result;
}

// Convert string to long integer
long fossil_wstr_to_long(const_wstring str) {
    if (str == NULL || *str == L'\0') {
        return 0; // Handle invalid input (NULL pointer or empty string)
    }

    wchar_t *endptr;
    errno = 0;
    long result = wcstol(str, &endptr, 10);
    if (errno == ERANGE || *endptr != L'\0') {
        // Handle conversion error
        return 0; // Return a default value or indicate error
    }

    return result;
}

// Convert string to unsigned long integer
unsigned long fossil_wstr_to_ulong(const_wstring str) {
    if (str == NULL || *str == L'\0') {
        return 0; // Handle invalid input (NULL pointer or empty string)
    }

    wchar_t *endptr;
    errno = 0;
    unsigned long result = wcstoul(str, &endptr, 10);
    if (errno == ERANGE || *endptr != L'\0') {
        // Handle conversion error
        return 0; // Return a default value or indicate error
    }

    return result;
}

// Convert string to long long integer
long long fossil_wstr_to_llong(const_wstring str) {
    if (str == NULL || *str == L'\0') {
        return 0; // Handle invalid input (NULL pointer or empty string)
    }

    wchar_t *endptr;
    errno = 0;
    long long result = wcstoll(str, &endptr, 10);
    if (errno == ERANGE || *endptr != L'\0') {
        // Handle conversion error
        return 0; // Return a default value or indicate error
    }

    return result;
}

// Convert string to unsigned long long integer
unsigned long long fossil_wstr_to_ullong(const_wstring str) {
    if (str == NULL || *str == L'\0') {
        return 0; // Handle invalid input (NULL pointer or empty string)
    }

    wchar_t *endptr;
    errno = 0;
    unsigned long long result = wcstoull(str, &endptr, 10);
    if (errno == ERANGE || *endptr != L'\0') {
        // Handle conversion error
        return 0; // Return a default value or indicate error
    }

    return result;
}
