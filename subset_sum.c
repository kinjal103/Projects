#include <stdio.h>
#include <stdlib.h>

int a[10];
int n;

int main()
{
  int i,count=0,sum,temp,j,temp1,k,flag1=0,flag2=0,flag3=0;
  printf("\nEnter the number of elements : ");
  scanf("%d",&n);
  printf("\nEnter the elements of the array : \n");
  for(i=0;i<n;i++)
    {
    scanf("%d",&a[i]);
    count+=a[i];
    }
  
  printf("\nEnter the sum : ");
  scanf("%d",&sum);
  
  if(count<sum)
    {
    printf("\nThe subset does not exist.\n");
    exit(0);  
    }
  
  for(i=0;i<n;i++)
    {
      for(j=i+1;j<n;j++)
      {
      if(a[i]>a[j])
        {
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
        }
      }
    }
  
  /*printf("\nThe elements of the sorted array are ::: \n");
  for(i=0;i<n;i++)
    {
    printf("%d\t",a[i]);
    }*/
  
  printf("\nThe subsets are ::: \n");
  for(i=0;i<n;i++)
    {
    if(a[i]==sum)
      {
      printf("{ %d }\n",a[i]);
      flag1=1;
      }
    }
    
  temp=sum;
  for(i=0;i<n;i++)
    {
    temp=sum-a[i];
    for(j=i+1;j<n;j++)
      {
      if(a[j]==temp)
        {
        printf("{ %d , %d }\n",a[i],a[j]);
        flag2=1;
        }
      }
    }
    
  temp=sum;
  for(i=0;i<n;i++)
    {
    temp=sum-a[i];
    for(j=i+1;j<n;j++)
      {
      temp1=temp-a[j];
      for(k=j+1;k<n;k++)
        {
        if(a[k]==temp1)
          {
          printf("{ %d , %d , %d }\n",a[i],a[j],a[k]);
          flag3=1;
          }
        }
      }
    }
    
    if(flag1==1)
      {
      printf("\nThe optimal solution is all the subsets with number of elements 1.\n");
      }
    else if(flag2==1)
      {
      printf("\nThe optimal solution is all the subsets with number of elements 2.\n");
      }
    else if(flag3==1)
      {
      printf("\nThe optimal solution is all the subsets with number of elements 3.\n");
      }
    
}

