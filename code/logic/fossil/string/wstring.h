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
#ifndef FOSSIL_STRINGS_WSTR_H
#define FOSSIL_STRINGS_WSTR_H

#ifdef __cplusplus
extern "C" {
#endif

#include "wletter.h" // For the bletter type definition

typedef wletter * wstring;             // cstring type
typedef wletter ** wstrings;           // cstring array
typedef const_wletter * const_wstring; // constent wstrings
typedef wletter ** const_wstrings;     // constent wstring array

/**
 * Create a copy of a C string.
 * 
 * Returns a new C string containing a copy of the input string.
 */
wstring fossil_wstr_create(const_wstring str);

/**
 * Erase (free) a C string.
 * 
 * Frees the memory allocated for the given C string.
 */
void fossil_wstr_erase(wstring str);

/**
 * Get the length of a C string.
 * 
 * Returns the length of the C string.
 */
size_t fossil_wstr_length(const_wstring str);

/**
 * Format a wide string.
 * 
 * @param format The format wide string.
 * @param ... Additional arguments to format.
 * @return The formatted wide string, or NULL if an error occurred.
 */
wstring fossil_wstr_format(const_wstring format, ...);

/**
 * Format a phone number wide string.
 * 
 * @param phone The phone number wide string.
 * @return The formatted phone number wide string, or NULL if an error occurred.
 */
wstring fossil_wstr_format_phone(const_wstring phone);

/**
 * Format a date wide string.
 * 
 * @param date The date wide string.
 * @return The formatted date wide string, or NULL if an error occurred.
 */
wstring fossil_wstr_format_date(const_wstring date);

/**
 * Format a time wide string.
 * 
 * @param time The time wide string.
 * @return The formatted time wide string, or NULL if an error occurred.
 */
wstring fossil_wstr_format_time(const_wstring time);

/**
 * Format a currency wide string.
 * 
 * @param currency The currency wide string.
 * @return The formatted currency wide string, or NULL if an error occurred.
 */
wstring fossil_wstr_format_currency(const_wstring currency);

/**
 * Format a percentage wide string.
 * 
 * @param percentage The percentage wide string.
 * @return The formatted percentage wide string, or NULL if an error occurred.
 */
wstring fossil_wstr_format_percentage(const_wstring percentage);

/**
 * Format a postal code wide string.
 * 
 * @param postal_code The postal code wide string.
 * @return The formatted postal code wide string, or NULL if an error occurred.
 */
wstring fossil_wstr_format_postal_code(const_wstring postal_code);

/**
 * Format a SSN (Social Security Number) wide string.
 * 
 * @param ssn The SSN wide string.
 * @return The formatted SSN wide string, or NULL if an error occurred.
 */
wstring fossil_wstr_format_ssn(const_wstring ssn);

/**
 * Compare two classic C strings.
 * 
 * Compares the classic C strings 'str1' and 'str2'.
 * Returns 0 if they are equal, a negative value if 'str1' is less than 'str2', and a positive value if 'str1' is greater than 'str2'.
 */
int fossil_wstr_compare(const_wstring str1, const_wstring str2);

/**
 * Copy a classic C string.
 * 
 * Copies the classic C string 'src' to 'dest'.
 * Returns the destination string 'dest'.
 */
wstring fossil_wstr_copy(wstring dest, const_wstring src);

/**
 * Concatenate two classic C strings.
 * 
 * Concatenates the classic C string 'src' to 'dest'.
 * Returns the concatenated string 'dest'.
 */
wstring fossil_wstr_concat(wstring dest, const_wstring src);

/**
 * Find a character in a classic C string.
 * 
 * Finds the first occurrence of 'ch' in 'str'.
 * Returns a pointer to the found character or NULL if not found.
 */
const_wstring fossil_wstr_find(const_wstring str, wletter ch);

/**
 * Reverse a classic C string.
 * 
 * Reverses the classic C string 'str'.
 * Returns the reversed string.
 */
const_wstring fossil_wstr_reverse(const_wstring str);

/**
 * Split a classic C string by delimiter.
 * 
 * Splits the classic C string 'str' by the delimiter 'delimiter'.
 * Returns an array of strings containing the split substrings.
 */
wstrings fossil_wstr_split(const_wstring str, wletter delimiter);

/**
 * Duplicate a classic C string.
 * 
 * Duplicates the classic C string 'str'.
 * Returns a newly allocated string containing a copy of 'str'.
 */
wstring fossil_wstr_strdup(const_wstring str);

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
wstring fossil_wstr_substr(const_wstring str, size_t start, size_t len);

/**
 * Frees the memory allocated for an array of C strings and the strings it contains.
 * 
 * @param splits An array of C strings to be freed.
 * 
 * @note        After calling this function, the C strings in the array `splits` will be
 *              deallocated and the array itself will be set to NULL.
 */
void fossil_wstr_erase_splits(wstrings splits);

/**
 * Convert integer to wide string.
 * 
 * @param num The integer to convert to a wide string.
 * @return A dynamically allocated wide string representing the integer, or NULL on failure.
 */
wstring fossil_wstr_from_int(int num);

/**
 * Convert long to wide string.
 * 
 * @param num The long integer to convert to a wide string.
 * @return A dynamically allocated wide string representing the long integer, or NULL on failure.
 */
wstring fossil_wstr_from_long(long num);

/**
 * Convert long long to wide string.
 * 
 * @param num The long long integer to convert to a wide string.
 * @return A dynamically allocated wide string representing the long long integer, or NULL on failure.
 */
wstring fossil_wstr_from_llong(long long num);

/**
 * Convert unsigned long to wide string.
 * 
 * @param num The unsigned long integer to convert to a wide string.
 * @return A dynamically allocated wide string representing the unsigned long integer, or NULL on failure.
 */
wstring fossil_wstr_from_ulong(unsigned long num);

/**
 * Convert unsigned long long to wide string.
 * 
 * @param num The unsigned long long integer to convert to a wide string.
 * @return A dynamically allocated wide string representing the unsigned long long integer, or NULL on failure.
 */
wstring fossil_wstr_from_ullong(unsigned long long num);

/**
 * Convert a double to a wide string.
 * 
 * @param num The double number to be converted.
 * @return A dynamically allocated wide string representing the double value.
 *         The caller is responsible for freeing the allocated memory.
 */
wstring fossil_wstr_from_double(double num);

/**
 * Convert wide string to integer
 * 
 * Converts the given wide string 'str' to an integer.
 * Returns the converted integer value.
 */
int fossil_wstr_to_int(const_wstring str);

/**
 * Convert wide string to floating point number
 * 
 * Converts the given wide string 'str' to a double precision floating point number.
 * Returns the converted floating point number.
 */
double fossil_wstr_to_double(const_wstring str);

/**
 * Convert wide string to long integer
 * 
 * Converts the given wide string 'str' to a long integer.
 * Returns the converted long integer value.
 */
long fossil_wstr_to_long(const_wstring str);

/**
 * Convert wide string to unsigned long integer
 * 
 * Converts the given wide string 'str' to an unsigned long integer.
 * Returns the converted unsigned long integer value.
 */
unsigned long fossil_wstr_to_ulong(const_wstring str);

/**
 * Convert wide string to long long integer
 * 
 * Converts the given wide string 'str' to a long long integer.
 * Returns the converted long long integer value.
 */
long long fossil_wstr_to_llong(const_wstring str);

/**
 * Convert wide string to unsigned long long integer
 * 
 * Converts the given wide string 'str' to an unsigned long long integer.
 * Returns the converted unsigned long long integer value.
 */
unsigned long long fossil_wstr_to_ullong(const_wstring str);

/**
 * Convert wide string to boolean
 * 
 * Converts the given wide string 'str' to a boolean value.
 * Returns 1 if 'str' is "true", "yes", "on", or non-zero; otherwise returns 0.
 */
int fossil_wstr_to_bool(const_wstring str);

/**
 * @brief Read a substring of length 'len' from the wide string starting at position 'pos'.
 * 
 * @param str The wide string to read from.
 * @param pos Pointer to the current position in the string. Updated after reading.
 * @param len Length of the substring to read.
 * @return wstring The substring read from the wide string.
 */
wstring fossil_wstrstream_read(const_wstring str, size_t *pos, size_t len);

/**
 * @brief Read a line from the wide string starting at position 'pos' and update 'end_pos'.
 * 
 * @param str The wide string to read from.
 * @param pos Pointer to the current position in the string. Updated after reading.
 * @param end_pos Pointer to the end position of the read line. Updated after reading.
 * @return wstring The line read from the wide string.
 */
wstring fossil_wstrstream_read_line(wstring str, size_t *pos, size_t *end_pos);

/**
 * @brief Write the source wide string to the destination starting at position 'pos'.
 * 
 * @param dest The destination wide string.
 * @param pos Pointer to the current position in the destination string. Updated after writing.
 * @param src The source wide string to write.
 */
void fossil_wstrstream_write(wstring dest, size_t *pos, const_wstring src);

/**
 * @brief Append the source wide string to the destination starting at position 'pos'.
 * 
 * @param dest The destination wide string.
 * @param pos Pointer to the current position in the destination string. Updated after appending.
 * @param src The source wide string to append.
 */
void fossil_wstrstream_append(wstring dest, size_t *pos, const_wstring src);

/**
 * @brief Set the stream position to 'offset'.
 * 
 * @param pos Pointer to the stream position. Updated to 'offset'.
 * @param offset The new stream position.
 */
void fossil_wstrstream_seek(size_t *pos, size_t offset);

/**
 * @brief Return the current stream position.
 * 
 * @param str The wide string.
 * @param pos The current stream position.
 * @return size_t The current stream position.
 */
size_t fossil_wstrstream_tell(const_wstring str, size_t pos);

#ifdef __cplusplus
} // namespae fossil
#endif

#endif /* FOSSIL_STRINGS_FRAMEWORK_H */
