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
#include "fossil/string/cstring.h"

int fossil_cstr_compare(const char* str1, const char* str2) {
    return strcmp(str1, str2);
}

char* fossil_cstr_copy(char* dest, const char* src) {
    return strcpy(dest, src);
}

char* fossil_cstr_concat(char* dest, const char* src) {
    return strcat(dest, src);
}

const char* fossil_cstr_find(const char* str, char ch) {
    return strchr(str, ch);
}

const char* fossil_cstr_reverse(const char* str) {
    size_t len = strlen(str);
    char* reversed = (char*)malloc(len + 1);
    for (size_t i = 0; i < len; ++i) {
        reversed[i] = str[len - i - 1];
    }
    reversed[len] = '\0';
    return reversed;
}

char** fossil_cstr_split(const char* str, char delimiter) {
    char** splits = NULL;
    size_t num_splits = 0;
    const char* start = str;
    const char* end = str;
    while (*end != '\0') {
        if (*end == delimiter) {
            size_t len = end - start;
            char* split = (char*)malloc(len + 1);
            strncpy(split, start, len);
            split[len] = '\0';
            splits = (char**)realloc(splits, (num_splits + 1) * sizeof(char*));
            splits[num_splits] = split;
            ++num_splits;
            start = end + 1;
        }
        ++end;
    }
    size_t len = end - start;
    char* split = (char*)malloc(len + 1);
    strncpy(split, start, len);
    split[len] = '\0';
    splits = (char**)realloc(splits, (num_splits + 1) * sizeof(char*));
    splits[num_splits] = split;
    ++num_splits;
    splits = (char**)realloc(splits, (num_splits + 1) * sizeof(char*));
    splits[num_splits] = NULL; // Null-terminate the array
    return splits;
}

char* fossil_cstr_strdup(const char* str) {
    size_t len = strlen(str);
    char* dup = (char*)malloc(len + 1);
    strcpy(dup, str);
    return dup;
}

char* fossil_cstr_substr(const char* str, size_t start, size_t len) {
    size_t str_len = strlen(str);
    if (start >= str_len) {
        return NULL;
    }
    char* substr = (char*)malloc(len + 1);
    strncpy(substr, str + start, len);
    substr[len] = '\0';
    return substr;
}

void fossil_cstr_erase_splits(char** splits) {
    if (splits == NULL) {
        return;
    }
    for (size_t i = 0; splits[i] != NULL; ++i) {
        free(splits[i]);
    }
    free(splits);
}

char* fossil_cstr_from_int(int num) {
    char temp[32]; // Assuming a reasonable size
    snprintf(temp, sizeof(temp), "%d", num);
    return fossil_cstr_strdup(temp);
}

char* fossil_cstr_from_long(long num) {
    char temp[32]; // Assuming a reasonable size
    snprintf(temp, sizeof(temp), "%ld", num);
    return fossil_cstr_strdup(temp);
}

char* fossil_cstr_from_llong(long long num) {
    char temp[32]; // Assuming a reasonable size
    snprintf(temp, sizeof(temp), "%lld", num);
    return fossil_cstr_strdup(temp);
}

char* fossil_cstr_from_ulong(unsigned long num) {
    char temp[32]; // Assuming a reasonable size
    snprintf(temp, sizeof(temp), "%lu", num);
    return fossil_cstr_strdup(temp);
}

char* fossil_cstr_from_ullong(unsigned long long num) {
    char temp[32]; // Assuming a reasonable size
    snprintf(temp, sizeof(temp), "%llu", num);
    return fossil_cstr_strdup(temp);
}

char* fossil_cstr_from_double(double num) {
    char temp[64]; // Assuming a reasonable size
    snprintf(temp, sizeof(temp), "%f", num);
    return fossil_cstr_strdup(temp);
}

char* fossil_cstrstream_read(const char* str, size_t *pos, size_t len) {
    size_t str_len = strlen(str);
    if (*pos >= str_len) {
        return NULL;
    }
    char* read_str = (char*)malloc(len + 1);
    strncpy(read_str, str + *pos, len);
    read_str[len] = '\0';
    *pos += len;
    return read_str;
}

char* fossil_cstrstream_read_line(const char* str, size_t *pos, size_t *end_pos) {
    size_t str_len = strlen(str);
    if (*pos >= str_len) {
        return NULL;
    }
    const char* start = str + *pos;
    const char* newline = strpbrk(start, "\n\r");
    if (newline != NULL) {
        *end_pos = newline - str;
    } else {
        *end_pos = str_len;
    }
    size_t len = *end_pos - *pos;
    char* line = (char*)malloc(len + 1);
    strncpy(line, start, len);
    line[len] = '\0';
    *pos = *end_pos + 1;
    return line;
}

void fossil_cstrstream_write(char* dest, size_t *pos, const char* src) {
    size_t dest_len = strlen(dest);
    size_t src_len = strlen(src);
    if (*pos > dest_len) {
        return;
    }
    char* temp = (char*)malloc(dest_len + src_len + 1);
    strcpy(temp, dest);
    strncpy(temp + *pos, src, src_len);
    strcpy(temp + *pos + src_len, dest + *pos);
    free(dest);
    dest = temp;
    *pos += src_len;
}

void fossil_cstrstream_append(char* dest, size_t *pos, const char* src) {
    size_t dest_len = strlen(dest);
    size_t src_len = strlen(src);
    if (*pos > dest_len) {
        return;
    }
    char* temp = (char*)malloc(dest_len + src_len + 1);
    strcpy(temp, dest);
    strcpy(temp + dest_len, src);
    free(dest);
    dest = temp;
    *pos += src_len;
}

void fossil_cstrstream_seek(size_t *pos, size_t offset) {
    *pos += offset;
}

size_t fossil_cstrstream_tell(const char* str, size_t pos) {
    return pos;
}

int fossil_cstr_to_int(const char* str) {
    return atoi(str);
}

double fossil_cstr_to_double(const char* str) {
    return atof(str);
}

long fossil_cstr_to_long(const char* str) {
    return atol(str);
}

unsigned long fossil_cstr_to_ulong(const char* str) {
    return strtoul(str, NULL, 10);
}

long long fossil_cstr_to_llong(const char* str) {
    return atoll(str);
}

unsigned long long fossil_cstr_to_ullong(const char* str) {
    return strtoull(str, NULL, 10);
}

int fossil_cstr_to_bool(const char* str) {
    if (strcmp(str, "true") == 0 || strcmp(str, "yes") == 0 || strcmp(str, "on") == 0 || atoi(str) != 0) {
        return 1;
    } else {
        return 0;
    }
}
