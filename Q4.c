//4.Write a C program to perform Level Order Traversal on a binary tree using a queue.

#include<stdio.h>
#include<stdlib.h>

typedef struct node 
{
    int data;
    struct node *left;
    struct node *right;
} tree;

tree *root = NULL;

tree* insert(tree* root) 
{
    int val;

    printf("Enter value : ");
    scanf("%d", &val);

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

void levelOrder(tree* root) 
{
    if (root == NULL) 
	{
        printf("Tree is empty\n");
        return;
    }

    tree* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) 
	{
        tree* temp = queue[front++];

        printf("%d ", temp->data);

        if (temp->left != NULL)
            queue[rear++] = temp->left;

        if (temp->right != NULL)
            queue[rear++] = temp->right;
    }
    printf("\n\n");
}

int main() {
    int ch;

    while(1) {
        printf("--- Binary Tree (Level Order) ---\n");
        printf("1. Insert\n");
        printf("2. Level Order Traversal\n");
        printf("3. Exit\n");

        printf("Enter choice : ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                root = insert(root);
                printf("\n");
                break;

            case 2:
                printf("Level Order: ");
                levelOrder(root);
                break;

            case 3:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
