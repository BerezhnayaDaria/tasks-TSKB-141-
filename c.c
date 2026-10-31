#include <stdio.h>
#include <math.h>

/* Функция для вычисления значения a */
double getA(const double x, const double y);
/* Функция для вычисления значения b */
double getB(const double x, const double y);

/* Главная функция программы */
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

/* Функция для вычисления значения a по формуле */
double getA(const double x, const double y) {
    return 1 + x + pow(x, 2) / 2 + pow(x, 3) / 3 + pow(x, 4) / 4;
}

/* Функция для вычисления значения b по формуле */
double getB(const double x, const double y) {
    return x * (sin(pow(x, 3)) + pow(cos(y), 2));
}
