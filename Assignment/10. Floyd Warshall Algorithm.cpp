#include<stdio.h>
#define INF 999

 void floyd_Warshall(int n,int cost[10][10])
 {
 	int dist[10][10],i,j,k;
 	for(i=1;i<=n;i++)
 	{
 		for(j=1;j<=n;j++)
 		{
 			dist[i][j]=cost[i][j];
		 }
	 }
	 
	for(k=1;k<=n;k++)                      // Floyd-Warshell Algorithm
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(dist[i][k]+dist[k][j]<dist[i][j])
				{
					dist[i][j]=dist[i][k]+dist[k][j];
				}		
			}
		}
	}
	
	printf("\nAll Pair Shortest path (Floyd-Warshell):\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(dist[i][j]==INF)
				printf("INF\t");
			else
				printf("%d\t",dist[i][j]);
		}
		printf("\n");
	}
 }
 
 int main()
 {
 	int n,i,j,cost[10][10];
 	printf("Enter the Number of Nodes: ");
 	scanf("%d",&n);
 	printf("Enter the Cost Adjacency Matrix:(Enter 0 for no Edges)\n");
 	for(i=1;i<=n;i++)
 	{
 		for(j=1;j<=n;j++)
 		{
 			scanf("%d",&cost[i][j]);
 			if(i != j && cost[i][j]==0)
 				cost[i][j]=INF;
		 }
	 }
	 
	 floyd_Warshall(n,cost);
	 return 0;
 }
 
