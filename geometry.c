#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <math.h>
//#define M_PI

void validation(char* str, int max_symb)
{
    char check_str[] = "circle";
    int i, j;
    char sx[10] = "", sy[10] = "", sr[10] = "";
    double x, y, r;
    printf("\n\n");

    for (i = 0; i < strlen(check_str); i++) {
        if (str[i] != check_str[i]) {
            printf("Mistake! Invalid input\n");
            printf("\"%s\" Not found \nDid you mean \"circle\"?\n", str);
            exit(0);
        }
    }

    while (str[i] == ' ')
        i++;

    if (str[i] != '(') {
        printf("Mistake! Invalid input\n");
        printf("Not found '('\n");
        exit(0);
    }
    i++;

    while (str[i] == ' ')
        i++;

    j = 0;
    while (str[i] != ' ') {
        sx[j] = str[i];
        i++;
        j++;
        if (j > 30) {
            printf("Mistake! Invalid input\n");
            printf("Not found parametr function\n");
            exit(0);
        }
    }
    sx[j] = '\0';

    while (str[i] == ' ')
        i++;

    j = 0;
    while ((str[i] != ',') && (str[i] != ' ')) {
        sy[j] = str[i];
        i++;
        j++;
        if (j > 30) {
            printf("Mistake! Invalid input\n");
            printf("Not found parametr function\n");
            exit(0);
        }
    }
    sy[j] = '\0';

    if (str[i] != ',') {
        printf("Mistake! Invalid input\n");
        printf("Not found ','\n");
        exit(0);
    }
    i++;

    while (str[i] == ' ')
        i++;

    j = 0;
    while ((str[i] != ')') && (str[i] != ' ')) {
        sr[j] = str[i];
        i++;
        j++;
        if (j > 30) {
            printf("Mistake! Invalid input\n");
            printf("Not found parametr function\n");
            exit(0);
        }
    }
    sr[j] = '\0';

    if (str[i] != ')') {
        printf("Mistake! Invalid input\n");
        printf("Not found ')'\n");
        exit(0);
    }
    if (i >= strlen(str)) {
        printf("Mistake! Invalid input\n");
        printf("Not found ')'\n");
        exit(0);
    }
    i++;

    while (str[i] == ' ')
        i++;
    if ((i + 1) < strlen(str)) {
        printf("Mistake! Invalid input\n");
        printf("Unexpected token\n");
        exit(0);
    }

    char* nstr;
    nstr = sx;
    x = strtod(nstr, &nstr);
    if (x == 0 || strlen(nstr) > 0) {
        printf("Mistake! Invalid input\n");
        printf("Parametr X\n");
        exit(0);
    }

    nstr = sy;
    y = strtod(nstr, &nstr);
    if (y == 0 || strlen(nstr) > 0) {
        printf("Mistake! Invalid input\n");
        printf("Parametr Y\n");
        exit(0);
    }

    nstr = sr;
    r = strtod(nstr, &nstr);
    if (r == 0 || strlen(nstr) > 0) {
        printf("Mistake! Invalid input\n");
        printf("Parametr R\n");
        exit(0);
    }

    // Для площади и периметра
    // double p = 2 * M_PI * r;
    // double s = M_PI * r * r;

    // printf("\nsx=%s\n", sx);
    // printf("\nsy=%s\n", sy);
    // printf("\nsr=%s\n", sr);
    // printf("\nperimetr=%f\n", p);
    // printf("\narea=%f\n", s);
}

int main()
{
    const int max_symb = 40;
    FILE* input;
    input = fopen("input.txt", "r");
    if (input == NULL)
        printf("Error open file\n");
    char source_str[max_symb];
    fgets(source_str, max_symb, input);
    fputs(source_str, stdout);
    validation(source_str, max_symb);

    return 0;
}