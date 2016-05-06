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

void display()
{
	node* cur=front;
	while(cur!=NULL)
	{
		cout<<cur->value<<"  ";
		cur=cur->next;
	}
	cout<<endl<<endl;
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
			cout<<array[temp]<<endl;
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
stack st;		
bool success;			
int sz=0;		
int diff;		
int code;

ifstream inputfile("source file.txt");				
ofstream output("code file.txt");				
ofstream out("compressed file.txt");				
ifstream in("compressed file.txt");				
ofstream final("output file.txt");		
ifstream bi("bin.txt");
ofstream bin("bin.txt");

node* fixed[MAX];	
node* a[MAX];		
void default_freq_data()
{
	int index=0;
	for(int ref=0;ref<127;ref++)
	{
		if((ref==9)||(ref==10)||(ref>=32))	
		{
			s[index]=char(ref);		
			freq[index]=1;			
			index++;				
		}
	}
}

node* create_nodes(char a[], int x)
{
	node* ptr=new node;
	ptr->freq = x;
	strcpy(ptr->ch,a);
	ptr->right = ptr->left = NULL;
	return ptr;
}


void sort_nodes(node* a[], int n)
{
	node* temp;		
	for (int i=0;i<n-1;i++)
	{
		for (int j=i;j<n;j++)
		{
			if (a[i]->freq>a[j]->freq)
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}


void shift_nodes(node* a[], int n)
{
	for (int i=1;i<n-1;i++)
		a[i]=a[i+1];
}

void create_tree()
{
	int u=0;
	node* ptr;
	for(int n=MAX;n>1;n--)
	{
		sort_nodes(a,n);
		u=a[0]->freq+a[1]->freq;
		strcpy(str,a[0]->ch);
		strcat(str,a[1]->ch);
		ptr=create_nodes(str,u);
		ptr->right=a[1];
		ptr->left=a[0];
		a[0]=ptr;
		shift_nodes(a,n);
	}	
}

void encode()
{
	create_tree();
	Assign_Code(a[0],c,0);					
	for(int i=0;i<MAX;i++)
	{
		a[i]=fixed[i];						
		if((strcmp(a[i]->ch,string))==0)
			a[i]->freq++;					
	}
}

node* ptr;
void decode()
{
	if(code==1)
		ptr=ptr->left;
	else
		ptr=ptr->right;
	
	if((ptr->left==NULL)&&(ptr->right==NULL))
	{
		final<<ptr->ch;
		for(int i=0;i<MAX;i++)
		{
			a[i]=fixed[i];						
			if((strcmp(a[i]->ch,ptr->ch))==0)
				a[i]->freq++;					
		}
		create_tree();
		ptr=a[0];
	}
}

int bin_to_dec()
{
	int val,i=0,dec=0;
	while(!st.isempty())			
	{
		st.pop(val);
		dec=dec+int(pow(2,i)*val);
		i++;
	}
	return dec;
}

void convert_to_ASCII()
{	
	int d,x;
	char ch;

	for(int i=1;i<=sz;i=i+7)
	{
		while(!st.isfull())
		{
			q.dequeue(x,success);		
			st.push(x);
		}
		d=bin_to_dec();					
		cout<<d<<endl;
		ch=char(d);					
		out<<ch;	
	}
}
void compression()
{
	if((sz%7)==0)					
	convert_to_ASCII();

	else
	{
		diff=7-(sz%7);				
		for(int i=0;i<diff;i++)
		{
			st.push(0);				
			sz++;
		}
		convert_to_ASCII();
	}
}
stack stck;

void dec_to_bin(int n)
{
	int count=0;
	while(n!=0)
	{
		stck.push(n%2);
		n=n/2;
		count++;
	}
	if(count!=7)
	{
		for(int i=0;i<(7-count);i++)
			stck.push(0);
	}	
 	while(!stck.isempty())
	{
		int val;
		stck.pop(val);
	}
}

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
		stk.delete_start();
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
void decompress()
{
	int x;
	char m;
	  in>>m;
		while(!in.eof())
		{  
			 x=int(m);
			d2b(x);
			in>>m;
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

	compression();		

	inputfile.close();	
	output.close();		
	out.close();		
	cout<<"\n\n\tSuccessfully compression done..\n\n";
	decomp();

in.close();
final.close();
bin.close();
return 0;

}
