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
#ifndef FOSSIL_STRINGS_CSTR_H
#define FOSSIL_STRINGS_CSTR_H

#ifdef __cplusplus
extern "C" {
#endif

#include "cletter.h" // For classic C letter type definitions

// Classic C string type definitions
typedef const cletter* const_cstring;
typedef cletter* cstring;
typedef cletter** cstrings;
typedef const cletter** const_cstrings;

/**
 * Create a copy of a C string.
 * 
 * Returns a new C string containing a copy of the input string.
 */
cstring fossil_cstr_create(const_cstring str);

/**
 * Erase (free) a C string.
 * 
 * Frees the memory allocated for the given C string.
 */
void fossil_cstr_erase(cstring str);

/**
 * Get the length of a C string.
 * 
 * Returns the length of the C string.
 */
size_t fossil_cstr_length(const_cstring str);

/**
 * Format a string.
 * 
 * @param format The format string.
 * @param ... Additional arguments to format.
 * @return The formatted string, or NULL if an error occurred.
 */
cstring fossil_cstr_format(const_cstring format, ...);

/**
 * Format a phone number string.
 * 
 * @param phone The phone number string.
 * @return The formatted phone number string, or NULL if an error occurred.
 */
cstring fossil_cstr_format_phone(const_cstring phone);

/**
 * Format a date string.
 * 
 * @param date The date string.
 * @return The formatted date string, or NULL if an error occurred.
 */
cstring fossil_cstr_format_date(const_cstring date);

/**
 * Format a time string.
 * 
 * @param time The time string.
 * @return The formatted time string, or NULL if an error occurred.
 */
cstring fossil_cstr_format_time(const_cstring time);

/**
 * Format a currency string.
 * 
 * @param currency The currency string.
 * @return The formatted currency string, or NULL if an error occurred.
 */
cstring fossil_cstr_format_currency(const_cstring currency);

/**
 * Format a percentage string.
 * 
 * @param percentage The percentage string.
 * @return The formatted percentage string, or NULL if an error occurred.
 */
cstring fossil_cstr_format_percentage(const_cstring percentage);

/**
 * Format a postal code string.
 * 
 * @param postal_code The postal code string.
 * @return The formatted postal code string, or NULL if an error occurred.
 */
cstring fossil_cstr_format_postal_code(const_cstring postal_code);

/**
 * Format a SSN (Social Security Number) string.
 * 
 * @param ssn The SSN string.
 * @return The formatted SSN string, or NULL if an error occurred.
 */
cstring fossil_cstr_format_ssn(const_cstring ssn);

/**
 * Compare two classic C strings.
 * 
 * Compares the classic C strings 'str1' and 'str2'.
 * Returns 0 if they are equal, a negative value if 'str1' is less than 'str2', and a positive value if 'str1' is greater than 'str2'.
 */
int fossil_cstr_compare(const_cstring str1, const_cstring str2);

/**
 * Copy a classic C string.
 * 
 * Copies the classic C string 'src' to 'dest'.
 * Returns the destination string 'dest'.
 */
cstring fossil_cstr_copy(cstring dest, const_cstring src);

/**
 * Concatenate two classic C strings.
 * 
 * Concatenates the classic C string 'src' to 'dest'.
 * Returns the concatenated string 'dest'.
 */
cstring fossil_cstr_concat(cstring dest, const_cstring src);

/**
 * Find a character in a classic C string.
 * 
 * Finds the first occurrence of 'ch' in 'str'.
 * Returns a pointer to the found character or NULL if not found.
 */
const_cstring fossil_cstr_find(const_cstring str, cletter ch);

/**
 * Reverse a classic C string.
 * 
 * Reverses the classic C string 'str'.
 * Returns the reversed string.
 */
const_cstring fossil_cstr_reverse(const_cstring str);

/**
 * Split a classic C string by delimiter.
 * 
 * Splits the classic C string 'str' by the delimiter 'delimiter'.
 * Returns an array of strings containing the split substrings.
 */
cstrings fossil_cstr_split(const_cstring str, cletter delimiter);

/**
 * Duplicate a classic C string.
 * 
 * Duplicates the classic C string 'str'.
 * Returns a newly allocated string containing a copy of 'str'.
 */
cstring fossil_cstr_strdup(const_cstring str);

/**
 * Extracts a substring from a null-terminated C string.
 * 
 * @param str   The null-terminated C string from which to extract the substring.
 * @param start The starting index of the substring.
 * @param len   The length of the substring to extract.
 * 
 * @return      A dynamically allocated null-terminated C string containing the extracted substring,
 *              or NULL if memory allocation fails or invalid parameters are provided.
 */
cstring fossil_cstr_substr(const_cstring str, size_t start, size_t len);

/**
 * Frees the memory allocated for an array of C strings and the strings it contains.
 * 
 * @param splits An array of C strings to be freed.
 * 
 * @note        After calling this function, the C strings in the array `splits` will be
 *              deallocated and the array itself will be set to NULL.
 */
void fossil_cstr_erase_splits(cstrings splits);

/**
 * Convert integer to classic C string.
 * 
 * @param num The integer to convert to a classic C string.
 * @return A dynamically allocated classic C string representing the integer, or NULL on failure.
 */
cstring fossil_cstr_from_int(int num);

/**
 * Convert long to classic C string.
 * 
 * @param num The long integer to convert to a classic C string.
 * @return A dynamically allocated classic C string representing the long integer, or NULL on failure.
 */
cstring fossil_cstr_from_long(long num);

/**
 * Convert long long to classic C string.
 * 
 * @param num The long long integer to convert to a classic C string.
 * @return A dynamically allocated classic C string representing the long long integer, or NULL on failure.
 */
cstring fossil_cstr_from_llong(long long num);

/**
 * Convert unsigned long to classic C string.
 * 
 * @param num The unsigned long integer to convert to a classic C string.
 * @return A dynamically allocated classic C string representing the unsigned long integer, or NULL on failure.
 */
cstring fossil_cstr_from_ulong(unsigned long num);

/**
 * Convert unsigned long long to classic C string.
 * 
 * @param num The unsigned long long integer to convert to a classic C string.
 * @return A dynamically allocated classic C string representing the unsigned long long integer, or NULL on failure.
 */
cstring fossil_cstr_from_ullong(unsigned long long num);

/**
 * Convert a double to a C string.
 * 
 * @param num The double number to be converted.
 * @return A dynamically allocated C string representing the double value.
 *         The caller is responsible for freeing the allocated memory.
 */
cstring fossil_cstr_from_double(double num);

/**
 * Convert classic C string to integer
 * 
 * Converts the given classic C string 'str' to an integer.
 * Returns the converted integer value.
 */
int fossil_cstr_to_int(const_cstring str);

/**
 * Convert classic C string to floating point number
 * 
 * Converts the given classic C string 'str' to a double precision floating point number.
 * Returns the converted floating point number.
 */
double fossil_cstr_to_double(const_cstring str);

/**
 * Convert classic C string to long integer
 * 
 * Converts the given classic C string 'str' to a long integer.
 * Returns the converted long integer value.
 */
long fossil_cstr_to_long(const_cstring str);

/**
 * Convert classic C string to unsigned long integer
 * 
 * Converts the given classic C string 'str' to an unsigned long integer.
 * Returns the converted unsigned long integer value.
 */
unsigned long fossil_cstr_to_ulong(const_cstring str);

/**
 * Convert classic C string to long long integer
 * 
 * Converts the given classic C string 'str' to a long long integer.
 * Returns the converted long long integer value.
 */
long long fossil_cstr_to_llong(const_cstring str);

/**
 * Convert classic C string to unsigned long long integer
 * 
 * Converts the given classic C string 'str' to an unsigned long long integer.
 * Returns the converted unsigned long long integer value.
 */
unsigned long long fossil_cstr_to_ullong(const_cstring str);

/**
 * Convert classic C string to boolean
 * 
 * Converts the given classic C string 'str' to a boolean value.
 * Returns 1 if 'str' is "true", "yes", "on", or non-zero; otherwise returns 0.
 */
int fossil_cstr_to_bool(const_cstring str);

/**
 * Read a substring from the given classic C string 'str'.
 * 
 * Reads 'len' characters from 'str' starting at position '*pos'.
 * Returns the read substring and updates '*pos' to the next position.
 */
cstring fossil_cstrstream_read(const_cstring str, size_t *pos, size_t len);

/**
 * Read a line from the given classic C string 'str'.
 * 
 * Reads characters from 'str' starting at position '*pos' until a newline or end of string.
 * Returns the read line and updates '*pos' to the next position after the newline.
 * Updates '*end_pos' to the position of the newline or end of string.
 */
cstring fossil_cstrstream_read_line(const_cstring str, size_t *pos, size_t *end_pos);

/**
 * Write a string to the given classic C string 'dest'.
 * 
 * Writes the string 'src' to 'dest' starting at position '*pos'.
 * Updates '*pos' to the next position after the written string.
 */
void fossil_cstrstream_write(cstring dest, size_t *pos, const_cstring src);

/**
 * Append a string to the given classic C string 'dest'.
 * 
 * Appends the string 'src' to 'dest' starting at position '*pos'.
 * Updates '*pos' to the next position after the appended string.
 */
void fossil_cstrstream_append(cstring dest, size_t *pos, const_cstring src);

/**
 * Seek to a specific position in the classic C string stream.
 * 
 * Sets '*pos' to the specified 'offset'.
 */
void fossil_cstrstream_seek(size_t *pos, size_t offset);

/**
 * Get the current position in the classic C string stream.
 * 
 * Returns the current position '*pos' in the classic C string 'str'.
 */
size_t fossil_cstrstream_tell(const_cstring str, size_t pos);

#ifdef __cplusplus
} // namespae fossil
#endif

#endif /* FOSSIL_STRINGS_FRAMEWORK_H */
