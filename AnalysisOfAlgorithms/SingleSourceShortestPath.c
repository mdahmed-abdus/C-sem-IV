#include <stdio.h>

#define ROW 20
#define COLUMN 20

void singleSource(int distance[ROW], int cost[ROW][COLUMN], int adjacent[ROW][COLUMN],
                  int size, int source, int destination);

int main()
{
    int i, j;
    int source, destination, size;

    int distance[ROW];
    int cost[ROW][COLUMN], adjacent[ROW][COLUMN];

    printf("Enter the size: ");
    scanf("%d", &size);

    printf("If there is a path enter 1, else enter 0\n");
    for (i = 1; i <= size; i++)
        for (j = 1; j <= size; j++)
        {
            printf("Enter the adjacency for [%d, %d]: ", i, j);
            scanf("%d", &adjacent[i][j]);
        }

    for (i = 1; i <= size; i++)
        for (j = 1; j <= size; j++)
            cost[i][j] = 100;

    printf("Enter the weight\n");
    for (i = 1; i <= size; i++)
        for (j = 1; j <= size; j++)
            if (adjacent[i][j] == 1)
            {
                printf("From %d to %d: ", i, j);
                scanf("%d", &cost[i][j]);
            }

    printf("Enter the source: ");
    scanf("%d", &source);
    printf("Enter the destination: ");
    scanf("%d", &destination);

    singleSource(distance, cost, adjacent, size, source, destination);

    printf("\n");
    return 0;
}

void singleSource(int distance[ROW], int cost[ROW][COLUMN], int adjacent[ROW][COLUMN],
                  int size, int source, int destination)
{
    int i, j, k;

    for (i = 0; i <= size; i++)
        distance[i] = cost[source][i];

    for (k = 2; k <= size; k++)
        for (j = 1; j <= size; j++)
            for (i = 1; i <= size; i++)
                if ((adjacent[i][j] == 1) && (distance[j] > distance[i] + cost[i][j]))
                    distance[j] = distance[i] + cost[i][j];

    for (i = 1; i <= size; i++)
        printf("The shortest distance from 1 to %d is: %d\n", i, distance[i]);
}
