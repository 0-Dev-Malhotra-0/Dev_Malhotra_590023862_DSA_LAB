/*2.Write a C program to implement a Hash table using arrays. 
	Perform Insert, Delete and Search operations on the hash table using the above Hash function (S.No.1). 
	Adopt a suitable user-defined exception handling strategy if collision occurs while inserting data.
*/

#include <stdio.h>
#define SIZE 10

int hashTable[SIZE];

void init() 
{
    int i;
    
	for (i = 0; i < SIZE; i++) 
        hashTable[i] = -1;
    
}

int hashFunction(int key) 
{
    int last_three = key % 1000;
    return last_three % SIZE;
}

void insert(int key) 
{
    int index = hashFunction(key);
    int start = index;

    while (hashTable[index] != -1 && hashTable[index] != -2) {
        index = (index + 1) % SIZE;

        if (index == start) 
		{
            printf("Hash Table is FULL!\n");
            return;
        }
    }

    hashTable[index] = key;
    printf("Inserted %d at index %d\n", key, index);
}

void search(int key) 
{
    int index = hashFunction(key);
    int start = index;

    while (hashTable[index] != -1) 
	{
        if (hashTable[index] == key) 
		{
            printf("Found %d at index %d\n", key, index);
            return;
        }
        
        index = (index + 1) % SIZE;

        if (index == start)
            break;
    }

    printf("Element not found!\n");
}

void deleteKey(int key) 
{
    int index = hashFunction(key);
    int start = index;

    while (hashTable[index] != -1) 
	{
        if (hashTable[index] == key) 
		{
            hashTable[index] = -2;
            printf("Deleted %d\n", key);
            return;
        }
        
        index = (index + 1) % SIZE;

        if (index == start)
            break;
    }

    printf("Element not found!\n");
}

void display() 
{
    printf("\nHash Table:\n");
    int i;
    
	for (i = 0; i < SIZE; i++) 
	{
        if (hashTable[i] == -1)
            printf("[%d] -> Empty\n", i);
        else if (hashTable[i] == -2)
            printf("[%d] -> Deleted\n", i);
        else
            printf("[%d] -> %d\n", i, hashTable[i]);
    }
}

int main() 
{
    int choice, key;

    init();

    while (1) 
	{
        printf("1.Insert\n2.Search\n3.Delete\n4.Display\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter SAP-ID: ");
                scanf("%d", &key);
                insert(key);
                break;

            case 2:
                printf("Enter SAP-ID to search: ");
                scanf("%d", &key);
                search(key);
                break;

            case 3:
                printf("Enter SAP-ID to delete: ");
                scanf("%d", &key);
                deleteKey(key);
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

    return 0;
}


