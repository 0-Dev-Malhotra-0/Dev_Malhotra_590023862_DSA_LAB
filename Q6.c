// 6.	Write a C program using array of structures with dynamic memory allocation to store employee details and find the employee with the highest salary.

#include <stdio.h>
#include <stdlib.h>

struct Employee
{
	int id;
	char name[50];
	double salary;
};

int main()
{
	int n, i, max = 0;
	printf("Enter number of employees : ");
	scanf("%d",&n);
	printf("\n");
	
	struct Employee *empArr = malloc(n * sizeof(struct Employee));
	
	if(!empArr)
	{
		printf("Memory allocation failed");
		return 1;
	}
	
	for (i = 0; i < n; i++) 
	{
        printf("Employee %d id : ", i+1);
        scanf("%d", &empArr[i].id);
        printf("Employee %d name : ", i+1);
        scanf("%s", empArr[i].name);
        printf("Employee %d salary : ", i+1);
        scanf("%lf", &empArr[i].salary);
        printf("\n");
    }
    
    for (i = 1; i < n; i++) 
	{
        if (empArr[i].salary > empArr[max].salary)
            max = i;
    }
    
    printf("\nEmployee with highest salary:\n");
    printf("ID : %d  \nName : %s \nSalary : %.0f",empArr[max].id, empArr[max].name, empArr[max].salary);

    free(empArr);
    
    return 0;

}

