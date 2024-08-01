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

// Classic byte string type definitions
typedef const bletter* const_bstring;
typedef bletter* bstring;
typedef bletter** bstrings;
typedef const bletter** const_bstrings;

// C Interface Functions for Classic Byte String Operations
#ifdef __cplusplus
extern "C" {
#endif

/** Compare two byte strings.
 *  @param str1 The first byte string.
 *  @param str2 The second byte string.
 *  @return     An integer less than, equal to, or greater than zero if str1 is found, respectively, to be less than, to match, or be greater than str2.
 */
int fossil_bstr_compare(const_bstring str1, const_bstring str2);

/** Copy a byte string.
 *  @param dest The destination byte string.
 *  @param src  The source byte string.
 *  @return     The destination byte string.
 */
bstring fossil_bstr_copy(bstring dest, const_bstring src);

/** Concatenate two byte strings.
 *  @param dest The destination byte string.
 *  @param src  The source byte string.
 *  @return     The destination byte string.
 */
bstring fossil_bstr_concat(bstring dest, const_bstring src);

/** Find the first occurrence of a character in a byte string.
 *  @param str The byte string to search.
 *  @param ch  The character to find.
 *  @return    A pointer to the first occurrence of ch in str, or NULL if ch is not found.
 */
const_bstring fossil_bstr_find(const_bstring str, bletter ch);

/** Reverse a byte string.
 *  @param str The byte string to reverse.
 *  @return    The reversed byte string.
 */
const_bstring fossil_bstr_reverse(const_bstring str);

/** Split a byte string into an array of substrings.
 *  @param str       The byte string to split.
 *  @param delimiter The delimiter character.
 *  @return          An array of substrings.
 */
bstrings fossil_bstr_split(const_bstring str, bletter delimiter);

/** Duplicate a byte string.
 *  @param str The byte string to duplicate.
 *  @return    The duplicated byte string.
 */
bstring fossil_bstr_strdup(const_bstring str);

/** Extract a substring from a byte string.
 *  @param str   The byte string.
 *  @param start The starting index of the substring.
 *  @param len   The length of the substring.
 *  @return      The extracted substring.
 */
bstring fossil_bstr_substr(const_bstring str, size_t start, size_t len);

/** Erase an array of splits.
 *  @param splits The array of splits.
 */
void fossil_bstr_erase_splits(bstrings splits);

/** Convert an integer to a byte string.
 *  @param num The integer to convert.
 *  @return    The converted byte string.
 */
bstring fossil_bstr_from_int(int num);

/** Convert a long integer to a byte string.
 *  @param num The long integer to convert.
 *  @return    The converted byte string.
 */
bstring fossil_bstr_from_long(long num);

/** Convert a long long integer to a byte string.
 *  @param num The long long integer to convert.
 *  @return    The converted byte string.
 */
bstring fossil_bstr_from_llong(long long num);

/** Convert an unsigned long integer to a byte string.
 *  @param num The unsigned long integer to convert.
 *  @return    The converted byte string.
 */
bstring fossil_bstr_from_ulong(unsigned long num);

/** Convert an unsigned long long integer to a byte string.
 *  @param num The unsigned long long integer to convert.
 *  @return    The converted byte string.
 */
bstring fossil_bstr_from_ullong(unsigned long long num);

/** Convert a double to a byte string.
 *  @param num The double to convert.
 *  @return    The converted byte string.
 */
bstring fossil_bstr_from_double(double num);

/** Read a byte string from a stream.
 *  @param str  The byte string stream.
 *  @param pos  The current position in the stream.
 *  @param len  The length of the byte string to read.
 *  @return     The read byte string.
 */
bstring fossil_bstrstream_read(const_bstring str, size_t* pos, size_t len);

/** Read a line from a byte string stream.
 *  @param str      The byte string stream.
 *  @param pos      The current position in the stream.
 *  @param end_pos  The position of the end of the line.
 *  @return         The read line.
 */
bstring fossil_bstrstream_read_line(const_bstring str, size_t* pos, size_t* end_pos);

/** Write a byte string to a stream.
 *  @param dest The destination byte string stream.
 *  @param pos  The current position in the stream.
 *  @param src  The source byte string to write.
 */
void fossil_bstrstream_write(bstring dest, size_t* pos, const_bstring src);

/** Append a byte string to a stream.
 *  @param dest The destination byte string stream.
 *  @param pos  The current position in the stream.
 *  @param src  The source byte string to append.
 */
void fossil_bstrstream_append(bstring dest, size_t* pos, const_bstring src);

/** Seek to a position in a byte string stream.
 *  @param pos     The current position in the stream.
 *  @param offset  The offset to seek.
 */
void fossil_bstrstream_seek(size_t* pos, size_t offset);

/** Get the current position in a byte string stream.
 *  @param str  The byte string stream.
 *  @param pos  The current position in the stream.
 *  @return     The current position in the stream.
 */
size_t fossil_bstrstream_tell(const_bstring str, size_t pos);

/** Convert a byte string to an integer.
 *  @param str The byte string to convert.
 *  @return    The converted integer.
 */
int fossil_bstr_to_int(const_bstring str);

/** Convert a byte string to a double.
 *  @param str The byte string to convert.
 *  @return    The converted double.
 */
double fossil_bstr_to_double(const_bstring str);

/** Convert a byte string to a long integer.
 *  @param str The byte string to convert.
 *  @return    The converted long integer.
 */
long fossil_bstr_to_long(const_bstring str);

/** Convert a byte string to an unsigned long integer.
 *  @param str The byte string to convert.
 *  @return    The converted unsigned long integer.
 */
unsigned long fossil_bstr_to_ulong(const_bstring str);

/** Convert a byte string to a long long integer.
 *  @param str The byte string to convert.
 *  @return    The converted long long integer.
 */
long long fossil_bstr_to_llong(const_bstring str);

/** Convert a byte string to an unsigned long long integer.
 *  @param str The byte string to convert.
 *  @return    The converted unsigned long long integer.
 */
unsigned long long fossil_bstr_to_ullong(const_bstring str);

/** Convert a byte string to a boolean value.
 *  @param str The byte string to convert.
 *  @return    The converted boolean value.
 */
int fossil_bstr_to_bool(const_bstring str);

#ifdef __cplusplus
} // namespae fossil
#endif

#endif /* FOSSIL_STRINGS_FRAMEWORK_H */
