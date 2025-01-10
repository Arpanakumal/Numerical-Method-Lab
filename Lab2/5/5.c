#include <stdio.h>

double lagrangeInterpolation(int n, double x[], double y[], double xp)
{
    double result = 0.0;

    for (int i = 0; i < n; i++)
    {
        double term = y[i];

        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                term = term * (xp - x[j]) / (x[i] - x[j]);
            }
        }

        result += term;
    }

    return result;
}

int main()
{
    int n;
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    double x[n], y[n];

    printf("Enter the data points (x and y values):\n");
    for (int i = 0; i < n; i++)
    {
        printf("x[%d] = ", i);
        scanf("%lf", &x[i]);
        printf("y[%d] = ", i);
        scanf("%lf", &y[i]);
    }

    double xp;
    printf("Enter the value of x at which to interpolate: ");
    scanf("%lf", &xp);

    double yp = lagrangeInterpolation(n, x, y, xp);

    printf("The interpolated value at x = %lf is y = %lf\n", xp, yp);
    printf("Name:Arpana Kumal\nRoll no:3");

    return 0;
}
