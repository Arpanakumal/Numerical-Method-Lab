#include <stdio.h>
#include <math.h>

double g(double x)
{
    return 1 + (1 / x);
}

void fixedPoint(double initialGuess, double tolerance, int maxIterations)
{
    double x0 = initialGuess;
    double x1;
    int iteration = 0;

    printf("Iter\t x0\t\t g(x0)\t\t Error\n");

    do
    {
        x1 = g(x0);
        printf("%d\t %lf\t %lf\t %lf\n", iteration + 1, x0, x1, fabs(x1 - x0));

        if (fabs(x1 - x0) < tolerance)
        {
            printf("\nRoot found: %lf after %d iterations.\n", x1, iteration + 1);
            return;
        }

        x0 = x1;
        iteration++;

    } while (iteration < maxIterations);

    printf("\nMaximum iterations reached. Approximate root: %lf\n", x1);
}

int main()
{
    double initialGuess, tolerance;
    int maxIterations;

    printf("Enter the initial guess: ");
    scanf("%lf", &initialGuess);

    printf("Enter the tolerance: ");
    scanf("%lf", &tolerance);

    printf("Enter the maximum number of iterations: ");
    scanf("%d", &maxIterations);

    fixedPoint(initialGuess, tolerance, maxIterations);
    printf("Name:Arpana Kumal\n Roll no:3");

    return 0;
}
