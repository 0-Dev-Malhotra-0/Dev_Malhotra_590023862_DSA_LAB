/* 1. Write a C program to traverse a singly linked list and count the number of nodes present 
in the list.*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main() 
{
    struct node *start = NULL, *ptr = NULL, *newnode = NULL;
    int count = 0, choice = 1;

    while (choice) 
    {
        newnode = malloc(sizeof(struct node));
        
        printf("Enter data : ");
        scanf("%d", &newnode->data);
        
		newnode->next = NULL;
        
		if (start == NULL) 
            start = ptr = newnode;
       
	    else 
		{
            ptr->next = newnode;
            ptr = newnode;
        }
        
        printf("Do you want to continue? (1/0): ");
        scanf("%d", &choice);
    }
    
    printf("\nSingly Linked List: ");
    ptr = start;
    
    while (ptr != NULL) 
    {
        printf("%d -> ", ptr->data);
        count++;
        ptr = ptr->next;
    }
    
    printf("NULL\n");
    printf("\nNumber of nodes in the linked list = %d\n", count);
    
    return 0;
}
