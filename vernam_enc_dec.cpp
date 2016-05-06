#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <iostream>

#define inc(X) (X+1)%len

using namespace std;

char key[1024];
int count, len;

char encrypt(char ch)
{
	char en = (ch^key[count]);
	inc(count);
	return en;
}

int main()
{
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
		strcat(new_path,".van");
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
	while((ch = getc(fin))!=EOF)
		putc(encrypt(ch),fout);
	fclose(fin);
	fclose(fout);
	cout << "Completed...";
	getch();

	return 0;
}