/*5.Write a C program to represent a graph using an adjacency matrix.
	The program should perform Breadth First Search (BFS) traversal starting from a given source vertex. 
	The program should:
		(i)	Accept the number of vertices n.
		(ii) Accept the adjacency matrix of the graph.
		(iii) Accept a starting vertex for traversal.
		(iv) Perform BFS traversal using a queue.
		(v)	Display the order of traversal of vertices.*/

#include <stdio.h>

#define MAX 20

int adj[MAX][MAX];
int visited[MAX];
int queue[MAX];

int main() 
{
    int n, i, j, start;
    int front = 0, rear = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) 
            scanf("%d", &adj[i][j]);
        
    }

    for (i = 0; i < n; i++) 
        visited[i] = 0;
    

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    queue[rear++] = start;
    visited[start] = 1;

    printf("BFS Traversal: ");

    while (front < rear) 
	{
        int current = queue[front++];
        printf("%d ", current);

        for (j = 0; j < n; j++) 
		{
            if (adj[current][j] == 1 && visited[j] == 0) 
			{
                queue[rear++] = j;
                visited[j] = 1;
            }
        }
    }

    return 0;
}

