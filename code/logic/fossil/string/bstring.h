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
#ifndef FOSSIL_STRINGS_BSTR_H
#define FOSSIL_STRINGS_BSTR_H

#ifdef __cplusplus
extern "C" {
#endif

#include "bletter.h" // For the bletter type definition

// Byte string macro
#define BSTR(str) ((bletter *)(str))

// Classic byte string type definitions
typedef const bletter* const_bstring;
typedef bletter* bstring;
typedef bletter** bstrings;
typedef const bletter** const_bstrings;

/**
 * Create a copy of a byte string.
 * 
 * Returns a new byte string containing a copy of the input byte string.
 */
bstring fossil_bstr_create(const_bstring str);

/**
 * Erase (free) a byte string.
 * 
 * Frees the memory allocated for the given byte string.
 */
void fossil_bstr_erase(bstring str);

/**
 * Get the length of a byte string.
 * 
 * Returns the length of the byte string.
 */
size_t fossil_bstr_length(const_bstring str);

/**
 * Format a byte string.
 * 
 * @param format The format byte string.
 * @param ... Additional arguments to format.
 * @return The formatted byte string, or NULL if an error occurred.
 */
bstring fossil_bstr_format(const_bstring format, ...);

/**
 * Format a phone number byte string.
 * 
 * @param phone The phone number byte string.
 * @return The formatted phone number byte string, or NULL if an error occurred.
 */
bstring fossil_bstr_format_phone(const_bstring phone);

/**
 * Format a date byte string.
 * 
 * @param date The date byte string.
 * @return The formatted date byte string, or NULL if an error occurred.
 */
bstring fossil_bstr_format_date(const_bstring date);

/**
 * Format a time byte string.
 * 
 * @param time The time byte string.
 * @return The formatted time byte string, or NULL if an error occurred.
 */
bstring fossil_bstr_format_time(const_bstring time);

/**
 * Format a currency byte string.
 * 
 * @param currency The currency byte string.
 * @return The formatted currency byte string, or NULL if an error occurred.
 */
bstring fossil_bstr_format_currency(const_bstring currency);

/**
 * Format a percentage byte string.
 * 
 * @param percentage The percentage byte string.
 * @return The formatted percentage byte string, or NULL if an error occurred.
 */
bstring fossil_bstr_format_percentage(const_bstring percentage);

/**
 * Format a postal code byte string.
 * 
 * @param postal_code The postal code byte string.
 * @return The formatted postal code byte string, or NULL if an error occurred.
 */
bstring fossil_bstr_format_postal_code(const_bstring postal_code);

/**
 * Format a SSN (Social Security Number) byte string.
 * 
 * @param ssn The SSN byte string.
 * @return The formatted SSN byte string, or NULL if an error occurred.
 */
bstring fossil_bstr_format_ssn(const_bstring ssn);

/**
 * Compare two byte strings.
 * 
 * Compares the byte strings 'str1' and 'str2'.
 * Returns 0 if they are equal, a negative value if 'str1' is less than 'str2', and a positive value if 'str1' is greater than 'str2'.
 */
int fossil_bstr_compare(const_bstring str1, const_bstring str2);

/**
 * Copy a byte string.
 * 
 * Copies the byte string 'src' to 'dest'.
 * Returns the destination string 'dest'.
 */
bstring fossil_bstr_copy(bstring dest, const_bstring src);

/**
 * Concatenate two byte strings.
 * 
 * Concatenates the byte string 'src' to 'dest'.
 * Returns the concatenated string 'dest'.
 */
bstring fossil_bstr_concat(bstring dest, const_bstring src);

/**
 * Find a character in a byte string.
 * 
 * Finds the first occurrence of 'ch' in 'str'.
 * Returns a pointer to the found character or NULL if not found.
 */
const_bstring fossil_bstr_find(const_bstring str, bletter ch);

/**
 * Reverse a byte string.
 * 
 * Reverses the byte string 'str'.
 * Returns the reversed string.
 */
const_bstring fossil_bstr_reverse(const_bstring str);

/**
 * Split a byte string by delimiter.
 * 
 * Splits the byte string 'str' by the delimiter 'delimiter'.
 * Returns an array of strings containing the split substrings.
 */
bstrings fossil_bstr_split(const_bstring str, bletter delimiter);

/**
 * Duplicate a byte string.
 * 
 * Duplicates the byte string 'str'.
 * Returns a newly allocated string containing a copy of 'str'.
 */
bstring fossil_bstr_strdup(const_bstring str);

/**
 * Extracts a substring from a byte string.
 * 
 * @param str   The byte string from which to extract the substring.
 * @param start The starting index of the substring.
 * @param len   The length of the substring to extract.
 * 
 * @return      A dynamically allocated byte string containing the extracted substring,
 *              or NULL if memory allocation fails or invalid parameters are provided.
 */
bstring fossil_bstr_substr(const_bstring str, size_t start, size_t len);

/**
 * Frees the memory allocated for an array of byte strings and the strings it contains.
 * 
 * @param splits An array of byte strings to be freed.
 * 
 * @note        After calling this function, the byte strings in the array `splits` will be
 *              deallocated and the array itself will be set to NULL.
 */
void fossil_bstr_erase_splits(bstrings splits);

/**
 * Convert integer to byte string.
 * 
 * @param num The integer to convert to a byte string.
 * @return A dynamically allocated byte string representing the integer, or bnullptr on failure.
 */
bstring fossil_bstr_from_int(int num);

/**
 * Convert long to byte string.
 * 
 * @param num The long integer to convert to a byte string.
 * @return A dynamically allocated byte string representing the long integer, or bnullptr on failure.
 */
bstring fossil_bstr_from_long(long num);

/**
 * Convert long long to byte string.
 * 
 * @param num The long long integer to convert to a byte string.
 * @return A dynamically allocated byte string representing the long long integer, or bnullptr on failure.
 */
bstring fossil_bstr_from_llong(long long num);

/**
 * Convert unsigned long to byte string.
 * 
 * @param num The unsigned long integer to convert to a byte string.
 * @return A dynamically allocated byte string representing the unsigned long integer, or bnullptr on failure.
 */
bstring fossil_bstr_from_ulong(unsigned long num);

/**
 * Convert unsigned long long to byte string.
 * 
 * @param num The unsigned long long integer to convert to a byte string.
 * @return A dynamically allocated byte string representing the unsigned long long integer, or bnullptr on failure.
 */
bstring fossil_bstr_from_ullong(unsigned long long num);

/**
 * Convert a double to a bstring.
 * 
 * @param num The double number to be converted.
 * @return A dynamically allocated bstring representing the double value.
 *         The caller is responsible for freeing the allocated memory.
 */
bstring fossil_bstr_from_double(double num);

/**
 * Convert byte string to integer
 * 
 * Converts the given byte string 'str' to an integer.
 * Returns the converted integer value.
 */
int fossil_bstr_to_int(const_bstring str);

/**
 * Convert byte string to floating point number
 * 
 * Converts the given byte string 'str' to a double precision floating point number.
 * Returns the converted floating point number.
 */
double fossil_bstr_to_double(const_bstring str);

/**
 * Convert byte string to long integer
 * 
 * Converts the given byte string 'str' to a long integer.
 * Returns the converted long integer value.
 */
long fossil_bstr_to_long(const_bstring str);

/**
 * Convert byte string to unsigned long integer
 * 
 * Converts the given byte string 'str' to an unsigned long integer.
 * Returns the converted unsigned long integer value.
 */
unsigned long fossil_bstr_to_ulong(const_bstring str);

/**
 * Convert byte string to long long integer
 * 
 * Converts the given byte string 'str' to a long long integer.
 * Returns the converted long long integer value.
 */
long long fossil_bstr_to_llong(const_bstring str);

/**
 * Convert byte string to unsigned long long integer
 * 
 * Converts the given byte string 'str' to an unsigned long long integer.
 * Returns the converted unsigned long long integer value.
 */
unsigned long long fossil_bstr_to_ullong(const_bstring str);

/**
 * Convert byte string to boolean
 * 
 * Converts the given byte string 'str' to a boolean value.
 * Returns 1 if 'str' is "true", "yes", "on", or non-zero; otherwise returns 0.
 */
int fossil_bstr_to_bool(const_bstring str);

/**
 * Read a substring from the given byte string 'str'.
 * 
 * Reads 'len' bytes from 'str' starting at position '*pos'.
 * Returns the read substring and updates '*pos' to the next position.
 */
bstring fossil_bstrstream_read(const_bstring str, size_t *pos, size_t len);

/**
 * Read a line from the given byte string 'str'.
 * 
 * Reads bytes from 'str' starting at position '*pos' until a newline or end of string.
 * Returns the read line and updates '*pos' to the next position after the newline.
 * Updates '*end_pos' to the position of the newline or end of string.
 */
bstring fossil_bstrstream_read_line(const_bstring str, size_t *pos, size_t *end_pos);

/**
 * Write a byte string to the given byte string 'dest'.
 * 
 * Writes the byte string 'src' to 'dest' starting at position '*pos'.
 * Updates '*pos' to the next position after the written byte string.
 */
void fossil_bstrstream_write(bstring dest, size_t *pos, const_bstring src);

/**
 * Append a byte string to the given byte string 'dest'.
 * 
 * Appends the byte string 'src' to 'dest' starting at position '*pos'.
 * Updates '*pos' to the next position after the appended byte string.
 */
void fossil_bstrstream_append(bstring dest, size_t *pos, const_bstring src);

/**
 * Seek to a specific position in the byte string stream.
 * 
 * Sets '*pos' to the specified 'offset'.
 */
void fossil_bstrstream_seek(size_t *pos, size_t offset);

/**
 * Get the current position in the byte string stream.
 * 
 * Returns the current position '*pos' in the byte string 'str'.
 */
size_t fossil_bstrstream_tell(const_bstring str, size_t pos);

#ifdef __cplusplus
} // namespae fossil
#endif

#endif /* FOSSIL_STRINGS_FRAMEWORK_H */
