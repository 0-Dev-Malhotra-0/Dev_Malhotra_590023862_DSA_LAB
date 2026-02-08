// 9.	Write a C program to show the difference in memory allocation between structure and union using sizeof().

#include <stdio.h>

union Employee
{
    int id;
    char name[50];
};

struct Student
{
    int id;
    char name[50];
};

int main()
{
	union Employee e;
    struct Student s;

    printf("Size of union Data = %zu bytes\n", sizeof(e));
	printf("Size of structure Student = %zu bytes", sizeof(s));
	 
    return 0;
}



