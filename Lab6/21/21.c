#include <stdio.h>
#include <math.h>

#define MAX 100
#define TOLERANCE 1e-6

double sourceTerm(double x, double y)
{
    return x * x + y * y;
}

void solvePoisson(double u[MAX][MAX], double f[MAX][MAX], int rows, int cols, double h, int maxIterations)
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
                u[i][j] = 0.25 * (u[i + 1][j] + u[i - 1][j] + u[i][j + 1] + u[i][j - 1] - h * h * f[i][j]);
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
    double f[MAX][MAX] = {0};
    int i, j;
    double x, y;
    double h = 1.0;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            x = i * h;
            y = j * h;
            f[i][j] = sourceTerm(x, y);
        }
    }

    for (i = 0; i < rows; i++)
    {
        u[i][0] = 0.0;
        u[i][cols - 1] = 0.0;
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

    solvePoisson(u, f, rows, cols, h, 10000);

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
