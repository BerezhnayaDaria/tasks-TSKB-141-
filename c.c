#include <stdio.h>
#include <math.h>

/**
*@brief вычисляет значения A по заданной формуле
*@param x - значение параметра х
*@param y - значение параметра y
*@return рассчитанное значение
*/
double getA(const double x, const double y);

/**
*@brief вычисляет значения B
*@param x - значение параметра х
*@param y - значение параметра y
*@return рассчитанное значение
*/
double getB(const double x, const double y);

/**
*@brief точка входа в программу
*@return возвращает 0, если программа выполнена корректно
*/
int main() {
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
    return 1 + x + pow(x, 2) / 2 + pow(x, 3) / 3 + pow(x, 4) / 4;
}

double getB(const double x, const double y) {
    return x * (sin(pow(x, 3)) + pow(cos(y), 2));
}
