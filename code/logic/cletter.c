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
#include "fossil/string/cletter.h"

// Return the character at the specified index in a null-terminated C string
cletter fossil_cletter_at(const_cletter *str, size_t index) {
    if (!str || index >= fossil_cstr_length(str)) {
        return '\0'; // Return null character for out-of-bounds access or null pointer
    }
    return str[index];
}

// cletter functions
int16_t fossil_cletter_is_alpha(cletter ch) {
    if (ch == '\0') {
        return 0;
    }
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int16_t fossil_cletter_is_digit(cletter ch) {
    if (ch == '\0') {
        return 0;
    }
    return ch >= '0' && ch <= '9';
}

int16_t fossil_cletter_is_alnum(cletter ch) {
    if (ch == '\0') {
        return 0;
    }
    return fossil_cletter_is_alpha(ch) || fossil_cletter_is_digit(ch);
}

int16_t fossil_cletter_is_lower(cletter ch) {
    if (ch == '\0') {
        return 0;
    }
    return ch >= 'a' && ch <= 'z';
}

int16_t fossil_cletter_is_upper(cletter ch) {
    if (ch == '\0') {
        return 0;
    }
    return ch >= 'A' && ch <= 'Z';
}

cletter fossil_cletter_to_lower(cletter ch) {
    if (ch == '\0') {
        return 0;
    }
    if (fossil_cletter_is_upper(ch)) {
        return ch + ('a' - 'A');
    }
    return ch;
}

cletter fossil_cletter_to_upper(cletter ch) {
    if (ch == '\0') {
        return 0;
    }
    if (fossil_cletter_is_lower(ch)) {
        return ch - ('a' - 'A');
    }
    return ch;
}

int16_t fossil_cletter_is_space(cletter ch) {
    if (ch == '\0') {
        return 0;
    }
    return isspace(ch);
}

int16_t fossil_cletter_is_punct(cletter ch) {
    if (ch == '\0') {
        return 0;
    }
    return ispunct(ch);
}

int16_t fossil_cletter_is_graph(cletter ch) {
    if (ch == '\0') {
        return 0;
    }
    return isgraph(ch);
}

int16_t fossil_cletter_is_print(cletter ch) {
    if (ch == '\0') {
        return 0;
    }
    return isprint(ch);
}

int16_t fossil_cletter_is_cntrl(cletter ch) {
    if (ch == '\0') {
        return 0;
    }
    return iscntrl(ch);
}

int16_t fossil_cletter_is_xdigit(cletter ch) {
    if (ch == '\0') {
        return 0;
    }
    return isxdigit(ch);
}
