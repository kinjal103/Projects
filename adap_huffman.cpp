#include<iostream.h>
#include<string.h>
#include<fstream.h>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>

const int MAX=97; 

struct queue_node
{
	int value;
	queue_node* next;
};

class queue
{
	node* front;
	node* rear;
public:
	queue();
	queue(const queue&);
	~queue();
	bool isempty();
	void enqueue(int,bool&);
	void dequeue(int&,bool&);
	void getfrontitem(int&,bool&);
	void delete_start();
	void display();
};


queue::queue()
{
	front=NULL;
	rear=NULL;
}

queue::queue(const queue& a)
{
	bool success;
	front=NULL;

	node* cur=a.front;
	while(cur!=NULL)
	{
		enqueue(cur->value,success);
		cur=cur->next;
	}
}

queue::~queue()
{
	int x;
	bool success;
	while(!isempty())
		dequeue(x,success);
}

bool queue::isempty()
{
	return(front==NULL);
}

void queue::enqueue(int x,bool& s)
{
	node* p=new qnode;
	s=(p!=NULL);
	if(s)
	{
		p->value=x;
		p->next=NULL;
		if(isempty())
			front=rear=p;
		else
		{
			rear->next=p;
			rear=p;
		}
	}
}

void queue::dequeue(int& x,bool& s)
{
	s=!isempty();
	if(s)
	{
		node* p=front;
		x=p->value;
		front=front->next;
		if(front==NULL)
			rear=NULL;

		p->next=NULL;
		delete p;
	}
}

void queue::getfrontitem(int& x,bool& s)
{
	s=!isempty();
	if(s)
		x=front->value;
}

void queue::delete_start()
{
	node* cur=front;
	front=front->next;
	cur->next=NULL;
	delete cur;
	cur=NULL;
}

void queue::display()
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
queue q;		
int sz=0;		
int diff;		
int code;

ifstream inputfile("input file.txt");				
ofstream output("encoded file.txt");				
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


void point_nodes()
{
	for(int i=0;i<MAX;i++)
	{
		str[0]=s[i];
		str[1]='\0';
		fixed[i]=create_nodes(str,freq[i]);
		a[i]=fixed[i];		
	}
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



void Assign_Code(node* tree, bool c[], int n)
{
	if((tree->left==NULL)&&(tree->right==NULL))
	{
		if((strcmp(tree->ch,string))==0)
		{
			for (int i=0;i<n;i++)
			{	
				output<<c[i];			
				q.enqueue(c[i],success);
				sz++;						}
		}
	}
	else
	{
		c[n]=1;					
		n++;
		Assign_Code(tree->left,c,n);
		c[n-1] = 0;						
		Assign_Code(tree->right,c,n);
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
queue binq;
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
		binq.enqueue(val,success);
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
		binq.delete_start();

	while(!binq.isempty())
	{
		int binary;
		binq.dequeue(binary,success);
	
		bin<<binary;
		
	}
}

void decimaltobinary(int n)
{
	int count=0,x;
	stack d2b;
	if(!d2b.isempty())
	while(!d2b.isempty())
		d2b.pop(x);

	d2b.push(n%2);
	count++;
	while(n/2!=0)
	{
		n=n/2;
		d2b.push(n%2);
		count++;
	}
	
	int addzeros=7-(count%7);
	for(int i=0;i<addzeros;i++)
	{
		d2b.push(0);
	}
	
	int val;
	while(!d2b.isempty())
	{
		d2b.pop(val);
		bin<<val;
	}
}
void decompress()
{
	int x;
	char m;
	  in>>m;
		while(!in.eof())
		{   x=int(m);
		decimaltobinary(x);
		
			in>>m;
			
		}
}



int main()
{
	default_freq_data();
	point_nodes();

	
	cout<<"Compressing .....\n";

	
	
		
	char input;
		
	if(!input||!output||!out) 
	{
		cerr<<"Error: can't open file.\n";		
		return 1;
	}
	else
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
	cout<<"\n\n\t The Compression has been Completed Successfully \n\n";
	decomp();

in.close();
final.close();
bin.close();
return 0;

}

