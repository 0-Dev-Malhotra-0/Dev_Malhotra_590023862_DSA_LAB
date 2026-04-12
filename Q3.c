/*3.Write a C program to implement recursive tree traversals on a binary tree. 
 	Your program should perform the following traversal functions:
	(i)	Inorder traversal (Left ? Root ? Right).
	(ii) Preorder traversal (Root ? Left ? Right).
	(iii) Postorder traversal (Left ? Right ? Root).
*/

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

void inorder(tree* root) 
{
    if (root != NULL) 
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(tree* root) 
{
    if (root != NULL) 
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(tree* root) 
{
    if (root != NULL) 
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() 
{
    int ch;

    while(1)
    {
        printf("--- Binary Tree Traversal ---\n");
        printf("1. Insert\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
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
                printf("Inorder: ");
                inorder(root);
                printf("\n\n");
                break;

            case 3:
                printf("Preorder: ");
                preorder(root);
                printf("\n\n");
                break;

            case 4:
                printf("Postorder: ");
                postorder(root);
                printf("\n\n");
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
