#include <stdio.h>

void selectionSort(int numbers[], int size);

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

    selectionSort(numbers, size);

    printf("Sorted elements are:\n");
    for (i = 0; i < size; i++)
        printf("%d ", numbers[i]);

    printf("\n");
    return 0;
}

void selectionSort(int numbers[], int size)
{
    for (int i = size - 1; i > 0; i--)
    {
        int largest = numbers[0];
        int loc = 0;

        for (int j = 1; j <= i; j++)
            if (numbers[j] > largest)
            {
                largest = numbers[j];
                loc = j;
            }

        numbers[loc] = numbers[i];
        numbers[i] = largest;
    }
}
