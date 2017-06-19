/*
	Graph Adjacency List Code
	Language - C
	Written by : Robin Kumar Sharma
	Date - 19th June, 2017

*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>

// Graph Node
struct ADL_Node{
	int dest;
	struct ADL_Node* next;
};

// Head for every Graph node
struct ADL_List{
	struct ADL_Node* head;
};

// Main graph structure
struct Graph{
	int value;
	struct ADL_List* array;
};

// create Graph
struct Graph* createGraph(int v){
	struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
	graph->value = v;
	graph->array = (struct ADL_List*)malloc(v*sizeof(struct ADL_List));
	for (int i = 0; i < v; ++i)
	{
		graph->array[i].head = NULL;
	}
	return graph;
};

// New Node
struct ADL_Node* addNode(int dest){
	struct ADL_Node* newNode = (struct ADL_Node*)malloc(sizeof(struct ADL_Node));
	newNode->dest = dest;
	newNode->next = NULL;
	return newNode;
};

// add Edge
void addEdge(struct Graph *graph, int src, int dest){
	// Add edge to source
	struct ADL_Node* node = addNode(dest);
	node->next = graph->array[src].head;
	graph->array[src].head = node;

	// Graph is undirected add edge to destination too
	node = addNode(src);
	node->next = graph->array[dest].head;
	graph->array[dest].head = node;
};

//print graph
void printGraph(struct Graph* graph){
	for(int i=0;i<graph->value;++i){
		struct ADL_Node *pcrawl = graph->array[i].head;
		printf("\n Adjacency List of vertex %d \n head ", i );
		while(pcrawl){
			printf("-> %d ", pcrawl->dest);
			pcrawl = pcrawl->next;
		}
		printf("\n");
	}
}

int main(int argc, char **argv){
	
	struct timeval before;
	struct timeval after;
	double time;
	int v =5;

	// Time start before creating graph
	gettimeofday(&before, NULL);

	struct Graph *graph = createGraph(v);

	addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // Stop time after graph creation
    gettimeofday(&after, NULL);

    time = (double)(after.tv_sec -before.tv_sec) + (double)(after.tv_usec -before.tv_usec)/1e6;
	//print graph
	printGraph(graph);

	printf("\nTotal Graph creation time : %f seconds\n\n", time);
	return 0;
}
