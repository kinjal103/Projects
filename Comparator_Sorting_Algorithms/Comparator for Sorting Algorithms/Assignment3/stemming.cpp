#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

using namespace std;

const int bufferSize = 1024, wordSize = 50;

struct rootWord
{
	char w[wordSize];
	int size;
	rootWord *next;
};
rootWord *head = NULL;

void insertRootWord( char *word, int length )
{
	word[length] = '\0';
	rootWord *NEW = new rootWord;
	strcpy( NEW->w, word );
	NEW->size = length;
	NEW->next = NULL;
	
	if( head == NULL )
		head = NEW;
	else
	{
		rootWord *temp = head;
		while( temp->next != NULL )
			temp = temp->next;
		temp->next = NEW;
	}
}

int findRootSize( char *word, int length )
{
	word[length] = '\0';
	rootWord *temp = head;
	char *pos;
	while( temp != NULL )
	{
		if( (pos = strstr( word, temp->w )) != NULL )
		{
			if( pos == word )
				return temp->size;
		}
		if( (pos = strstr( temp->w, word )) != NULL )
		{
			if( pos == temp->w )
			{
				strcpy( temp->w, word );
				temp->size = length;
				return temp->size;
			}
		}
		temp = temp->next;
	}
	insertRootWord( word, length );
	return length;
}

int main( int argc, char *argv[] )
{
	int fd, count, i, j, k, l, pass;
	char buffer1[bufferSize], buffer2[bufferSize];
	char word[wordSize];

	if( argc != 2 )
		return -1;

	fd = open( argv[1], O_RDONLY );
	if( fd < 0 )
		return -2;
	
	for( pass = 0; pass < 2; pass ++ )
	{
		while( (count = read( fd, buffer1, bufferSize-1 )) > 0 )
		{
			j = 0;
			k = 0;
			l = 0;
			for( i = 0; i < count; i++ )
			{
				if( buffer1[i] == ' ' || buffer1[i] == 10 || buffer1[i] == 13 )
				{
					if( k = findRootSize( word, k ) )
					{
						l = 0;	
						while( --k >= 0 )
							buffer2[j++] = word[l++];
						buffer2[j++] = ' ';
					}
					k = 0;
				}
				else
					word[k++] = buffer1[i];
			}
			buffer2[j++] = '\0';
			if( pass == 1 )
				cout<<buffer2;
		}
		lseek( fd, 0l, 0 );
	}

	close( fd );
	return 0;
}
