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
#ifndef FOSSIL_STRINGS_WLETTER_H
#define FOSSIL_STRINGS_WLETTER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <wchar.h>  // For wide character functions like wcslen, wcscpy, etc.
#include <wctype.h> // For wide character classification functions like iswalpha, iswdigit, etc.
#include <stddef.h> // For size_t
#include <stdint.h> // For standard integer types like int, uint8_t, etc.
#include <string.h> // For C string operations like strlen, strcpy, etc.
#include <stdlib.h> // For dynamic memory allocation functions like malloc, free
#include <stdio.h>  // For standard I/O operations like printf, scanf, etc.

// charecter types for the string types
typedef wchar_t wletter;             // wiswig character
typedef const wchar_t const_wletter; // const wiswig character

/**
 * wletter functions
 */

/**
 * @brief Return the wide character at the specified index in a null-terminated wide C string.
 *
 * @param str   The input null-terminated wide C string.
 * @param index The index of the wide character to retrieve.
 * @return      The wide character at the specified index, or L'\0' if the index is out of bounds or the string is NULL.
 */
wletter fossil_wletter_at(const_wletter *str, size_t index);

/**
 * Check if the wletter is an alphabetic character.
 * 
 * Returns a non-zero value if 'ch' is an alphabetic character, otherwise 0.
 */
int16_t fossil_wletter_is_alpha(wletter ch);

/**
 * Check if the wletter is a digit.
 * 
 * Returns a non-zero value if 'ch' is a digit, otherwise 0.
 */
int16_t fossil_wletter_is_digit(wletter ch);

/**
 * Check if the wletter is an alphanumeric character.
 * 
 * Returns a non-zero value if 'ch' is an alphanumeric character, otherwise 0.
 */
int16_t fossil_wletter_is_alnum(wletter ch);

/**
 * Check if the wletter is a lowercase letter.
 * 
 * Returns a non-zero value if 'ch' is a lowercase letter, otherwise 0.
 */
int16_t fossil_wletter_is_lower(wletter ch);

/**
 * Check if the wletter is an uppercase letter.
 * 
 * Returns a non-zero value if 'ch' is an uppercase letter, otherwise 0.
 */
int16_t fossil_wletter_is_upper(wletter ch);

/**
 * Convert the wletter to lowercase.
 * 
 * Returns the lowercase version of 'ch' if 'ch' is an uppercase letter, otherwise 'ch'.
 */
wletter fossil_wletter_to_lower(wletter ch);

/**
 * Convert the wletter to uppercase.
 * 
 * Returns the uppercase version of 'ch' if 'ch' is a lowercase letter, otherwise 'ch'.
 */
wletter fossil_wletter_to_upper(wletter ch);

/**
 * Check if the wletter is a whitespace character.
 * 
 * Returns a non-zero value if 'ch' is a whitespace character, otherwise 0.
 */
int16_t fossil_wletter_is_space(wletter ch);

/**
 * Check if the wletter is a punctuation character.
 * 
 * Returns a non-zero value if 'ch' is a punctuation character, otherwise 0.
 */
int16_t fossil_wletter_is_punct(wletter ch);

/**
 * Check if the wletter is a printable character excluding space.
 * 
 * Returns a non-zero value if 'ch' is a printable character excluding space, otherwise 0.
 */
int16_t fossil_wletter_is_graph(wletter ch);

/**
 * Check if the wletter is a printable character including space.
 * 
 * Returns a non-zero value if 'ch' is a printable character including space, otherwise 0.
 */
int16_t fossil_wletter_is_print(wletter ch);

/**
 * Check if the wletter is a control character.
 * 
 * Returns a non-zero value if 'ch' is a control character, otherwise 0.
 */
int16_t fossil_wletter_is_cntrl(wletter ch);

/**
 * Check if the wletter is a hexadecimal digit.
 * 
 * Returns a non-zero value if 'ch' is a hexadecimal digit, otherwise 0.
 */
int16_t fossil_wletter_is_xdigit(wletter ch);

#ifdef __cplusplus
} // namespae fossil
#endif

#endif /* FOSSIL_STRINGS_FRAMEWORK_H */
