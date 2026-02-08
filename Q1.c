// 1.	Write a C program to dynamically allocate memory for an array, display elements, and properly free allocated memory before program termination.

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n, i;
	
	printf("Enter number of elements : ");
	scanf("%d",&n);
	
	if(n <= 0)
    {
        printf("Invalid size");
        return 1;
    }
    
	int *arr = malloc(n * sizeof(int));
	if(!arr)
	{
		printf("Memory allocation failed");
		return 1;
	}
	
	printf("Enter %d elements : ",n);
	for(i = 0; i < n; i++)
		scanf("%d",&arr[i]);
		
	printf("Elements are : ");
	for(i = 0; i < n; i++)
		printf("%d ",arr[i]);
		
	free(arr);
	
	return 0;
}


