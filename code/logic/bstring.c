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
#include "fossil/string/bstring.h"

int fossil_bstr_compare(const_bstring str1, const_bstring str2) {
    size_t len1 = 0;
    size_t len2 = 0;
    while (str1[len1] != '\0') len1++;
    while (str2[len2] != '\0') len2++;
    size_t min_len = (len1 < len2) ? len1 : len2;
    for (size_t i = 0; i < min_len; ++i) {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
    }
    return len1 - len2;
}

bstring fossil_bstr_copy(bstring dest, const_bstring src) {
    size_t len = 0;
    while (src[len] != '\0') len++;
    memcpy(dest, src, (len + 1) * sizeof(bletter));
    return dest;
}

bstring fossil_bstr_concat(bstring dest, const_bstring src) {
    size_t len_dest = 0;
    size_t len_src = 0;
    while (dest[len_dest] != '\0') len_dest++;
    while (src[len_src] != '\0') len_src++;
    memcpy(dest + len_dest, src, (len_src + 1) * sizeof(bletter));
    return dest;
}

const_bstring fossil_bstr_find(const_bstring str, bletter ch) {
    size_t len = 0;
    while (str[len] != '\0') {
        if (str[len] == ch) return str + len;
        len++;
    }
    return NULL; 
}

const_bstring fossil_bstr_reverse(const_bstring str) {
    size_t len = 0;
    while (str[len] != '\0') len++;
    bstring reversed = (bstring)malloc((len + 1) * sizeof(bletter));
    if (!reversed) return NULL; 
    for (size_t i = 0; i < len; ++i) {
        reversed[i] = str[len - 1 - i];
    }
    reversed[len] = '\0';
    return reversed;
}

bstrings fossil_bstr_split(const_bstring str, bletter delimiter) {
    size_t len = 0;
    bstrings splits = NULL;
    size_t count = 0;
    const_bstring start = str;
    const_bstring end = NULL; 

    while ((end = fossil_bstr_find(start, delimiter)) != NULL) {
        size_t part_len = end - start;
        bstring token = (bstring)malloc((part_len + 1) * sizeof(bletter));
        if (!token) return NULL; 
        memcpy(token, start, part_len * sizeof(bletter));
        token[part_len] = '\0';
        
        splits = (bstrings)realloc(splits, (count + 1) * sizeof(bstring));
        if (!splits) return NULL; 
        splits[count++] = token;
        start = end + 1;
    }
    
    size_t part_len = 0;
    while (start[part_len] != '\0') part_len++;
    bstring token = (bstring)malloc((part_len + 1) * sizeof(bletter));
    if (!token) return NULL; 
    memcpy(token, start, part_len * sizeof(bletter));
    token[part_len] = '\0';

    splits = (bstrings)realloc(splits, (count + 1) * sizeof(bstring));
    if (!splits) return NULL; 
    splits[count++] = token;
    
    splits = (bstrings)realloc(splits, (count + 1) * sizeof(bstring));
    if (!splits) return NULL; 
    splits[count] = NULL; 

    return splits;
}

bstring fossil_bstr_strdup(const_bstring str) {
    size_t len = 0;
    while (str[len] != '\0') len++;
    bstring dup = (bstring)malloc((len + 1) * sizeof(bletter));
    if (!dup) return NULL; 
    memcpy(dup, str, (len + 1) * sizeof(bletter));
    return dup;
}

bstring fossil_bstr_substr(const_bstring str, size_t start, size_t len) {
    bstring substr = (bstring)malloc((len + 1) * sizeof(bletter));
    if (!substr) return NULL; 
    memcpy(substr, str + start, len * sizeof(bletter));
    substr[len] = '\0';
    return substr;
}

void fossil_bstr_erase_splits(bstrings splits) {
    for (bstrings s = splits; *s != NULL;  ++s) {
        free(*s);
    }
    free(splits);
}

bstring fossil_bstr_from_int(int num) {
    char buffer[12];
    sprintf(buffer, "%d", num);
    size_t len = strlen(buffer);
    bstring result = (bstring)malloc((len + 1) * sizeof(bletter));
    if (!result) return NULL;
    strcpy((char *)result, buffer);
    return result;
}

