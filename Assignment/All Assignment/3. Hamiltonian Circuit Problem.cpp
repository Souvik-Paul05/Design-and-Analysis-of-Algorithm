#include<stdio.h>
#include<stdbool.h>
#define MAX 20

 int graph[MAX][MAX];
 int path[MAX];
 int n;
 
 bool isSafe(int v,int pos)
 {
 	if(graph[path[pos-1]][v]==0)
 	{
 		return false;
	 }
	for(int i=0;i<pos;i++)
	{
		if(path[i]==v)
			return false;
	}
	return true;
 }
 
 bool hamiltonianCircuit(int pos)
 {
 	if(pos==n)
 	{
 		if(graph[path[pos-1]][path[0]]==1)
 		{
 			return true;
		 }
		else
		{
			return false;
		}
	}
	for(int v=1;v<n;v++)
	{
		if(isSafe(v,pos))
		{
		path[pos]=v;
		if(hamiltonianCircuit(pos+1)==true)
		{
			return true;
		}
		path[pos]=-1;
	}
  }
   return false;
 }
 
 void solve_Hamiltonian()         // Function to solve the hamiltonian circuit problem
 {
 	for(int i=0;i<n;i++)
 	{
 		path[i]=-1;
	 }
	path[0]=0;
	if(hamiltonianCircuit(1)==false)
	{
		printf("\nNo Hamiltonian Circuit Exists...\n");
		return;
	}
	printf("\nHamiltonian Circuit:\n");
	for(int i=0;i<n;i++)
	{
		printf("%d->",path[i]);
	}
	printf("%d\n",path[0]);
 }
 
 int main()
 {
 	printf("Enter Number of Vertices: ");
 	scanf("%d",&n);
 	printf("Enter the Adjacency Matrix:\n");
 	for(int i=0;i<n;i++)
 	{
 		for(int j=0;j<n;j++)
 		{
 			scanf("%d",&graph[i][j]);
		 }
	 }
	 solve_Hamiltonian();
	 return 0;
 }
