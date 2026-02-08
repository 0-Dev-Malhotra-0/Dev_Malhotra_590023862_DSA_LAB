// 3.	Write a C program to dynamically allocate an array and find the largest and smallest element.

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
		
	int lrg = arr[0], sml = arr[0];
	for(i = 0; i < n; i++)
	{
		if(arr[i] > lrg)
			lrg = arr[i];
		if(arr[i] < sml)
			sml = arr[i];
	}
	
	printf("\nLargest Element : %d \nSmallest Element : %d",lrg,sml);
		
	free(arr);
	
	return 0;
}

