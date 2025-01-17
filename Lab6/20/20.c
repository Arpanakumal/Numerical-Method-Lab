#include <stdio.h>
#include <math.h>

#define MAX 100
#define TOLERANCE 1e-6

void solveLaplace(double u[MAX][MAX], int rows, int cols, int maxIterations)
{
    int i, j, iter;
    double diff, maxDiff;

    for (iter = 0; iter < maxIterations; iter++)
    {
        maxDiff = 0.0;

        for (i = 1; i < rows - 1; i++)
        {
            for (j = 1; j < cols - 1; j++)
            {
                double oldVal = u[i][j];
                u[i][j] = 0.25 * (u[i + 1][j] + u[i - 1][j] + u[i][j + 1] + u[i][j - 1]);
                diff = fabs(u[i][j] - oldVal);
                if (diff > maxDiff)
                {
                    maxDiff = diff;
                }
            }
        }

        if (maxDiff < TOLERANCE)
        {
            printf("Converged after %d iterations.\n", iter + 1);
            break;
        }
    }

    if (iter == maxIterations)
    {
        printf("Reached maximum iterations without full convergence.\n");
    }
}

int main()
{
    int rows = 5, cols = 5;
    double u[MAX][MAX] = {0};
    int i, j;

    for (i = 0; i < rows; i++)
    {
        u[i][0] = 100.0;
        u[i][cols - 1] = 100.0;
    }

    for (j = 0; j < cols; j++)
    {
        u[0][j] = 0.0;
        u[rows - 1][j] = 0.0;
    }

    printf("Initial Grid:\n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("%6.2f ", u[i][j]);
        }
        printf("\n");
    }

    solveLaplace(u, rows, cols, 10000);

    printf("\nSolution Grid:\n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("%6.2f ", u[i][j]);
        }
        printf("\n");
    }
    printf("Name:Arpana Kumal\nRoll no:3");

    return 0;
}
