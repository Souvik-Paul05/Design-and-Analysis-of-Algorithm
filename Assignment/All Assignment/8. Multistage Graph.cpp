#include<stdio.h>
#include<limits.h>
#define MAX 100
#define INF 9999

 int main()
 {
 	int graph[MAX][MAX],cost[MAX],path[MAX],n;
 	printf("Enter the number of vertices: ");
 	scanf("%d",&n);
 	printf("Enter the Adjacency Matrix (Enter 0 for no edges):\n");
 	for(int i=0;i<n;i++)
 	{
 		for(int j=0;j<n;j++)
 		{
 			scanf("%d",&graph[i][j]);
		 }
	 }
	cost[n-1]=0;
	
	for(int i=n-2;i>=0;i--)
	{
		cost[i]=INF;
		for(int j=i+1;j<n;j++)
		{
			if(graph[i][j]!=0 && graph[i][j]+cost[j]<cost[i])
			{
				cost[i]=graph[i][j]+cost[j];
				path[i]=j;
			}
		}
	}
	printf("\nMinimum Cost from Source to Destination: %d\n",cost[0]);
	
	printf("Path: 0");
	int k=0;
	while(k!=n-1)
	{
		k=path[k];
		printf(" -> %d",k);
	}
	printf("\n");
	return 0;
 }
