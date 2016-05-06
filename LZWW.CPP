#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<dos.h>
#include<stdlib.h>

struct diction
{
   int index;
   int length;

   char word[5];

}entry[25];


void main()
{
   clrscr();

   char str[40];
   char alp[10];
   int n;

   int dc=0;

   cout<<endl;

   cout<<"Initial Dictionary(MAX 7 CHAR):";
   for(int k=0;k<7;k++)
   {
       cin>>entry[k].word[0];
       entry[k].index=k+1;
       entry[k].length=1;
       dc++;
   }

   cout<<endl;
   cout<<"Enter the string:";
   gets(str);

   cout<<endl;

   int pt=0;
   char nxt;

   while(str[pt]!='\0')
   {
      int flag=0;
      int len=0;
      int count=0;
      int id=0;

      for(int i=dc-1;i>=0;i--)
      {

	  int temp=pt;
	  count=0;
	  int found=1;

	  for(int x=0;x<entry[i].length;x++)
	  {
	      if(str[temp+x]!=entry[i].word[x])
	      {
	      found--;
	      break;
	      }
	  }

	  if(found!=0)
	  {
	  count=entry[i].length;
	  if(len<count)
	  {
	  id=i;
	  len=count;
	  }
	  }

      }


      if(len>0)
      {   flag++;   }

      if(flag!=0)
      {
	  cout<<(id+1)<<" ";
	  entry[dc].index=dc+1;
	  entry[dc].length=len+1;

	 for(int y=0;y<len;y++)
	 {
	   entry[dc].word[y]=entry[id].word[y];

	 }
	   entry[dc].word[y]=str[pt+len];
	   dc++;


	    if(str[pt]!='\0')
	    {
	    pt+=len;
	    }
	    if(str[pt]!='\0')
	    {
      }

	    }

}
   cout<<endl<<endl<<"Dictionary"<<endl;
   cout<<"Index"<<"  "<<"Entry"<<endl;

    for(int d=0;d<dc-1;d++)
    {

       cout<<d+1<<"\t";
       for(int p=0;p<entry[d].length;p++)
       {

	  cout<<entry[d].word[p];
       }

       cout<<endl;
    }


   getch();
}

/*	Output

Initial Dictionary:helowrd

Enter the string:helloworld

1 2 3 3 4 5 4 6 3 7

Dictionary
Index  Entry
1       h
2       e
3       l
4       o
5       w
6       r
7       d
8       he
9       el
10      ll
11      lo
12      ow
13      wo
14      or
15      rl
16      ld               */

                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                

