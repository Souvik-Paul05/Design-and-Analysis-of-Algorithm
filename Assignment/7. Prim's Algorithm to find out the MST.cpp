#include<stdio.h>

 void prims(int n,int cost[10][10])
 {
 	int visited[10]={0},min,u,v,i,j,num=1;
 	int total_cost=0;
 	visited[1]=1;                              // start from node 1
 	
 	printf("\nEdges in the Minimum Spanning Tree:\n");
 	while(num<n)
 	{
 		min=999;
 		for(i=1;i<=n;i++)
 		{
 			if(visited[i])
 			{
 				for(j=1;j<=n;j++)
 				{
 					if(!visited[j] && cost[i][j]<min)
 					{
 						min=cost[i][j];
 						u=i;
 						v=j;
					 }
				 }
			 }
		 }
		visited[v]=1;
		printf("%d -> %d = %d\n",u,v,cost[u][v]);
		total_cost=total_cost+cost[u][v];
		num++;
	 }
	printf("\nBy Prims Algo, Total Cost of MST: %d\n",total_cost);
 }
 
 int main()
 {
 	int i,j,n,cost[10][10];
 	printf("Enter the Number of Nodes: ");
 	scanf("%d",&n);
 	
 	printf("Enter the Cost Adjacency Matrix (Enter 0 for No Edges): \n");
 	for(i=1;i<=n;i++)
 	{
 		for(j=1;j<=n;j++)
 		{
 			scanf("%d",&cost[i][j]);
 			if(cost[i][j]==0)
 				cost[i][j]=999;             // No Edges 
		 }
	 }
	prims(n,cost);
	return 0;
 }
