#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 150

int Skip_Space(const char* str, int i)
{
    while (str[i] == ' ')
        i++;
    return i;
}

int Convert_String(char* str, int par)
{
    char* nstr;
    nstr = str;
    double r = strtod(nstr, &nstr);
    if (r == 0 || strlen(nstr) > 0) {
        return -1;
    }

    return r;
}

void Correct_Writing(const char* str, int max_symb, char* otvet)
{
    char check_str[] = "circle";
    int i, j;
    char sx[10] = "", sy[10] = "", sr[10] = "";
    double x, y, r;
    printf("\n\n");

    if (strncmp(str, check_str, 6) != 0) {
        sprintf(otvet,
                "Mistake! Invalid input\n \"%s\" Not found \nDid you mean "
                "\"circle\"?\n",
                str);
        return;
    }
    i = 6;

    i = Skip_Space(str, i);

    if (str[i] != '(') {
        sprintf(otvet, "Mistake! Invalid input\nNot found '('\n");
        return;
    }
    i++;

    i = Skip_Space(str, i);

    j = 0;
    while (str[i] != ' ') {
        sx[j] = str[i];
        i++;
        j++;
        if (j > 30) {
            sprintf(otvet,
                    "Mistake! Invalid input\nNot found parametr function\n");
            return;
        }
    }
    sx[j] = '\0';

    i = Skip_Space(str, i);

    j = 0;
    while ((str[i] != ',') && (str[i] != ' ')) {
        sy[j] = str[i];
        i++;
        j++;
        if (j > 30) {
            sprintf(otvet,
                    "Mistake! Invalid input\nNot found parametr function\n");
            return;
        }
    }
    sy[j] = '\0';

    if (str[i] != ',') {
        sprintf(otvet, "Mistake! Invalid input\nNot found ','\n");
        return;
    }
    i++;

    i = Skip_Space(str, i);

    j = 0;
    while ((str[i] != ')') && (str[i] != ' ')) {
        sr[j] = str[i];
        i++;
        j++;
        if (j > 30) {
            sprintf(otvet,
                    "Mistake! Invalid input\nNot found parametr function\n");
            return;
        }
    }
    sr[j] = '\0';

    if (str[i] != ')') {
        sprintf(otvet, "Mistake! Invalid input\nNot found ')'\n");
        return;
    }

    if (i >= strlen(str)) {
        sprintf(otvet, "Mistake! Invalid input\nNot found ')'\n");
        return;
    }
    i++;

    i = Skip_Space(str, i);
    if ((i + 1) < strlen(str)) {
        sprintf(otvet, "Mistake! Invalid input\nUnexpected token\n");
        return;
    }

    x = Convert_String(sx, 1);
    y = Convert_String(sy, 2);
    r = Convert_String(sr, 3);

    if (x == -1) {
        sprintf(otvet, "Mistake! Invalid input\nParametr X\n");
        return;
    }
    if (y == -1) {
        sprintf(otvet, "Mistake! Invalid input\nParametr Y\n");
        return;
    }
    if (r == -1) {
        sprintf(otvet, "Mistake! Invalid input\nParametr R\n");
        return;
    }
}

int main()
{
    int max_symb = 40;
    FILE* input;
    char otvet[N];
    input = fopen("input.txt", "r");
    if (input == NULL) {
        printf("Error open file\n");
        return 1;
    }
    char source_str[max_symb];
    fgets(source_str, max_symb, input);

    fputs(source_str, stdout);
    Correct_Writing(source_str, max_symb, otvet);
    printf("%s\n", otvet);

    return 0;
}