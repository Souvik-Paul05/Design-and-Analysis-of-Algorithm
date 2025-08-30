#include<stdio.h>
#include<stdlib.h>

 void swap(int* a,int* b)
 {
 	int temp=*a;
 	*a=*b;
 	*b=temp;
 }
 int partition(int arr[],int low,int high)
 {
 	int pivot=arr[low];
 	int i=low;
 	int j=high;
 	while(i<j)
 	{
 		while(arr[i]<=pivot && i<=high-1)
 		{
 			i++;
		 }
		while(arr[j]>pivot && j>=low+1)
		{
			j--;
		}
		if(i<j)
		{
			swap(&arr[i],&arr[j]);
		}
	 }
	swap(&arr[low],&arr[j]);
	return j;
 }
 
 void quicksort(int arr[],int low,int high)
 {
 	if(low<high)
 	{
 		int partition_index=partition(arr,low,high);
 		quicksort(arr,low,partition_index-1);
 		quicksort(arr,partition_index+1,high);
	 }
 }
 
 int main()
 {
 	int arr[100],n,i;
 	printf("Enter the Array Size: ");
 	scanf("%d",&n);
 	printf("Enter the Array Elements:\n");
 	for(i=0;i<n;i++)
 	{
 		scanf("%d",&arr[i]);
	 }
 	quicksort(arr,0,n-1);
 	printf("By Quick Sort, The Sorted Array:\n");
 	for(i=0;i<n;i++)
 	{
 		printf("%d  ",arr[i]);
	 }
	 return 0;
 }
