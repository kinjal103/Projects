#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <iostream>

#define inc(X) (X+1)%len

using namespace std;

char key[1024];
int count, len;
char table[256][256];

char encrypt(char ch)
{
	char en = table[(int)ch][(int)key[count]];
	inc(count);
	return en;
}

char decrypt(char ch)
{
	int i=0;
	for(i=0;i<256;i++)
	{
		if(table[(int)key[count]][i]==ch)
			return (char)i;
	}
	return -1;
}

void initialize_table()
{
	int i=0, j=0;
	for(i=0;i<256;i++)
	{
		for(j=0;j<256;j++)
			table[i][j] = (char)((j+i)%256);
	}
}

int main()
{
	initialize_table();
	cout << "Enter path of file: ";
	char path[1024], new_path[1024];
	cin >> path;
	cout << "Enter key:";
	cin >> key;
	int choice, i;
Y:	cout << "1) Encrypt" << endl;
	cout << "2) Decrypt" << endl;
	cout << "Enter choice:";
	cin >> choice;
	len = strlen(key);
	count = 0;
	if(choice == 1)
	{
		strcpy(new_path,path);
		strcat(new_path,".vig");
	}
	else if(choice == 2)
	{
		strcpy(new_path,path);
		strcat(new_path,".dec");
	}
	else
	{
		cout << "Enter proper choice!";
		goto Y;
	}
	FILE *fin, *fout;
	fin = fopen(path,"r");
	fout = fopen(new_path,"w");
	char ch;
	if(choice == 1)
	{
		while((ch = getc(fin))!=EOF)
			putc(encrypt(ch),fout);
	}
	else
	{
		while((ch = getc(fin))!=EOF)
			putc(decrypt(ch),fout);
	}
	fclose(fin);
	fclose(fout);
	cout << "Completed...";
	getch();

	return 0;
}