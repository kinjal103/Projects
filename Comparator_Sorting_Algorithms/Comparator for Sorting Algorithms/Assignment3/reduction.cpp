#include <iostream>
#include <fcntl.h>
#include <unistd.h>

using namespace std;

const int bufferSize = 1024, wordSize = 15;
char redundancy[][wordSize] = { "a", "an", "the", "of" };
int setSize = 4;

bool inRedundancy( char *word, int size )
{
	bool retVal = false;
	int i, j;
	for( i = 0; i < setSize; i++ )
	{
		j = 0;
		while( j < size )
		{
			if( redundancy[i][j] == word[j] )
				j++;
			else
				break;
		}
		if( j == size )
		{
			retVal = true;
			break;
		}
	}
	return retVal;
}

int main( int argc, char *argv[] )
{
	int fd, count, i, j, k, l;
	char buffer1[bufferSize], buffer2[bufferSize];
	char word[wordSize];

	if( argc != 2 )
		return -1;

	fd = open( argv[1], O_RDONLY );
	if( fd < 0 )
		return -2;

	while( (count = read( fd, buffer1, bufferSize-1 )) > 0 )
	{
		j = 0;
		k = 0;
		l = 0;
		for( i = 0; i < count; i++ )
		{
			if( buffer1[i] == ' ' || buffer1[i] == 10 || buffer1[i] == 13 )
			{
				if( !inRedundancy( word, k ) )
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
		cout<<buffer2;
	}

	close( fd );
	return 0;
}
