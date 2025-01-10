#include <stdio.h>
#include <math.h>

double f(double x)
{
    return x * x - 5 * x + 6;
}

double false_position(double a, double b, double tol)
{
    double c = a;

    if (f(a) * f(b) > 0)
    {
        printf("The False Position method cannot be applied. f(a) and f(b) must have opposite signs.\n");
        return -1;
    }

    while ((b - a) / 2.0 > tol)
    {

        c = (a * f(b) - b * f(a)) / (f(b) - f(a));

        if (f(c) == 0.0)
        {
            break;
        }

        if (f(c) * f(a) < 0)
            b = c;
        else
            a = c;
    }

    return c;
}

int main()
{
    double a = 1, b = 3;
    double tolerance = 1e-5;

    double root = false_position(a, b, tolerance);

    if (root != -1)
        printf("The root is approximately: %lf\n", root);
    printf("Name:Arpana Kumal\n Roll no:3");

    return 0;
}
