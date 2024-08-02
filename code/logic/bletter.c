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
#include "fossil/string/bletter.h"

// Return the byte at the specified index in a byte string
bletter fossil_bletter_at(bletter *str, size_t index) {
    if (!str || index >= strlen((char *)str)) {
        return '\0'; // Return null character for out-of-bounds access or null pointer
    }
    return str[index];
}

// bletter functions
int16_t fossil_bletter_is_alpha(bletter ch) {
    if (ch == '\0') {
        return 0;
    }
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int16_t fossil_bletter_is_digit(bletter ch) {
    if (ch == '\0') {
        return 0;
    }
    return ch >= '0' && ch <= '9';
}

int16_t fossil_bletter_is_alnum(bletter ch) {
    if (ch == '\0') {
        return 0;
    }
    return fossil_bletter_is_alpha(ch) || fossil_bletter_is_digit(ch);
}

int16_t fossil_bletter_is_lower(bletter ch) {
    if (ch == '\0') {
        return 0;
    }
    return ch >= 'a' && ch <= 'z';
}

int16_t fossil_bletter_is_upper(bletter ch) {
    if (ch == '\0') {
        return 0;
    }
    return ch >= 'A' && ch <= 'Z';
}

bletter fossil_bletter_to_lower(bletter ch) {
    if (ch == '\0') {
        return 0;
    }
    if (fossil_bletter_is_upper(ch)) {
        return ch + ('a' - 'A');
    }
    return ch;
}

bletter fossil_bletter_to_upper(bletter ch) {
    if (ch == '\0') {
        return 0;
    }
    if (fossil_bletter_is_lower(ch)) {
        return ch - ('a' - 'A');
    }
    return ch;
}

int16_t fossil_bletter_is_space(bletter ch) {
    if (ch == '\0') {
        return 0;
    }
    return isspace(ch);
}

int16_t fossil_bletter_is_punct(bletter ch) {
    if (ch == '\0') {
        return 0;
    }
    return ispunct(ch);
}

int16_t fossil_bletter_is_graph(bletter ch) {
    if (ch == '\0') {
        return 0;
    }
    return isgraph(ch);
}

int16_t fossil_bletter_is_print(bletter ch) {
    if (ch == '\0') {
        return 0;
    }
    return isprint(ch);
}

int16_t fossil_bletter_is_cntrl(bletter ch) {
    if (ch == '\0') {
        return 0;
    }
    return iscntrl(ch);
}

int16_t fossil_bletter_is_xdigit(bletter ch) {
    if (ch == '\0') {
        return 0;
    }
    return isxdigit(ch);
}
