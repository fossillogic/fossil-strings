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

#include "wletter.h"

#ifdef __cplusplus
extern "C" {
#endif

// Classic wide-character C string types
typedef wchar_t wletter;
typedef wstring wstring;
typedef wchar_t** wstrings;
typedef const wstring const_wstring;
typedef const wchar_t** const_wstrings;

// C interface functions

/** Compare two wide strings.
 *  @param str1 The first wide string to compare.
 *  @param str2 The second wide string to compare.
 *  @return     A negative value if str1 is less than str2, a positive value if str1 is greater than str2, or 0 if they are equal.
 */
int fossil_wstr_compare(const_wstring str1, const_wstring str2);

/** Copy a wide string.
 *  @param dest The destination wide string.
 *  @param src  The source wide string.
 *  @return     The destination wide string.
 */
wstring fossil_wstr_copy(wstring dest, const_wstring src);

/** Concatenate two wide strings.
 *  @param dest The destination wide string.
 *  @param src  The source wide string.
 *  @return     The destination wide string.
 */
wstring fossil_wstr_concat(wstring dest, const_wstring src);

/** Find the first occurrence of a wide character in a wide string.
 *  @param str The wide string to search.
 *  @param ch  The wide character to find.
 *  @return    A pointer to the first occurrence of ch in str, or nullptr if ch is not found.
 */
const_wstring fossil_wstr_find(const_wstring str, wletter ch);

/** Reverse a wide string.
 *  @param str The wide string to reverse.
 *  @return    A pointer to the reversed wide string.
 */
const_wstring fossil_wstr_reverse(const_wstring str);

/** Split a wide string into multiple substrings based on a delimiter.
 *  @param str       The wide string to split.
 *  @param delimiter The delimiter character.
 *  @return          A vector of wide strings representing the substrings.
 */
wstrings fossil_wstr_split(const_wstring str, wletter delimiter);

/** Duplicate a wide string.
 *  @param str The wide string to duplicate.
 *  @return    The duplicated wide string.
 */
wstring fossil_wstr_strdup(const_wstring str);

/** Extract a substring from a wide string.
 *  @param str   The wide string.
 *  @param start The starting index of the substring.
 *  @param len   The length of the substring.
 *  @return      The extracted substring.
 */
wstring fossil_wstr_substr(const_wstring str, size_t start, size_t len);

/** Erase the splits created by fossil_wstr_split.
 *  @param splits The splits to erase.
 */
void fossil_wstr_erase_splits(wstrings splits);

/** Convert an integer to a wide string.
 *  @param num The integer value.
 *  @return    The wide string representation of the number.
 */
wstring fossil_wstr_from_int(int num);

/** Convert a long integer to a wide string.
 *  @param num The long integer value.
 *  @return    The wide string representation of the number.
 */
wstring fossil_wstr_from_long(long num);

/** Convert a long long integer to a wide string.
 *  @param num The long long integer value.
 *  @return    The wide string representation of the number.
 */
wstring fossil_wstr_from_llong(long long num);

/** Convert an unsigned long integer to a wide string.
 *  @param num The unsigned long integer value.
 *  @return    The wide string representation of the number.
 */
wstring fossil_wstr_from_ulong(unsigned long num);

/** Convert an unsigned long long integer to a wide string.
 *  @param num The unsigned long long integer value.
 *  @return    The wide string representation of the number.
 */
wstring fossil_wstr_from_ullong(unsigned long long num);

/** Convert a double to a wide string.
 *  @param num The double value.
 *  @return    The wide string representation of the number.
 */
wstring fossil_wstr_from_double(double num);

/** Read a specified number of characters from a wide string stream.
 *  @param str  The wide string stream.
 *  @param pos  The current position in the stream.
 *  @param len  The number of characters to read.
 *  @return     The read wide string.
 */
wstring fossil_wstrstream_read(const_wstring str, size_t* pos, size_t len);

/** Read a line from a wide string stream.
 *  @param str      The wide string stream.
 *  @param pos      The current position in the stream.
 *  @param end_pos  The position of the end of the line.
 *  @return         The read line as a wide string.
 */
wstring fossil_wstrstream_read_line(const_wstring str, size_t* pos, size_t* end_pos);

/** Write a wide string to a wide string stream at the specified position.
 *  @param dest The destination wide string stream.
 *  @param pos  The current position in the stream.
 *  @param src  The source wide string to write.
 */
void fossil_wstrstream_write(wstring dest, size_t* pos, const_wstring src);

/** Append a wide string to a wide string stream at the specified position.
 *  @param dest The destination wide string stream.
 *  @param pos  The current position in the stream.
 *  @param src  The source wide string to append.
 */
void fossil_wstrstream_append(wstring dest, size_t* pos, const_wstring src);

/** Seek to a new position in a wide string stream.
 *  @param pos    The current position in the stream.
 *  @param offset The offset to seek by.
 */
void fossil_wstrstream_seek(size_t* pos, size_t offset);

/** Get the current position in a wide string stream.
 *  @param str The wide string stream.
 *  @param pos The current position in the stream.
 *  @return    The current position in the stream.
 */
size_t fossil_wstrstream_tell(const_wstring str, size_t pos);

/** Convert a wide string to an integer.
 *  @param str The wide string representing the number.
 *  @return    The converted integer value.
 */
int fossil_wstr_to_int(const_wstring str);

/** Convert a wide string to a double.
 *  @param str The wide string representing the number.
 *  @return    The converted double value.
 */
double fossil_wstr_to_double(const_wstring str);

/** Convert a wide string to a long integer.
 *  @param str The wide string representing the number.
 *  @return    The converted long integer value.
 */
long fossil_wstr_to_long(const_wstring str);

/** Convert a wide string to an unsigned long integer.
 *  @param str The wide string representing the number.
 *  @return    The converted unsigned long integer value.
 */
unsigned long fossil_wstr_to_ulong(const_wstring str);

/** Convert a wide string to a long long integer.
 *  @param str The wide string representing the number.
 *  @return    The converted long long integer value.
 */
long long fossil_wstr_to_llong(const_wstring str);

/** Convert a wide string to an unsigned long long integer.
 *  @param str The wide string representing the number.
 *  @return    The converted unsigned long long integer value.
 */
unsigned long long fossil_wstr_to_ullong(const_wstring str);

/** Convert a wide string to a boolean value.
 *  @param str The wide string representing the boolean value.
 *  @return    The converted boolean value.
 */
int fossil_wstr_to_bool(const_wstring str);

#ifdef __cplusplus
} // namespae fossil
#endif

#endif /* FOSSIL_STRINGS_FRAMEWORK_H */
