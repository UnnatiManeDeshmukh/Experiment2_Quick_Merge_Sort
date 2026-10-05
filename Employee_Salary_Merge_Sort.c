#include <stdio.h>

void merge(int salary[], int low, int mid, int high)
{
    int temp[50];
    int i = low;
    int j = mid + 1;
    int k = low;

    while (i <= mid && j <= high)
    {
        if (salary[i] < salary[j])
        {
            temp[k] = salary[i];
            i++;
        }
        else
        {
            temp[k] = salary[j];
            j++;
        }
        k++;
    }

    while (i <= mid)
    {
        temp[k] = salary[i];
        i++;
        k++;
    }

    while (j <= high)
    {
        temp[k] = salary[j];
        j++;
        k++;
    }

    for (i = low; i <= high; i++)
    {
        salary[i] = temp[i];
    }
}

void mergeSort(int salary[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        mergeSort(salary, low, mid);
        mergeSort(salary, mid + 1, high);

        merge(salary, low, mid, high);
    }
}

int main()
{
    int salary[50], n;

    printf("EMPLOYEE SALARY SORTING USING MERGE SORT\n");
    printf("----------------------------------------\n");

    printf("Enter number of employees: ");
    scanf("%d", &n);

    printf("Enter employee salaries:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &salary[i]);
    }

    mergeSort(salary, 0, n - 1);

    printf("\nSalaries in ascending order:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", salary[i]);
    }

    printf("\n");

    return 0;
}