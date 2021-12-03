#include <stdio.h>
#define size 3

void inp(int (*a)[size], char c)
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            printf(" %c[%d][%d] = ", c, i, j);
            scanf("%d", &a[i][j]);
        }
}

void add(int (*a)[size], int (*b)[size], int (*c)[size])
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            c[i][j] = a[i][j] + b[i][j];
}

void multiply(int (*a)[size], int (*b)[size], int (*c)[size])
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < size; k++)
                c[i][j] += a[i][k] + b[k][j];
        }
}

void transpose(int (*a)[size], int (*b)[size]){
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            b[j][i] = a[i][j];
};

void display(int (*a)[size], char s[])
{
    printf("\n%s : \n", s);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            printf("%d\t", a[i][j]);
        printf("\n");
    }
}

int main()
{
    int A[size][size], B[size][size], C[size][size];
    inp(A, 'A');
    inp(B, 'B');
    add(A, B, C);
    display(C, "ADDITION OF MATRIX");
    multiply(A, B, C);
    display(C, "MULTIPLICATION OF MATRIX");
    transpose(A, C);
    display(C, "TRANSPOSE OF MATRIX");

    return 0;
}