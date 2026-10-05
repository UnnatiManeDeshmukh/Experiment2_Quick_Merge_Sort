#include <stdio.h>

void quickSort(float price[], int low, int high)
{
    if (low < high)
    {
        float pivot = price[high];
        int i = low - 1;

        for (int j = low; j < high; j++)
        {
            if (price[j] < pivot)
            {
                i++;

                float temp = price[i];
                price[i] = price[j];
                price[j] = temp;
            }
        }

        float temp = price[i + 1];
        price[i + 1] = price[high];
        price[high] = temp;

        int partitionIndex = i + 1;

        quickSort(price, low, partitionIndex - 1);
        quickSort(price, partitionIndex + 1, high);
    }
}

void merge(float price[], int low, int mid, int high)
{
    float temp[50];
    int i = low;
    int j = mid + 1;
    int k = low;

    while (i <= mid && j <= high)
    {
        if (price[i] < price[j])
            temp[k++] = price[i++];
        else
            temp[k++] = price[j++];
    }

    while (i <= mid)
        temp[k++] = price[i++];

    while (j <= high)
        temp[k++] = price[j++];

    for (i = low; i <= high; i++)
        price[i] = temp[i];
}

void mergeSort(float price[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        mergeSort(price, low, mid);
        mergeSort(price, mid + 1, high);
        merge(price, low, mid, high);
    }
}

int main()
{
    float price[50], quickPrice[50], mergePrice[50];
    int n;

    printf("PRODUCT PRICE SORTING\n");
    printf("---------------------\n");

    printf("Enter number of products: ");
    scanf("%d", &n);

    printf("Enter product prices:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%f", &price[i]);
        quickPrice[i] = price[i];
        mergePrice[i] = price[i];
    }

    quickSort(quickPrice, 0, n - 1);
    mergeSort(mergePrice, 0, n - 1);

    printf("\nQuick Sort - Prices in ascending order:\n");

    for (int i = 0; i < n; i++)
        printf("%.2f ", quickPrice[i]);

    printf("\n\nMerge Sort - Prices in ascending order:\n");

    for (int i = 0; i < n; i++)
        printf("%.2f ", mergePrice[i]);

    printf("\n");

    return 0;
}