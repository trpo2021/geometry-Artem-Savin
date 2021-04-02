#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <stdio.h>

typedef struct {
    double x, y, r;
    double p, s;

    void Calculate_area_and_perimeter()
    {
        const double pi = 3.141592;
        double p = 2 * pi * r;
        double s = pi * r * r;
        printf("perimetr=%f\narea=%f\n", p, s);
        return;
    }
} TCircle;

void Correct_Writing(const char* str, TCircle* circle, char* result);
#endif
