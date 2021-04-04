#ifndef TESTS_H
#define TESTS_H

// #define CTEST_MAIN
#include "../src/geometry/geometry.h"
#include "ctest.h"

CTEST(suite, test1)
{
    ASSERT_EQUAL(1 + 2, 3);
}

CTEST(suite, test2)
{
    struct TCircle c;
    char result[1000];

    Correct_Writing("", &c, result);

    ASSERT_NOT_EQUAL(result[0], 0);
}

CTEST(suite, test3)
{
    struct TCircle c;
    char result[1000];

    Correct_Writing("oval(10 10, 5)", &c, result);

    ASSERT_NOT_EQUAL(result[0], 0);
}

CTEST(suite, test4)
{
    struct TCircle c;
    char result[1000];

    Correct_Writing("circle( 10 )", &c, result);

    ASSERT_NOT_EQUAL(result[0], 0);
}

CTEST(suite, test5)
{
    struct TCircle c;
    char result[1000];

    Correct_Writing("circle( 10,10,10 )", &c, result);

    ASSERT_NOT_EQUAL(result[0], 0);
}

CTEST(suite, test6)
{
    struct TCircle c;
    char result[1000];

    Correct_Writing("circle)", &c, result);

    ASSERT_NOT_EQUAL(result[0], 0);
}

#endif
