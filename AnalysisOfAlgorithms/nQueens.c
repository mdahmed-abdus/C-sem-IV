#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int canPlace(int board[], int row, int col);
int printBoard(int board[], int noOfQueens, int counter);
int nQueens(int board[], int row, int noOfQueens, int counter);

int main()
{
    int board[100];
    int noOfQueens, solutions;

    printf("Enter the number of queens: ");
    scanf("%d", &noOfQueens);

    solutions = nQueens(board, 1, noOfQueens, 0);

    printf("\nNumber of solutions: %d", solutions);

    printf("\n");
    return 0;
}

int canPlace(int board[], int row, int col)
{
    for (int i = 1; i <= row - 1; i++)
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
            return 0;
    return 1;
}

int printBoard(int board[], int noOfQueens, int counter)
{
    printf("\nSolution %d:\n", ++counter);

    for (int i = 1; i <= noOfQueens; i++)
        printf("\t%d", i);
    for (int i = 1; i <= noOfQueens; i++)
    {
        printf("\n\n%d", i);
        for (int j = 1; j <= noOfQueens; j++)
        {
            if (board[i] == j)
                printf("\tQ");
            else
                printf("\t-");
        }
    }
    printf("\n");

    return counter;
}

int nQueens(int board[], int row, int noOfQueens, int counter)
{
    for (int col = 1; col <= noOfQueens; col++)
        if (canPlace(board, row, col))
        {
            board[row] = col;
            if (row == noOfQueens)
                counter = printBoard(board, noOfQueens, counter);
            else
                counter = nQueens(board, row + 1, noOfQueens, counter);
        }

    return counter;
}
