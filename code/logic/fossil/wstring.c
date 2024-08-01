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

const_wstring fossil_wstr_reverse(const_wstring str) {
    size_t len = wcslen(str);
    wletter* rev = malloc((len + 1) * sizeof(wletter));
    for (size_t i = 0; i < len; ++i) {
        rev[i] = str[len - i - 1];
    }
    rev[len] = L'\0';
    return rev;
}

wstrings fossil_wstr_split(const_wstring str, wletter delimiter) {
    wstrings splits = malloc(sizeof(wstring));
    size_t splits_size = 0;
    wstring start = str;
    wstring next = wcschr(start, delimiter);

    while (next != NULL) {
        size_t len = next - start;
        wstring substr = malloc((len + 1) * sizeof(wletter));
        wcsncpy(substr, start, len);
        substr[len] = L'\0';
        splits = realloc(splits, (splits_size + 1) * sizeof(wstring));
        splits[splits_size++] = substr;
        start = next + 1;
        next = wcschr(start, delimiter);
    }

    wstring substr = malloc((wcslen(start) + 1) * sizeof(wletter));
    wcscpy(substr, start);
    splits = realloc(splits, (splits_size + 1) * sizeof(wstring));
    splits[splits_size++] = substr;
    splits[splits_size] = NULL;

    return splits;
}

wstring fossil_wstr_strdup(const_wstring str) {
    size_t len = wcslen(str);
    wstring dup = malloc((len + 1) * sizeof(wletter));
    wcscpy(dup, str);
    return dup;
}

wstring fossil_wstr_substr(const_wstring str, size_t start, size_t len) {
    if (start >= wcslen(str)) {
        return NULL;
    }
    wstring substr = malloc((len + 1) * sizeof(wletter));
    wcsncpy(substr, str + start, len);
    substr[len] = L'\0';
    return substr;
}

void fossil_wstr_erase_splits(wstrings splits) {
    for (size_t i = 0; splits[i] != NULL; ++i) {
        free(splits[i]);
    }
    free(splits);
}

wstring fossil_wstr_from_int(int num) {
    size_t len = snprintf(NULL, 0, "%d", num);
    wstring result = malloc((len + 1) * sizeof(wletter));
    swprintf(result, len + 1, L"%d", num);
    return result;
}

wstring fossil_wstr_from_long(long num) {
    size_t len = snprintf(NULL, 0, "%ld", num);
    wstring result = malloc((len + 1) * sizeof(wletter));
    swprintf(result, len + 1, L"%ld", num);
    return result;
}

wstring fossil_wstr_from_llong(long long num) {
    size_t len = snprintf(NULL, 0, "%lld", num);
    wstring result = malloc((len + 1) * sizeof(wletter));
    swprintf(result, len + 1, L"%lld", num);
    return result;
}

wstring fossil_wstr_from_ulong(unsigned long num) {
    size_t len = snprintf(NULL, 0, "%lu", num);
    wstring result = malloc((len + 1) * sizeof(wletter));
    swprintf(result, len + 1, L"%lu", num);
    return result;
}

wstring fossil_wstr_from_ullong(unsigned long long num) {
    size_t len = snprintf(NULL, 0, "%llu", num);
    wstring result = malloc((len + 1) * sizeof(wletter));
    swprintf(result, len + 1, L"%llu", num);
    return result;
}

wstring fossil_wstr_from_double(double num) {
    size_t len = snprintf(NULL, 0, "%.17g", num);
    wstring result = malloc((len + 1) * sizeof(wletter));
    swprintf(result, len + 1, L"%.17g", num);
    return result;
}

wstring fossil_wstrstream_read(const_wstring str, size_t* pos, size_t len) {
    wstring substr = malloc((len + 1) * sizeof(wletter));
    wcsncpy(substr, str + *pos, len);
    substr[len] = L'\0';
    *pos += len;
    return substr;
}

wstring fossil_wstrstream_read_line(const_wstring str, size_t* pos, size_t* end_pos) {
    size_t start = *pos;
    while (str[*pos] != L'\n' && str[*pos] != L'\0') {
        (*pos)++;
    }
    size_t len = *pos - start;
    if (str[*pos] == L'\n') {
        (*pos)++;
    }
    *end_pos = *pos;
    return fossil_wstr_substr(str, start, len);
}

void fossil_wstrstream_write(wstring dest, size_t* pos, const_wstring src) {
    wcscpy(dest + *pos, src);
    *pos += wcslen(src);
}

void fossil_wstrstream_append(wstring dest, size_t* pos, const_wstring src) {
    wcscat(dest + *pos, src);
    *pos += wcslen(src);
}

void fossil_wstrstream_seek(size_t* pos, size_t offset) {
    *pos = offset;
}

size_t fossil_wstrstream_tell(const_wstring str, size_t pos) {
    return pos;
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
    return wcscmp(str, L"true") == 0 || wcscmp(str, L"yes") == 0 || wcscmp(str, L"on") == 0 || wcstol(str, NULL, 10) != 0;
}
