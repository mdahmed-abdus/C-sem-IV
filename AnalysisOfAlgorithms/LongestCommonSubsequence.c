#include <stdio.h>
#include <string.h>

#define UP 'U'
#define LEFT 'L'
#define DIAGONAL 'D'

void longestCommonSubsequence(char str1[], char str2[]);
void displayLCS(char direction[100][100], char str[], int lengthStr1, int lengthStr2);

int main()
{
    char str1[100], str2[100];

    printf("Enter the 1st string: ");
    gets(str1);
    printf("Enter the 2nd string: ");
    gets(str2);

    longestCommonSubsequence(str1, str2);

    printf("\n");
    return 0;
}

void longestCommonSubsequence(char str1[], char str2[])
{
    int i, j;

    char table[100][100];
    char direction[100][100];

    int lengthStr1 = strlen(str1);
    int lengthStr2 = strlen(str2);

    for (i = 0; i <= lengthStr1; i++)
        table[i][0] = 0;
    for (j = 0; j <= lengthStr2; j++)
        table[0][j] = 0;

    for (i = 1; i <= lengthStr1; i++)
        for (j = 1; j <= lengthStr2; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                table[i][j] = table[i - 1][j - 1] + 1;
                direction[i][j] = DIAGONAL;
            }
            else if (table[i - 1][j] >= table[i][j - 1])
            {
                table[i][j] = table[i - 1][j];
                direction[i][j] = UP;
            }
            else
            {
                table[i][j] = table[i][j - 1];
                direction[i][j] = LEFT;
            }
        }

    printf("Longest common subsequence is:\n");
    displayLCS(direction, str1, lengthStr1, lengthStr2);
}

void displayLCS(char direction[100][100], char str[], int lengthStr1, int lengthStr2)
{
    if (lengthStr1 == 0 || lengthStr2 == 0)
        return;
    else
    {
        if (direction[lengthStr1][lengthStr2] == DIAGONAL)
        {
            displayLCS(direction, str, lengthStr1 - 1, lengthStr2 - 1);
            printf("%c", str[lengthStr1 - 1]);
        }
        else if (direction[lengthStr1][lengthStr2] == UP)
            displayLCS(direction, str, lengthStr1 - 1, lengthStr2);
        else
            displayLCS(direction, str, lengthStr1, lengthStr2 - 1);
    }
}
