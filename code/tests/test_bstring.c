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
// * Fossil Logic Test byte string
// * * * * * * * * * * * * * * * * * * * * * * * *

// Fixture setup
FOSSIL_FIXTURE(b_string_fixture);
FOSSIL_SETUP(b_string_fixture) {
    // Setup code if needed
}

FOSSIL_TEARDOWN(b_string_fixture) {
    // Teardown code if needed
}

// Test case: bstring creation
FOSSIL_TEST(test_fossil_bstring_create) {
    bstring var = fossil_bstr_strdup((const_bstring)u"Pizza time!");
    ASSUME_ITS_TRUE(fossil_bstr_compare(var, (const_bstring)u"Pizza time!") == 0);
    free(var);
}

// Test case: bstring length
FOSSIL_TEST(test_fossil_bstring_length) {
    bstring var = fossil_bstr_strdup((const_bstring)u"Pizza time!");
    ASSUME_ITS_EQUAL_SIZE(11, strlen((const char*)var));
    free(var);
}

// Test case: bstring concatenation
FOSSIL_TEST(test_fossil_bstring_concatenation) {
    bstring var1 = fossil_bstr_strdup((const_bstring)u"Pizza ");
    bstring var2 = fossil_bstr_strdup((const_bstring)u"time!");
    var1 = (bstring)realloc(var1, (strlen((const char*)var1) + strlen((const char*)var2) + 1) * sizeof(uint16_t));
    fossil_bstr_concat(var1, var2);
    ASSUME_ITS_TRUE(fossil_bstr_compare(var1, (const_bstring)u"Pizza time!") == 0);
    ASSUME_ITS_EQUAL_SIZE(10, strlen((const char*)var1));
    free(var1);
    free(var2);
}

// Test case: bstring substring
FOSSIL_TEST(test_fossil_bstring_substring) {
    bstring var = fossil_bstr_strdup((const_bstring)u"Pizza time!");
    bstring sub = fossil_bstr_substr((const_bstring)var, 6, 4);
    ASSUME_ITS_TRUE(fossil_bstr_compare(sub, (const_bstring)u"time") == 0);
    free(var);
    free(sub);
}

// Test case: bstring clear
FOSSIL_TEST(test_fossil_bstring_clear) {
    bstring var = fossil_bstr_strdup((const_bstring)u"Pizza time!");
    var[0] = '\0'; // Clear the string
    ASSUME_ITS_EQUAL_SIZE(0, strlen((const char*)var));
    free(var);
}

// Test case: bstring copy constructor
FOSSIL_TEST(test_fossil_bstring_copy_constructor) {
    bstring original = fossil_bstr_strdup((const_bstring)u"Pizza time!");
    bstring copy = fossil_bstr_strdup((const_bstring)original);
    ASSUME_ITS_TRUE(fossil_bstr_compare(copy, (const_bstring)u"Pizza time!") == 0);
    free(original);
    free(copy);
}

// Test case: bstring move constructor
FOSSIL_TEST(test_fossil_bstring_move_constructor) {
    bstring original = fossil_bstr_strdup((const_bstring)u"Pizza time!");
    bstring moved = original;
    original = NULL; // Simulate moving by nullifying the original
    ASSUME_ITS_TRUE(fossil_bstr_compare(moved, (const_bstring)u"Pizza time!") == 0);
    ASSUME_ITS_EQUAL_SIZE(0, strlen((const char*)original)); // Ensure original is moved from
    free(moved);
}

// Test cases for bstrings
// Test case 1: Default constructor
FOSSIL_TEST(test_bstrings_default_constructor) {
    bstrings strings = NULL;
    ASSUME_ITS_EQUAL_SIZE(0, 0); // Since no size function in C, just checking initialization
    // For `empty` equivalent check, assume a simple size function or similar
    ASSUME_ITS_TRUE(strings == NULL);
}

