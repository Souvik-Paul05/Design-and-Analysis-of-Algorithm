#include<stdio.h>

 void Bellman_Ford(int n,int cost[10][10],int s,int dist[10])
 {
 	int i,j,k;
 	for(i=1;i<=n;i++)      // Initialize Distance
 	{
 		dist[i]=999; 
	 }
	dist[s]=0;
	
	for(k=1;k<=n-1;k++)              // edges repeatedly for (n-1) times
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(cost[i][j] != 999 && dist[i]+cost[i][j]<dist[j])
				{
					dist[j]=dist[i]+cost[i][j];
				}
			}
		}
	}
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(cost[i][j] != 999 && dist[i]+cost[i][j]<dist[j])
			{
				printf("Graph Contain a Negative Weight Cycle...\n\n");
			}
		}
	}
 }
 
 int main()
 {
 	int i,j,s,n,cost[10][10],dist[10];
 	printf("Enter the Number of Nodes: ");
 	scanf("%d",&n);
 	printf("Enter the Cost Adjacency Matrix:(Eneter 0 for no Edges)\n");
 	for(i=1;i<=n;i++)
 	{
 		for(j=1;j<=n;j++)
 		{
 			scanf("%d",&cost[i][j]);
 			if(cost[i][j]==0 && i != j)
 			{
 				cost[i][j]=999;  // No edges....
			 }
		 }
	 }
	 
	printf("Enter the Source Vertex (1 to %d): ",n);
	scanf("%d",&s);
	
	Bellman_Ford(n,cost,s,dist);
	printf("By Bellamn Ford Algorithm, Shortest Path from %d:\n",s);
	for(i=1;i<=n;i++)
	{
		printf("%d -> %d = %d\n",s,i,dist[i]);
	}
	return 0;
 }
