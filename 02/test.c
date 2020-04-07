#include <stdio.h>

#define MAX_OF_TWO_INT(a, b) ((a) > (b) ? (a) : (b))

int GetMaxInTwoInt(int a, int b)
{
    return ((a) > (b) ? (a) : (b));
}

int main(int argc, char *argv[])
{
    int a = 1;
    int b = -1;
    printf("Macro MAX result is %d\r\n", MAX_OF_TWO_INT(++a, b));

    a = 1;
    b = -1;
    printf("Function MAX result is %d\r\n", GetMaxInTwoInt(++a, b));

    getchar();
}
