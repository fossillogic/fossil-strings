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

// Compare two wide strings
int fossil_wstr_compare(const_wstring str1, const_wstring str2) {
    return wcscmp(str1, str2);
}

// Copy source wide string to destination
wstring fossil_wstr_copy(wstring dest, const_wstring src) {
    if (dest != src) {
        wcscpy(dest, src);
    }
    return dest;
}

// Concatenate source wide string to destination
wstring fossil_wstr_concat(wstring dest, const_wstring src) {
    if (src != NULL && dest != src) {
        wcscat(dest, src);
    }
    return dest;
}

// Find character in wide string
const_wstring fossil_wstr_find(const_wstring str, wletter ch) {
    return wcschr(str, ch);
}

// Reverse the wide string
wstring fossil_wstr_reverse(wstring str) {
    size_t len = wcslen(str);
    wstring reversed = (wstring)malloc((len + 1) * sizeof(wletter));
    if (!reversed) return NULL;

    for (size_t i = 0; i < len; ++i) {
        reversed[i] = str[len - i - 1];
    }
    reversed[len] = L'\0';
    return reversed;
}

// Split wide string by delimiter
wstrings fossil_wstr_split(const_wstring str, wletter delimiter) {
    wstrings splits = malloc(sizeof(wstring));
    if (!splits) return NULL;
    size_t splits_size = 0;
    wstring start = str;
    wstring next = wcschr(start, delimiter);

    while (next != NULL) {
        size_t len = next - start;
        wstring substr = malloc((len + 1) * sizeof(wletter));
        if (!substr) return NULL; // Handle allocation failure
        wcsncpy(substr, start, len);
        substr[len] = L'\0';
        splits = realloc(splits, (splits_size + 1) * sizeof(wstring));
        if (!splits) return NULL; // Handle reallocation failure
        splits[splits_size++] = substr;
        start = next + 1;
        next = wcschr(start, delimiter);
    }

    wstring substr = malloc((wcslen(start) + 1) * sizeof(wletter));
    if (!substr) return NULL;
    wcscpy(substr, start);
    splits = realloc(splits, (splits_size + 1) * sizeof(wstring));
    if (!splits) return NULL;
    splits[splits_size++] = substr;
    splits[splits_size] = NULL;

    return splits;
}

// Duplicate wide string
wstring fossil_wstr_strdup(const_wstring str) {
    size_t len = wcslen(str);
    wstring dup = malloc((len + 1) * sizeof(wletter));
    if (!dup) return NULL;
    wcscpy(dup, str);
    return dup;
}

// Get substring of a wide string
wstring fossil_wstr_substr(const_wstring str, size_t start, size_t len) {
    if (start >= wcslen(str)) {
        return NULL;
    }
    wstring substr = malloc((len + 1) * sizeof(wletter));
    if (!substr) return NULL;
    wcsncpy(substr, str + start, len);
    substr[len] = L'\0';
    return substr;
}

// Free memory allocated for split wide strings
void fossil_wstr_erase_splits(wstrings splits) {
    if (splits) {
        for (size_t i = 0; splits[i] != NULL; ++i) {
            free(splits[i]);
        }
        free(splits);
    }
}

// Convert integer to wide string
wstring fossil_wstr_from_int(int num) {
    size_t len = swprintf(NULL, 0, L"%d", num);
    wstring result = malloc((len + 1) * sizeof(wletter));
    if (!result) return NULL;
    swprintf(result, len + 1, L"%d", num);
    return result;
}

// Convert long to wide string
wstring fossil_wstr_from_long(long num) {
    size_t len = swprintf(NULL, 0, L"%ld", num);
    wstring result = malloc((len + 1) * sizeof(wletter));
    if (!result) return NULL;
    swprintf(result, len + 1, L"%ld", num);
    return result;
}

// Convert long long to wide string
wstring fossil_wstr_from_llong(long long num) {
    size_t len = swprintf(NULL, 0, L"%lld", num);
    wstring result = malloc((len + 1) * sizeof(wletter));
    if (!result) return NULL;
    swprintf(result, len + 1, L"%lld", num);
    return result;
}

// Convert unsigned long to wide string
wstring fossil_wstr_from_ulong(unsigned long num) {
    size_t len = swprintf(NULL, 0, L"%lu", num);
    wstring result = malloc((len + 1) * sizeof(wletter));
    if (!result) return NULL;
    swprintf(result, len + 1, L"%lu", num);
    return result;
}

// Convert unsigned long long to wide string
wstring fossil_wstr_from_ullong(unsigned long long num) {
    size_t len = swprintf(NULL, 0, L"%llu", num);
    wstring result = malloc((len + 1) * sizeof(wletter));
    if (!result) return NULL;
    swprintf(result, len + 1, L"%llu", num);
    return result;
}

// Convert double to wide string
wstring fossil_wstr_from_double(double num) {
    size_t len = swprintf(NULL, 0, L"%.17g", num);
    wstring result = malloc((len + 1) * sizeof(wletter));
    if (!result) return NULL;
    swprintf(result, len + 1, L"%.17g", num);
    return result;
}

// Convert wide string to integer
int fossil_wstr_to_int(const_wstring str) {
    return wcstol(str, NULL, 10);
}

// Convert wide string to double
double fossil_wstr_to_double(const_wstring str) {
    return wcstod(str, NULL);
}

// Convert wide string to long
long fossil_wstr_to_long(const_wstring str) {
    return wcstol(str, NULL, 10);
}

// Convert wide string to unsigned long
unsigned long fossil_wstr_to_ulong(const_wstring str) {
    return wcstoul(str, NULL, 10);
}

// Convert wide string to long long
long long fossil_wstr_to_llong(const_wstring str) {
    return wcstoll(str, NULL, 10);
}

// Convert wide string to unsigned long long
unsigned long long fossil_wstr_to_ullong(const_wstring str) {
    return wcstoull(str, NULL, 10);
}

// Convert wide string to boolean
int fossil_wstr_to_bool(const_wstring str) {
    return wcscmp(str, L"true") == 0 || wcscmp(str, L"yes") == 0 || wcscmp(str, L"on") == 0 || wcstol(str, NULL, 10) != 0;
}
