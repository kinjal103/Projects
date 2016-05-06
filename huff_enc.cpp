#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

struct symbol
{
	char symb;
	int freq;
	char code[50];
	int top;
	struct symbol *left;
	struct symbol *right;
	struct symbol *parent;

	symbol()
	{
		left = NULL;
		right = NULL;
		parent = NULL;
		top = 0;
	}
}sym[256];

struct symbol *cur_roots[1024];
int tot_cur_roots=0;
int sym_cnt=0;

int check_existing(char ch)
{
	int i=0;
	for(i=0;i<sym_cnt;i++)
	{
		if(sym[i].symb==ch)
			return 0;
	}

	return 1;
}

int increment_freq(char ch)
{
	for(int i=0;i<sym_cnt;i++)
	{
		if(sym[i].symb==ch)
		{
			sym[i].freq++;
			return 1;
		}
	}

	return 0;
}

void display_symbols()
{
	for(int i=0;i<sym_cnt;i++)
		cout<<"Character: "<<sym[i].symb<<" Frequency: "<<sym[i].freq<<endl;
}

void sort_increasing()
{
	int i=0,j=0,min;
	struct symbol temp;
	for(i=0;i<(sym_cnt-1);i++)
	{
		min=i;
		for(j=i+1;j<sym_cnt;j++)
		{
			if(sym[j].freq<sym[min].freq)
				min=j;
		}
		if(i!=min)
		{
			temp=sym[i];
			sym[i]=sym[min];
			sym[min]=temp;
		}
	}
}

void make_tree()
{
	struct symbol *new_node = (struct symbol*)malloc(sizeof(struct symbol));
	int i=0;
	new_node->left = cur_roots[0];
	new_node->right = cur_roots[1];
	new_node->freq = cur_roots[0]->freq + cur_roots[1]->freq;
	cur_roots[0]->parent = new_node;
	cur_roots[1]->parent = new_node;
	for(i=2;i<tot_cur_roots;i++)
		cur_roots[i-2]=cur_roots[i];
	cur_roots[tot_cur_roots-2] = new_node;
//	cout<<"left"<<cur_roots[tot_cur_roots-2]->left->freq<<"right"<<cur_roots[tot_cur_roots-2]->right->freq<<endl;
	tot_cur_roots-=1;
}

void sort_cur_roots()
{
	int i=0,j=0,min;
	struct symbol temp;
	for(i=0;i<(tot_cur_roots-1);i++)
	{
		min=i;
		for(j=i+1;j<tot_cur_roots;j++)
		{
		if((cur_roots[j]->freq)<(cur_roots[min]->freq))
				min=j;
		}
		if(i!=min)
		{
			temp=*cur_roots[i];
			*cur_roots[i]=*cur_roots[min];
			*cur_roots[min]=temp;
		}
	}
}

void generate_code()
{
	int i=0,j=0;
	struct symbol *temp;
	char temp_s[1024];
	for(i=0;i<sym_cnt;i++)
	{
		temp = &sym[i];
		while(temp->parent!=NULL)
		{
			if(temp->parent->left==temp)
				sym[i].code[sym[i].top++]='0';
			else
				sym[i].code[sym[i].top++]='1';
			temp = temp->parent;
		}
		for(j=1;j<=sym[i].top;j++)
			temp_s[j-1]=sym[i].code[(sym[i].top)-j];
		for(j=0;j<sym[i].top;j++)
			sym[i].code[j]=temp_s[j];
		sym[i].code[sym[i].top]=0;
	}
}

void display_codes()
{
	int i=0;
	for(i=0;i<sym_cnt;i++)
	{
		cout<<"Character: "<<sym[i].symb<<" Code: "<<sym[i].code<<endl;
	}
}

int main(int argc, char* argv[])
{
	int i=0;
	if(argc!=3)
	{
		cout<<"Enter new filename(output file's name) as first parameter and file name to be compressed as second parameter";
		exit(1);
	}
	FILE *fptr1 = fopen(argv[1],"w"), *fptr2 = fopen(argv[2],"r");
	char ch;
	while((ch = getc(fptr2))!=EOF)
	{
		if(check_existing(ch))
		{
			sym[sym_cnt].symb=ch;
			sym[sym_cnt].freq=1;
			sym[sym_cnt].top=0;
			sym_cnt++;
		}
		else
			increment_freq(ch);
	}
	sort_increasing();
	display_symbols();
	tot_cur_roots = sym_cnt;
	for(i=0;i<sym_cnt;i++)
		cur_roots[i] = &sym[i];

	while(tot_cur_roots>1)
	{
		make_tree();
		sort_cur_roots();
		for(i=0;i<tot_cur_roots;i++)
			cout << cur_roots[i]->freq << endl;
		cout << endl;
	}
/*	cout << "Left most:"<< cur_roots[0]->right->left->parent->parent->freq<<endl;
	cout << "Right most:"<< cur_roots[0]->right->right->right->parent->parent->parent->freq<<endl;*/
	generate_code();
	display_codes();

	fclose(fptr1);
	fclose(fptr2);

	return 0;
}
