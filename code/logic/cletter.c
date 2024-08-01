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

cletter fossil_cletter_at(const_cletter *str, size_t index) {
    if (str == NULL) {
        return '\0';
    }
    size_t len = strlen(str);
    if (index >= len) {
        return '\0';
    }
    return str[index];
}

int16_t fossil_cletter_is_alpha(cletter ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int16_t fossil_cletter_is_digit(cletter ch) {
    return (ch >= '0' && ch <= '9');
}

int16_t fossil_cletter_is_alnum(cletter ch) {
    return fossil_cletter_is_alpha(ch) || fossil_cletter_is_digit(ch);
}

int16_t fossil_cletter_is_lower(cletter ch) {
    return (ch >= 'a' && ch <= 'z');
}

int16_t fossil_cletter_is_upper(cletter ch) {
    return (ch >= 'A' && ch <= 'Z');
}

cletter fossil_cletter_to_lower(cletter ch) {
    if (fossil_cletter_is_upper(ch)) {
        return ch + ('a' - 'A');
    }
    return ch;
}

cletter fossil_cletter_to_upper(cletter ch) {
    if (fossil_cletter_is_lower(ch)) {
        return ch - ('a' - 'A');
    }
    return ch;
}

int16_t fossil_cletter_is_space(cletter ch) {
    return (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r' || ch == '\v' || ch == '\f');
}

int16_t fossil_cletter_is_punct(cletter ch) {
    return ((ch >= '!' && ch <= '/') ||
            (ch >= ':' && ch <= '@') ||
            (ch >= '[' && ch <= '`') ||
            (ch >= '{' && ch <= '~'));
}

int16_t fossil_cletter_is_graph(cletter ch) {
    return (ch >= '!' && ch <= '~');
}

int16_t fossil_cletter_is_print(cletter ch) {
    return (ch >= ' ' && ch <= '~');
}

int16_t fossil_cletter_is_cntrl(cletter ch) {
    return (ch >= 0 && ch <= 31) || (ch == 127);
}

int16_t fossil_cletter_is_xdigit(cletter ch) {
    return ((ch >= '0' && ch <= '9') ||
            (ch >= 'a' && ch <= 'f') ||
            (ch >= 'A' && ch <= 'F'));
}
