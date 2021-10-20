#include <stdio.h>
#define SIZE 5

void Union(int arr1[], int arr2[])
{
    int farr[SIZE * 2];
    int i = 0;
    for (; i < SIZE; i++)
        farr[i] = arr1[i];
    for (int j = 0; j < SIZE; j++)
    {
        int k = 0;
        for (; k < i; k++)
            if (arr2[j] == farr[k])
                break;
        if (k == i)
        {
            farr[i] = arr2[j];
            i++;
        }
    }
    printf("\nUnion of the array is : ");
    for (int k = 0; k < i; k++)
        printf("%d ", farr[k]);
}

void Interection(int arr1[], int arr2[])
{
    int farr[SIZE];
    int i = 0, k = 0;
    for (; i < SIZE; i++)
    {
        int j = 0;
        for (; j < SIZE; j++)
            if (arr2[i] == arr1[j])
            {
                farr[k] = arr2[i];
                k++;
                break;
            }
    }
    printf("\nIntersection of the array is : ");
    for (int j = 0; j < k; j++)
        printf("%d ", farr[j]);
}

void Diff(int arr1[], int arr2[])
{
    int farr[SIZE];
    
}

void Syy_Diff()
{
}

void Accept(int arr[])
{
    for (int i = 0; i < SIZE; i++)
    {
        printf("Enter Element %d : ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void Display(int arr[])
{
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int A[SIZE], B[SIZE];
    printf("Enter First set \n");
    Accept(A);
    Display(A);
    printf("Enter Second set \n");
    Accept(B);
    Display(B);
    Union(A, B);
    Interection(A, B);
    Diff(A, B);
    return 0;
}