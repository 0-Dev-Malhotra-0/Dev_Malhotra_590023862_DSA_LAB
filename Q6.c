/*6. Write a C program to perform Linear Search that finds all occurrences of a given element in an array.
	(i)	Input: array of size n and a key element.
	(ii) Output: all positions where the element occurs.
	(iii) If the element does not exist, display an appropriate message.
*/

#include <stdio.h>

int main() 
{
    int n, i, key, found = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements: ", n);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    printf("Element found at positions: ");

    for(i = 0; i < n; i++) 
    {
        if(arr[i] == key) 
        {
            printf("%d ", i);  
            found = 1;
        }
    }

    if(found == 0)
        printf("Element not found");

    return 0;
}
