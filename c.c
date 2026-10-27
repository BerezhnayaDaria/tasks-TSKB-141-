#include <stdio.h>
#include <math.h>

double getA(const double x, const double y);
double getB(const double x, const double y);

int main(void) {
    const double X = 0.335;
    const double Y = 0.025;

    printf("Исходные данные:\n");
    printf("x = %.3f\n", X);
    printf("y = %.3f\n", Y);

    printf("\nРезультаты вычислений:\n");
    printf("a = %.6f\n", getA(X, Y));
    printf("b = %.6f\n", getB(X, Y));

    return 0;
}

double getA(const double x, const double y) {
    return 1 + x + x*x/2 + x*x*x/3 + x*x*x*x/4;
}

double getB(const double x, const double y) {
    return x * (sin(x * x * x) + cos(y) * cos(y));
}
