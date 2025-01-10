#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 10

void gaussElimination(int n, double a[MAX][MAX], double b[MAX], double x[MAX])
{
    int i, j, k;
    double factor;

    for (k = 0; k < n - 1; k++)
    {
        for (i = k + 1; i < n; i++)
        {
            if (a[k][k] == 0)
            {
                printf("Mathematical Error: Division by zero.\n");
                exit(1);
            }
            factor = a[i][k] / a[k][k];
            for (j = k; j < n; j++)
            {
                a[i][j] -= factor * a[k][j];
            }
            b[i] -= factor * b[k];
        }
    }

    for (i = n - 1; i >= 0; i--)
    {
        x[i] = b[i];
        for (j = i + 1; j < n; j++)
        {
            x[i] -= a[i][j] * x[j];
        }
        if (a[i][i] == 0)
        {
            printf("Mathematical Error: Division by zero.\n");
            exit(1);
        }
        x[i] /= a[i][i];
    }
}

int main()
{
    int n, i, j;
    double a[MAX][MAX], b[MAX], x[MAX];

    printf("Enter the number of equations: ");
    scanf("%d", &n);

    if (n > MAX)
    {
        printf("Maximum number of equations is %d.\n", MAX);
        return 1;
    }

    printf("Enter the coefficients of the equations:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("a[%d][%d] = ", i + 1, j + 1);
            scanf("%lf", &a[i][j]);
        }
    }

    printf("Enter the constant terms:\n");
    for (i = 0; i < n; i++)
    {
        printf("b[%d] = ", i + 1);
        scanf("%lf", &b[i]);
    }

    gaussElimination(n, a, b, x);

    printf("\nSolution:\n");
    for (i = 0; i < n; i++)
    {
        printf("x[%d] = %.6lf\n", i + 1, x[i]);
    }
    printf("Name:Arpana Kumal\nRoll no:3");

    return 0;
}
