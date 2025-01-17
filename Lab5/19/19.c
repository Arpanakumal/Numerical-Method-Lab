#include <stdio.h>
#include <math.h>

double f(double x, double y, double z)
{

    return -2 * y;
}

double g(double x, double y, double z)
{
    return z;
}

void euler(double x0, double y0, double z0, double h, double xn, double *y_end)
{
    double x = x0, y = y0, z = z0;

    while (x < xn)
    {
        double k1 = h * g(x, y, z);
        double l1 = h * f(x, y, z);

        y += k1;
        z += l1;
        x += h;
    }

    *y_end = y;
}

void shootingMethod(double x0, double y0, double xn, double yn, double z_guess1, double z_guess2, double h)
{
    double y_end1, y_end2;
    double z1 = z_guess1, z2 = z_guess2;

    euler(x0, y0, z1, h, xn, &y_end1);

    euler(x0, y0, z2, h, xn, &y_end2);

    double z_new, y_end_new;
    while (fabs(y_end1 - yn) > 1e-6)
    {
        z_new = z1 + (yn - y_end1) * (z2 - z1) / (y_end2 - y_end1);

        euler(x0, y0, z_new, h, xn, &y_end_new);

        z1 = z2;
        y_end1 = y_end2;

        z2 = z_new;
        y_end2 = y_end_new;
    }

    printf("Final solution: z(x0) = %.6f, y(xn) = %.6f\n", z_new, y_end_new);
}

int main()
{
    double x0 = 0, y0 = 1;
    double xn = 1, yn = 0;
    double z_guess1 = -1, z_guess2 = 0;
    double h = 0.1;
    printf("Solving boundary value problem using Shooting Method...\n");
    shootingMethod(x0, y0, xn, yn, z_guess1, z_guess2, h);
    printf("Name:Arpana Kumal\nRoll no:3");

    return 0;
}
