#include <iostream>

#define SIZE 5

using namespace std;

void pigeonSort( int *vector, int size, int holes )
{
	holes++;
	int i, j = 0;
	int *holeVector = new int[holes];
	for( i = 0; i < holes; i++ )
		holeVector[i] = 0;
	for( i = 0; i < size; i++ )
		holeVector[vector[i]]++;
	for( i = 0; i < holes; i++ )
		while( holeVector[i]-- )
			vector[j++] = i;
}

/*Function corresponding to function majorityElement*/
int majorityElement( int *vector, int size, int holes )
{
	holes++;
	int i, j = 0;
	int *holeVector = new int[holes];
	for( i = 0; i < holes; i++ )
		holeVector[i] = 0;
	for( i = 0; i < size; i++ )
		holeVector[vector[i]]++;
	for( i = 0; i < holes; i++ )
		if( holeVector[i] > size/2 )
			return i;
	return -1;
}

int findMax( int *vector, int size )
{
	int i, max = 0;
	for( i = 0; i < size; i++ )
		if( vector[i] > max )
			max = vector[i];
	return max;
}

int arraySum( int *vector, int size )
{
	int i, sum = 0;
	for( i = 0; i < size; i++ )
		sum += vector[i];
	return sum;
}

/*Function corresponding to procedure subArray*/
void subArrays( int *vector, int size, int *A, int *B, int *sizeA, int *sizeB )
{
	int i, a = 0, b = 0;
	for( i = size-1; i >= 0; i-- )
	{
		if( arraySum( B, b ) >= arraySum( A, a ) )
			A[a++] = vector[i];
		else
			B[b++] = vector[i]; 
	}
	*sizeA = a;
	*sizeB = b;
}

void display( int *vector, int size )
{
	int i;
	cout<<endl<<"[ ";
	for( i = 0; i < size; i++ )
		cout<<vector[i]<<" ";
	cout<<"]";
}

int main( void )
{
	int vector[SIZE] = { 2, 4, 4, 5, 4 };
	int A[SIZE], B[SIZE], a, b;
	int majorityElem;
	cout<<"Array: ";
	display( vector, SIZE );
	pigeonSort( vector, SIZE, findMax( vector, SIZE ) );
	subArrays( vector, SIZE, A, B, &a, &b );
	cout<<endl<<"Sub array 1: ";
	display( A, a );
	cout<<endl<<"Sub array 2: ";
	display( B, b );	
	majorityElem = majorityElement( vector, SIZE, findMax( vector, SIZE ) );
	if( majorityElem == -1 )
		cout<<endl<<"No majority element."<<endl;
	else
		cout<<endl<<"Majority element: "<<majorityElem<<endl;
	return 0;
}
