#include <stdio.h>

int main()
{
    int n;
    double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;

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
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumX2 += x[i] * x[i];
    }

    double denominator = n * sumX2 - sumX * sumX;
    double B = (n * sumXY - sumX * sumY) / denominator;
    double A = (sumY - B * sumX) / n;

    printf("\nThe least squares fit line is: Y = %.2lf + %.2lfX\n", A, B);
    printf("Name:Arpana Kumal\nRoll no:3");

    return 0;
}
