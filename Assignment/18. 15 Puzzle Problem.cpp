#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define SIZE 4
#define MAX 100

 typedef struct Node
 {
 	int puzzle[SIZE][SIZE];
 	int x,y;                        // Blank tile Position
 	int cost;                       
 	int level;                      // Depth
 	struct Node* parent;
 } Node;
 
 int goal[SIZE][SIZE]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,0};
 int dir_x[]={-1,1,0,0};
 int dir_y[]={0,0,-1,1};
 
 int is_solvable(int puzzle[SIZE][SIZE])
 {
 	int arr[SIZE*SIZE];
 	int index=0,blank_row;
 	
 	for(int i=0;i<SIZE;i++)
 	{
 		for(int j=0;j<SIZE;j++)
 		{
 			arr[index++]=puzzle[i][j];
 			if(puzzle[i][j]==0)
 			{
 				blank_row=SIZE-i;
			 }
		 }
	 }
	 
	int inv_count=0;
	for(int i=0;i<SIZE*SIZE;i++)
	{
		for(int j=i+1;j<SIZE*SIZE;j++)
		{
			if(arr[i] && arr[j] && arr[i]>arr[j])
			{
				inv_count++;
			}
		}
	}
	
	if((blank_row%2==0 && inv_count%2==1) || (blank_row%2==1 && inv_count%2==0))
	{
		return 1;
	}
	return 0;
 }
 
 void swap(int* a,int* b)
 {
 	int temp=*a;
 	*a=*b;
 	*b=temp;
 }
 
 void Copy_Puzzle(int source[SIZE][SIZE],int dest[SIZE][SIZE])         // Copy Puzzle State
 {
 	for(int i=0;i<SIZE;i++)
 	{
 		for(int j=0;j<SIZE;j++)
 		{
 			dest[i][j]=source[i][j];
		 }
	 }
 }
 
 int Calculate_Cost(int puzzle[SIZE][SIZE])
 {
 	int cost=0;
 	for(int i=0;i<SIZE;i++)
 	{
 		for(int j=0;j<SIZE;j++)
 		{
 			int val=puzzle[i][j];
 			if(val!=0)
 			{
 				int goal_x=(val-1)/SIZE;
 				int goal_y=(val-1)%SIZE;
 				cost+=abs(i-goal_x)+abs(j-goal_y);
			 }
		 }
	 }
	return cost;
 }
 
 Node* newnode(int puzzle[SIZE][SIZE],int x,int y,int new_x,int new_y,int level,Node* parent) 
 {
 	Node* node=(Node*)malloc(sizeof(Node));         // Create a New Node
 	Copy_Puzzle(puzzle,node->puzzle);
 	swap(&node->puzzle[x][y],&node->puzzle[new_x][new_y]);
 	node->cost=Calculate_Cost(node->puzzle);
 	node->level=level;
 	node->x=new_x;
 	node->y=new_y;
 	node->parent=parent;
 	return node;
 }
 
 Node* open[MAX];
 int opensize=0;
 
 void Add_to_open(Node* node)         // Add to Priority Queue
 {
 	int i=opensize++;
 	while(i>0 && open[i-1]->cost+open[i-1]->level > node->cost+node->level)
 	{
 		open[i]=open[i-1];
 		i--;
	 }
	open[i]=node;
 }
 
 void print_puzzle(int puzzle[SIZE][SIZE])
 {
 	for(int i=0;i<SIZE;i++)
 	{
 		for(int j=0;j<SIZE;j++)
 		{
 			if(puzzle[i][j]==0)
 			{
 				printf("X ");
			 }
			else
			{
				printf("%d ",puzzle[i][j]);
			}
		 }
		printf("\n");
	 }
 }
 
 void print_path(Node* node)
 {
 	if(node==NULL)
 		return;
 	print_path(node->parent);
 	printf("\nStep (Cost: %d, Level: %d):\n",node->cost,node->level);
 	print_puzzle(node->puzzle);
 }
 
 void solve(int puzzle[SIZE][SIZE],int x,int y)
 {
 	Node* start=newnode(puzzle,x,y,x,y,0,NULL);
 	Add_to_open(start);
 	
 	while(opensize>0)
 	{
 		Node* current=open[0];
 		for(int i=0;i<opensize-1;i++)
 		{
 			open[i]=open[i+1];
		 }
		opensize--;
		if(current->cost==0)
		{
			printf("\nSolved!\n");
			print_path(current);
			return;
		}
		for(int i=0;i<4;i++)
		{
			int new_x=current->x + dir_x[i];
			int new_y=current->y + dir_y[i];
			if(new_x>=0 && new_x<SIZE && new_y>=0 && new_y<SIZE)
			{
				Node* child = newnode(current->puzzle,current->x,current->y,new_x,new_y,current->level+1,current);
				Add_to_open(child);
			}
		}
	 }
	printf("No Solution Found.\n");
 }
 
 int main()
 {
 	int puzzle[SIZE][SIZE];
 	int x,y;
 	printf("Enter the 15-Puzzle (Use 0 for Blank Tile):\n");
 	for(int i=0;i<SIZE;i++)
 	{
 		for(int j=0;j<SIZE;j++)
 		{
 			scanf("%d",&puzzle[i][j]);
 			if(puzzle[i][j]==0)
 			{
 				x=i;
 				y=j;
			 }
		 }
	 }
	 
	if(!is_solvable(puzzle))
	{
		printf("\nThe Puzzle is not Solvable.\n");
		return 0;
	}
	solve(puzzle,x,y);
	return 0;
 }
 
 
 
 
