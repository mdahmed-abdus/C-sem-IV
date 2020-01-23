#include <stdio.h>

int binarySearch(int numbers[], int low, int high, int toSearch);

int main()
{
    int numbers[100];
    int size, i;
    int toSearch;

    printf("Enter the number of elements: ");
    scanf("%d", &size);

    printf("Enter the numbers in ascending order\n");
    for (i = 0; i < size; i++)
    {
        printf("Enter the value of element %d: ", i);
        scanf("%d", &numbers[i]);
    }

    printf("Enter the element to be searched: ");
    scanf("%d", &toSearch);

    int indexFound = -1;
    if ((size == 1) && (toSearch == numbers[0]))
        indexFound = 0;
    else if (size == 2)
    {
        if (toSearch == numbers[0])
            indexFound = 0;
        else if (toSearch == numbers[1])
            indexFound = 1;
    }
    else
        indexFound = binarySearch(numbers, 0, size--, toSearch);

    if (indexFound == -1)
        printf("Element not found");
    else
        printf("Element found at index: %d", indexFound);

    printf("\n");
    return 0;
}

int binarySearch(int numbers[], int low, int high, int toSearch)
{
    int middle = (low + high) / 2;
    int indexFound = -1;

    if (low <= high)
    {
        if (toSearch == numbers[middle])
            return middle;
        else if (toSearch < numbers[middle])
            indexFound = binarySearch(numbers, 0, middle - 1, toSearch);
        else
            indexFound = binarySearch(numbers, middle + 1, high, toSearch);
    }

    return indexFound;
}
