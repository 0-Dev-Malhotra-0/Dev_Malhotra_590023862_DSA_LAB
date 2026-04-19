/*3.Write a C program to implement a Priority Queue using a Binary Heap (Min Heap or Max Heap). 
	The program should support the following operations:
	(i) Insert (Enqueue with Priority): 
		Insert an element along with its priority into the queue. 
		Maintain heap property using heapify-up.
	(ii) Delete (Dequeue Highest Priority Element): 
		Remove the element with the highest priority: 
		(Min Heap ? smallest element) and (Max Heap ? largest element). 
		Maintain heap property using heapify-down.
	(iii) Peek: Display the element with the highest priority without removing it.
	(iv) Display: Print all elements of the priority queue.
*/

#include <stdio.h>

#define MAX 100

typedef struct {
    int value;
    int priority;
} Node;

Node heap[MAX];
int size = 0;

void swap(Node *a, Node *b)
{
    Node temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int index)
{
    int parent = (index - 1) / 2;

    if (index > 0 && heap[parent].priority < heap[index].priority)
    {
        swap(&heap[parent], &heap[index]);
        heapifyUp(parent);
    }
}

void insert(int value, int priority)
{
    if (size == MAX)
    {
        printf("Queue Overflow!\n");
        return;
    }

    heap[size].value = value;
    heap[size].priority = priority;

    heapifyUp(size);
    size++;

    printf("\n");
}

void heapifyDown(int index)
{
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest = index;

    if (left < size && heap[left].priority > heap[largest].priority)
        largest = left;

    if (right < size && heap[right].priority > heap[largest].priority)
        largest = right;

    if (largest != index)
    {
        swap(&heap[index], &heap[largest]);
        heapifyDown(largest);
    }
}

void deleteRoot()
{
    if (size == 0)
    {
        printf("Queue Underflow!\n");
        return;
    }

    printf("Deleted element: %d (priority %d)\n", heap[0].value, heap[0].priority);

    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);

    printf("\n");
}

void peek()
{
    if (size == 0)
    {
        printf("Queue is empty!\n");
        return;
    }

    printf("Top element: %d (priority %d)\n\n", heap[0].value, heap[0].priority);
}

void display()
{
    if (size == 0)
    {
        printf("Queue is empty!\n");
        return;
    }

    int i;
    printf("Priority Queue:\n");
    for (i = 0; i < size; i++)
        printf("Value: %d, Priority: %d\n", heap[i].value, heap[i].priority);

    printf("\n");
}

int main()
{
    int choice, value, priority;

    while (1)
    {
        printf("--- Priority Queue (Max Heap) ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Enter priority: ");
                scanf("%d", &priority);
                insert(value, priority);
                break;

            case 2:
                deleteRoot();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
