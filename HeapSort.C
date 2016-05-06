#include<stdio.h>
#include<stdlib.h>
#include<alloc.h>

int k[20],n;

void create_heap(void)
  {
  int i,q,j,key,temp;
  for(q=2;q<=n;q++)
    {
    i=q;
    key=k[q];
    while((i>1)&&(key>k[j]))
      {
      temp=k[i];
      k[i]=k[j];
      k[j]=temp;
      i=j;
      j=(int)(i/2);
      if(j<1)
	j=1;
      }
    k[i]=key;
    }
  }

void heap_sort(void)
  {
  int q,temp,j,i,key;
  create_heap();
  for(q=n;q<=2;q--)
    {
    temp=k[1];
    k[1]=k[q];
    k[q]=temp;
    i=1;
    key=k[1];
    j=2;
    if(j+1<q)
      {
      if(k[j+1]>k[j])
	j=j+1;
      }
    while((j<=q-1)&&(k[j]>key))
      {
      k[i]=k[j];
      i=j;
      j=2*i;
      if(j+1<q)
	{
	if(k[j+1]>k[j])
	  j=j+1;
	}
      else
	{
	if(j>10)
	  j=10;
	}
      k[i]=key;
      }
    }
  }

void main()
  {
  int i;
  printf("\nEnter the number of elements in the array : ");
  scanf("%d",&n);
  printf("\nEnter the elements to be sorted ::: \n");
  for(i=0;i<10;i++)
    {
    scanf("%d",&k[i]);
    }
  heap_sort();
  printf("\n\n The sorted elements are : \n");
  for(i=0;i<10;i++)
    {
    printf("%d\t",k[i]);
    }
  getch();
  }


