#include<stdio.h>
#include<stdlib.h>
#define MAX 100

 typedef struct
 {
 	int search,dest,weight;
 } Edge;
 
 typedef struct
 {
 	int parent,rank;
 } Subset;
 
 int find(Subset subsets[],int i)
 {
 	if(subsets[i].parent != i)
 	{
 		subsets[i].parent=find(subsets,subsets[i].parent);
	 }
	 return subsets[i].parent;
 }
 
 void union_sets(Subset subsets[],int x,int y)          // Union by Rank
 {
 	int root_x=find(subsets,x);
 	int root_y=find(subsets,y);
 	
 	if(subsets[root_x].rank < subsets[root_y].rank)
 	{
 		subsets[root_x].parent=root_y;
	 }
	else if(subsets[root_x].rank > subsets[root_y].rank)
	{
		subsets[root_y].parent=root_x;
	}
	else
	{
		subsets[root_y].parent=root_x;
		subsets[root_x].rank++;
	}
 }
 
 int compare(const void* a,const void* b)
 {
 	Edge* e1=(Edge*)a;
 	Edge* e2=(Edge*)b;
 	return e1->weight - e2->weight;
 }
 
 void kruskal(int graph[MAX][MAX],int V)
 {
 	Edge edges[MAX*MAX];
 	int edge_count=0;
 	
 	for(int i=0;i<V;i++)
 	{
 		for(int j=i+1;j<V;j++)
 		{
 			if(graph[i][j] != 0)
 			{
 				edges[edge_count].search = i;
 				edges[edge_count].dest = j;
 				edges[edge_count].weight = graph[i][j];
 				edge_count++;
			 }
		 }
	 }
	 
	qsort(edges,edge_count,sizeof(Edge),compare);
	
	Subset* subsets= (Subset*)malloc(V*sizeof(Subset));
	for(int v=0;v<V;v++)
	{
		subsets[v].parent=v;
		subsets[v].rank=0;
	}
	Edge result[MAX];
	int e=0,i=0;
	
	while(e<V-1 && i<edge_count)
	{
		Edge next=edges[i++];
		int x=find(subsets,next.search);
		int y=find(subsets,next.dest);
		
		if(x != y)
		{
			result[e++]=next;
			union_sets(subsets,x,y);
		}
	}
	
	printf("\nEdges in the Minimum Spanning Tree:\n");
	int total_cost=0;
	for(int i=0;i<e;i++)
	{
		printf("%d -> %d = %d\n",result[i].search,result[i].dest,result[i].weight);
		total_cost+=result[i].weight;
	}
	printf("\nBy Kruskal Algo, Total Cost of MST: %d\n",total_cost);
 }
 
 int main()
 {
 	int V;
 	int graph[MAX][MAX];
 	
 	printf("Enter the Number of Vertex: ");
 	scanf("%d",&V);
 	
 	printf("Enter the Cost Adjacency Matrix: (Enter 0 for no Edges)\n");
 	for(int i=0;i<V;i++)
 	{
 		for(int j=0;j<V;j++)
 		{
 			scanf("%d",&graph[i][j]);
		 }
	 }
	kruskal(graph,V);
	return 0;
 }
 
 
 
 
