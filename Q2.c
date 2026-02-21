/* 2. Write a C program to implement a singly linked list and search for a given element in the 
list. If the element is found, display the position of the element in the linked list; otherwise, 
display element does not exit.*/

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
    int i, n;
    
    printf("Enter number of nodes : ");
    scanf("%d",&n);

    for(i= 0; i < n; i++) 
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
    }
    
    printf("\nSingly Linked List: ");
    
	ptr = start;
    
    while (ptr != NULL) 
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    
    printf("NULL\n");
    
    int search, pos = 1, found = 0;
    
    printf("\nEnter element to search : ");
    scanf("%d",&search);
    
    ptr = start;
    
    while (ptr != NULL)
    {
    	if (ptr->data == search)
    	{
    		found = 1;
    		break;
		}
		ptr = ptr->next;
		pos++;
	}
	
	if (found)
		printf("\nElement found at %d position",pos);
	
	else
		printf("\nElement does not exist");	
		
    return 0;
}

