/*1.Write a C program to implement a Binary Search Tree (BST) using a linked list representation.
	 Your program should support the following operations:
	(i)	Insertion: Insert a node into the BST while maintaining BST properties. 
		Duplicate values should not be allowed.
	(ii)Deletion: Delete a node from the BST based on a given key.
		Handle all three cases: 
		(a) Node is a leaf node
		(b) Node has one child 
		(c) Node has two children
	(iii)Searching: Search for a given value in the BST (Display whether the element is found or not).
	(iv)Traversal: In order Traversal (Left ? Root ? Right).
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

tree* insert(tree* root, int val)
{	
    if (root == NULL) 
    {
        tree* newnode = (tree*)malloc(sizeof(tree));
        
        if(newnode == NULL)
        {
            printf("Memory allocation failed\n");
            exit(1);
        }

        newnode->data = val;
        newnode->left = NULL;
        newnode->right = NULL;

        return newnode;
    }
    
    if (val < root->data)
        root->left = insert(root->left, val);

    else if (val > root->data)
        root->right = insert(root->right, val);

    else
        printf("Duplicate value not allowed\n");

    return root;	
}

tree* findMin(tree* root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}

tree* deleteNode(tree* root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);

    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    else
    {
        // (a) Leaf node
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }

        // (b) One child
        else if (root->left == NULL || root->right == NULL)
        {
            tree* temp = (root->left == NULL) ? root->right : root->left;
            free(root);
            return temp;
        }

        // (c) Two children
        tree* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

tree* search(tree* root, int key)
{
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);
        
    return search(root->right, key);
}

void traversal(tree* root) 
{
    if (root != NULL) 
    {
        traversal(root->left);
        printf("%d ", root->data);
        traversal(root->right);
    }
}

int main()
{
    int ch, val, key;
    tree* result;

    while(1)
    {
        printf("--- Binary Search Tree ---\n");
        printf("1. Insert\n");
        printf("2. Deletion\n");
        printf("3. Searching\n");
        printf("4. Traversal\n");
        printf("5. Exit\n");

        printf("Enter choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("Enter value : ");
                scanf("%d",&val);
                root = insert(root, val);
                printf("\n");
                break;

            case 2:
                printf("Enter value to delete : ");
                scanf("%d",&key);
                root = deleteNode(root, key);
                printf("Node deleted (if existed)\n\n");
                break;

            case 3:
                printf("Enter value to search : ");
                scanf("%d",&key);

                result = search(root, key);

                if (result != NULL)
                    printf("Element found\n\n");
                
				else
                    printf("Element not found\n\n");
                
				break;

            case 4:
                printf("Traversal: ");
                traversal(root);
                printf("\n\n");
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid Choice\n");
        }
    }
}