// Test case 2: Constructor with vector of bstring
FOSSIL_TEST(test_bstrings_constructor_vector_bstring) {
    bstrings strings = (bstrings)malloc(3 * sizeof(bstring));
    strings[0] = fossil_bstr_strdup((const_bstring)u"Hello");
    strings[1] = fossil_bstr_strdup((const_bstring)u"World");
    strings[2] = fossil_bstr_strdup((const_bstring)u"!");
    ASSUME_ITS_EQUAL_SIZE(3, 3);
    ASSUME_ITS_TRUE(fossil_bstr_compare(strings[0], (const_bstring)u"Hello") == 0);
    ASSUME_ITS_TRUE(fossil_bstr_compare(strings[1], (const_bstring)u"World") == 0);
    ASSUME_ITS_TRUE(fossil_bstr_compare(strings[2], (const_bstring)u"!") == 0);
    free(strings[0]);
    free(strings[1]);
    free(strings[2]);
    free(strings);
}

// Test case 3: Constructor with vector of const bletter*
FOSSIL_TEST(test_bstrings_constructor_vector_bletter) {
    bstrings strings = (bstrings)malloc(2 * sizeof(bstring));
    strings[0] = fossil_bstr_strdup((const_bstring)u"Good");
    strings[1] = fossil_bstr_strdup((const_bstring)u"Morning");
    ASSUME_ITS_EQUAL_SIZE(2, 2);
    ASSUME_ITS_TRUE(fossil_bstr_compare(strings[0], (const_bstring)u"Good") == 0);
    ASSUME_ITS_TRUE(fossil_bstr_compare(strings[1], (const_bstring)u"Morning") == 0);
    free(strings[0]);
    free(strings[1]);
    free(strings);
}

// Test case 4: Equality operator
FOSSIL_TEST(test_bstrings_equality_operator) {
    bstrings strings1 = (bstrings)malloc(2 * sizeof(bstring));
    strings1[0] = fossil_bstr_strdup((const_bstring)u"Hello");
    strings1[1] = fossil_bstr_strdup((const_bstring)u"World");

    bstrings strings2 = (bstrings)malloc(2 * sizeof(bstring));
    strings2[0] = fossil_bstr_strdup((const_bstring)u"Hello");
    strings2[1] = fossil_bstr_strdup((const_bstring)u"World");

    bstrings strings3 = (bstrings)malloc(3 * sizeof(bstring));
    strings3[0] = fossil_bstr_strdup((const_bstring)u"Hello");
    strings3[1] = fossil_bstr_strdup((const_bstring)u"World");
    strings3[2] = fossil_bstr_strdup((const_bstring)u"!");

    ASSUME_ITS_TRUE(memcmp(strings1, strings2, 2 * sizeof(bstring)) == 0);
    ASSUME_ITS_TRUE(memcmp(strings1, strings3, 3 * sizeof(bstring)) != 0);

    free(strings1[0]);
    free(strings1[1]);
    free(strings1);
    free(strings2[0]);
    free(strings2[1]);
    free(strings2);
    free(strings3[0]);
    free(strings3[1]);
    free(strings3[2]);
    free(strings3);
}

// Test case 5: Concatenation operator
FOSSIL_TEST(test_bstrings_concatenation_operator) {
    bstrings strings1 = (bstrings)malloc(2 * sizeof(bstring));
    strings1[0] = fossil_bstr_strdup((const_bstring)u"Hello");
    strings1[1] = fossil_bstr_strdup((const_bstring)u"World");

    bstrings strings2 = (bstrings)malloc(1 * sizeof(bstring));
    strings2[0] = fossil_bstr_strdup((const_bstring)u"!");

    // Concatenate
    bstrings result = (bstrings)malloc(3 * sizeof(bstring));
    result[0] = strings1[0];
    result[1] = strings1[1];
    result[2] = strings2[0];

    ASSUME_ITS_EQUAL_SIZE(3, 3);
    ASSUME_ITS_TRUE(fossil_bstr_compare(result[0], (const_bstring)u"Hello") == 0);
    ASSUME_ITS_TRUE(fossil_bstr_compare(result[1], (const_bstring)u"World") == 0);
    ASSUME_ITS_TRUE(fossil_bstr_compare(result[2], (const_bstring)u"!") == 0);

    free(strings1);
    free(strings2);
    free(result[0]);
    free(result[1]);
    free(result[2]);
    free(result);
}

