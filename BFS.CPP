#include<iostream.h>
#include<stdio.h>
#include<process.h>
#include<alloc.h>
#include<conio.h>
#include<string.h>

struct node
{
	int m[3][3];
	int pos[2];
	struct node *up;
	struct node *down;
	struct node *left;
	struct node *right;
	char ch[50];
}*root, *a;

int goal[3][3]={1,2,3,4,5,6,7,8,0};
int s=0, e=1, n=0;
int ipos[2];
int i,j;
node d[200];

void copy(node *a, node*b)
{
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			a->m[i][j]=b->m[i][j];
	}
	a->pos[0]=b->pos[0];
	a->pos[1]=b->pos[1];
	a->up=b->up;
	a->down=b->down;
	a->left=b->left;
	a->right=b->right;
}

void copy2d(int a[3][3],int b[3][3])
{
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			a[i][j]=b[i][j];
	}
}

void copy1d(int a[2],int b[2])
{
	a[0]=b[0];
	a[1]=b[1];
}

void disp(int a[3][3])
{
	cout<<"\n";
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			cout<<a[i][j]<<"\t";
		}
		cout<<"\n";
	}
}

void getdet()
{
	int initial[3][3];
	cout<<"Enter the initial state : \n";
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			cin>>initial[i][j];
			if(initial[i][j]==0)
			{
				ipos[0]=i;
				ipos[1]=j;
			}
		}
	}
	root=(node *)malloc(sizeof(struct node));
	copy2d(root->m,initial);
	copy1d(root->pos,ipos);
	strcpy(root->ch,"ROOT");
	root->up=NULL;
	root->down=NULL;
	root->left=NULL;
	root->right=NULL;
	d[n]=*root;
	n++;
	e=1;
	s=0;
	clrscr();
	disp(root->m);
	getch();
}

int tv,ti,tj;

node* change(int deci,node *a)
{
	node *t= new node;
	copy2d(t->m,a->m);
	copy1d(t->pos,a->pos);
	switch(deci)
	{
		case 1://go up
			if(t->pos[0]-1<0)
				return NULL;
			ti=t->pos[0]-1;
			tj=t->pos[1];
			break;
		case 2://go left
			if(t->pos[1]-1<0)
				return NULL;
			ti=t->pos[0];
			tj=t->pos[1]-1;
			break;
		case 3://go down
			if(t->pos[0]+1>2)
				return NULL;
			ti=t->pos[0]+1;
			tj=t->pos[1];
			break;
		case 4://go right
			if(t->pos[1]+1>2)
				return NULL;
			ti=t->pos[0];
			tj=t->pos[1]+1;
			break;
	}
	tv=t->m[ti][tj];
	t->m[ti][tj]=t->m[t->pos[0]][t->pos[1]];
	t->m[t->pos[0]][t->pos[1]]=tv;
	t->pos[0]=ti;
	t->pos[1]=tj;
	t->up=t->down=t->left=t->right=NULL;
	return t;
}

int k,alck=0;
int found=0;

int chkg(node *a)
{
	if(
	a->m[0][0]==1 &&
	a->m[0][1]==2 &&
	a->m[0][2]==3 &&
	a->m[1][0]==4 &&
	a->m[1][1]==5 &&
	a->m[1][2]==6 &&
	a->m[2][0]==7 &&
	a->m[2][1]==8 &&
	a->m[2][2]==0 )
		return 1;
	return 0;
}

int counter=0;
int aa[3][3];

int chk(node *t)
{
	for(i=0; i<=s; i++)
	{
		copy2d(aa,d[i].m);
		alck=0;
		for(j=0; j<3; j++)
		{
			for(k=0; k<3; k++)
			{
				if(t->m[j][k]==aa[j][k])
					alck++;
			}
		}
		if(alck==9)
			return 1;
	}
	return 0;
}

void bfs()
{
	int xx=0;
	char *up="-U", *down="-D", *left="-L", *right="-R";
	while(s!=e)
	{
		if(counter>100)
		{
			cout<<"Solution not possible";
			getch();
			exit(1);
		}
		*a=d[s];
		if(chkg(a))
		{
			found=1;
			cout<<"Sol found\n";
			disp(a->m);
			cout<<a->ch;
			getch();
			exit(1);
		}
		if((a->down=change(3,a)))
		{
		  //	if(chk(a->down)==0)
			{
				strcpy((a->down->ch),(a->ch));
				strcat((a->down->ch),down);
				n++;
				d[e]=*(a->down);
				e++;
			}
		}
		if(a->right=change(4,a))
		{
		  //	if(chk(a->right)==0)
			{
				strcpy((a->right->ch),(a->ch));
				strcat((a->right->ch),right);
				n++;
				d[e]=*(a->right);
				e++;
			}
		}
		if((a->up=change(1,a)))
		{
		    //	if(chk(a->up)==0)
			{
				strcpy((a->up->ch),(a->ch));
				strcat((a->up->ch),up);
				n++;
				d[e]=*(a->up);
				e++;
			}
		}
		if((a->left=change(2,a)))
		{
		//	if(chk(a->left)==0)
			{
				strcpy((a->left->ch),(a->ch));
				strcat((a->left->ch),left);
				n++;
				d[e]=*(a->left);
				e++;
			}
		}
		s++;
		counter++;
	}
}

void main()
{
	clrscr();
	getdet();
	cout<<"\n\n";
	bfs();
	getch();
    //	disp(state->m);
    //	getch();
  //	dfs();
}