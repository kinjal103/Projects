#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <iostream>

#define SIZE 100000

using namespace std;

void swap( int *a, int *b )
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void Display( int *vector, int size )
{
	int i;
	for( i = 0; i < size; i++ )
	{
		printf( " %d ", vector[i] ); 
	}
}

void BubbleSort( int *vector, int size )
{
	int pass, i;
	for( pass = size-1; pass > 0; pass-- )
	{
		for( i = 0; i < pass; i++ )
		{
			if( vector[i] > vector[i+1] )
				swap( &vector[i], &vector[i+1] );
		}
	}
}

void InsertionSort( int *vector, int size )
{
	int i, j, temp;
	for( i = 0; i < size; i++ )
	{
		temp = vector[i];
		for( j = i-1; j >= 0 && vector[j] > temp; j-- )
		{
			vector[j+1] = vector[j];
		}
		vector[j+1] = temp; 
	}
}

void SelectionSort( int *vector, int size )
{
	int pass, i, smallest;
	for( pass = 0; pass < size-1; pass++ )
	{
		smallest = pass;
		for( i = pass+1 ; i < size; i++ )
		{
			if( vector[smallest] > vector[i] )
				smallest = i; 
		}
		swap( &vector[pass], &vector[smallest] );
	}
}

void QuickSort( int *vector, int lb, int ub )
{
	int i = lb, j = ub;
	if( i >= j )
		return;
	while( i < j )
	{
		while( vector[i] <= vector[lb] )
			i++;
		while( vector[j] > vector[lb] )
			j--;
		if( i < j )
			swap( &vector[i], &vector[j] );
	}
	swap( &vector[lb], &vector[j] );
	QuickSort( vector, lb, j-1 );
	QuickSort( vector, i, ub );
}

void SimpleMerge( int *vector, int first, int second, int third )
{
	int i = first, j = second, k = third;
	int temp[SIZE], l = 0;
	while( i < second && j <= third )
	{
		if( vector[i] <= vector[j] )
			temp[l++] = vector[i++];
		else
			temp[l++] = vector[j++];
	}
	while( i < second )
		temp[l++] = vector[i++];
	while( j <= third )
		temp[l++] = vector[j++];
	for( i = 0; i < l; i++ )
		vector[first + i] = temp[i];
}

void MergeSort( int *vector, int lb, int ub )
{
	int middle = (lb + ub)/2;
	if( lb == ub )
		return;
	MergeSort( vector, lb, middle );
	MergeSort( vector, middle+1, ub );
	SimpleMerge( vector, lb, middle+1, ub );
}

int main( void )
{
	timeval start[5], end[5];
	int vector[5][SIZE], i;
	for( i = 0; i < SIZE; i++ )
	{
		vector[0][i] = rand()%100;
		vector[1][i] = vector[0][i];
		vector[2][i] = vector[1][i];	
		vector[3][i] = vector[2][i];
		vector[4][i] = vector[3][i];
	}
	
	gettimeofday( &start[0], NULL );	
	BubbleSort( vector[0], SIZE );
	gettimeofday( &end[0], NULL );
	
	gettimeofday( &start[1], NULL );	
	InsertionSort( vector[1], SIZE );
	gettimeofday( &end[1], NULL );
	
	gettimeofday( &start[2], NULL );	
	SelectionSort( vector[2], SIZE );
	gettimeofday( &end[2], NULL );

	gettimeofday( &start[3], NULL );	
	QuickSort( vector[3], 0, SIZE-1 );
	gettimeofday( &end[3], NULL );

	gettimeofday( &start[4], NULL );	
	MergeSort( vector[4], 0, SIZE-1 );
	gettimeofday( &end[4], NULL );
	
	printf("Execution times (%d elements)\n", SIZE);
	cout<<(end[0].tv_sec - start[0].tv_sec)*1000000 + end[0].tv_usec - start[0].tv_usec<<" BubbleSort"<<endl;
	cout<<(end[1].tv_sec - start[1].tv_sec)*1000000 + end[1].tv_usec - start[1].tv_usec<<" InsertionSort"<<endl;
	cout<<(end[2].tv_sec - start[2].tv_sec)*1000000 + end[2].tv_usec - start[2].tv_usec<<" SelectionSort"<<endl;
	cout<<(end[3].tv_sec - start[3].tv_sec)*1000000 + end[3].tv_usec - start[3].tv_usec<<" QuickSort"<<endl;
	cout<<(end[4].tv_sec - start[4].tv_sec)*1000000 + end[4].tv_usec - start[4].tv_usec<<" MergeSort"<<endl;
	return 0;
}
