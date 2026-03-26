/* 3.Write a program to check whether a given string is a palindrome or not 
     using an Array and a Queue data structure. 
*/

#include<stdio.h>
#define MAX 100

int main()
{
	int front = 0, rear = -1;
	char string[MAX];
	
	printf("Enter string : ");
	scanf("%s",string);
	
    int i = 0, n = 0;
	
	while (string[i] != '\0')
	{
		n++;
		i++;
	}
	
	char queue[n];
	
    for (i = 0; i < n; i++)
    	queue[++rear] = string[i];
    
	int flag = 0;
    int j = rear;
    i = front;

    while (i < j) 
	{
        if (queue[i] != queue[j]) 
		{
            flag = 1;
            break;
        }
        
        i++;
        j--;
    }
	
	if (flag == 0)
		printf("Palindrome");
	else
		printf("Not Palindrome");
		
	return 0;
}

