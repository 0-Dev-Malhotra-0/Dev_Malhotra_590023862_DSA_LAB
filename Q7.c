/*7. Write a C program to implement Binary Search using recursion.
	(i)	Input a sorted array and a key value.
	(ii) Use a recursive function to perform the search.
	(iii) Return and display the index of the element if found.
*/

#include <stdio.h>

int binarySearch(int arr[], int low, int high, int key) 
{
    if(low > high)
        return -1;  

    int mid = (low + high) / 2;

    if(arr[mid] == key)
        return mid;
    else if(arr[mid] > key)
        return binarySearch(arr, low, mid - 1, key);
    else
        return binarySearch(arr, mid + 1, high, key);
}

int main() 
{
    int n, i, key, result;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d sorted elements: ", n);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter key to search: ");
    scanf("%d", &key);

    result = binarySearch(arr, 0, n - 1, key);

    if(result != -1)
        printf("Element found at index: %d", result);
    else
        printf("Element not found");

    return 0;
}
