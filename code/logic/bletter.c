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

bletter fossil_bletter_at(const_bletter *str, size_t index) {
    if (str == NULL || index < 0)
        return (uint16_t)'\0';
    
    size_t len = 0;
    while (str[len] != (uint16_t)'\0')
        len++;
    
    if (index >= len)
        return (uint16_t)'\0';
    
    return str[index];
}

int16_t fossil_bletter_is_alpha(bletter ch) {
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}

int16_t fossil_bletter_is_digit(bletter ch) {
    return (ch >= '0' && ch <= '9');
}

int16_t fossil_bletter_is_alnum(bletter ch) {
    return fossil_bletter_is_alpha(ch) || fossil_bletter_is_digit(ch);
}

int16_t fossil_bletter_is_lower(bletter ch) {
    return (ch >= 'a' && ch <= 'z');
}

int16_t fossil_bletter_is_upper(bletter ch) {
    return (ch >= 'A' && ch <= 'Z');
}

bletter fossil_bletter_to_lower(bletter ch) {
    if (fossil_bletter_is_upper(ch))
        return ch + ('a' - 'A');
    else
        return ch;
}

bletter fossil_bletter_to_upper(bletter ch) {
    if (fossil_bletter_is_lower(ch))
        return ch - ('a' - 'A');
    else
        return ch;
}

int16_t fossil_bletter_is_space(bletter ch) {
    return (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\v' || ch == '\f' || ch == '\r');
}

int16_t fossil_bletter_is_punct(bletter ch) {
    return ((ch >= '!' && ch <= '/') ||
            (ch >= ':' && ch <= '@') ||
            (ch >= '[' && ch <= '`') ||
            (ch >= '{' && ch <= '~'));
}

int16_t fossil_bletter_is_graph(bletter ch) {
    return (ch >= '!' && ch <= '~');
}

int16_t fossil_bletter_is_print(bletter ch) {
    return (ch >= ' ' && ch <= '~');
}

int16_t fossil_bletter_is_cntrl(bletter ch) {
    return (ch >= 0 && ch <= 31) || (ch == 127);
}

int16_t fossil_bletter_is_xdigit(bletter ch) {
    return (fossil_bletter_is_digit(ch) ||
            (ch >= 'A' && ch <= 'F') ||
            (ch >= 'a' && ch <= 'f'));
}
