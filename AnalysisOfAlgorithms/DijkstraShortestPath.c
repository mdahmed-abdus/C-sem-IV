#include <stdio.h>

#define INFINITY 32767
#define ROW 20
#define COL 20

void dijkstraSP(int adjacent[ROW][COL], int weights[ROW][COL], int noOfNodes, int source, int destination);
void displayShortestPath(int shortestPath[ROW], int size);

int main()
{
    int i, j;
    int adjacent[ROW][COL], weights[ROW][COL];
    int noOfNodes, source, destination;

    printf("Enter the number of nodes: ");
    scanf("%d", &noOfNodes);

    for (i = 1; i <= noOfNodes; i++)
        for (j = 1; j <= noOfNodes; j++)
        {
            weights[i][j] = INFINITY;
            adjacent[i][j] = 0;
        }

    for (i = 1; i <= noOfNodes; i++)
        for (j = 1; j <= noOfNodes; j++)
        {
            printf("Enter the adjacency for %d to %d: ", i, j);
            scanf("%d", &adjacent[i][j]);
        }

    for (i = 1; i <= noOfNodes; i++)
        for (j = 1; j <= noOfNodes; j++)
            if (adjacent[i][j] == 1)
            {
                printf("Enter the weight for %d to %d: ", i, j);
                scanf("%d", &weights[i][j]);
            }

    printf("Enter the source: ");
    scanf("%d", &source);
    printf("Enter the destination: ");
    scanf("%d", &destination);

    dijkstraSP(adjacent, weights, noOfNodes, source, destination);

    printf("\n");
    return 0;
}

void dijkstraSP(int adjacent[ROW][COL], int weights[ROW][COL], int noOfNodes, int source, int destination)
{
    int i;
    int currentDistance, newDistance, minDistance, current;
    int distance[ROW], nodeset[ROW];
    int path[ROW], shortestPath[ROW];
    int x, y, size;

    for (i = 1; i <= noOfNodes; i++)
    {
        distance[i] = INFINITY;
        nodeset[i] = 0;
    }

    current = source;
    distance[current] = 0;
    nodeset[current] = 1;

    while (current != destination)
    {
        currentDistance = distance[current];
        for (i = 1; i <= noOfNodes; i++)
            if (adjacent[current][i] && !nodeset[i])
            {
                newDistance = currentDistance + weights[current][i];
                if (newDistance < distance[i])
                {
                    distance[i] = newDistance;
                    path[i] = current;
                }
            }

        minDistance = INFINITY;
        for (i = 1; i <= noOfNodes; i++)
            if (!nodeset[i] && distance[i] < minDistance)
            {
                minDistance = distance[i];
                current = i;
            }
        nodeset[current] = i;
    }

    y = destination;
    i = size = 0;
    do
    {
        x = path[y];
        shortestPath[i++] = y;
        shortestPath[i++] = x;
        y = x;
        size += 2;
    } while (y != source);

    displayShortestPath(shortestPath, size);
}

void displayShortestPath(int shortestPath[ROW], int size)
{
    printf("\nShortest path is:\n");
    for (int i = size - 1; i >= 0; i--)
    {
        if (i == 0)
            printf("%d\n", shortestPath[i]);
        else if (i % 2 != 0)
            printf("%d -> ", shortestPath[i]);
        else
            printf("%d, ", shortestPath[i]);
    }
}
