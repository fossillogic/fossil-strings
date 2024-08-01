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
#include "fossil/string/wletter.h"

wletter fossil_wletter_at(const_wletter *str, size_t index) {
    if (str == NULL)
        return L'\0';

    const_wletter *p = str;
    size_t count = 0;
    while (*p != L'\0') {
        if (count == index)
            return *p;
        ++p;
        ++count;
    }

    return L'\0';
}

int16_t fossil_wletter_is_alpha(wletter ch) {
    return iswalpha(ch) != 0;
}

int16_t fossil_wletter_is_digit(wletter ch) {
    return iswdigit(ch) != 0;
}

int16_t fossil_wletter_is_alnum(wletter ch) {
    return iswalnum(ch) != 0;
}

int16_t fossil_wletter_is_lower(wletter ch) {
    return iswlower(ch) != 0;
}

int16_t fossil_wletter_is_upper(wletter ch) {
    return iswupper(ch) != 0;
}

wletter fossil_wletter_to_lower(wletter ch) {
    return towlower(ch);
}

wletter fossil_wletter_to_upper(wletter ch) {
    return towupper(ch);
}

int16_t fossil_wletter_is_space(wletter ch) {
    return iswspace(ch) != 0;
}

int16_t fossil_wletter_is_punct(wletter ch) {
    return iswpunct(ch) != 0;
}

int16_t fossil_wletter_is_graph(wletter ch) {
    return iswgraph(ch) != 0;
}

int16_t fossil_wletter_is_print(wletter ch) {
    return iswprint(ch) != 0;
}

int16_t fossil_wletter_is_cntrl(wletter ch) {
    return iswcntrl(ch) != 0;
}

int16_t fossil_wletter_is_xdigit(wletter ch) {
    return iswxdigit(ch) != 0;
}
