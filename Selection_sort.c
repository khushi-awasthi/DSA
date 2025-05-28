#include <stdio.h>
void selectionSort(int a[])
{
    int min, temp = 0;
    for (int i = 0; i < 10; i++)
    {
        min = i;
        for (int j = i + 1; j < 10; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}
void printArray(int arr[])
{
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {64, 25, 12, 22, 11, 38, 52, 9, 18, 6};
    // int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr);

    printf("Sorted array: ");
    printArray(arr);

    return 0;
}
