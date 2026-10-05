#include <stdio.h>

void quickSort(int marks[], int low, int high)
{
    if (low < high)
    {
        int pivot = marks[high];
        int i = low - 1;

        for (int j = low; j < high; j++)
        {
            if (marks[j] < pivot)
            {
                i++;

                int temp = marks[i];
                marks[i] = marks[j];
                marks[j] = temp;
            }
        }

        int temp = marks[i + 1];
        marks[i + 1] = marks[high];
        marks[high] = temp;

        int partitionIndex = i + 1;

        quickSort(marks, low, partitionIndex - 1);
        quickSort(marks, partitionIndex + 1, high);
    }
}

int main()
{
    int marks[50], n;

    printf("STUDENT MARKS SORTING USING QUICK SORT\n");
    printf("--------------------------------------\n");

    printf("Enter number of students: ");
    scanf("%d", &n);

    printf("Enter marks:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &marks[i]);
    }

    quickSort(marks, 0, n - 1);

    printf("\nMarks in ascending order:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", marks[i]);
    }

    printf("\n");

    return 0;
}