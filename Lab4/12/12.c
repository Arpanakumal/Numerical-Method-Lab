#include <stdio.h>

#define MAX 10

void doolittleFactorization(float A[MAX][MAX], float L[MAX][MAX], float U[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {

        for (int j = i; j < n; j++)
        {
            float sum = 0;
            for (int k = 0; k < i; k++)
                sum += L[i][k] * U[k][j];
            U[i][j] = A[i][j] - sum;
        }

        for (int j = i; j < n; j++)
        {
            if (i == j)
                L[i][i] = 1;
            else
            {
                float sum = 0;
                for (int k = 0; k < i; k++)
                    sum += L[j][k] * U[k][i];
                L[j][i] = (A[j][i] - sum) / U[i][i];
            }
        }
    }
}

void printMatrix(float mat[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%0.2f\t", mat[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n;
    float A[MAX][MAX], L[MAX][MAX] = {0}, U[MAX][MAX] = {0};

    printf("Enter the size of the matrix (n x n): ");
    scanf("%d", &n);

    printf("Enter the elements of the matrix A:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%f", &A[i][j]);
        }
    }

    doolittleFactorization(A, L, U, n);

    printf("\nMatrix A:\n");
    printMatrix(A, n);

    printf("\nLower Triangular Matrix L:\n");
    printMatrix(L, n);

    printf("\nUpper Triangular Matrix U:\n");
    printMatrix(U, n);
    printf("Name:Arpana Kumal\nRoll no:3");

    return 0;
}
