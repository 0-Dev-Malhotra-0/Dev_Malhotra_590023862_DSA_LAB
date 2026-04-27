/*3.Write a C program to accept the number of vertices and edges of a graph and represent it using an adjacency matrix. 
	The program should:
	(i)	construct and display the adjacency matrix.
	(ii)Implement functions to calculate and print the in-degree and out-degree of a given vertex.*/

#include <stdio.h>
#define MAX 20

int main() 
{
    int n, e;
    int adj[MAX][MAX] = {0};
    int u, v, i, j;
    int vertex, indegree = 0, outdegree = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v) for directed graph:\n");
    for (i = 0; i < e; i++) 
	{
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    printf("\nAdjacency Matrix:\n");
    for (i = 0; i < n; i++) 
    {
        for (j = 0; j < n; j++) 
            printf("%d ", adj[i][j]);
            
        printf("\n");
    }

    printf("\nEnter vertex to find degree: ");
    scanf("%d", &vertex);

    for (j = 0; j < n; j++) 
        outdegree += adj[vertex][j];
    
    for (i = 0; i < n; i++) 
        indegree += adj[i][vertex];
    

    printf("Out-degree of %d = %d\n", vertex, outdegree);
    printf("In-degree of %d = %d\n", vertex, indegree);

    return 0;
}


