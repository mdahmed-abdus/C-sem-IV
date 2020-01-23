#include <stdio.h>

void insertionSort(int numbers[], int size);

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

    insertionSort(numbers, size);

    printf("Sorted elements are:\n");
    for (i = 0; i < size; i++)
        printf("%d ", numbers[i]);
    printf("\n");

    return 0;
}

void insertionSort(int numbers[], int size)
{
    for (int k = 1; k < size; k++)
    {
        int x = numbers[k];
        int i = k - 1;

        while (i >= 0 && numbers[i] > x)
        {
            numbers[i + 1] = numbers[i];
            i--;
        }
        numbers[i + 1] = x;
    }
}
