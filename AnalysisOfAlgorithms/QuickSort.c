#include <stdio.h>

int partion(int numbers[], int lb, int ub);
void quickSort(int numbers[], int lb, int ub);

int main()
{
    int numbers[100];
    int size, i;

    printf("Enter the number of elements: ");
    scanf("%d", &size);

    for (i = 0; i < size; i++)
    {
        printf("Enter the value of element %d: ", i);
        scanf("%d", &numbers[i]);
    }

    printf("Sorted elements are:\n");
    if (size == 1)
        printf("%d", numbers[0]);
    else if (size == 2)
    {
        if (numbers[0] > numbers[1])
        {
            int temp = numbers[0];
            numbers[0] = numbers[1];
            numbers[1] = temp;
        }
        printf("%d %d", numbers[0], numbers[1]);
    }
    else
    {
        quickSort(numbers, 0, size - 1);

        for (i = 0; i < size; i++)
            printf("%d ", numbers[i]);
    }

    printf("\n");
    return 0;
}

int partition(int numbers[], int lb, int ub)
{
    int down, up;
    int x, temp;

    down = lb;
    up = ub;
    x = numbers[lb];

    while (down < up)
    {
        while (numbers[down] <= x && down < up)
            down++;
        while (numbers[up] > x)
            up--;

        if (down < up)
        {
            temp = numbers[down];
            numbers[down] = numbers[up];
            numbers[up] = temp;
        }
    }
    numbers[lb] = numbers[up];
    numbers[up] = x;

    return up;
}

void quickSort(int numbers[], int lb, int ub)
{
    if (lb < ub)
    {
        int j = partition(numbers, lb, ub);
        quickSort(numbers, lb, j - 1);
        quickSort(numbers, j + 1, ub);
    }
}
