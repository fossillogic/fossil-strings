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

// C Interface Functions for Classic C String Operations
#ifdef __cplusplus
extern "C" {
#endif

/** Compare two C strings.
 *  @param str1 The first C string to compare.
 *  @param str2 The second C string to compare.
 *  @return     An integer less than, equal to, or greater than zero if str1 is found, respectively, to be less than, to match, or be greater than str2.
 */
int fossil_cstr_compare(const_cstring str1, const_cstring str2);

/** Copy a C string.
 *  @param dest The destination C string.
 *  @param src  The source C string.
 *  @return     A pointer to the destination C string.
 */
cstring fossil_cstr_copy(cstring dest, const_cstring src);

/** Concatenate two C strings.
 *  @param dest The destination C string.
 *  @param src  The source C string.
 *  @return     A pointer to the destination C string.
 */
cstring fossil_cstr_concat(cstring dest, const_cstring src);

/** Find the first occurrence of a character in a C string.
 *  @param str The C string to search.
 *  @param ch  The character to find.
 *  @return    A pointer to the first occurrence of ch in str, or a null pointer if ch is not found.
 */
const_cstring fossil_cstr_find(const_cstring str, cletter ch);

/** Reverse a C string.
 *  @param str The C string to reverse.
 *  @return    A pointer to the reversed C string.
 */
const_cstring fossil_cstr_reverse(const_cstring str);

/** Split a C string into an array of C strings.
 *  @param str       The C string to split.
 *  @param delimiter The delimiter character.
 *  @return          An array of C strings.
 */
cstrings fossil_cstr_split(const_cstring str, cletter delimiter);

/** Duplicate a C string.
 *  @param str The C string to duplicate.
 *  @return    A pointer to the duplicated C string.
 */
cstring fossil_cstr_strdup(const_cstring str);

/** Extract a substring from a C string.
 *  @param str   The C string to extract from.
 *  @param start The starting index of the substring.
 *  @param len   The length of the substring.
 *  @return      A pointer to the extracted substring.
 */
cstring fossil_cstr_substr(const_cstring str, size_t start, size_t len);

/** Erase an array of C strings.
 *  @param splits The array of C strings to erase.
 */
void fossil_cstr_erase_splits(cstrings splits);

/** Convert an integer to a C string.
 *  @param num The integer to convert.
 *  @return    A pointer to the converted C string.
 */
cstring fossil_cstr_from_int(int num);

/** Convert a long integer to a C string.
 *  @param num The long integer to convert.
 *  @return    A pointer to the converted C string.
 */
cstring fossil_cstr_from_long(long num);

/** Convert a long long integer to a C string.
 *  @param num The long long integer to convert.
 *  @return    A pointer to the converted C string.
 */
cstring fossil_cstr_from_llong(long long num);

/** Convert an unsigned long integer to a C string.
 *  @param num The unsigned long integer to convert.
 *  @return    A pointer to the converted C string.
 */
cstring fossil_cstr_from_ulong(unsigned long num);

/** Convert an unsigned long long integer to a C string.
 *  @param num The unsigned long long integer to convert.
 *  @return    A pointer to the converted C string.
 */
cstring fossil_cstr_from_ullong(unsigned long long num);

/** Convert a double to a C string.
 *  @param num The double to convert.
 *  @return    A pointer to the converted C string.
 */
cstring fossil_cstr_from_double(double num);

/** Convert a C string to an integer.
 *  @param str The C string to convert.
 *  @return    The converted integer value.
 */
int fossil_cstr_to_int(const_cstring str);

/** Convert a C string to a double.
 *  @param str The C string to convert.
 *  @return    The converted double value.
 */
double fossil_cstr_to_double(const_cstring str);

/** Convert a C string to a long integer.
 *  @param str The C string to convert.
 *  @return    The converted long integer value.
 */
long fossil_cstr_to_long(const_cstring str);

/** Convert a C string to an unsigned long integer.
 *  @param str The C string to convert.
 *  @return    The converted unsigned long integer value.
 */
unsigned long fossil_cstr_to_ulong(const_cstring str);

/** Convert a C string to a long long integer.
 *  @param str The C string to convert.
 *  @return    The converted long long integer value.
 */
long long fossil_cstr_to_llong(const_cstring str);

/** Convert a C string to an unsigned long long integer.
 *  @param str The C string to convert.
 *  @return    The converted unsigned long long integer value.
 */
unsigned long long fossil_cstr_to_ullong(const_cstring str);

/** Convert a C string to a boolean value.
 *  @param str The C string to convert.
 *  @return    The converted boolean value.
 */
int fossil_cstr_to_bool(const_cstring str);

#ifdef __cplusplus
} // namespae fossil
#endif

#endif /* FOSSIL_STRINGS_FRAMEWORK_H */