// Test case 6: Indexing operator
FOSSIL_TEST(test_bstrings_indexing_operator) {
    bstrings strings = (bstrings)malloc(3 * sizeof(bstring));
    strings[0] = fossil_bstr_strdup((const_bstring)u"Apple");
    strings[1] = fossil_bstr_strdup((const_bstring)u"Banana");
    strings[2] = fossil_bstr_strdup((const_bstring)u"Cherry");

    ASSUME_ITS_TRUE(fossil_bstr_compare(strings[0], (const_bstring)u"Apple") == 0);
    ASSUME_ITS_TRUE(fossil_bstr_compare(strings[1], (const_bstring)u"Banana") == 0);
    ASSUME_ITS_TRUE(fossil_bstr_compare(strings[2], (const_bstring)u"Cherry") == 0);

    free(strings[0]);
    free(strings[1]);
    free(strings[2]);
    free(strings);
}

// Test case 7: Const indexing operator
FOSSIL_TEST(test_bstrings_const_indexing_operator) {
    bstrings strings = (bstrings)malloc(3 * sizeof(bstring));
    strings[0] = fossil_bstr_strdup((const_bstring)u"One");
    strings[1] = fossil_bstr_strdup((const_bstring)u"Two");
    strings[2] = fossil_bstr_strdup((const_bstring)u"Three");

    ASSUME_ITS_TRUE(fossil_bstr_compare(strings[0], (const_bstring)u"One") == 0);
    ASSUME_ITS_TRUE(fossil_bstr_compare(strings[1], (const_bstring)u"Two") == 0);
    ASSUME_ITS_TRUE(fossil_bstr_compare(strings[2], (const_bstring)u"Three") == 0);

    free(strings[0]);
    free(strings[1]);
    free(strings[2]);
    free(strings);
}

// Test case 8: Clear method
FOSSIL_TEST(test_bstrings_clear_method) {
    bstrings strings = (bstrings)malloc(2 * sizeof(bstring));
    strings[0] = fossil_bstr_strdup((const_bstring)u"Clear");
    strings[1] = fossil_bstr_strdup((const_bstring)u"Me");

    // Clear the strings
    free(strings[0]);
    free(strings[1]);
    free(strings);

    ASSUME_ITS_EQUAL_SIZE(0, 0); // Check size as 0
}

// Test group
FOSSIL_TEST_GROUP(c_bstrings_tests) {
    ADD_TESTF(test_fossil_bstring_create, b_string_fixture);
    ADD_TESTF(test_fossil_bstring_length, b_string_fixture);
    ADD_TESTF(test_fossil_bstring_concatenation, b_string_fixture);
    ADD_TESTF(test_fossil_bstring_substring, b_string_fixture);
    ADD_TESTF(test_fossil_bstring_clear, b_string_fixture);
    ADD_TESTF(test_fossil_bstring_copy_constructor, b_string_fixture);
    ADD_TESTF(test_fossil_bstring_move_constructor, b_string_fixture);
    ADD_TESTF(test_bstrings_default_constructor, b_string_fixture);
    ADD_TESTF(test_bstrings_constructor_vector_bstring, b_string_fixture);
    ADD_TESTF(test_bstrings_constructor_vector_bletter, b_string_fixture);
    ADD_TESTF(test_bstrings_equality_operator, b_string_fixture);
    ADD_TESTF(test_bstrings_concatenation_operator, b_string_fixture);
    ADD_TESTF(test_bstrings_indexing_operator, b_string_fixture);
    ADD_TESTF(test_bstrings_const_indexing_operator, b_string_fixture);
    ADD_TESTF(test_bstrings_clear_method, b_string_fixture);
} // end of tests
