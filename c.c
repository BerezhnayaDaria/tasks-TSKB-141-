#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

/**
 * @brief вычисляет значение функции e в степени x
 * @param x   значение параметра x
 * @return Рассчитанное значение функции
 */
double getY(const double x);

/**
 * @brief вычисляет сумму функционального ряда с заданной точностью
 * @param x   значение параметра x
 * @param e   заданная точность вычислений
 * @return Рассчитанная сумма ряда
 */
double getSum(const double x, const double e);

/**
 * @brief Вычисляет коэффициент для следующего члена ряда
 * @param x   значение параметра x
 * @param i   номер текущего члена ряда
 * @return Рассчитанный коэффициент
 */
double getCoef(const double x, const int i);

/**
 * @brief точка входа в программу
 * @return 0, если программа выполнена корректно, иначе не 0
 */
int main()
{
    const double xbegin = 1.0;
    const double xend = 2.0;
    const double step = 0.1;
    const double e = 1.5e-4;

    printf("x\t\t y\t\t S\n");
    printf("------------------------------------------\n");

    for (double x = xbegin; x < xend + step / 2; x += step)
    {
        printf("%lf\t %lf\t %lf\n", x, getY(x), getSum(x, e));
    }

    return 0;
}

double getY(const double x)
{
    return exp(x);
}

double getSum(const double x, const double e)
{
    double a = 1.0;
    double result = a;

    for (int i = 1; fabs(a) >= e - DBL_EPSILON; i++)
    {
        result += a;
        a *= getCoef(x, i);
    }

    return result;
}

double getCoef(const double x, const int i)
{
    return x / (i + 1);
}
