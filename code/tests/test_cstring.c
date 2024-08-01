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

// Fixture setup
FOSSIL_FIXTURE(c_string_fixture);
FOSSIL_SETUP(c_string_fixture) {
    // Setup code if needed
}

FOSSIL_TEARDOWN(c_string_fixture) {
    // Teardown code if needed
}

// Test case: CString creation
FOSSIL_TEST(test_fossil_cstring_create) {
    char* var = fossil_cstr_create("Hello");
    ASSUME_ITS_TRUE(strcmp(var, "Hello") == 0);
    free(var);
}

// Test case: CString length
FOSSIL_TEST(test_fossil_cstring_length) {
    char* var = fossil_cstr_create("Hello");
    ASSUME_ITS_EQUAL_SIZE(5, strlen(var));
    free(var);
}

// Test case: CString creation empty
FOSSIL_TEST(test_fossil_cstring_create_empty) {
    char* var = fossil_cstr_create("");
    ASSUME_ITS_EQUAL_SIZE(0, strlen(var));
    free(var);
}

// Test case: CString concatenation
FOSSIL_TEST(test_fossil_cstring_concatenation) {
    char* var1 = fossil_cstr_create("Hello, ");
    char* var2 = fossil_cstr_create("World!");
    char* concatenated = fossil_cstr_concat(var1, var2);
    ASSUME_ITS_TRUE(strcmp(concatenated, "Hello, World!") == 0);
    free(var1);
    free(var2);
    free(concatenated);
}

// Test case: CString substring
FOSSIL_TEST(test_fossil_cstring_substring) {
    char* var = fossil_cstr_create("Hello, World!");
    char* substring = fossil_cstr_substr(var, 7, 6);
    ASSUME_ITS_TRUE(strcmp(substring, "World!") == 0);
    free(var);
    free(substring);
}

// Test case: CString substring length
FOSSIL_TEST(test_fossil_cstring_substr_length) {
    char* var = fossil_cstr_create("Hello, World!");
    char* substring = fossil_cstr_substr(var, 7, 5);
    ASSUME_ITS_TRUE(strcmp(substring, "World") == 0);
    ASSUME_ITS_EQUAL_SIZE(5, strlen(substring));
    free(var);
    free(substring);
}

// Test case: CString clear
FOSSIL_TEST(test_fossil_cstring_clear) {
    char* var = fossil_cstr_create("Hello, World!");
    var[0] = '\0'; // Simulate clear
    ASSUME_ITS_EQUAL_SIZE(0, strlen(var));
    free(var);
}

// Test case: CString assignment
FOSSIL_TEST(test_fossil_cstring_assignment) {
    char* var = fossil_cstr_create("Hello,");
    char* copy = fossil_cstr_copy(var, " World!");
    ASSUME_ITS_TRUE(strcmp(copy, "Hello, World!") == 0);
    free(var);
    free(copy);
}

// Test case: Default constructor
FOSSIL_TEST(test_cstrings_default_constructor) {
    char** strings = fossil_cstrs_create_empty();
    ASSUME_ITS_EQUAL_SIZE(0, fossil_cstrs_size(strings));
    ASSUME_ITS_TRUE(fossil_cstrs_empty(strings));
    free(strings);
}

// Test case: Constructor with vector of CString
FOSSIL_TEST(test_cstrings_constructor_vector_cstring) {
    char* strVec[] = { "Hello", "World", "!" };
    char** strings = fossil_cstrs_create_from_array(strVec, 3);
    ASSUME_ITS_EQUAL_SIZE(3, fossil_cstrs_size(strings));
    ASSUME_ITS_TRUE(strcmp(strings[0], "Hello") == 0);
    ASSUME_ITS_TRUE(strcmp(strings[1], "World") == 0);
    ASSUME_ITS_TRUE(strcmp(strings[2], "!") == 0);
    free(strings[0]);
    free(strings[1]);
    free(strings[2]);
    free(strings);
}

// Test case: Constructor with vector of const cletter*
FOSSIL_TEST(test_cstrings_constructor_vector_cletter) {
    const char* cstrVec[] = { "Good", "Morning" };
    char** strings = fossil_cstrs_create_from_const_array(cstrVec, 2);
    ASSUME_ITS_EQUAL_SIZE(2, fossil_cstrs_size(strings));
    ASSUME_ITS_TRUE(strcmp(strings[0], "Good") == 0);
    ASSUME_ITS_TRUE(strcmp(strings[1], "Morning") == 0);
    free(strings[0]);
    free(strings[1]);
    free(strings);
}

