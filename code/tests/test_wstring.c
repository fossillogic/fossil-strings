/*
 * -----------------------------------------------------------------------------
 * File: test_wstr_functions.cpp
 * Project: Fossil Logic
 * Description: This file contains the test cases for the wide string functions
 *              defined in the fossil_strings_wstr.h header.
 * 
 * This file is part of the Fossil Logic project, which aims to develop high-
 * performance, cross-platform applications and libraries. The code contained
 * herein is subject to the terms and conditions defined in the project license.
 * 
 * Author: Michael Gene Brockus (Dreamer)
 * Date: 07/01/2024
 * 
 * Copyright (C) 2024 Fossil Logic. All rights reserved.
 * -----------------------------------------------------------------------------
 */
#include <fossil/string/framework.h>

#include <fossil/unittest/framework.h>
#include <fossil/xassume.h>

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Utilities
// * * * * * * * * * * * * * * * * * * * * * * * *
// Setup steps for things like test fixtures and
// mock objects are set here.
// * * * * * * * * * * * * * * * * * * * * * * * *

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Wide String Functions Tests
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_FIXTURE(wstr_fixture);
FOSSIL_SETUP(wstr_fixture) {
    // Setup code if needed
}

FOSSIL_TEARDOWN(wstr_fixture) {
    // Teardown code if needed
}

// Test case 1: Compare two wide strings
FOSSIL_TEST(test_fossil_wstr_compare) {
    const_wstring str1 = L"Hello";
    const_wstring str2 = L"Hello";
    const_wstring str3 = L"World";
    
    ASSUME_ITS_EQUAL_I32(0, fossil_wstr_compare(str1, str2));
    ASSUME_ITS_TRUE(fossil_wstr_compare(str1, str3) < 0);
    ASSUME_ITS_TRUE(fossil_wstr_compare(str3, str1) > 0);
}

// Test case 2: Copy a wide string
FOSSIL_TEST(test_fossil_wstr_copy) {
    wstring dest = (wstring)malloc(20 * sizeof(wchar_t));
    const_wstring src = L"Hello, World!";
    
    ASSUME_ITS_EQUAL_WSTR(dest, fossil_wstr_copy(dest, src));
    ASSUME_ITS_TRUE(wcscmp(dest, src) == 0);
    free(dest); // Remember to free allocated memory
}

// Test case 3: Concatenate two wide strings
FOSSIL_TEST(test_fossil_wstr_concat) {
    wstring dest = (wstring)malloc(50 * sizeof(wchar_t));
    wcscpy(dest, L"Hello, ");
    const_wstring src = L"World!";
    
    ASSUME_ITS_EQUAL_WSTR(dest, fossil_wstr_concat(dest, src));
    ASSUME_ITS_TRUE(wcscmp(dest, L"Hello, World!") == 0);
    free(dest); // Remember to free allocated memory
}

// Test case 4: Find a wide character in a wide string
FOSSIL_TEST(test_fossil_wstr_find) {
    const_wstring str = L"Hello, World!";
    wletter ch = L'W';
    
    ASSUME_ITS_TRUE(fossil_wstr_find(str, ch) == wcschr(str, ch));
}

// Test case 5: Reverse a wide string
FOSSIL_TEST(test_fossil_wstr_reverse) {
    const_wstring str = L"Hello";
    const_wstring reversed = L"olleH";
    
    ASSUME_ITS_TRUE(wcscmp(fossil_wstr_reverse(str), reversed) == 0);
}

// Test case 6: Split a wide string
FOSSIL_TEST(test_fossil_wstr_split) {
    const_wstring str = L"Hello,World!";
    wletter delimiter = L',';
    wstrings result = fossil_wstr_split(str, delimiter);
    
    ASSUME_ITS_EQUAL_WSTR(result[0], L"Hello");
    ASSUME_ITS_EQUAL_WSTR(result[1], L"World!");
    
    // Free allocated memory
    fossil_wstr_erase_splits(result);
}

// Test case 7: Duplicate a wide string
FOSSIL_TEST(test_fossil_wstr_strdup) {
    const_wstring str = L"Hello, World!";
    
    ASSUME_ITS_EQUAL_WSTR(fossil_wstr_strdup(str), str);
}

// Test case 8: Extract a substring from a wide string
FOSSIL_TEST(test_fossil_wstr_substr) {
    const_wstring str = L"Hello, World!";
    const_wstring substr = L"World";
    
    ASSUME_ITS_EQUAL_WSTR(fossil_wstr_substr(str, 7, 5), substr);
}

// Test case 9: Convert integer to wide string
FOSSIL_TEST(test_fossil_wstr_from_int) {
    int num = 123;
    const_wstring expected = L"123";
    
    ASSUME_ITS_EQUAL_WSTR(fossil_wstr_from_int(num), expected);
}

// Test case 10: Convert wide string to integer
FOSSIL_TEST(test_fossil_wstr_to_int) {
    const_wstring str = L"123";
    
    ASSUME_ITS_EQUAL_I32(123, fossil_wstr_to_int(str));
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_GROUP(c_wstrings_tests) {    
    // Wide String Functions Fixture
    ADD_TESTF(test_fossil_wstr_compare, wstr_fixture);
    ADD_TESTF(test_fossil_wstr_copy, wstr_fixture);
    ADD_TESTF(test_fossil_wstr_concat, wstr_fixture);
    ADD_TESTF(test_fossil_wstr_find, wstr_fixture);
    ADD_TESTF(test_fossil_wstr_reverse, wstr_fixture);
    ADD_TESTF(test_fossil_wstr_split, wstr_fixture);
    ADD_TESTF(test_fossil_wstr_strdup, wstr_fixture);
    ADD_TESTF(test_fossil_wstr_substr, wstr_fixture);
    ADD_TESTF(test_fossil_wstr_from_int, wstr_fixture);
    ADD_TESTF(test_fossil_wstr_to_int, wstr_fixture);
} // end of tests