bstring fossil_bstr_from_long(long num) {
    char buffer[22];
    sprintf(buffer, "%ld", num);
    size_t len = strlen(buffer);
    bstring result = (bstring)malloc((len + 1) * sizeof(bletter));
    if (!result) return NULL;
    strcpy((char *)result, buffer);
    return result;
}

bstring fossil_bstr_from_llong(long long num) {
    char buffer[22];
    sprintf(buffer, "%lld", num);
    size_t len = strlen(buffer);
    bstring result = (bstring)malloc((len + 1) * sizeof(bletter));
    if (!result) return NULL;
    strcpy((char *)result, buffer);
    return result;
}

bstring fossil_bstr_from_ulong(unsigned long num) {
    char buffer[22];
    sprintf(buffer, "%lu", num);
    size_t len = strlen(buffer);
    bstring result = (bstring)malloc((len + 1) * sizeof(bletter));
    if (!result) return NULL;
    strcpy((char *)result, buffer);
    return result;
}

bstring fossil_bstr_from_ullong(unsigned long long num) {
    char buffer[22];
    sprintf(buffer, "%llu", num);
    size_t len = strlen(buffer);
    bstring result = (bstring)malloc((len + 1) * sizeof(bletter));
    if (!result) return NULL;
    strcpy((char *)result, buffer);
    return result;
}

bstring fossil_bstr_from_double(double num) {
    char buffer[32];
    sprintf(buffer, "%f", num);
    size_t len = strlen(buffer);
    bstring result = (bstring)malloc((len + 1) * sizeof(bletter));
    if (!result) return NULL;
    strcpy((char *)result, buffer);
    return result;
}

bstring fossil_bstrstream_read(const_bstring str, size_t* pos, size_t len) {
    bstring read_str = (bstring)malloc((len + 1) * sizeof(bletter));
    if (!read_str) return NULL;
    memcpy(read_str, str + *pos, len * sizeof(bletter));
    read_str[len] = '\0';
    *pos += len;
    return read_str;
}

bstring fossil_bstrstream_read_line(const_bstring str, size_t* pos, size_t* end_pos) {
    const_bstring start = str + *pos;
    const_bstring end = fossil_bstr_find(start, '\n');
    if (!end) end = str + strlen((const char *)str);
    size_t len = end - start;
    bstring line = (bstring)malloc((len + 1) * sizeof(bletter));
    if (!line) return NULL;
    memcpy(line, start, len * sizeof(bletter));
    line[len] = '\0';
    *end_pos = (end - str);
    *pos = *end_pos + 1;
    return line;
}

void fossil_bstrstream_write(bstring dest, size_t* pos, const_bstring src) {
    size_t len = 0;
    while (src[len] != '\0') len++;
    memcpy(dest + *pos, src, len * sizeof(bletter));
    *pos += len;
}

void fossil_bstrstream_append(bstring dest, size_t* pos, const_bstring src) {
    size_t len = 0;
    while (src[len] != '\0') len++;
    memcpy(dest + *pos, src, len * sizeof(bletter));
    *pos += len;
}

void fossil_bstrstream_seek(size_t* pos, size_t offset) {
    *pos = offset;
}

size_t fossil_bstrstream_tell(const_bstring str, size_t pos) {
    return pos;
}

int fossil_bstr_to_int(const_bstring str) {
    return atoi((const char *)str);
}

double fossil_bstr_to_double(const_bstring str) {
    return atof((const char *)str);
}

long fossil_bstr_to_long(const_bstring str) {
    return atol((const char *)str);
}

unsigned long fossil_bstr_to_ulong(const_bstring str) {
    return strtoul((const char *)str, NULL, 10);
}

long long fossil_bstr_to_llong(const_bstring str) {
    return atoll((const char *)str);
}

unsigned long long fossil_bstr_to_ullong(const_bstring str) {
    return strtoull((const char *)str, NULL, 10);
}

int fossil_bstr_to_bool(const_bstring str) {
    return atoi((const char *)str) != 0;
}
