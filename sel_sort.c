#include<stdio.h>

void main()
  {
  int pass,min_index,n,i,arr[10000],temp;
  printf("Enter the number of elements : ");
  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
    arr[i]=rand()%n;
    }

  printf("\nThe elements in the original array are : \n");
  for(i=0;i<n;i++)
    {
    printf("%d\t",arr[i]);
    }


  /* selection sort */

  for(pass=0;pass<n-1;pass++)
    {
    min_index=pass;
    for(i=pass+1;i<n;i++)
      {
      if(arr[i]<arr[min_index])
	min_index=i;
      }
    if(min_index!=pass)
      {
      temp=arr[pass];
      arr[pass]=arr[min_index];
      arr[min_index]=temp;
      }
    }

  printf("\nThe elements in the sorted array are : \n");
  for(i=0;i<n;i++)
    {
    printf("%d\t",arr[i]);
    }

  }
