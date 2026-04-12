/*2.Write a C program to create a binary tree using linked list representation and perform various operations on it.
	(i)	Insert nodes into the tree (use user input).
	(ii) Create separate functions to count.
		-> Total number of nodes.
		-> Number of leaf nodes (nodes with no children).
		-> Height of the binary tree.
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    struct node *left;
    int data;
    struct node *right;
} tree;

tree *root = NULL;

tree* insert(tree* root) 
{
	int val;
	
	printf("Enter value : ");
	scanf("%d",&val);
	
    tree* newnode = (tree*)malloc(sizeof(tree));
    
    if(newnode == NULL)
	{
	    printf("Memory allocation failed\n");
	    exit(1);
	}
	
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;
    

    if (root == NULL) 
        return newnode;

    tree* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) 
	{
        tree* temp = queue[front++];

        if (temp->left == NULL) 
		{
            temp->left = newnode;
            return root;
        } 
		
		else
            queue[rear++] = temp->left;
        

        if (temp->right == NULL) 
		{
            temp->right = newnode;
            return root;
        } 
		
		else 
            queue[rear++] = temp->right;
        
    }
    
    return root;
}

int count_total(tree *root)
{
    if (root == NULL)
        return 0;

    return 1 + count_total(root->left) + count_total(root->right);
}

int count_leaf(tree *root)
{
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    return count_leaf(root->left) + count_leaf(root->right);
}

int find_height(tree *root)
{
    if (root == NULL)
        return 0;

    int left = find_height(root->left);
    int right = find_height(root->right);

    return 1 + (left > right ? left : right);
}

int main()
{
    int ch;

    while(1)
    {
        printf("--- Binary Tree ---\n");
        printf("1. Insert\n");
        printf("2. Total Nodes\n");
        printf("3. Leaf Nodes\n");
        printf("4. Height\n");
        printf("5. Exit\n");

        printf("Enter choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                root = insert(root);
                printf("\n");
                break;

            case 2:
                printf("Total Nodes = %d\n\n", count_total(root));
                break;

            case 3:
                printf("Leaf Nodes = %d\n\n", count_leaf(root));
                break;

            case 4:
                printf("Height = %d\n\n", find_height(root));
                break;

            case 5:
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }
}

