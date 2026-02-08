// 8.	Write a C program to demonstrate the use of union by storing integer, float, and character data and explain memory sharing.

#include <stdio.h>

union Data 
{
    int i;
    float f;
    char c;
};

int main() 
{
    union Data data;

    data.i = 100;
    printf("After setting int : i = %d, f = %.2f, c = %c\n", data.i, data.f, data.c);

    data.f = 3.14f;
    printf("After setting float: i = %d, f = %.2f, c = %c\n", data.i, data.f, data.c);

    data.c = 'Z';
    printf("After setting char: i = %d, f = %.2f, c = %c\n", data.i, data.f, data.c);

    return 0;
}



