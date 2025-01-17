#include <stdio.h>

double f(double x, double y)
{

    return x + y;
}

void heunsMethod(double x0, double y0, double xn, double h)
{
    double x = x0, y = y0, y_predict, slope;

    printf("x\t\t y\n");
    printf("%.4f\t %.4f\n", x, y);

    while (x < xn)
    {

        y_predict = y + h * f(x, y);

        slope = (f(x, y) + f(x + h, y_predict)) / 2.0;
        y = y + h * slope;

        x = x + h;

        printf("%.4f\t %.4f\n", x, y);
    }
}

int main()
{
    double x0, y0, xn, h;

    printf("Enter the initial value of x (x0): ");
    scanf("%lf", &x0);

    printf("Enter the initial value of y (y0): ");
    scanf("%lf", &y0);

    printf("Enter the final value of x (xn): ");
    scanf("%lf", &xn);

    printf("Enter the step size (h): ");
    scanf("%lf", &h);

    printf("\nSolving the ODE using Heun's method:\n");
    heunsMethod(x0, y0, xn, h);
    printf("Name:Arpana Kumal\nRoll no:3");

    return 0;
}
