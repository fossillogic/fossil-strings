/*
 * -----------------------------------------------------------------------------
 * File: test_strings.cpp
 * Project: Fossil Logic
 * Description: This file contains the test cases for the string library.
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
// * Fossil Logic Test classic string
// * * * * * * * * * * * * * * * * * * * * * * * *

// Test case 1: Test fossil_wstring_create
FOSSIL_TEST(test_fossil_wstring_create) {
    wstring var = NULL;
    ASSUME_ITS_TRUE(NULL == fossil_wstr_create(var));
    fossil_wstr_erase(var); // Clean up after creating a wstring
}

// Test case 2: Test fossil_wstring_create with a string
FOSSIL_TEST(test_fossil_wstring_create_with_value) {
    wstring var = fossil_wstr_create(L"Pizza time!");
    ASSUME_ITS_EQUAL_WSTR(L"Pizza time!", var);
    fossil_wstr_erase(var); // Clean up after creating a wstring
}

// Test case 3: Test fossil_wstring_create with a string and length
FOSSIL_TEST(test_fossil_wstring_create_with_value_and_length) {
    wstring var = fossil_wstr_create(L"Pizza");
    ASSUME_ITS_EQUAL_WSTR(L"Pizza", var);
    ASSUME_ITS_EQUAL_SIZE(5, fossil_wstr_length(var));
    fossil_wstr_erase(var); // Clean up after creating a wstring
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_GROUP(c_wstrings_tests) {    
    // Classic Strings Fixture
    ADD_TEST(test_fossil_wstring_create);
    ADD_TEST(test_fossil_wstring_create_with_value);
    ADD_TEST(test_fossil_wstring_create_with_value_and_length);
} // end of tests
