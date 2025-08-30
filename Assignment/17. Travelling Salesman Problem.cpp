#include<stdio.h>
#define MAX 10
#define INF 999

 int tsp(int cost[MAX][MAX],int visited[MAX],int pos,int n,int count,int cost_so_far,int start)
 {
 	int city,new_cost;
 	if(count==n && cost[pos][start]!=0)
 	{
 		return cost_so_far + cost[pos][start];
	 }
	int ans=INF;
	
	for(city=0;city<n;city++)
	{
		if(!visited[city] && cost[pos][city]!=0 && cost[pos][city]!=INF)
		{
			visited[city]=1;
			new_cost=tsp(cost,visited,city,n,count+1,cost_so_far + cost[pos][city],start);
			ans=(new_cost<ans)?new_cost:ans;
			visited[city]=0;
		}
	}
	return ans;
 }
 
 int main()
 {
 	int n,cost[MAX][MAX],visited[MAX]={0},result;
 	printf("Enter Number of Cities: ");
 	scanf("%d",&n);
 	
 	printf("Enter the Cost Adjacency Matrix:\n");
 	for(int i=0;i<n;i++)
 	{
 		for(int j=0;j<n;j++)
 		{
 			scanf("%d",&cost[i][j]);
		 }
	 }
	visited[0]=1;           // Start from city 0
	
	result=tsp(cost,visited,0,n,1,0,0);
	printf("\nMinimum Cost to Complete TSP Tour: %d",result);
	return 0;
 }
