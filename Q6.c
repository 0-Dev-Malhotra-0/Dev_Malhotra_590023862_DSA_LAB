/*6.Write a C program to represent a graph using an adjacency matrix. 
	The program should perform Depth First Search (DFS) traversal starting from a given source vertex.
	The program should:
		(i)	Accept the number of vertices n.
		(ii) Accept the adjacency matrix of the graph.
		(iii) Accept a starting vertex for traversal.
		(iv) Perform DFS traversal using recursion or stack.
		(v)	Display the order of traversal of vertices.*/

#include <stdio.h>

#define MAX 20

int adj[MAX][MAX];
int visited[MAX];
int n;

void dfs(int v) 
{
    int j;
    printf("%d ", v);
    visited[v] = 1;

    for (j = 0; j < n; j++) 
	{
        if (adj[v][j] == 1 && visited[j] == 0) 
            dfs(j);
        
    }
}

int main() 
{
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) 
	{
        for (j = 0; j < n; j++) 
            scanf("%d", &adj[i][j]);
        
    }

    for (i = 0; i < n; i++) 
        visited[i] = 0;
    

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("DFS Traversal: ");
    dfs(start);

    return 0;
}


