#include <stdio.h>
#include <string.h>
#include<conio.h>
#define inf 1<<20
int posmax, posmin;
int awin=-1,bwin=-1;
char board[15];

void print_board()
{
    int i;
    for (i = 1; i <= 9; i++)
    {
	printf("%c ",board[i]);
	if (i % 3 == 0)
	    printf("\n");
    }
    printf("\n");
}

int check_win(char board[])
{
    if ((board[1] == 'A' && board[2] == 'A' && board[3] == 'A') ||
	(board[4] == 'A' && board[5] == 'A' && board[6] == 'A') ||
	(board[7] == 'A' && board[8] == 'A' && board[9] == 'A') ||
	(board[1] == 'A' && board[4] == 'A' && board[7] == 'A') ||
	(board[2] == 'A' && board[5] == 'A' && board[8] == 'A') ||
	(board[3] == 'A' && board[6] == 'A' && board[9] == 'A') ||
	(board[1] == 'A' && board[5] == 'A' && board[9] == 'A') ||
	(board[3] == 'A' && board[5] == 'A' && board[7] == 'A'))
    {
	return 1;
    }
    else if((board[1] == 'B' && board[2] == 'B' && board[3] == 'B') ||
	    (board[4] == 'B' && board[5] == 'B' && board[6] == 'B') ||
	    (board[7] == 'B' && board[8] == 'B' && board[9] == 'B') ||
	    (board[1] == 'B' && board[4] == 'B' && board[7] == 'B') ||
	    (board[2] == 'B' && board[5] == 'B' && board[8] == 'B') ||
	    (board[3] == 'B' && board[6] == 'B' && board[9] == 'B') ||
	    (board[1] == 'B' && board[5] == 'B' && board[9] == 'B') ||
	    (board[3] == 'B' && board[5] == 'B' && board[7] == 'B'))
    {
	return -1;
    }
    else return 0;
}

int check_draw(char board[])
{
    if ((check_win(board) == 0) && (board[1] != '_') && (board[2] != '_') &&
	(board[3] != '_') && (board[4] != '_') && (board[5] != '_') &&
	(board[6] != '_') && (board[7] != '_') && (board[8] != '_') &&
	(board[9] != '_'))
    {
	return 1;
    }
    else return 0;
}

int minimax(int player, char board[], int n)
{
    int i, res, j;

    int max = -inf;
    int min = inf;

    int chk = check_win(board);
    if (chk == 1)
	return 1;
    else if (chk == (-1))
	return -1;
    else if (chk = check_draw(board))
	return 0;

    for (i = 1; i <= 9; i++)
    {
	if(board[i] == '_')
	{
	    if(player == 2)
	    {
		board[i] = 'B';
		res = minimax(1, board, n + 1);

		board[i] = '_';
		if(res < min)
		{
		    min = res;
		    if (n == 0)
			posmin = i;
		}
	    }
	    else if (player == 1)
	    {
		board[i] = 'A';
		res = minimax(2, board, n + 1);
		board[i] = '_';
		if (res > max)
		{
		    max = res;
		    if (n == 0)
			posmax = i;
		}
	    }
	}
    }

    if (player == 1)
	return max;
    else return min;
}


// 1 is A, 2 is B
int main()
{
    int i, j, input, opt;
    clrscr();

    for(i = 1; i <= 9; i++)
	board[i] = '_';

    printf("Board:\n");
    print_board();
    for(i = 1; i <=3; i++)
    {
      for(j = 1; j <= 3; j++)
      {
	printf("%d",-1);
      }
     printf("\n");
    }
    for(i = 1; i <= 9; i++)
    {
	if (i % 2 == 0)
	    printf("Player B give input:\n");
	else
	    printf("Player A give input:\n");

	scanf("%d", &input);
	if (i % 2 != 0)
	    board[input] = 'A';
	else
	    board[input] = 'B';

	printf("Board:\n");
	print_board();

	int chk = check_win(board);
	if (chk == 1)
	{
	    printf("win..Player A\n");
	    getch();
	    break;
	}
	else if (chk == -1)
	{
	    printf("win..Player B\n");
	    getch();
	    break;
	}
	else if ((chk == 0) && (i != 9))
	{
	   // posmax = -1;
	   // posmin = -1;
	    if(i % 2 == 0)
	    {
		opt = minimax(1, board, 0);
		printf("winning position move :player A is %d\n", posmax);
	    }
	    else
	    {
	    opt = minimax(2, board, 0);
	    printf("winning position move :player B is %d\n", posmin);
	    }
	}
	else
	    printf("game tied!\n");
    }
    return 0;
}