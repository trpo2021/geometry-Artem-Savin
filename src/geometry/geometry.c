#include <libgeometry/geometry.h>

int main()
{
    const int max_symb = 40;
    FILE* input;
    char result[150];
    input = fopen("input.txt", "r");
    if (input == NULL) {
        printf("Error open file\n");
        return 1;
    }
    char source_str[max_symb];
    fgets(source_str, max_symb, input);

    fputs(source_str, stdout);
    Correct_Writing(source_str, result);
    printf("%s\n", result);

    return 0;
}