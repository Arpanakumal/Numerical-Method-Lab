#include <stdio.h>
#include <math.h>

double function(double x)
{

    return x * x;
}

double simpsonsRule(double a, double b, int n)
{
    if (n % 2 != 0)
    {
        printf("Number of intervals (n) must be even for Simpson's 1/3 rule.\n");
        return -1;
    }

    double h = (b - a) / n;
    double sum = function(a) + function(b);

    for (int i = 1; i < n; i++)
    {
        double x = a + i * h;
        if (i % 2 == 0)
        {
            sum += 2 * function(x);
        }
        else
        {
            sum += 4 * function(x);
        }
    }

    return (h / 3) * sum;
}

int main()
{
    double a, b;
    int n;

    printf("Enter the lower limit of integration (a): ");
    scanf("%lf", &a);
    printf("Enter the upper limit of integration (b): ");
    scanf("%lf", &b);
    printf("Enter the number of intervals (n, must be even): ");
    scanf("%d", &n);

    if (n <= 0 || n % 2 != 0)
    {
        printf("Number of intervals must be an even positive integer.\n");
        return 1;
    }

    double result = simpsonsRule(a, b, n);

    if (result != -1)
    {
        printf("\nThe integral of the function from %.2lf to %.2lf is approximately: %.6lf\n", a, b, result);
        printf("Name:Arpana Kumal\nRoll no:3");
    }

    return 0;
}
