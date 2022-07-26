/*To implement Insertion sort*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

float timedifference_msec(struct timeval t0,struct timeval t1)
{
	return(t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}

void display(int n,int arr[])
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d \t",arr[i]);
	}
}

void main()
{
	struct timeval t0;
	struct timeval t1;
	float elapsed;
	int n,i,j=0,key;
	
	printf("\n Enter number of elements ");
	scanf("%d",&n);
	int arr[n];
	
	for(i=0;i<n;i++)
	{
		arr[i]=rand()%100;
	}
	
	printf("\n The unsorted elements are :");
	display(n,arr);
	
	gettimeofday(&t0, NULL);
	
	for(i=1;i<n;i++)
	{
		key=arr[i];
		j=i-1;
		
		while(j>=0 && arr[j]>key)
		{
			arr[j+1]=arr[j];
			j=j-1;
		}
		arr[j+1]=key;
	}
	
	printf("\n The sorted elements are :");
	display(n,arr);
	
	gettimeofday(&t1, NULL);
	elapsed=timedifference_msec(t0,t1);
	printf("\nCode executed in %f milliseconds.\n", elapsed);
}
