#include <stdio.h>
#define SIZE 5

int Union(int arr1[], int arr2[], int size, int size1,  int arr3[])
{
    int i = 0;
    for (; i < size; i++)
        arr3[i] = arr1[i];
    for (int j = 0; j < size1; j++)
    {
        int k = 0;
        for (; k < i; k++)
            if (arr2[j] == arr3[k])
                break;
        if (k == i)
        {
            arr3[i] = arr2[j];
            i++;
        }
    }
    return i;
}

int Interection(int arr1[], int arr2[], int arr3[])
{
    int i = 0, k = 0;
    for (; i < SIZE; i++)
    {
        int j = 0;
        for (; j < SIZE; j++)
            if (arr2[i] == arr1[j])
            {
                arr3[k] = arr2[i];
                k++;
                break;
            }
    }
    return k;
}

int Diff(int arr1[], int arr2[], int arr3[])
{
    int k = 0;
    for (int i = 0; i < SIZE; i++)
    {
        int j = 0;
        for (; j < SIZE; j++)
        {
            if (arr1[i] == arr2[j])
                break;
        }
        if (j == SIZE)
        {
            arr3[k] = arr1[i];
            k++;
        }
    }
    return k;
}

int Syy_Diff(int arr1[], int arr2[], int arr3[])
{
    int farr1[SIZE], farr2[SIZE];
    int k = Diff(arr1, arr2, farr1);
    int k1 = Diff(arr2, arr1, farr2);
    int uni = Union(farr1, farr2, k, k1, arr3);
    return uni;
}

void Accept(int arr[])
{
    for (int i = 0; i < SIZE; i++)
    {
        printf("Enter Element %d : ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void Display(int arr[], int len, char str[])
{
    printf("%s : ", str);
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int A[SIZE], B[SIZE], C[SIZE*2];
    printf("Enter First set \n");
    Accept(A);
    printf("Enter Second set \n");
    Accept(B);
    Display(A, SIZE, "\nA");
    Display(B, SIZE, "\nB");
    Display(C, Union(A, B, SIZE, SIZE, C), "\nUnion");
    Display(C, Interection(A, B, C), "\nIntersection");
    Display(C, Diff(A, B, C), "\nA-B");
    Display(C, Diff(B, A, C), "\nB-A");
    Display(C, Syy_Diff(A, B, C), "\nSymmetric_Difference");
    return 0;
}