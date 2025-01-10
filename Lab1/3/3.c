#include <stdio.h>
#include <math.h>

double f(double x)
{
    return x * x * x - 3 * x - 2;
}

double f_prime(double x)
{
    return 3 * x * x - 3;
}

double newton_raphson(double x0, double tol)
{
    double x1;

    while (1)
    {

        x1 = x0 - f(x0) / f_prime(x0);

        if (fabs(x1 - x0) < tol)
        {
            break;
        }

        x0 = x1;
    }

    return x1;
}

int main()
{
    double x0 = 2;
    double tolerance = 1e-5;

    double root = newton_raphson(x0, tolerance);

    printf("The root is approximately: %lf\n", root);
    printf("Name:Arpana Kumal\n Roll no:3");

    return 0;
}
