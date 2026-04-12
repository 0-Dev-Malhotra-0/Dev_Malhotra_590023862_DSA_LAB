/*1. Write a C program to create a binary tree using an array. 
	The program should support the following operations: 
	(i)	Insert elements into the tree.
	(ii) Display the tree elements.
	(iii) Display the parent, left child, and right child of a given node.
*/

#include<stdio.h>
#include<math.h>

int size = 0;

void insert(int tree[], int max)
{
    if (size >= max) 
    {
        printf("Tree is full\n");
        return;
    }
    
    int value;
    
    printf("Enter value : ");
    scanf("%d",&value);
    
    tree[size++] = value;
}

void display(int tree[])
{
    if (size == 0)
    {
        printf("Tree is empty\n");
        return;
    }   
    
    int i;
    
    for (i = 0; i < size; i++)
        printf("%d ", tree[i]);
        
    printf("\n");
}
    
void display_relation(int tree[]) 
{
    if (size == 0)
    {
        printf("Tree is empty\n");
        return;
    }
       
    int k, index = -1, val;
    
    printf("Enter node : ");
    scanf("%d", &val);
    
    for (k = 0; k < size; k++)
	{
	    if (tree[k] == val)
	    {
	        index = k;
	        break;
	    }
	}
	
	if (index == -1)
	{
	    printf("Node Not Found\n");
	    return;
	}
	
	if (index == 0)
	    printf("Parent node : NULL (Root)\n");
	else
	    printf("Parent node : %d\n", tree[(index - 1) / 2]);
	
	if (2 * index + 1 < size)
	    printf("Left node : %d\n", tree[2 * index + 1]);
	else
	    printf("Left node : NULL\n");
	
	if (2 * index + 2 < size)
	    printf("Right node : %d\n", tree[2 * index + 2]);
	else
	    printf("Right node : NULL\n");
}

int main()
{
    int max, h;
    
    printf("Enter height of tree : ");
    scanf("%d",&h);
    
    max = (int)pow(2,h) - 1;
    
    int tree[max];
    int ch;
    
    while(1)
    {
        printf("\n--- Binary Tree ---\n");
        printf("1. Insert\n");
        printf("2. Display\n");
        printf("3. Display Relations\n");
        printf("4. Exit\n");
        
        printf("Enter choice : ");
        scanf("%d",&ch);
        
        switch(ch)
        {
            case 1:
                insert(tree, max);
                break;
                
            case 2:
                display(tree);
                break;
                
            case 3:
                display_relation(tree);
                break;
                
            case 4:
                return 0;
                
            default:
                printf("Invalid Choice\n");
        }
    }
}
