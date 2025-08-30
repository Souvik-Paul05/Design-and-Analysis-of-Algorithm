#include<stdio.h>
#include<math.h>
 
 int x[100];
 
 int place(int k, int i)
 {
 	for(int j=0;j<k;j++)
 	{
 		if(x[j]==i || (abs(x[j]-i)==abs(j-k)))
 		{
 			return 0;
		 }
	 }
	return 1;
 }
 
 void NQueens(int k,int n)
 {
 	for(int i=1;i<=n;i++)
 	{
 		if(place(k,i))
 		{
 			x[k]=i;
 			if(k==n-1)
 			{
 				for(int j=0;j<n;j++)
 				{
 					printf("%d ",x[j]);
				 }
				printf("\n");
			 }
			else
			{
				NQueens(k+1,n);
			}
		 }
	 }
 }
 
 int main()
 {
 	int n;
 	printf("Enter the number of queens: ");
 	scanf("%d",&n);
 	NQueens(0,n);
 	return 0;
 }
