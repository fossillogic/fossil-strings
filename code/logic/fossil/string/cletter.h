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
#ifndef FOSSIL_STRINGS_CLETTER_H
#define FOSSIL_STRINGS_CLETTER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <stdint.h>

// charecter types for the string types
typedef char cletter;                // classic C style character
typedef const char const_cletter;    // const classic C style character

/**
 * @brief Return the character at the specified index in a null-terminated C string.
 *
 * @param str   The input null-terminated C string.
 * @param index The index of the character to retrieve.
 * @return      The character at the specified index, or '\0' if the index is out of bounds or the string is NULL.
 */
cletter fossil_cletter_at(const_cletter *str, size_t index);

/**
 * Check if the character is an alphabetic character.
 * 
 * Returns a non-zero value if 'ch' is an alphabetic character, otherwise 0.
 */
int16_t fossil_cletter_is_alpha(cletter ch);

/**
 * Check if the character is a digit.
 * 
 * Returns a non-zero value if 'ch' is a digit, otherwise 0.
 */
int16_t fossil_cletter_is_digit(cletter ch);

/**
 * Check if the character is an alphanumeric character.
 * 
 * Returns a non-zero value if 'ch' is an alphanumeric character, otherwise 0.
 */
int16_t fossil_cletter_is_alnum(cletter ch);

/**
 * Check if the character is a lowercase letter.
 * 
 * Returns a non-zero value if 'ch' is a lowercase letter, otherwise 0.
 */
int16_t fossil_cletter_is_lower(cletter ch);

/**
 * Check if the character is an uppercase letter.
 * 
 * Returns a non-zero value if 'ch' is an uppercase letter, otherwise 0.
 */
int16_t fossil_cletter_is_upper(cletter ch);

/**
 * Convert the character to lowercase.
 * 
 * Returns the lowercase version of 'ch' if 'ch' is an uppercase letter, otherwise 'ch'.
 */
cletter fossil_cletter_to_lower(cletter ch);

/**
 * Convert the character to uppercase.
 * 
 * Returns the uppercase version of 'ch' if 'ch' is a lowercase letter, otherwise 'ch'.
 */
cletter fossil_cletter_to_upper(cletter ch);

/**
 * Check if the character is a whitespace character.
 * 
 * Returns a non-zero value if 'ch' is a whitespace character, otherwise 0.
 */
int16_t fossil_cletter_is_space(cletter ch);

/**
 * Check if the character is a punctuation character.
 * 
 * Returns a non-zero value if 'ch' is a punctuation character, otherwise 0.
 */
int16_t fossil_cletter_is_punct(cletter ch);

/**
 * Check if the character is a printable character excluding space.
 * 
 * Returns a non-zero value if 'ch' is a printable character excluding space, otherwise 0.
 */
int16_t fossil_cletter_is_graph(cletter ch);

/**
 * Check if the character is a printable character including space.
 * 
 * Returns a non-zero value if 'ch' is a printable character including space, otherwise 0.
 */
int16_t fossil_cletter_is_print(cletter ch);

/**
 * Check if the character is a control character.
 * 
 * Returns a non-zero value if 'ch' is a control character, otherwise 0.
 */
int16_t fossil_cletter_is_cntrl(cletter ch);

/**
 * Check if the character is a hexadecimal digit.
 * 
 * Returns a non-zero value if 'ch' is a hexadecimal digit, otherwise 0.
 */
int16_t fossil_cletter_is_xdigit(cletter ch);

#ifdef __cplusplus
} // namespae fossil
#endif

#endif /* FOSSIL_STRINGS_FRAMEWORK_H */
