#include<stdio.h>
 
 void dijkastras(int n,int cost[10][10],int s,int dist[10])
 {
 	int i,v=-1,count=1,min,visited[10];
 	
 	for(i=1;i<=n;i++)
 	{
 		visited[i]=0;
 		dist[i]=cost[s][i];
	 }
	visited[s]=1;
	dist[s]=0;
	
	while(count<n)
	{
		min=999;
		for(i=1;i<=n;i++)
		{
			if(dist[i]<min && visited[i]==0)
			{
				min=dist[i];
				v=i;
			}
		}
		if(v==-1)                        // Remaining node are unreachable
			break;
		
		visited[v]=1;
		count++;
		
		for(i=1;i<=n;i++)
		{
			if(!visited[i] && dist[i]>dist[v]+cost[v][i])
			{
				dist[i]= dist[v]+cost[v][i];
			}
		}
	}
 }
 
 int main()
 {
 	int i,j,s,n,cost[10][10],dist[10];
 	printf("Enter the Number of Nodes: ");
 	scanf("%d",&n);
 	printf("Enter the Cost Adjacency Matrix:(Enter 0 for No Edges)\n");
 	for(i=1;i<=n;i++)
 	{
 		for(j=1;j<=n;j++)
 		{
 			scanf("%d",&cost[i][j]);
 			if(cost[i][j]==0 && i!=j)
 				cost[i][j]=999;           // No edges between different nodes
		 }
	 }
	printf("Enete the Source Vertex(1 to %d): ",n);
	scanf("%d",&s);
	
	dijkastras(n,cost,s,dist);
	printf("Shortest Paths from Node %d:\n",s);
	for(i=1;i<=n;i++)
	{
		printf("%d -> %d = %d\n",s,i,dist[i]);
	}
	return 0;
 }
