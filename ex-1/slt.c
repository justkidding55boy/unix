// A C++ program for Dijkstra's single source shortest path algorithm. 
// The program is for adjacency matrix representation of the graph 

#include <limits.h> 
#include <stdio.h> 

// Number of vertices in the graph 
#define V 6
#define TRUE 1
#define FALSE 0

// A utility function to find the vertex with minimum distance value, from 
// the set of vertices not yet included in shortest path tree 
int minDistance(int dist[], int sptSet[]) 
{ 
	// Initialize min value 
	int min = INT_MAX, min_index = INT_MAX; 
    
    int v;
	for (v = 0; v < V; v++) 
		if (sptSet[v] == FALSE && dist[v] <= min) 
			min = dist[v], min_index = v; 

	return min_index; 
} 

// A utility function to print the constructed distance array 
int printSolution(int dist[]) 
{ 
	printf("Vertex \t\t Distance from Source\n");
    int i; 
	for (i = 0; i < V; i++) 
		printf("%d \t\t %d\n", i, dist[i]); 
    return 0;
} 

// Function that implements Dijkstra's single source shortest path algorithm 
// for a graph represented using adjacency matrix representation 
void dijkstra(int graph[V][V], int src) 
{ 
	int dist[V]; // The output array. dist[i] will hold the shortest 
	// distance from src to i 

	int sptSet[V]; // sptSet[i] will be TRUE if vertex i is included in shortest 
	// path tree or shortest distance from src to i is finalized 

	// Initialize all distances as 0INITE and stpSet[] as FALSE
    int i; 
	for (i = 0; i < V; i++) 
		dist[i] = INT_MAX, sptSet[i] = FALSE; 

	// Distance of source vertex from itself is always 0 
	dist[src] = 0; 

	// Find shortest path for all vertices
    int count; 
	for (count = 0; count < V - 1; count++) { 
		// Pick the minimum distance vertex from the set of vertices not 
		// yet processed. u is always equal to src in the first iteration. 
		int u = minDistance(dist, sptSet); 

		// Mark the picked vertex as processed 
		sptSet[u] = TRUE; 

		// Update dist value of the adjacent vertices of the picked vertex. 
		int v;
        for (v = 0; v < V; v++) 

			// Update dist[v] only if is not in sptSet, there is an edge from 
			// u to v, and total weight of path from src to v through u is 
			// smaller than current value of dist[v] 
            //only if the node has not been calculated yet
            //the node is connected
            //if dist[u] == INF_MAX then it means dist[u] != INF_MAX
			if (!sptSet[v] && graph[u][v]  
				&& dist[u] + graph[u][v] < dist[v]) 
				dist[v] = dist[u] + graph[u][v]; 
	} 

	// print the constructed distance array 
	printSolution(dist); 
} 

// driver program to test above function 
int main() 
{ 
	/* Let us create the example graph discussed above */
    
    int graph[V][V] = {
    {  0,  2, 5,  1, 0, 0},
    {  2,  0, 3,  2, 0, 0},
    {  5,  3, 0,  3,   1,   5},
    {  1,  2, 3,  0,   1, 0},
    {0,0, 1,  1,   0,   2},
    {0,0, 5, 0,  2,   0}
};

	dijkstra(graph, 0); 

	return 0; 
} 

