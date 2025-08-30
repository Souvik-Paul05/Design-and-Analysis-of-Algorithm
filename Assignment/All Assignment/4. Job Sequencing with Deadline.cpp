#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

 typedef struct
 {
 	char id[10];
 	int deadline;
 	int profit;
 } Job;
 
 int compare(const void* a,const void* b)       // descending by Profit
 {
 	Job* job1= (Job*)a;
 	Job* job2= (Job*)b;
 	return job2->profit - job1->profit;
 }
 
 int find_Max_Deadline(Job jobs[],int n)
 {
 	int max=jobs[0].deadline;
 	for(int i=1;i<n;i++)
 	{
 		if(jobs[i].deadline>max)
 			max= jobs[i].deadline;
	 }
	return max;
 }
 
 void job_sequencing(Job jobs[],int n)
 {
 	qsort(jobs,n,sizeof(Job),compare);
 	int maxDeadline= find_Max_Deadline(jobs,n);
 	char result[MAX][5];                            // store job id
 	int slot[MAX];                                  // track for free or occupied slots
 	for(int i=0;i<maxDeadline;i++)
 	{
 		slot[i]=0;
	 }
	int total_profit = 0;
	
	for(int i=0;i<n;i++)
	{
		for(int j=jobs[i].deadline-1;j>=0;j--)
		{
			if(slot[j]==0)
			{
				slot[j]=1;
				strcpy(result[j],jobs[i].id);
				total_profit= total_profit + jobs[i].profit;
				break;
			}
		}
	}
	printf("\nSchedule Jobs: ");
	for(int i=0;i<maxDeadline;i++)
	{
		if(slot[i])
		{
			printf("%s ",result[i]);
		}
	}
	printf("\nTotal Profit: %d\n",total_profit);
 }
 
 int main()
 {
 	int n;
 	Job jobs[MAX];
 	printf("Enter the number of jobs: ");
 	scanf("%d",&n);
 	for(int i=0;i<n;i++)
 	{
 		printf("Enter Job ID, Deadline, Profit for job %d: ",i+1);
 		scanf("%s%d%d",&jobs[i].id,&jobs[i].deadline,&jobs[i].profit);
	 }
	job_sequencing(jobs,n);
	return 0;
 }
