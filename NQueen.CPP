#include<stdio.h>
#include<math.h>
#include<process.h>
#include<conio.h>
#include<stdlib.h>
void main()
{
int a,b,c;
int temp,extra;
clrscr();
printf("Please,Type value of N:");
scanf("%d",&a);
c=0;
temp=(3*a)/2;
extra=a/2;
for(b=0;b<extra;b++)
	{
	printf("Place to be filled will be %d\n",c+1);
	c=c+temp;
	printf("Place to be filled will be %d\n",c+1);
	c=c+5;
	}
getch();
}