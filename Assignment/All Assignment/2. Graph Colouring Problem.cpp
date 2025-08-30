#include<stdio.h>

 static int c=0;
 int g[100][100];
 static int count=0,m,n;
 int x[100];
 
 void next_value(int k)
 {
 	int j;
 	while(1)
 	{
 		x[k]=(x[k]+1)%(m+1);
 		if(x[k]==0)
 			return;
 		for(j=1;j<=n;j++)
 		{
 			if(g[k][j]==1 && x[k]==x[j])
 				break;
		 }
		if(j==n+1)
			return;
	 }
 }
 
 void graph_colouring(int k)
 {
 	int i;
 	while(1)
 	{
 		next_value(k);
 		if(x[k]==0)
 			return;
 		if(k==n)
 		{
		  c=1;
		  for(i=1;i<=n;i++)
		  {
		  	printf("%d\t",x[i]);
		  }
		  printf("\n");
		 }
		else
			graph_colouring(k+1);
	 }
 }
 
 int main()
 {
 	int i,j,temp;
 	printf("Enter the no. of Nodes: ");
	scanf("%d",&n);
	printf("Enter the number of colour to insert: ");
	scanf("%d",&m);
	printf("Create Adjacency Matrix if edges put 1 oterwise 0:\n");
	for(i=1;i<=n;i++)
	{
		x[i]=0;
		for(j=1;j<=n;j++)
		{
			if(i==j)
			{
				g[i][j]=0;
			}
			else
			{
				printf("%d->%d\t",i,j);
				scanf("%d",&temp);
				g[i][j]=temp;
			}
		}
	 }
	 
	 printf("\nAdjacency Matrix:\n");
	 for(i=1;i<=n;i++)
	 {
	 	for(j=1;j<=n;j++)
	 	{
	 		printf("%d  ",g[i][j]);
		 }
		 printf("\n");
	  } 
	 
	 printf("\nPossible Solutions are:\n");
	 for(int p=1;p<=n;p++)
	 {
	 	if(c==1)
	 		break;
	 	graph_colouring(1);
	 }
	 return 0;
 }
