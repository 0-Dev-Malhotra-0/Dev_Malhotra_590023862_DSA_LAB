/*5.Write a C program to implement non-recursive tree traversals of a binary tree using a stack. 
	Your program should implement the following traversals using the stack:
	(i)	Inorder traversal (Left ? Root ? Right).
	(ii) Preorder traversal (Root ? Left ? Right).
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} tree;

tree *root = NULL;

typedef struct stack {
    tree* data[100];
    int top;
} stack;


void push(stack *s, tree* node) 
{
    s->data[++(s->top)] = node;
}

tree* pop(stack *s) 
{
    return s->data[(s->top)--];
}

int isEmpty(stack *s) 
{
    return s->top == -1;
}

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

void inorder(tree* root) 
{
    stack s;
    s.top = -1;
    tree* curr = root;

    while (curr != NULL || !isEmpty(&s)) 
	{
        while (curr != NULL) 
		{
            push(&s, curr);
            curr = curr->left;
        }

        curr = pop(&s);
        printf("%d ", curr->data);

        curr = curr->right;
    }
    printf("\n\n");
}

void preorder(tree* root) 
{
    if (root == NULL)
        return;

    stack s;
    s.top = -1;

    push(&s, root);

    while (!isEmpty(&s)) 
	{
        tree* temp = pop(&s);

        printf("%d ", temp->data);

        if (temp->right != NULL)
            push(&s, temp->right);

        if (temp->left != NULL)
            push(&s, temp->left);
    }
    printf("\n\n");
}

int main() 
{
    int ch;

    while(1) {
        printf("--- Non-Recursive Traversal ---\n");
        printf("1. Insert\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Exit\n");

        printf("Enter choice : ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                root = insert(root);
                printf("\n");
                break;

            case 2:
                printf("Inorder: ");
                inorder(root);
                break;

            case 3:
                printf("Preorder: ");
                preorder(root);
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
