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

// Function to compare two wide strings
int fossil_wstr_compare(const_wstring str1, const_wstring str2) {
    return wcscmp(str1, str2);
}

// Function to copy a wide string
wstring fossil_wstr_copy(wstring dest, const_wstring src) {
    return wcscpy(dest, src);
}

// Function to concatenate two wide strings
wstring fossil_wstr_concat(wstring dest, const_wstring src) {
    return wcscat(dest, src);
}

// Function to find a character in a wide string
const_wstring fossil_wstr_find(const_wstring str, wletter ch) {
    return wcschr(str, ch);
}

// Function to split a wide string by a delimiter
wstring fossil_wstr_split(wstring str, wchar_t delimiter) {
    wstring temp = _wcsdup(str);  // Use _wcsdup to avoid modifying the original string
    wstring token = wcstok(temp, &delimiter, NULL);
    return token;
}

// Function to duplicate a wide string
wstring fossil_wstr_strdup(const_wstring str) {
    size_t len = wcslen(str);
    wstring dup = (wstring)malloc((len + 1) * sizeof(wchar_t));
    if (dup) {
        wcscpy(dup, str);
    }
    return dup;
}

// Function to get a substring from a wide string
wstring fossil_wstr_substr(const_wstring str, size_t start, size_t len) {
    if (start >= wcslen(str)) return NULL;
    wstring substr = (wstring)malloc((len + 1) * sizeof(wchar_t));
    if (substr) {
        wcsncpy(substr, str + start, len);
        substr[len] = L'\0';
    }
    return substr;
}

// Functions to convert numbers to wide strings
wstring fossil_wstr_from_int(int num) {
    wchar_t buffer[20];
    swprintf(buffer, 20, L"%d", num);
    return fossil_wstr_strdup(buffer);
}

wstring fossil_wstr_from_long(long num) {
    wchar_t buffer[20];
    swprintf(buffer, 20, L"%ld", num);
    return fossil_wstr_strdup(buffer);
}

wstring fossil_wstr_from_llong(long long num) {
    wchar_t buffer[20];
    swprintf(buffer, 20, L"%lld", num);
    return fossil_wstr_strdup(buffer);
}

wstring fossil_wstr_from_ulong(unsigned long num) {
    wchar_t buffer[20];
    swprintf(buffer, 20, L"%lu", num);
    return fossil_wstr_strdup(buffer);
}

wstring fossil_wstr_from_ullong(unsigned long long num) {
    wchar_t buffer[20];
    swprintf(buffer, 20, L"%llu", num);
    return fossil_wstr_strdup(buffer);
}

wstring fossil_wstr_from_double(double num) {
    wchar_t buffer[20];
    swprintf(buffer, 20, L"%f", num);
    return fossil_wstr_strdup(buffer);
}

// Functions to convert wide strings to numbers
int fossil_wstr_to_int(const_wstring str) {
    return (int)wcstol(str, NULL, 10);
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
