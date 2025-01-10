#include <stdio.h>
#include <math.h>

#define MAX 10

void gaussJordan(float matrix[MAX][MAX], int n)
{
    int i, j, k;
    float temp;

    for (i = 0; i < n; i++)
    {

        temp = matrix[i][i];
        for (j = 0; j <= n; j++)
        {
            matrix[i][j] /= temp;
        }

        for (k = 0; k < n; k++)
        {
            if (k != i)
            {
                temp = matrix[k][i];
                for (j = 0; j <= n; j++)
                {
                    matrix[k][j] -= temp * matrix[i][j];
                }
            }
        }
    }
}

int main()
{
    float matrix[MAX][MAX];
    int n, i, j;

    printf("Enter the number of equations: ");
    scanf("%d", &n);

    printf("Enter the augmented matrix (coefficients and constants):\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j <= n; j++)
        {
            scanf("%f", &matrix[i][j]);
        }
    }

    gaussJordan(matrix, n);

    printf("The solutions are:\n");
    for (i = 0; i < n; i++)
    {
        printf("x%d = %.3f\n", i + 1, matrix[i][n]);
    }
    printf("Name:Arpana Kumal\nRoll no:3");
    return 0;
}
