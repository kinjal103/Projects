#include<stdio.h>
#include<stdlib.h>
int s,arr[50],freq;
int part1[25],part2[25];
void pigeonhole_sort()
{
   	int hole[1000],i,a,x,max,flag=0;
   	for(i=0;i<1000;i++)
   	{
   		hole[i]=0;
   	}
   	
   	for(i=0;i<s;i++)
   	{
   		a=arr[i];
   		hole[a]++;
   	}
   	
   	x=0;
   	for(i=999;i>=0;i--)
   	{
   	if(hole[i]>(s/2))
   		{
   		printf("\nThe majority element is %d\n",i);
   	   	flag=1;
   	   	}
   	   		
   		while(hole[i]>0)
   		{
			arr[x]=i;
			x++;
			hole[i]--;
		}
	}   		 			
   	if(flag==0)
   	printf("\nThe given array has no majority element.\n");	
}


int sumarr(int a[50],int size)
{
	int i,sum=0;
	for(i=0;i<size;i++)
	sum=sum+a[i];
	
	return sum;
}

int main()
{
int i,sum=0,j,x,sum1,sum2;
printf("\nEnter the size of the array : ");
scanf("%d",&s);
printf("\nEnter the elements of the array : ");
for(i=0;i<s;i++)
{
	scanf("%d",&arr[i]);
	sum=sum+arr[i];
}
sum=sum/2;
pigeonhole_sort();

	part1[0]=arr[0];
	arr[0]=0;
	x=1;
	for(i=1;i<s;i++)                  
	{
	                                  
	if(sumarr(part1,x)<=sum)             
	                                    
	  {                                 
		if((sumarr(part1,x+1)+arr[i])<=sum)
		{
		part1[x]=arr[i];
		arr[i]=0;
		x++;
		}
					
	  }
	  else
	  {
	  	break;
	  }
	  
	
	}
	j=0;
	for(i=0;i<s;i++)
	{
		if(arr[i]!=0)
		{
			part2[j]=arr[i];
			j++;
		}
	}
sum1=sumarr(part1,x);
sum2=sumarr(part2,j);	
printf("\n\n");
for(i=0;i<x;i++)
{
	printf(" %d ",part1[i]);
}
printf("\nSum of first part is %d \n ",sum1);
for(i=0;i<j;i++)
{
	printf("%d ",part2[i]);
}
printf("\nSum of second part is %d",sum2);
if(sum1>sum2)
printf("\n\nDifference between both the sums is %d. \n",sum1-sum2);
else
printf("\n\nDifference between both the sums is %d. \n",sum2-sum1);
	return 0;
}

/*
OUTPUT :::

Enter the size of the array : 15

 Enter the elements of the array ::: 
1
2
2
2
6
2
8
2
1
8
2
2
9
2
2

The majority element is 2


 9  8  8 
sumarr of first subset is 25. 
6 2 2 2 2 2 2 2 2 2 1 1 
sumarr of second subset is 26.

Difference between both the sumarrs is 1. 
*/
