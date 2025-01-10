#include <stdio.h>
#include <math.h>

double function(double x)
{

    return x * x;
}

double trapezoidalRule(double a, double b, int n)
{
    double h = (b - a) / n;
    double sum = function(a) + function(b);

    for (int i = 1; i < n; i++)
    {
        double x = a + i * h;
        sum += 2 * function(x);
    }

    return (h / 2) * sum;
}

int main()
{
    double a, b;
    int n;
    printf("Enter the lower limit of integration (a): ");
    scanf("%lf", &a);
    printf("Enter the upper limit of integration (b): ");
    scanf("%lf", &b);
    printf("Enter the number of intervals (n): ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Number of intervals must be greater than 0.\n");
        return 1;
    }

    double result = trapezoidalRule(a, b, n);

    printf("\nThe integral of the function from %.2lf to %.2lf is approximately: %.6lf\n", a, b, result);
    printf("Name:Arpana Kumal\nRoll no:3");

    return 0;
}
