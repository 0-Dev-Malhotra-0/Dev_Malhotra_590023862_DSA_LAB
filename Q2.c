/*2.Write a C program to implement a Binary Heap (Min Heap or Max Heap). 
	The program should support the following operations:
	(i) Heap Creation: Initialize an empty heap using an array.
	(ii) Insertion (Heapify-Up): Insert a new element into the heap.
		 Maintain the heap property using heapify-up operation.
	(iii) Deletion (Heapify-Down): 
		  Delete the root element (minimum in Min Heap / maximum in Max Heap). 
		  Maintain heap property using heapify-down operation.
	(iv) Display Heap: Print the elements of the heap.
*/

#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;

void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int index)
{
    int parent = (index - 1) / 2;

    if (index > 0 && heap[parent] > heap[index]) 
	{
        swap(&heap[parent], &heap[index]);
        heapifyUp(parent);
    }
}

void insert(int value) 
{
    if (size == MAX) 
	{
        printf("Heap Overflow!\n");
        return;
    }

    heap[size] = value;
    heapifyUp(size);
    size++;
    
    printf("\n");
}

void heapifyDown(int index) 
{
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int smallest = index;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;

    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != index) 
	{
        swap(&heap[index], &heap[smallest]);
        heapifyDown(smallest);
    }
}

void deleteRoot() 
{
    if (size == 0) {
        printf("Heap Underflow!\n");
        return;
    }

    printf("Deleted element: %d\n", heap[0]);

    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
    
    printf("\n");
}

void display() 
{
    if (size == 0) 
	{
        printf("Heap is empty!\n");
        return;
	}
	
	int i;
    printf("Heap elements: ");
    for (i = 0; i < size; i++) 
        printf("%d ", heap[i]);
    
    printf("\n\n");
}

int main() 
{
    int choice, value;

    while (1) 
	{
        printf("--- Min Heap Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete Root\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;

            case 2:
                deleteRoot();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
