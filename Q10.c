// 10.	Write a C program using structure and dynamic memory allocation to sort student record based on marks.

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
    int n, i, j;
    printf("Enter number of students : ");
    scanf("%d", &n);
	printf("\n");
	
    struct Student *stu = malloc(n * sizeof(struct Student));
    if (!stu) 
	{
        printf("Memory allocation failed\n");
        return 1;
    }

    for (i = 0; i < n; i++) 
	{
        printf("Student %d roll no. : ", i+1);
        scanf("%d", &stu[i].roll);
        printf("Student %d name : ", i+1);
        scanf("%s", stu[i].name);
        printf("Student %d marks : ", i+1);
        scanf("%d", &stu[i].marks);
        printf("\n");
    }

    printf("\nStudent Details :\n\n");
    for (i = 0; i < n; i++) 
    {
    	printf("Roll no. : %d \nName : %s \nMarks : %d\n",stu[i].roll, stu[i].name, stu[i].marks);
		printf("\n");
	}
	
    for (i = 0; i < n-1; i++) 
	{
        for (j = 0; j < n-1-i; j++) 
		{
            if (stu[j].marks > stu[j+1].marks) 
			{
                struct Student temp = stu[j];
                stu[j] = stu[j+1];
                stu[j+1] = temp;
            }
        }
    }

    printf("\nStudents sorted by marks (ascending) :\n\n");
    
    for (i = 0; i < n; i++) 
        printf("Roll no. : %d \nName : %s \nMarks : %d\n\n",stu[i].roll, stu[i].name, stu[i].marks);

    free(stu);
    
    return 0;
}

