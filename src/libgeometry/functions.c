#include "geometry.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>

int Skip_Space(const char* str, int i)
{
    while (str[i] == ' ')
        i++;
    return i;
}

int Convert_String(char* str)
{
    char* nstr;
    nstr = str;
    double r = strtod(nstr, &nstr);
    if (r == 0 || strlen(nstr) > 0) {
        return -1;
    }
    return r;
}

int Get_Parametr(const char* str, int i, char* sx)
{
    int j = 0;
    char s[10] = "";
    while ((str[i] != ' ') && (str[i] != ',') && (str[i] != ')')) {
        s[j] = str[i];
        i++;
        j++;
        if (j > 30) {
            return -1;
        }
    }
    s[j] = '\0';
    strcpy(sx, s);
    return i;
}

void Correct_Writing(const char* str, char* result)
{
    char check_str[] = "circle";
    size_t i;
    size_t j = -1;
    char sx[10] = "", sy[10] = "", sr[10] = "";
    double x, y, r;
    printf("\n\n");

    if (strncmp(str, check_str, strlen(check_str)) != 0) {
        sprintf(result,
                "Mistake! Invalid input\n \"%s\" Not found \nDid you mean "
                "\"circle\"?\n",
                str);
        return;
    }
    i = 6;

    i = Skip_Space(str, i);
    if (str[i] != '(') {
        sprintf(result, "Mistake! Invalid input\nNot found '('\n");
        return;
    }
    i++;

    i = Skip_Space(str, i);
    i = Get_Parametr(str, i, sx);
    if (i == j) {
        sprintf(result,
                "Mistake! Invalid input\nNot found parametr X function\n");
        return;
    }

    i = Skip_Space(str, i);
    i = Get_Parametr(str, i, sy);
    if (i == j) {
        sprintf(result,
                "Mistake! Invalid input\nNot found parametr Y function\n");
        return;
    }

    if (str[i] != ',') {
        sprintf(result, "Mistake! Invalid input\nNot found ','\n");
        return;
    }
    i++;

    i = Skip_Space(str, i);
    i = Get_Parametr(str, i, sr);
    if (i == j) {
        sprintf(result,
                "Mistake! Invalid input\nNot found parametr R function\n");
        return;
    }

    if (str[i] != ')') {
        sprintf(result, "Mistake! Invalid input\nNot found ')'\n");
        return;
    }

    if (i >= strlen(str)) {
        sprintf(result, "Mistake! Invalid input\nNot found ')'\n");
        return;
    }
    i++;

    i = Skip_Space(str, i);
    if ((i + 1) < strlen(str)) {
        sprintf(result, "Mistake! Invalid input\nUnexpected token\n");
        return;
    }

    x = Convert_String(sx);
    y = Convert_String(sy);
    r = Convert_String(sr);

    if (x == j) {
        sprintf(result, "Mistake! Invalid input\nParametr X\n");
        return;
    }
    if (y == j) {
        sprintf(result, "Mistake! Invalid input\nParametr Y\n");
        return;
    }
    if (r == -1) {
        sprintf(result, "Mistake! Invalid input\nParametr R\n");
        return;
    }

    double p = 2 * M_PI * r;
    double s = M_PI * r * r;
    sprintf(result, "\nperimetr=%f\narea=%f\n", p, s);
}
