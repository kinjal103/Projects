#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<process.h>
int cb[8][8];
void put_values();
void block_row(int x);
void block_column(int y);
void block_diagonal(int x,int y);

void main()
{
int i,j;
clrscr();
flushall;

	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
			{
			cb[i][j]=2;
			}
		printf("\n");
	}
printf("\n\n\tBegin:\n\n\t");
put_values();
printf("\n\n\tDisplay:\n\n");
getch();

	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
			{
				printf("%3d",cb[i][j]);
			}
		printf("\n");
	}

getch();

}

void put_values()
{
randomize();
float temp;
int i,j,k,extra;
a:
temp=random(8);
i=temp+1;
for(extra=0;extra<8;extra++)
	{

	if(cb[extra][i]==0)
		{
		goto a;
}
		cb[i][k]=1;
		block_row(i);
		block_column(k);
		block_diagonal(i,k);
	}
}

void block_row(int x)
{
int i;
for(i=0;i<8;i++)
	{
	if(cb[x][i]==2)
		{
		cb[x][i]=0;
		}
	}
}


void block_column(int y)
{
int i;
for(i=0;i<8;i++)
	{
	if(cb[i][y]==2)
		{
		cb[i][y]=0;
		}
	}
}
void block_diagonal(int x,int y)
{
int i,j;
int temp;
if(x<y)
	{
	for(i=y;i>0;i--)
		{
		cb[x-i+1][y-i+1]=0;
		}
	temp=8-y;
	for(i=temp;i>0;i--)
		{
		cb[x+i][y+i]=0;
		}
	}

else if(x<y)
	{
	for(i=x;i>0;i--)
		{
		cb[x-i][y-i]=0;
		}
	temp=8-x;
	for(i=temp;i>0;i--)
		{
		cb[x+i][y+i]=0;
		}
	}

else if(x==y)
	{
	for(i=x;i>0;i--)
		{
		cb[x-i][y-i]=0;
		}
	temp=8-x;
	for(i=temp;i>0;i--)
		{
		cb[x+i][y+i]=0;
		}
	}

else
	{
	printf("\n\n\tError\n");
	getch();
	exit(1);
	}
}