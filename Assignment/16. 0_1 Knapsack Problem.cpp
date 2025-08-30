#include<stdio.h>

 int max(int a,int b)
 {
 	return (a>b)?a:b;
 }
 
 void Knapsack(int n,int weights[],int profits[],int capacity)
 {
 	int i,w;
 	int dp[100][100];
 	
 	for(i=0;i<=n;i++)
 	{
 		for(w=0;w<=capacity;w++)
 		{
 			if(i==0 || w==0)
 			{
 				dp[i][w]=0;
			 }
			else if(weights[i-1]<=w)
			{
				dp[i][w]=max(profits[i-1]+dp[i-1][w-weights[i-1]],dp[i-1][w]);
			}
			else
			{
				dp[i][w]=dp[i-1][w];
			}
		 }
	 }
 	
	printf("\nMaximum Profit: %d\n",dp[n][capacity]);
	printf("Items Included (Index Starts from 1): ");
	i=n;
	w=capacity;
	while(i>0 && w>0)
	{
		if(dp[i][w] != dp[i-1][w])
		{
			printf("Item %d  ",i);
			w=w-weights[i-1];
		}
		i--;
	}	
	printf("\n");
 }
 
 int main()
 {
 	int n,weights[100],profits[100],capacity,i;
 	printf("Enter the Number of Items: ");
 	scanf("%d",&n);
 	
 	printf("Enter the Weights of the Items:\n");
 	for(i=0;i<n;i++)
 	{
 		scanf("%d",&weights[i]);
	 }
	 
	printf("Enter the Profits of the Items:\n");
 	for(i=0;i<n;i++)
 	{
 		scanf("%d",&profits[i]);
	 }
	 
	printf("Enter the Capacity of the Knapsack: ");
	scanf("%d",&capacity);
	
 	Knapsack(n,weights,profits,capacity);
 	return 0;
 }
