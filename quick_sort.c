#include<stdio.h>
#include<stdlib.h>
int main()
  {
  int temp,max,arr[11],n,pass,i,l,r;
  n=10;
   for(i=0;i<n;i++)
    {
    arr[i]=rand()%100;
    }
    printf("The elements in the original array are:");
    printf("namrata");
    for(i=0;i<n;i++)
    {
    printf("%d\t",arr[i]);
    }


  max=arr[0];
  for(i=0;i<n;i++)
    {
    if(max<arr[i])
      max=arr[i];
    }
  arr[n]=max+1;
  
st :  for(pass=0;pass<n;)
    {
    for(l=pass+1,r=n;;)
      {
      while(arr[pass]<arr[l])
        l++;
      while(arr[pass]>arr[r])
        r--;
      if(l<r)
        {
        temp=arr[l];
        arr[l]=arr[r];
        arr[r]=temp;
        }
      else
        {
        pass++;
        goto st;
        }
      }
    }

  printf("\nThe elements of the sorted array are :\n");
  for(i=0;i<n;i++)
    {
    printf("%d\t",arr[i]);
    }
    return 0;
  }
