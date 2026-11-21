#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <stdbool.h>

/**
 * @brief cчитывает с клавиатуры значение с плавающей точкой
 * @param message  сообщение для пользователя
 * @return cчитанное значение
 */
double getValue(const char* message);

/**
 * @brief проверяет, что шаг положительный
 * @param step  значение шага
 */
void checkStep(const double step);

/**
 * @brief проверяет правильность заданного интервала
 * @param xbegin  начало интервала
 * @param xend  конец интервала
 */
void checkSegment(const double xbegin, const double xend);

/**
 * @brief проверяет, принадлежит ли точка области определения функции
 * @param x  значение параметра х
 * @return true, если точка принадлежит области определения, иначе false
 */
bool isOOF(const double x);

/**
 * @brief вычисляет значение заданной функции
 * @param x  значение параметра х
 * @return рассчитанное значение функции
 */
double getY(const double x);

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно
 */
int main()
{
    double xbegin = getValue("Enter segment start: ");
    double xend = getValue("Enter segment end: ");
    double step = getValue("Enter step: ");

    checkStep(step);
    checkSegment(xbegin, xend);

    for (double x = xbegin; x < xend + step; x += step)
    {
        if (isOOF(x))
        {
            printf("x = %lf, y = %lf\n", x, getY(x));
        }
        else
        {
            printf("x = %lf, y is not define\n", x);
        }
    }

    return 0;
}

double getValue(const char* message)
{
    if (message != NULL)
    {
        printf("%s\n", message);
    }

    double value = 0;

    if (scanf("%lf", &value) != 1)
    {
        printf("Input error");
        exit(1);
    }

    return value;
}

void checkStep(const double step)
{
    if (step <= 0)
    {
        printf("Error, step have to be positive");
        exit(1);
    }
}

void checkSegment(const double xbegin, const double xend)
{
    if (xbegin > xend)
    {
        printf("Error, segment begin have to be "
        "less or equal segment end");
        exit(1);
    }
}

bool isOOF(const double x)
{
    return (x >= 0);
}

double getY(const double x)
{
    return x + sqrt(x) + cbrt(x) - 2.5;
}
