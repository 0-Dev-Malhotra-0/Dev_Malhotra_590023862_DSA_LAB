// 4.	Write a C program to dynamically allocate memory for a 2D matrix and perform matrix addition and subtraction.

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int r, c, i, j;
	
	printf("Enter number of rows and columns : ");
	scanf("%d%d",&r,&c);
	
	if(r <= 0 || c <= 0)
    {
        printf("Invalid size");
        return 1;
    }
    
	int **arr1 = malloc(r * sizeof(int));
	int **arr2 = malloc(r * sizeof(int));
	int **sum = malloc(r * sizeof(int));
	int **diff = malloc(r * sizeof(int));
	
	if(!arr1 || !arr2 || !sum || !diff)
	{
		printf("Memory allocation failed");
		return 1;
	}
	
	for (i = 0; i < r; i++) 
	{
        arr1[i] = malloc(c * sizeof(int));
        arr2[i] = malloc(c * sizeof(int));
        sum[i] = malloc(c * sizeof(int));
        diff[i] = malloc(c * sizeof(int));
        if (!arr1[i] || !arr2[i] || !sum[i] || !diff[i]) 
		{
            printf("Memory allocation failed");
            return 1;
        }
    }
	
	printf("\nEnter elements of Matrix 1 : \n");
	for(i = 0; i < r; i++)
		for(j = 0; j < c; j++)
		{
			printf("Enter [%d][%d] element : ",i,j);
			scanf("%d",&arr1[i][j]);
		}
		
	printf("\nEnter elements of Matrix 2 : \n");
	for(i = 0; i < r; i++)
		for(j = 0; j < c; j++)
		{
			printf("Enter [%d][%d] element : ",i,j);
			scanf("%d",&arr2[i][j]);
		}
			
	printf("\nElements of Matrix 1 : \n");
	for(i = 0; i < r; i++)
	{
		for(j = 0; j < c; j++)
			printf("%d\t",arr1[i][j]);
			
		printf("\n");
	}
	
	printf("\nElements of Matrix 2 : \n");
	for(i = 0; i < r; i++)
	{
		for(j = 0; j < c; j++)
			printf("%d\t",arr2[i][j]);
		
		printf("\n");
	}
		
	for(i = 0; i < r; i++)
		for(j = 0; j < c; j++)
		{
			sum[i][j] = arr1[i][j] + arr2[i][j];
			diff[i][j] = arr1[i][j] - arr2[i][j];
		}
	
	printf("\nMatrix 1 + Matrix 2 :\n");
    for (i = 0; i < r; i++) 
	{
        for (j = 0; j < c; j++) 
            printf("%d\t", sum[i][j]);

        printf("\n");
    }
    printf("\nMatrix 1 - Matrix 2 :\n");
    for (i = 0; i < r; i++) 
	{
        for (j = 0; j < c; j++) 
            printf("%d\t", diff[i][j]);
            
        printf("\n");
    }

	for (i = 0; i < r; i++) 
	{
        free(arr1[i]); 
		free(arr2[i]);
        free(sum[i]); 
		free(diff[i]);
    }
    
    free(arr1); 
	free(arr2); 
	free(sum); 
	free(diff);

	return 0;
}
