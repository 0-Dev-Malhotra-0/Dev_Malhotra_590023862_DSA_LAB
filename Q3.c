/*3. Write a C program to implement the Insertion Sort algorithm.
	(i)	Input: An array of n integers.
	(ii) Output: Sorted array in ascending order.
	(iii) Requirements:
		-> Display the array after inserting each element.
*/

#include <stdio.h>

int main() 
{
    int n, i, j, k, key;

    printf("Enter number of elements : ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements : ", n);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for(i = 1; i < n; i++) 
    {
        key = arr[i];
        j = i - 1;

        while(j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;

        printf("After inserting element %d (pass %d): ", key, i);
        for(k = 0; k < n; k++)
            printf("%d ", arr[k]);
        printf("\n");
    }

    printf("\nSorted array: ");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}

