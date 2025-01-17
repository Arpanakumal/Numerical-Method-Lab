#include <stdio.h>
#include <math.h>

#define MAX 10
#define EPSILON 0.0001
#define MAX_ITER 100

void jacobiIteration(double equations[MAX][MAX + 1], double x[MAX], int n)
{
    double new_x[MAX];
    int iter = 0;
    double max_diff;

    do
    {
        max_diff = 0.0;

        for (int i = 0; i < n; i++)
        {
            new_x[i] = equations[i][n];

            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    new_x[i] -= equations[i][j] * x[j];
                }
            }

            new_x[i] /= equations[i][i];

            double diff = fabs(new_x[i] - x[i]);
            if (diff > max_diff)
                max_diff = diff;
        }

        for (int i = 0; i < n; i++)
        {
            x[i] = new_x[i];
        }

        iter++;
    } while (max_diff > EPSILON && iter < MAX_ITER);

    if (iter >= MAX_ITER)
    {
        printf("Solution did not converge within the maximum number of iterations.\n");
    }
    else
    {
        printf("Solution converged in %d iterations.\n", iter);
    }
}

int main()
{
    int n;
    double equations[MAX][MAX + 1], x[MAX] = {0};

    printf("Enter the number of variables (n): ");
    scanf("%d", &n);

    printf("Enter the coefficients of the equations row-wise (including the constant term):\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            scanf("%lf", &equations[i][j]);
        }
    }

    printf("Enter the initial guesses for the variables:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &x[i]);
    }

    jacobiIteration(equations, x, n);

    printf("The solutions are:\n");
    for (int i = 0; i < n; i++)
    {
        printf("x[%d] = %.4f\n", i + 1, x[i]);
    }
    printf("Name:Arpana Kumal\nRoll no:3");

    return 0;
}