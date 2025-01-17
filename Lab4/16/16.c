#include <stdio.h>
#include <math.h>

#define MAX 10
#define EPSILON 0.0001
#define MAX_ITER 100

void powerMethod(double matrix[MAX][MAX], double vector[MAX], int n)
{
    double new_vector[MAX], lambda_old = 0.0, lambda_new = 0.0;
    int iter = 0;

    double norm = 0.0;
    for (int i = 0; i < n; i++)
    {
        norm += vector[i] * vector[i];
    }
    norm = sqrt(norm);
    for (int i = 0; i < n; i++)
    {
        vector[i] /= norm;
    }

    do
    {

        for (int i = 0; i < n; i++)
        {
            new_vector[i] = 0.0;
            for (int j = 0; j < n; j++)
            {
                new_vector[i] += matrix[i][j] * vector[j];
            }
        }

        lambda_new = 0.0;
        for (int i = 0; i < n; i++)
        {
            lambda_new += new_vector[i] * vector[i];
        }

        norm = 0.0;
        for (int i = 0; i < n; i++)
        {
            norm += new_vector[i] * new_vector[i];
        }
        norm = sqrt(norm);
        for (int i = 0; i < n; i++)
        {
            new_vector[i] /= norm;
        }

        double diff = fabs(lambda_new - lambda_old);
        if (diff < EPSILON)
        {
            break;
        }

        for (int i = 0; i < n; i++)
        {
            vector[i] = new_vector[i];
        }
        lambda_old = lambda_new;

        iter++;
    } while (iter < MAX_ITER);

    if (iter >= MAX_ITER)
    {
        printf("The Power Method did not converge within the maximum number of iterations.\n");
    }
    else
    {
        printf("The Power Method converged in %d iterations.\n", iter);
        printf("Dominant Eigenvalue: %.6f\n", lambda_new);
        printf("Corresponding Eigenvector:\n");
        for (int i = 0; i < n; i++)
        {
            printf("x[%d] = %.6f\n", i + 1, vector[i]);
        }
    }
}

int main()
{
    int n;
    double matrix[MAX][MAX], vector[MAX];

    printf("Enter the size of the square matrix (n): ");
    scanf("%d", &n);

    printf("Enter the elements of the matrix row-wise:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%lf", &matrix[i][j]);
        }
    }

    printf("Enter the initial guess vector:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &vector[i]);
    }

    powerMethod(matrix, vector, n);
    printf("Name:Arpana Kumal\nRoll no:3");

    return 0;
}
