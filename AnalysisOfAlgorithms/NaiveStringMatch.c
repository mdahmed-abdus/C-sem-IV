#include <stdio.h>
#include <string.h>

int naive(char testStr[], char patternStr[]);

int main()
{
    char testStr[100], patternStr[100];

    printf("Enter the test string: ");
    gets(testStr);
    printf("Enter the pattern string: ");
    gets(patternStr);

    int matched = naive(testStr, patternStr);

    if (matched)
        printf("'%s' is a substring of '%s'", patternStr, testStr);
    else
        printf("'%s' is not a substring of '%s'", patternStr, testStr);

    printf("\n");
    return 0;
}

int naive(char testStr[], char patternStr[])
{
    int testLen = strlen(testStr);
    int patternLen = strlen(patternStr);

    for (int i = 0; i <= testLen - patternLen; i++)
    {
        int j = 0;

        while (j < patternLen && testStr[i + j] == patternStr[j])
            j++;

        if (j == patternLen)
            return 1;
    }

    return 0;
}
