#include <ctest.h>
#include <libgeometry/geometry.h>
#include <stdio.h>

CTEST(suite, test1)
{
    TCircle c;
    char result[1000];

    Correct_Writing("", &c, result);

    ASSERT_NOT_EQUAL(result[0], 0);
}

CTEST(suite, test2)
{
    TCircle c;
    char result[1000];

    Correct_Writing("oval(10 10, 5)", &c, result);

    ASSERT_NOT_EQUAL(result[0], 0);
}

CTEST(suite, test3)
{
    TCircle c;
    char result[1000];

    Correct_Writing("circle( 10 )", &c, result);

    ASSERT_NOT_EQUAL(result[0], 0);
}

CTEST(suite, test4)
{
    TCircle c;
    char result[1000];

    Correct_Writing("circle( 10,10,10 )", &c, result);

    ASSERT_NOT_EQUAL(result[0], 0);
}

CTEST(suite, test5)
{
    TCircle c;
    char result[1000];

    Correct_Writing("circle)", &c, result);

    ASSERT_NOT_EQUAL(result[0], 0);
}