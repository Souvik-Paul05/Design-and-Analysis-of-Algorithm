#include<stdio.h>
 int main()
 {
 	float weight[100],profit[100],capacity;
 	float ratio[100],temp,total_profit;
 	int i,j,n;
 	printf("Enter the number of items: ");
 	scanf("%d",&n);
 	for(i=0;i<n;i++)
 	{
 		printf("Enter Weight and Profit of item[%d]: ",i+1);
 		scanf("%f%f",&weight[i],&profit[i]);
	 }
 	printf("Enter the Knapsack Capacity: ");
 	scanf("%f",&capacity); 
	for(i=0;i<n;i++)
	{
		ratio[i]=profit[i]/weight[i];
	}
	
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(ratio[i]<ratio[j])
			{
				temp=ratio[j];
				ratio[j]=ratio[i];
				ratio[i]=temp;
				
				temp=weight[j];
				weight[j]=weight[i];
				weight[i]=temp;
				
				temp=profit[j];
				profit[j]=profit[i];
				profit[i]=temp;
			}
		}
	}
	printf("\nBy using Fractional Knapsack Algorithm using Greedy Method:");
	for(i=0;i<n;i++)
	{
		if(weight[i]>capacity)
			break;
		else
		{
			total_profit=total_profit+profit[i];
			capacity=capacity-weight[i];
		}
	}
	if(i<n)
	{
		total_profit=total_profit+(ratio[i]*capacity);
	}
	printf("\nThe Maximum Profit is: %.2f",total_profit);
	return 0;
 }
