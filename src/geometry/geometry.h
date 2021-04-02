#ifndef GEOMETRY_H
#define GEOMETRY_H

// #include <stdio.h>

struct TCircle
{
        double x, y, r;
};

void Correct_Writing(const char *str,  struct TCircle *c, char *result);

void Calculate_area_and_perimeter( struct TCircle *c );


#endif // GEOMETRY_H
