#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define MAX 20

 int board[MAX];
 
 void printSolution(int n)           // Function to print the board
 {
 	for(int i=0;i<n;i++)
 	{
 		for(int j=0;j<n;j++)
 		{
 			if(board[i]==j)
 				printf("Q");
 			else
 				printf(".");
		 }
		printf("\n");
	 }
	printf("\n");
 }
 
 bool isSafe(int row,int col)           // Function to check if the queens can be placed or not
 {
 	for(int i=0;i<row;i++)
 	{
 		if(board[i]==col || abs(board[i]-col)== abs(i-row))
 		{
 			return false;
		 }
	 }
	return true;
 }
 
 void solve_NQueens(int row,int n)             // Backtracking
 {
 	if(row==n)
 	{
 		printSolution(n);
 		return;
	 }
	for(int col=0;col<n;col++)
	{
		if(isSafe(row,col))
		{
			board[row]=col;
			solve_NQueens(row+1,n);
		}
	}
 }
 
 int main()
 {
 	int n;
 	printf("Enter the Number of Queens(N): ");
 	scanf("%d",&n);
 	if(n<1 || n>MAX)
 	{
 		printf("\nINVALID INPUT!...Enter the input between 1 to %d",MAX);
 		return 1;
	 }
	printf("\nSolutions for %d-Queens Problem:\n\n",n);
	solve_NQueens(0,n);
	return 0;
 }
