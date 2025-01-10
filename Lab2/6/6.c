#include <stdio.h>

void calculateDividedDifferences(int n, double x[], double y[][n])
{
    for (int j = 1; j < n; j++)
    {
        for (int i = 0; i < n - j; i++)
        {
            y[i][j] = (y[i + 1][j - 1] - y[i][j - 1]) / (x[i + j] - x[i]);
        }
    }
}

double newtonInterpolation(int n, double x[], double y[][n], double xp)
{
    double result = y[0][0];
    double term = 1.0;

    for (int i = 1; i < n; i++)
    {
        term *= (xp - x[i - 1]);
        result += term * y[0][i];
    }

    return result;
}

int main()
{
    int n;
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    double x[n], y[n][n];

    printf("Enter the data points (x and y values):\n");
    for (int i = 0; i < n; i++)
    {
        printf("x[%d] = ", i);
        scanf("%lf", &x[i]);
        printf("y[%d] = ", i);
        scanf("%lf", &y[i][0]);
    }

    calculateDividedDifferences(n, x, y);

    printf("\nDivided Difference Table:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            printf("%10.6lf ", y[i][j]);
        }
        printf("\n");
    }

    double xp;
    printf("\nEnter the value of x at which to interpolate: ");
    scanf("%lf", &xp);

    double yp = newtonInterpolation(n, x, y, xp);

    printf("\nThe interpolated value at x = %lf is y = %lf\n", xp, yp);
    printf("Name:Arpana Kumal\nRoll no:3");

    return 0;
}
