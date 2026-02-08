// 2.	Write a C program to dynamically allocate memory for an array of N integers and perform insertion, display, sum, and average operations.

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
	
	long sum=0;
	double avg=0;
	
	for(i = 0; i < n; i++)
		sum += arr[i];
	
	avg = (double)sum / n;
	
	printf("\nSum = %d \nAverage = %.2f",sum,avg);
	
	free(arr);
	
	return 0;
}

