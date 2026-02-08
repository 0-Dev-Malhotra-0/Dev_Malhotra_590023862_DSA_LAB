// 5.	Write a C program using structure and dynamic memory allocation to store and display student details such as roll number, name, and marks.

#include <stdio.h>
#include <stdlib.h>

struct Student
{
    int roll;
    char name[50];
    int marks;
};

int main() 
{
    int n, i;
    printf("Enter number of students : ");
    scanf("%d", &n);
	printf("\n");
	
    struct Student *stuArr = malloc(n * sizeof(struct Student));
    if (!stuArr) 
	{
        printf("Memory allocation failed\n");
        return 1;
    }

    for (i = 0; i < n; i++) 
	{
        printf("Student %d roll no. : ", i+1);
        scanf("%d", &stuArr[i].roll);
        printf("Student %d name : ", i+1);
        scanf("%s", stuArr[i].name);
        printf("Student %d marks : ", i+1);
        scanf("%d", &stuArr[i].marks);
        printf("\n");
    }

    printf("\nStudent Details :\n\n");
    for (i = 0; i < n; i++) 
    {
    	printf("Roll no. : %d \nName : %s \nMarks : %d\n",stuArr[i].roll, stuArr[i].name, stuArr[i].marks);
		printf("\n");
	}
	
    free(stuArr);
    
    return 0;
}

