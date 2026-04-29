/*1. Write a C program to implement the Bubble Sort algorithm.
	(i)	Input: An array of n integers.
	(ii) Output: Sorted array in ascending order.
	(iii) Requirements:
		-> Display the array after each pass.
		-> Count and display the total number of comparisons and swaps.
*/

#include <stdio.h>

int main() 
{
    int n, i, j, k, temp;
    int comp = 0, swaps = 0;

    printf("Enter number of elements : ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements : ", n);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for(i = 0; i < n - 1; i++) 
    {
        for(j = 0; j < n - i - 1; j++) 
        {
            comp++;  
            
            if(arr[j] > arr[j + 1]) 
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps++;  
            }
        }

        printf("After pass %d : ", i + 1);
        
        for(k = 0; k < n; k++)  
            printf("%d ", arr[k]);
        printf("\n");
    }

    printf("\nSorted array: ");
    for(k = 0; k < n; k++)
        printf("%d ", arr[k]);

    printf("\nTotal comparisons: %d", comp);
    printf("\nTotal swaps: %d", swaps);

    return 0;
}
