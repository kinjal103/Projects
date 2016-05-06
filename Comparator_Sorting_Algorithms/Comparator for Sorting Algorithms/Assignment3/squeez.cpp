#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

using namespace std;

int main( int argc, char *argv[] )
{
	int fd, count, i, j;
	const int bufferSize = 1024;
	char buffer1[bufferSize], buffer2[bufferSize];

	if( argc != 2 )
		return -1;

	fd = open( argv[1], O_RDONLY );
	if( fd < 0 )
		return -2;

	while( (count = read( fd, buffer1, bufferSize-1 )) > 0 )
	{
		j = 0;
		for( i = 0; i < count; i++ )
		{
			if( buffer1[i] == ' ' )
			{
				if( i != 0 && buffer1[i-1] != ' ' )
					buffer2[j++] = buffer1[i];	
			}
			else
				buffer2[j++] = buffer1[i];
		}
		buffer2[j++] = '\0';
		cout<<buffer2;
	}

	close( fd );
	return 0;
}
