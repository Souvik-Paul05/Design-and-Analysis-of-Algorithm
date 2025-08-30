#include<stdio.h>
#include<stdlib.h>
#define MAX 100

 int parent[MAX];
 int size[MAX];
 
 int find(int x)                 // Find the Root of a Set
 {
 	while(x !=parent[x])
 	{
 		x=parent[x];
	 }
	return x;
 }
 
 void Weighted_Union(int a,int b)
 {
 	int root_A=find(a);
 	int root_B=find(b);
 	
 	if(root_A==root_B)
 	{
 		printf("They are Already in the Set.\n");
 		return;
	 }
	 
	if(size[root_A]<size[root_B])
	{
		parent[root_A]=root_B;
		size[root_B] += size[root_A];
	}
	else
	{
		parent[root_B]=root_A;
		size[root_A] += size[root_B];
	}
	printf("Union Done Between %d and %d\n",a,b);
 }
 
 int main()
 {
 	int n;
 	printf("Enter Number of Elements: ");
 	scanf("%d",&n);
 	
 	for(int i=0;i<n;i++)
 	{
 		parent[i]=i;
 		size[i]=1;
	 }
	 
	int ch,a,b;
	while(1)
   {
   	printf("\nMENU:\n\n");
   	printf("1. Union.\n");
   	printf("2. Find.\n");
   	printf("3. Display Parents.\n");
   	printf("4. Exit.\n");
   printf("\nEnter your choice: ");
   scanf("%d",&ch);
   switch(ch)
   {
   	  	case 1:
   	  	 printf("Enter Two Elements to Union: ");
         scanf("%d%d",&a,&b);
         Weighted_Union(a,b);
         break;
        case 2:
        	printf("Enter Element to Find its Root: ");
        	scanf("%d",&a);
        	printf("Root of %d is: %d\n",a,find(a));
        	break;
        case 3:
        	printf("Element -> Parent:\n");
        	for(int i=0;i<n;i++)
        	{
        		printf("%d -> %d\n",i,parent[i]);
			}
        	break;
        case 4:
        	printf("\nExiting...\n");
        	exit(0);
        	break;
        default:
        	printf("Wrong Choice......");	
       }
    }
	return 0;
 }
