/* 5. Write a C program to reverse the data of the nodes of a singly linked list without changing 
the links between the nodes.*/

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

void ReverseData(struct node *start,int count)
{
    if(start == NULL)
        return;

    int i;
    
    struct node *ptr = start;

    int arr[count];

    ptr = start;

    for(i = 0; i < count; i++)
    {
        arr[i] = ptr->data;
        ptr = ptr->next;
    }

    ptr = start;

    for(i = count - 1; i >= 0; i--)
    {
        ptr->data = arr[i];
        ptr = ptr->next;
    }
}

void Display(struct node *start)
{
    while(start != NULL)
    {
        printf("%d -> ", start->data);
        start = start->next;
    }
    printf("NULL\n");
}

int main()
{
    struct node *start = NULL, *ptr = NULL, *newnode = NULL;
    int n, i;

    printf("Enter number of nodes : ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        newnode = malloc(sizeof(struct node));

        printf("Enter data : ");
        scanf("%d", &newnode->data);

        newnode->next = NULL;

        if(start == NULL)
            start = ptr = newnode;
        
		else
        {
            ptr->next = newnode;
            ptr = newnode;
        }
    }

    printf("\nOriginal List :\n");
    Display(start);

    ReverseData(start,n);

    printf("\nList After Reversing Data :\n");
    Display(start);

    return 0;
}

