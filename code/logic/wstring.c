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
#include "fossil/string/wstring.h"

int fossil_wstr_compare(const_wstring str1, const_wstring str2) {
    return wcscmp(str1, str2);
}

wstring fossil_wstr_copy(wstring dest, const_wstring src) {
    return wcscpy(dest, src);
}

wstring fossil_wstr_concat(wstring dest, const_wstring src) {
    return wcscat(dest, src);
}

const_wstring fossil_wstr_find(const_wstring str, wletter ch) {
    return wcschr(str, ch);
}

wstring fossil_wstr_reverse(wstring str) {
    size_t len = wcslen(str);
    for (size_t i = 0; i < len / 2; ++i) {
        wletter temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
    return str;
}

wstrings fossil_wstr_split(const_wstring str, wletter delimiter) {
    size_t count = 0;
    wstring temp = str;
    while (*temp) {
        if (*temp == delimiter) count++;
        temp++;
    }

    wstrings result = (wstrings)malloc((count + 2) * sizeof(wstring));
    if (!result) return NULL;

    size_t idx = 0;
    wstring token = wcstok((wstring)str, &delimiter, NULL);
    while (token) {
        result[idx++] = wcsdup(token);
        token = wcstok(NULL, &delimiter, NULL);
    }
    result[idx] = NULL;

    return result;
}

void fossil_wstr_erase_splits(wstrings splits) {
    if (!splits) return;
    for (size_t i = 0; splits[i]; i++) {
        free(splits[i]);
    }
    free(splits);
}

wstring fossil_wstr_strdup(const_wstring str) {
    size_t len = wcslen(str);
    wstring dup = (wstring)malloc((len + 1) * sizeof(wletter));
    if (dup) {
        wcscpy(dup, str);
    }
    return dup;
}

wstring fossil_wstr_substr(const_wstring str, size_t start, size_t len) {
    if (start >= wcslen(str)) return NULL;

    wstring substr = (wstring)malloc((len + 1) * sizeof(wletter));
    if (!substr) return NULL;

    wcsncpy(substr, str + start, len);
    substr[len] = L'\0';

    return substr;
}

wstring fossil_wstr_from_int(int num) {
    wchar_t buffer[32];
    swprintf(buffer, sizeof(buffer) / sizeof(wchar_t), L"%d", num);
    return fossil_wstr_strdup(buffer);
}

wstring fossil_wstr_from_long(long num) {
    wchar_t buffer[32];
    swprintf(buffer, sizeof(buffer) / sizeof(wchar_t), L"%ld", num);
    return fossil_wstr_strdup(buffer);
}

wstring fossil_wstr_from_llong(long long num) {
    wchar_t buffer[32];
    swprintf(buffer, sizeof(buffer) / sizeof(wchar_t), L"%lld", num);
    return fossil_wstr_strdup(buffer);
}

wstring fossil_wstr_from_ulong(unsigned long num) {
    wchar_t buffer[32];
    swprintf(buffer, sizeof(buffer) / sizeof(wchar_t), L"%lu", num);
    return fossil_wstr_strdup(buffer);
}

wstring fossil_wstr_from_ullong(unsigned long long num) {
    wchar_t buffer[32];
    swprintf(buffer, sizeof(buffer) / sizeof(wchar_t), L"%llu", num);
    return fossil_wstr_strdup(buffer);
}

wstring fossil_wstr_from_double(double num) {
    wchar_t buffer[64];
    swprintf(buffer, sizeof(buffer) / sizeof(wchar_t), L"%f", num);
    return fossil_wstr_strdup(buffer);
}

int fossil_wstr_to_int(const_wstring str) {
    return wcstol(str, NULL, 10);
}

double fossil_wstr_to_double(const_wstring str) {
    return wcstod(str, NULL);
}

long fossil_wstr_to_long(const_wstring str) {
    return wcstol(str, NULL, 10);
}

unsigned long fossil_wstr_to_ulong(const_wstring str) {
    return wcstoul(str, NULL, 10);
}

long long fossil_wstr_to_llong(const_wstring str) {
    return wcstoll(str, NULL, 10);
}

unsigned long long fossil_wstr_to_ullong(const_wstring str) {
    return wcstoull(str, NULL, 10);
}

int fossil_wstr_to_bool(const_wstring str) {
    if (wcscmp(str, L"true") == 0 || wcscmp(str, L"1") == 0) return 1;
    return 0;
}
