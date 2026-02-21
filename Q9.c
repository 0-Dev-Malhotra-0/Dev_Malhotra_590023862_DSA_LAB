/* 9. Write a C program to represent and evaluate a Polynomial using a Linked List. 
Each node should represent a term containing coefficient and exponent.*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node {
    int coeff;
    int exp;
    struct node *next;
};

void createPoly(struct node **start)
{
    int n, i;

    printf("Enter number of terms: ");
    scanf("%d",&n);

    for(i = 0; i < n; i++)
    {
        struct node *newnode = malloc(sizeof(struct node));

        printf("Enter coefficient: ");
        scanf("%d",&newnode->coeff);

        printf("Enter exponent: ");
        scanf("%d",&newnode->exp);

        newnode->next = NULL;

        if(*start == NULL)
        {
            *start = newnode;
        }
        
        else
        {
            struct node *ptr = *start;
            while(ptr->next != NULL)
                ptr = ptr->next;

            ptr->next = newnode;
        }
        
    }
}

void displayPoly(struct node *start)
{
    if(start == NULL)
    {
        printf("Polynomial is empty\n");
        return;
    }

    while(start != NULL)
    {
        printf("%dx^%d", start->coeff, start->exp);

        if(start->next != NULL)
            printf(" + ");

        start = start->next;
    }
    printf("\n");
}

int evaluatePoly(struct node *start, int x)
{
    int sum = 0;

    while(start != NULL)
    {
        sum += start->coeff * pow(x, start->exp);
        start = start->next;
    }

    return sum;
}

int main()
{
    struct node *poly = NULL;
    int choice = 0, x, result;

    while(choice != 4)
    {
        printf("--- Polynomial Using Linked List ---\n");
        printf("1. Create Polynomial\n");
        printf("2. Display Polynomial\n");
        printf("3. Evaluate Polynomial\n");
        printf("4. Exit\n");
        
		printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: 
				createPoly(&poly); 
				break;
            case 2: 
				displayPoly(poly); 
				break;
            case 3:
                printf("Enter value of x: ");
                scanf("%d",&x);
                result = evaluatePoly(poly, x);
                printf("Polynomial Value = %d\n", result);
                break;
            case 4: 
				break;
            default: 
				printf("Invalid choice\n");
        }
        printf("\n");
    }
    return 0;
}

