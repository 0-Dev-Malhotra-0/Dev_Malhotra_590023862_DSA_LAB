/*4. Write a C program to implement the Merge Sort using recursion.
	(i)	Input: An array of n integers.
	(ii) Output: Sorted array in ascending order.
	(iii) Requirements:
		-> Clearly implement the divide and merge steps.
*/

#include <stdio.h>

void merge(int arr[], int left, int mid, int right) 
{
    int i = left, j = mid + 1, k = 0;
    int temp[right - left + 1];
    
    while(i <= mid && j <= right) 
    {
        if(arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while(i <= mid)
        temp[k++] = arr[i++];

    while(j <= right)
        temp[k++] = arr[j++];

    for(i = left, k = 0; i <= right; i++, k++)
        arr[i] = temp[k];
}

void mergeSort(int arr[], int left, int right) 
{
    if(left < right) 
    {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() 
{
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements: ", n);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    mergeSort(arr, 0, n - 1);

    printf("Sorted array: ");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
