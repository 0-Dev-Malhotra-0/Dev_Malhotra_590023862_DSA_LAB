/* 3.Write a C program to reverse a given string using a stack.
 The program should follow the Last In First Out (LIFO) principle of the stack.
*/

#include<stdio.h>
#include<stdlib.h>

struct stack{
    char data;
    struct stack *next;
};

int main()
{
	int i, n = 0;
	char str[100];
	
	printf("Enter string : ");
	scanf("%s",&str);
	
	struct stack *top = NULL, *ptr = NULL;
	
    for(i = 0; i < str[n] != '\0' ; i++)
    {
    	struct stack *newnode;

    	newnode = (struct stack*)malloc(sizeof(struct stack));

	    newnode->data = str[i];
	    newnode->next = top;
	    top = newnode;
	}
    
    ptr = top;
    
    printf("Reversed string : ");
    
    while (ptr != NULL)
    {
    	printf("%c",ptr->data);
    	ptr = ptr->next;
	}
	
	return 0;
}
