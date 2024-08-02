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

// Return the wide character at the specified index in a null-terminated wide C string
wletter fossil_wletter_at(const_wletter *str, size_t index) {
    if (!str || index >= fossil_wstr_length(str)) {
        return L'\0'; // Return null wide character for out-of-bounds access or null pointer
    }
    return str[index];
}

int16_t fossil_wletter_is_alpha(wletter ch) {
    if (ch == L'\0') {
        return 0;
    }
    return iswalpha(ch) ? 1 : 0;
}

int16_t fossil_wletter_is_digit(wletter ch) {
    if (ch == L'\0') {
        return 0;
    }
    return iswdigit(ch) ? 1 : 0;
}

int16_t fossil_wletter_is_alnum(wletter ch) {
    if (ch == L'\0') {
        return 0;
    }
    return iswalnum(ch) ? 1 : 0;
}

int16_t fossil_wletter_is_lower(wletter ch) {
    if (ch == L'\0') {
        return 0;
    }
    return iswlower(ch) ? 1 : 0;
}

int16_t fossil_wletter_is_upper(wletter ch) {
    if (ch == L'\0') {
        return 0;
    }
    return iswupper(ch) ? 1 : 0;
}

wletter fossil_wletter_to_lower(wletter ch) {
    if (ch == L'\0') {
        return 0;
    }
    return towlower(ch);
}

wletter fossil_wletter_to_upper(wletter ch) {
    if (ch == L'\0') {
        return 0;
    }
    return towupper(ch);
}

int16_t fossil_wletter_is_space(wletter ch) {
    if (ch == L'\0') {
        return 0;
    }
    return iswspace(ch) ? 1 : 0;
}

int16_t fossil_wletter_is_punct(wletter ch) {
    if (ch == L'\0') {
        return 0;
    }
    return iswpunct(ch) ? 1 : 0;
}

int16_t fossil_wletter_is_graph(wletter ch) {
    if (ch == L'\0') {
        return 0;
    }
    return iswgraph(ch) ? 1 : 0;
}

int16_t fossil_wletter_is_print(wletter ch) {
    if (ch == L'\0') {
        return 0;
    }
    return iswprint(ch) ? 1 : 0;
}

int16_t fossil_wletter_is_cntrl(wletter ch) {
    if (ch == L'\0') {
        return 0;
    }
    return iswcntrl(ch) ? 1 : 0;
}

int16_t fossil_wletter_is_xdigit(wletter ch) {
    if (ch == L'\0') {
        return 0;
    }
    return iswxdigit(ch) ? 1 : 0;
}
