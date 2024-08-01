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
#ifndef FOSSIL_STRINGS_BLETTER_H
#define FOSSIL_STRINGS_BLETTER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h> // For size_t
#include <stdint.h> // For standard integer types like int, uint8_t, etc.
#include <string.h> // For C string operations like strlen, strcpy, etc.
#include <stdlib.h> // For dynamic memory allocation functions like malloc, free
#include <stdio.h>  // For standard I/O operations like printf, scanf, etc.

// charecter types for the string types
typedef uint16_t bletter;             // byte letter character
typedef const uint16_t const_bletter; // const byte letter character

/**
 * bletter functions
 */

/**
 * @brief Return the byte at the specified index in a byte string.
 *
 * @param str   The input byte string.
 * @param index The index of the byte to retrieve.
 * @return      The byte at the specified index, or '\0' if the index is out of bounds or the string is NULL.
 */
bletter fossil_bletter_at(const_bletter *str, size_t index);


/**
 * Check if the character is an alphabetic character.
 * 
 * Returns a non-zero value if 'ch' is an alphabetic character, otherwise 0.
 */
int16_t fossil_bletter_is_alpha(bletter ch);

/**
 * Check if the character is a digit.
 * 
 * Returns a non-zero value if 'ch' is a digit, otherwise 0.
 */
int16_t fossil_bletter_is_digit(bletter ch);

/**
 * Check if the character is an alphanumeric character.
 * 
 * Returns a non-zero value if 'ch' is an alphanumeric character, otherwise 0.
 */
int16_t fossil_bletter_is_alnum(bletter ch);

/**
 * Check if the character is a lowercase letter.
 * 
 * Returns a non-zero value if 'ch' is a lowercase letter, otherwise 0.
 */
int16_t fossil_bletter_is_lower(bletter ch);

/**
 * Check if the character is an uppercase letter.
 * 
 * Returns a non-zero value if 'ch' is an uppercase letter, otherwise 0.
 */
int16_t fossil_bletter_is_upper(bletter ch);

/**
 * Convert the character to lowercase.
 * 
 * Returns the lowercase version of 'ch' if 'ch' is an uppercase letter, otherwise 'ch'.
 */
bletter fossil_bletter_to_lower(bletter ch);

/**
 * Convert the character to uppercase.
 * 
 * Returns the uppercase version of 'ch' if 'ch' is a lowercase letter, otherwise 'ch'.
 */
bletter fossil_bletter_to_upper(bletter ch);

/**
 * Check if the character is a whitespace character.
 * 
 * Returns a non-zero value if 'ch' is a whitespace character, otherwise 0.
 */
int16_t fossil_bletter_is_space(bletter ch);

/**
 * Check if the character is a punctuation character.
 * 
 * Returns a non-zero value if 'ch' is a punctuation character, otherwise 0.
 */
int16_t fossil_bletter_is_punct(bletter ch);

/**
 * Check if the character is a printable character excluding space.
 * 
 * Returns a non-zero value if 'ch' is a printable character excluding space, otherwise 0.
 */
int16_t fossil_bletter_is_graph(bletter ch);

/**
 * Check if the character is a printable character including space.
 * 
 * Returns a non-zero value if 'ch' is a printable character including space, otherwise 0.
 */
int16_t fossil_bletter_is_print(bletter ch);

/**
 * Check if the character is a control character.
 * 
 * Returns a non-zero value if 'ch' is a control character, otherwise 0.
 */
int16_t fossil_bletter_is_cntrl(bletter ch);

/**
 * Check if the character is a hexadecimal digit.
 * 
 * Returns a non-zero value if 'ch' is a hexadecimal digit, otherwise 0.
 */
int16_t fossil_bletter_is_xdigit(bletter ch);

#ifdef __cplusplus
} // namespae fossil
#endif

#endif /* FOSSIL_STRINGS_FRAMEWORK_H */
