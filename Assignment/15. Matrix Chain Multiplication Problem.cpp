#include<stdio.h>
#include<limits.h>

 void Optimal_Parenthesization(int s[][100],int i,int j)
 {
 	if(i==j)
 	{
 		printf("A%d",i);
	 }
	else
	{
		printf("(");
		Optimal_Parenthesization(s,i,s[i][j]);
		Optimal_Parenthesization(s,s[i][j]+1,j);
		printf(")");
	}
 }
 
 void matrix_chain_order(int p[],int n)
 {
 	int m[100][100];                        // Store Minimum Number of Multiplication Needed
 	int s[100][100];                        // Store the Index of the matrix
 	
 	for(int i=1;i<n;i++)
 	{
 		m[i][i]=0;
	 }
	 
	for(int L=2;L<n;L++)                // L is the Chain Length
	{
		for(int i=1;i<=n-L;i++)
		{
			int j=i+L-1;
			m[i][j]=INT_MAX;
			for(int k=i;k<j;k++)
			{
				int q=m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
				if(q<m[i][j])
				{
					m[i][j]=q;
					s[i][j]=k;
				}
			}
		}
	}
	
	printf("\nMinimum Number of Multiplication Needed is %d\n",m[1][n-1]);
	printf("Optimal Parenthesization: ");
	Optimal_Parenthesization(s,1,n-1);
	printf("\n");
 }
 
 int main()
 {
 	int n;
 	printf("Enter the Number of Matrix: ");
 	scanf("%d",&n);
 	
 	int p[n+1];
 	printf("Enter Dimensions (p[0] to p[%d]):\n",n);
 	for(int i=0;i<=n;i++)
 	{
 		scanf("%d",&p[i]);
	 }
	
	matrix_chain_order(p,n+1);
	return 0;
 }
