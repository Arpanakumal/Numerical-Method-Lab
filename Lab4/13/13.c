#include <stdio.h>
#include <math.h>

#define MAX 10

void choleskyFactorization(float A[MAX][MAX], float L[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            float sum = 0;

            if (j == i)
            {
                for (int k = 0; k < j; k++)
                    sum += L[j][k] * L[j][k];
                L[j][j] = sqrt(A[j][j] - sum);
            }
            else
            {
                for (int k = 0; k < j; k++)
                    sum += L[i][k] * L[j][k];
                L[i][j] = (A[i][j] - sum) / L[j][j];
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
            if (i >= j)
                printf("%0.2f\t", mat[i][j]);
            else
                printf("0.00\t");
        }
        printf("\n");
    }
}

int main()
{
    int n;
    float A[MAX][MAX], L[MAX][MAX] = {0};

    printf("Enter the size of the matrix (n x n): ");
    scanf("%d", &n);

    printf("Enter the elements of the matrix A (symmetric and positive definite):\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%f", &A[i][j]);
        }
    }

    int isSymmetric = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (A[i][j] != A[j][i])
            {
                isSymmetric = 0;
                break;
            }
        }
        if (!isSymmetric)
            break;
    }

    if (!isSymmetric)
    {
        printf("Matrix is not symmetric. Cholesky factorization requires a symmetric positive definite matrix.\n");
        return 1;
    }

    choleskyFactorization(A, L, n);

    printf("\nMatrix A:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%0.2f\t", A[i][j]);
        }
        printf("\n");
    }

    printf("\nLower Triangular Matrix L:\n");
    printMatrix(L, n);
    printf("Name:Arpana Kumal\nRoll no:3");

    return 0;
}
