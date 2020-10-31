#include<stdio.h> 

#define V 4 
#define INFINITY 10000000 
  
void printM(int dist[][V]) 
{ 
    printf ("FloydWarshall Algorithm:  \n"); 
    for (int i = 0; i < V; i++) 
    { 
        for (int j = 0; j < V; j++) 
        { 
            if (dist[i][j] == INFINITY) 
                printf("%7s", "INF"); 
            else
                printf ("%7d", dist[i][j]); 
        } 
        printf("\n"); 
    } 
} 
  
void floydWarshall(int graph[][V]) 
{ 
    int dist[V][V], i, j, k; 
    for (i = 0; i < V; i++) 
        for (j = 0; j < V; j++) 
            dist[i][j] = graph[i][j]; 
    for (k = 0; k < V; k++) 
    { 
        for (i = 0; i < V; i++) 
        { 
            for (j = 0; j < V; j++) 
            { 
                if (dist[i][k] + dist[k][j] < dist[i][j]) 
                    dist[i][j] = dist[i][k] + dist[k][j]; 
            } 
        } 
    } 
    printM(dist); 
} 

int main() 
{ 
    int graph[V][V] = { {0,9,-4,INFINITY}, 
                        {6,0,INFINITY,2}, 
                        {INFINITY,5,0,INFINITY}, 
                        {INFINITY,INFINITY,1,0}
                      }; 
    floydWarshall(graph); 
    return 0; 
} 
