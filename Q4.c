//4.Write a C program to accept a graph in the form of an adjacency matrix and determine whether the graph is undirected or not.

#include <stdio.h>

#define MAX 20

int main() 
{
    int n;
    int adj[MAX][MAX];
    int i, j, flag = 1;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) 
	{
        for (j = 0; j < n; j++) 
            scanf("%d", &adj[i][j]);
    }

    for (i = 0; i < n; i++) 
	{
        for (j = 0; j < n; j++) 
		{
            if (adj[i][j] != adj[j][i]) 
			{
                flag = 0;
                break;
            }
        }
    }

    if (flag == 1)
        printf("Graph is Undirected\n");
    else
        printf("Graph is Directed\n");

    return 0;
}