// Test case: Equality operator
FOSSIL_TEST(test_cstrings_equality_operator) {
    char* str1[] = { "Hello", "World" };
    char* str2[] = { "Hello", "World" };
    char* str3[] = { "Hello", "World", "!" };

    ASSUME_ITS_TRUE(fossil_cstrs_equal(str1, str2, 2));
    ASSUME_ITS_TRUE(!fossil_cstrs_equal(str1, str3, 3));
    free(str1[0]);
    free(str1[1]);
    free(str2[0]);
    free(str2[1]);
    free(str3[0]);
    free(str3[1]);
    free(str3[2]);
    free(str1);
    free(str2);
    free(str3);
}

// Test case: Concatenation operator
FOSSIL_TEST(test_cstrings_concatenation_operator) {
    char* str1[] = { "Hello", "World" };
    char* str2[] = { "!" };
    char** result = fossil_cstrs_concat(str1, 2, str2, 1);
    ASSUME_ITS_EQUAL_SIZE(3, fossil_cstrs_size(result));
    ASSUME_ITS_TRUE(strcmp(result[0], "Hello") == 0);
    ASSUME_ITS_TRUE(strcmp(result[1], "World") == 0);
    ASSUME_ITS_TRUE(strcmp(result[2], "!") == 0);
    free(result[0]);
    free(result[1]);
    free(result[2]);
    free(result);
}

// Test case: Indexing operator
FOSSIL_TEST(test_cstrings_indexing_operator) {
    char* strings[] = { "Apple", "Banana", "Cherry" };
    ASSUME_ITS_TRUE(strcmp(strings[0], "Apple") == 0);
    ASSUME_ITS_TRUE(strcmp(strings[1], "Banana") == 0);
    ASSUME_ITS_TRUE(strcmp(strings[2], "Cherry") == 0);
    free(strings[0]);
    free(strings[1]);
    free(strings[2]);
}

// Test case: Const indexing operator
FOSSIL_TEST(test_cstrings_const_indexing_operator) {
    const char* strings[] = { "One", "Two", "Three" };
    ASSUME_ITS_TRUE(strcmp(strings[0], "One") == 0);
    ASSUME_ITS_TRUE(strcmp(strings[1], "Two") == 0);
    ASSUME_ITS_TRUE(strcmp(strings[2], "Three") == 0);
}

// Test case: Clear method
FOSSIL_TEST(test_cstrings_clear_method) {
    char* strings[] = { "Clear", "Me" };
    fossil_cstrs_clear(strings, 2);
    ASSUME_ITS_EQUAL_SIZE(0, fossil_cstrs_size(strings));
    ASSUME_ITS_TRUE(fossil_cstrs_empty(strings));
    free(strings);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_GROUP(c_cstrings_tests) {    
    // Classic Strings Fixture
    ADD_TESTF(test_fossil_cstring_create, c_string_fixture);
    ADD_TESTF(test_fossil_cstring_length, c_string_fixture);
    ADD_TESTF(test_fossil_cstring_create_empty, c_string_fixture);
    ADD_TESTF(test_fossil_cstring_concatenation, c_string_fixture);
    ADD_TESTF(test_fossil_cstring_substring, c_string_fixture);
    ADD_TESTF(test_fossil_cstring_substr_length, c_string_fixture);
    ADD_TESTF(test_fossil_cstring_clear, c_string_fixture);
    ADD_TESTF(test_fossil_cstring_assignment, c_string_fixture);
    ADD_TESTF(test_cstrings_default_constructor, c_string_fixture);
    ADD_TESTF(test_cstrings_constructor_vector_cstring, c_string_fixture);
    ADD_TESTF(test_cstrings_constructor_vector_cletter, c_string_fixture);
    ADD_TESTF(test_cstrings_equality_operator, c_string_fixture);
    ADD_TESTF(test_cstrings_concatenation_operator, c_string_fixture);
    ADD_TESTF(test_cstrings_indexing_operator, c_string_fixture);
    ADD_TESTF(test_cstrings_const_indexing_operator, c_string_fixture);
    ADD_TESTF(test_cstrings_clear_method, c_string_fixture);
} // end of tests
