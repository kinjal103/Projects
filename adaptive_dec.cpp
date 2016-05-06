#include<iostream.h>
#include<string.h>
#include<fstream.h>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
 

struct node
{
	int value;
	node* next;
};

	void delete_start();
	void display();

void delete_start()
{
	node* cur=front;
	front=front->next;
	cur->next=NULL;
	delete cur;
	cur=NULL;
}

class stack
{
	int array[7];
	int top;
public:
	stack()
	{
		top=-1;
	}

	bool isempty()
	{
		if(top==-1)
			return true;
		else 
			return false;
	}

	bool isfull()
	{
		if(top==6)
			return true;
		else
			return false;
	}

	void push(int x)
	{
		if(!isfull())
			array[++top]=x;
		else
			cout<<"Array is full\n";
	}

	void pop(int &x)
	{
		if(!isempty())
			x=array[top--];
		else
			cout<<"Array is empty\n";
	}

	void getstacktop(int &x)
	{
		if(!isempty())
			x=array[top];
		else
			cout<<"Array is empty\n";
	}

	void insertbottom(int x)
	{
		stack T;
		int val;
		if(isempty())
			push(x);
		else
		{
			while(!isempty())
			{
				pop(val);
				T.push(val);
			}
			push(x);
			while(!T.isempty())
			{
				T.pop(val);
				push(val);
			}
		}
	}

	void display()
	{
		int temp=top;
		while(temp!=-1)
		{
			cout<<array[temp]<<"\n";
			temp--;
		}
		cout<<endl;
	}
};
struct node
{
	int freq;		
	char ch[MAX];	
	node* right;	
	node* left;		
};


char s[MAX];
char str[MAX];	
int freq[MAX];	
bool c[MAX];	
char string[2];	
stack stk;		
bool success;			
int sz=0;		
int diff;		
int code;

ifstream inputfile("code file.txt");				
ofstream output("source file.txt");				
ofstream out("compressed file.txt");				
ifstream in("compressed file.txt");				
ofstream final("input file.txt");		
ifstream bin("bin.txt");
ofstream bin("bin.txt");

void decomp()
{
	int x;
	char m;
	in>>m;
	while(!in.eof())
	{   
		x=int(m);
		{
			cout<<x<<endl;
			dec_to_bin(x);
		}
		in>>m;		
	}

	for(int i=0;i<diff;i++)
		binq.delete_start();
}

void d2b(int n)
{
	int count=0,x;
	stack stk;
	if(!stk.isempty())
	while(!stk.isempty())
		stk.pop(x);

	stk.push(n%2);
	count++;
	while(n/2!=0)
	{
		n=n/2;
		stk.push(n%2);
		count++;
	}
	
	int addzeros=7-(count%7);
	for(int i=0;i<addzeros;i++)
	{
		stk.push(0);
	}
	
	int val;
	while(!stk.isempty())
	{
		stk.pop(val);
		bin<<val;
	}
}


int main()
{
	default_freq_data();
	sort_nodes();

	cout<<"Compressing\n";

	char input;
		
	{
		while(inputfile)
		{
			
			input=inputfile.get();
			cout<<input<<"";
			string[0]=input; 
			string[1]='\0';
			encode();	
		}
	}

	inputfile.close();	
	output.close();		
	out.close();		
	cout<<"\n\n\tSuccessfully decompression done..\n\n";
	
	decomp();

return 0;

}
