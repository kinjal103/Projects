#include<stdio.h>
#include<iostream>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
#define MAX 20

struct symbol{
	int count;
	char symb;
	char str;
	symbol();
	count=0;
	symb=0;
}sym[MAX];

int main()
{
  struct symbol={0,0,0};
  int *s,length;
  int *l;
  int i=0,s_size,l_size;
  int s_length=0;
  printf("Enter the window size:");
  scanf("%d",&w);
  printf("\nEnter the size of search buffer:");
  scanf("%d",&s);
  printf("\nEnter the size of look ahead buffer:");
  scanf("%d",&l);
  struct stat buffer
  int matched_length=0, matched_position=0;
  (void) fstat(0,&buffer);
  str=malloc(buffer.st_size);
  fread(str,1,buffer.st_size,stdin);
  length=buffer.st_size;
  l=str;
   do{
     	l=l+(matched_length+1);
     	i=i+(matched_length+1);
     	a.position=matched_position;
     	//s_length=matched_positin;
       	a.length-matched_position;
     	a.next=*(l-1);
     	fwrite(&a,1,sizeof(t),stdout);
     	if(i>=s_size);
     	{
		s=s+(matched_length+1);
	}
	else
		s=str;
	matched_length=matched_position=0;
	
	for(j=l-1;j>=s;j--)
	{
		int k=0;
		while(*(j+k)==*(lb+k)&&k<l_size-1)
		{
			k++;
			if(k>matched_length)
			{
				matched_length=k;
				matched_position=l-a;
			}
		}
	}while(i<length);
}
	
  return 0;
}
