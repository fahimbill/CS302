
//Fahim Billah
#include <stdio.h>
#include<stdbool.h>
#include <limits.h>
#define V 6 //verticies


int minK(int key[], bool mstSet[]);
int printMST(int parent[], int n, int graph[V][V]);
void MST(int graph[V][V]);

int main()
{
int graph[V][V] = {{0, 4, 4, 1, 0, 0}, {4, 0, 0, 6, 4, 0}, {4, 0, 0, 2, 0, 15}, {1, 6, 2, 0, 5, 6}, {0, 4, 0, 5, 0, 3}, {0, 0, 15, 6, 3, 0}};


    MST(graph);

    return 0;
}

int minK(int key[], bool mstSet[])
{

int min = INT_MAX, index;

for (int x = 0; x < V; x++)
    if (mstSet[x] == false && key[x] < min)
        min = key[x], index = x;

return index;
}

int printMST(int parent[], int n, int graph[V][V])
{
printf("Edge: \t\t\tWeight\n");
for (int i = 1; i < V; i++)
    printf("Vertex %d - Vertex %d \t%d \n", parent[i], i, graph[i][parent[i]]);
}

void MST(int graph[V][V])
{
    int parent[V];
    int key[V];
    bool mstSet[V];

    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;


    key[0] = 0;
    parent[0] = -1;


    for (int count = 0; count < V-1; count++)
    {
        int a = minK(key, mstSet);

        mstSet[a] = true;

        for (int b = 0; b < V; b++)


        if (graph[a][b] && mstSet[b] == false && graph[a][b] < key[b])
            parent[b] = a, key[b] = graph[a][b];
    }


    printMST(parent, V, graph);
}
