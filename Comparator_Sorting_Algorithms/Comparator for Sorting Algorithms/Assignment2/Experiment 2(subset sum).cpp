#include <iostream>
#include <stdlib.h>

using namespace std;

int *nextSubSet( int size, int reset )
{
	static int *pattern = new int[size], currentSize = 0;
	int i, j, temp; bool firstSubsetOfCurrentSize = false, lastSubsetOfCurrentSize = true;
	if( reset )
	{
		for( i = 0; i < size; i++ )
			pattern[i] = 0;
		currentSize = 0;
	}
	
	for( j = 0, i = size-1; j < currentSize; j++, i-- )
	{
		if( pattern[i] == 0 )
			lastSubsetOfCurrentSize = false;
	}
	if( lastSubsetOfCurrentSize )
	{
		for( i = 0; i < size; i++ )
			pattern[i] = 0;
		currentSize++;	
		firstSubsetOfCurrentSize = true;
		if( currentSize > size )
			return NULL;
	}
	if( firstSubsetOfCurrentSize )
	{
		for( i = 0; i < currentSize; i++ )
			pattern[i] = 1;
		firstSubsetOfCurrentSize = false;
	}
	else
	{
		temp = 0;
		for( i = size-1; i >= 0; i-- )
		{
			if( pattern[i] == 1 )
			{
				temp++;
				if( i + 1 == size || pattern[i+1] == 1 )
				{
					if( i + 1 != size )
						pattern[i+1] = 0;
					continue;
				}
				else
				{
					pattern[i] = 0;
					for( j = 1; j <= temp; j++ )
						pattern[i + j] = 1;
					break;
				}
			}
			else
				pattern[i+1] = 0;
		}
	}
	return pattern;
}

int *nextFixedSizeSubSet( int size, int reset, int subSetSize )
{
	static int *pattern = new int[size], currentSize = 0;
	int i, j, temp;
	bool lastSubsetOfCurrentSize = true;
	if( reset )
	{
		for( i = 0; i < size; i++ )
			pattern[i] = 0;
		currentSize = 0;
	}
	if( currentSize != subSetSize )
	{
		currentSize= subSetSize;
		for( i = 0; i < size; i++ )
			if( i < subSetSize )
				pattern[i] = 1;
			else
				pattern[i] = 0;
		return pattern;
	}

	for( j = 0, i = size-1; j < currentSize; j++, i-- )
	{
		if( pattern[i] == 0 )
			lastSubsetOfCurrentSize = false;
	}

	if( lastSubsetOfCurrentSize )
		return NULL;
	else
	{
		temp = 0;
		for( i = size-1; i >= 0; i-- )
		{
			if( pattern[i] == 1 )
			{
				temp++;
				if( i + 1 == size || pattern[i+1] == 1 )
				{
					if( i + 1 != size )
						pattern[i+1] = 0;
					continue;
				}
				else
				{
					pattern[i] = 0;
					for( j = 1; j <= temp; j++ )
						pattern[i + j] = 1;
					break;
				}
			}
			else
				pattern[i+1] = 0;
		}
		return pattern;
	}
}

void clear( int *vector, int size )
{
	int i;
	for( i = 0; i < size; i++ )
		vector[i] = 0;
}

int patternSum( int *vector, int *pattern, int size )
{
	int i, sum = 0;
	for( i = 0; i < size; i++ )
	{
		if( pattern[i] == 1 )
			sum += vector[i];
	}
	return sum;
}

void patternCopy( int *tempVector, int *vector, int *pattern, int *flags, int *tempIndex, int size )
{
	int i;
	for( i = 0; i < size; i++ )
	{
		if( pattern[i] == 1 && flags[i] != 1 )
		{
			flags[i] = 1;
			tempVector[(*tempIndex)++] = vector[i];
		}
	}
}

void patternPrint( int *vector, int *pattern, int size )
{
	int i;
	cout<<"[ ";
	for( i = 0; i < size; i++ )
	{
		if( pattern[i] == 1 )
			cout<<vector[i]<<" ";
	}
	cout<<"]"<<endl;
}

void copy( int *vector, int *tempVector, int size )
{
	int i;
	for( i = 0; i < size; i++ )
		vector[i] = tempVector[i];
}

void printVector( int *vector, int size )
{
	int i;
	cout<<"Vector: ";
	for( i = 0; i < size; i++ )
		cout<<vector[i]<<" ";
	cout<<endl;
}

void subSetSum( int *vector, int size, int targetSum )
{
	int subSetSize, sum = 0;
	int *pattern, *tempVector = new int[size], *flags = new int[size], tempIndex;
	int newSize = size;
	for( subSetSize = 1; subSetSize <= newSize; subSetSize++ )
	{
		clear( flags, newSize );
		tempIndex = 0;
		while( (pattern = nextFixedSizeSubSet( newSize, 0, subSetSize )) != NULL )
		{
			sum = patternSum( vector, pattern, newSize );
			if( sum <= targetSum )
				patternCopy( tempVector, vector, pattern, flags, &tempIndex, newSize );
			if( sum == targetSum )
				patternPrint( vector, pattern , newSize );
		}
		newSize = tempIndex;
		copy( vector, tempVector, newSize );
	}
}

int main( void )
{
	int size = 10, i, j;
	int *vector = new int[size];
	int targetSum;
	for( i = 0; i < size; i++ )
	{
		vector[i] = random()%100;
	}
	targetSum = 50;
	printVector( vector, size );
	subSetSum( vector, size, targetSum );
	return 0;
}


