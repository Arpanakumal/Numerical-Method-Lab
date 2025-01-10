#include <stdio.h>
#include <math.h>

double f(double x)
{
    return 4 * x * x * x - 2 * x + 6;
}

double bisection(double a, double b, double tol)
{

    if (f(a) * f(b) >= 0)
    {
        printf("The bisection method cannot be applied. f(a) and f(b) must have opposite signs.\n");
        return -1;
    }

    double c = a;
    while ((b - a) / 2.0 > tol)
    {

        c = (a + b) / 2.0;

        if (f(c) == 0.0)
            break;

        if (f(c) * f(a) < 0)
            b = c;
        else
            a = c;
    }

    return c;
}

int main()
{
    double a = -2, b = 2;
    double tolerance = 1e-5;

    double root = bisection(a, b, tolerance);

    if (root != -1)
        printf("The root is approximately: %lf\n", root);
    printf("Name:Arpana Kumal\n Roll no:3");

    return 0;
}
