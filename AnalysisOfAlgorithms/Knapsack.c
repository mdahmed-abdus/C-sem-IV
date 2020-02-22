#include <stdio.h>

void sort(float profits[], float weights[], int noOfElements);
float knapsack(float profits[], float weights[], int capacity, int noOfElements);

int main()
{
    float weights[100], profits[100];
    int capacity, noOfElements, i;
    float solution;

    printf("Enter the capacity of knapsack: ");
    scanf("%d", &capacity);
    printf("Enter the number of elements: ");
    scanf("%d", &noOfElements);

    for (i = 0; i < noOfElements; i++)
    {
        printf("Enter the profit of element %d: ", i);
        scanf("%f", &profits[i]);
    }
    for (i = 0; i < noOfElements; i++)
    {
        printf("Enter the weight of element %d: ", i);
        scanf("%f", &weights[i]);
    }

    solution = knapsack(profits, weights, capacity, noOfElements);

    printf("Optimal solution is: %f", solution);

    printf("\n");
    return 0;
}

void sort(float profits[], float weights[], int noOfElements)
{
    int i, j;

    for (i = 0; i < noOfElements - 1; i++)
        for (j = 0; j < noOfElements - 1 - i; j++)
            if ((profits[j] / weights[j]) < (profits[j + 1] / weights[j + 1]))
            {
                float temp = profits[j];
                profits[j] = profits[j + 1];
                profits[j + 1] = temp;

                temp = weights[j];
                weights[j] = weights[j + 1];
                weights[j + 1] = temp;
            }
}

float knapsack(float profits[], float weights[], int capacity, int noOfElements)
{
    float selectedElements[100];
    float solution = 0;
    int i;

    for (i = 0; i < noOfElements; i++)
        selectedElements[i] = 0;

    sort(profits, weights, noOfElements);

    i = 0;
    while (i < noOfElements && weights[i] <= capacity)
    {
        selectedElements[i] = 1;
        capacity -= weights[i];
        i++;
    }

    if (i < noOfElements)
        selectedElements[i] = capacity / weights[i];

    for (i = 0; i < noOfElements; i++)
        solution += selectedElements[i] * profits[i];

    return solution;
}
