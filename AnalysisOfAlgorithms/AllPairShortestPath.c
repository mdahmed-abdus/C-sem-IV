#include <stdio.h>

#define ROW 20
#define COLUMN 20

int min(int no1, int no2);
void allPair(int path[ROW][COLUMN], int cost[ROW][COLUMN], int noOfNodes);
void printMatrix(int path[ROW][COLUMN], int noOfNodes);

int main()
{
    int path[ROW][COLUMN], cost[ROW][COLUMN], noOfNodes;
    int i, j;

    printf("Enter the number of nodes: ");
    scanf("%d", &noOfNodes);

    printf("If there is no edge then enter 1000\n");
    for (i = 1; i <= noOfNodes; i++)
        for (j = 1; j <= noOfNodes; j++)
        {
            if (i != j)
            {
                printf("Enter the cost of edge [%d, %d]: ", i, j);
                scanf("%d", &cost[i][j]);
            }
            else
                cost[i][j] = 0;
        }

    allPair(path, cost, noOfNodes);

    printf("\n");
    return 0;
}

int min(int no1, int no2)
{
    if (no1 < no2)
        return no1;
    return no2;
}

void allPair(int path[ROW][COLUMN], int cost[ROW][COLUMN], int noOfNodes)
{
    int i, j, k;

    for (i = 1; i <= noOfNodes; i++)
        for (j = 1; j <= noOfNodes; j++)
            path[i][j] = cost[i][j];

    printf("Path 0:\n");
    printMatrix(path, noOfNodes);

    for (k = 1; k <= noOfNodes; k++)
    {
        for (i = 1; i <= noOfNodes; i++)
            for (j = 1; j <= noOfNodes; j++)
                path[i][j] = min(path[i][j], path[i][k] + path[k][j]);

        if (k == noOfNodes)
            printf("Shortest path:\n");
        else
            printf("Path %d:\n", k);
        printMatrix(path, noOfNodes);
    }
}

void printMatrix(int path[ROW][COLUMN], int noOfNodes)
{
    int i, j;

    printf("\t");
    for (i = 1; i <= noOfNodes; i++)
        printf("%d\t", i);
    printf("\n");
    for (i = 1; i <= noOfNodes; i++)
    {
        printf("\n%d\t", i);
        for (j = 1; j <= noOfNodes; j++)
            printf("%d\t", path[i][j]);
        printf("\n");
    }
    printf("\n");
}
