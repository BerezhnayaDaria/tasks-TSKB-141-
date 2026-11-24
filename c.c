#include <stdio.h>
#include <stdlib.h>
#include <float.h>

/**
 * @brief считывает с клавиатуры целочисленное значение
 * @param message  сообщение для пользователя
 * @return считанное значение
 */
int getInt(const char* message);

/**
 * @brief считывает с клавиатуры значение с плавающей точкой
 * @param message  сообщение для пользователя
 * @return считанное значение
 */
double getValue(const char* message);

/**
 * @brief проверяет, что значение n является положительным числом
 * @param n  значение параметра n
 */
void checkPositive(const int n);

/**
 * @brief проверяет, что значение e является положительным числом
 * @param e  значение параметра e
 */
void checkEpsilon(const double e);

/**
 * @brief вычисляет сумму первых n членов последовательности
 * @param n  количество членов последовательности
 * @return Рассчитанная сумма
 */
double sumN(const int n);

/**
 * @brief вычисляет сумму членов последовательности, модуль которых не меньше e
 * @param e  заданная точность вычислений
 * @return рассчитанная сумма
 */
double sumE(const double e);

/**
 * @brief вычисляет значение данной функции
 * @param i  номер текущего члена последовательности
 * @return рассчитанный коэффициент
 */
double getCoef(const int i);

/**
*@brief точка входа в программу
*@return возвращает 0, если программа выполнена корректно
*/
int main()
{
    int n = getInt("Enter n: ");
    checkPositive(n);

    double e = getValue("Enter e: ");
    checkEpsilon(e);

    printf("Summ of %d elements is: %lf\n", n, sumN(n));
    printf("Summ of elements less %lf is: %lf\n", e, sumE(e));

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

int getInt(const char* message)
{
    if (message != NULL)
    {
        printf("%s\n", message);
    }

    int value = 0;

    if (scanf("%d", &value) != 1)
    {
        printf("Input error");
        exit(1);
    }

    return value;
}

void checkPositive(const int n)
{
    if (n <= 0)
    {
        printf("Error, n have to be positive\n");
        exit(1);
    }
}

void checkEpsilon(const double e)
{
    if (e <= 0)
    {
        printf("Error, e have to be positive\n");
        exit(1);
    }
}

double sumN(const int n)
{
    double a = 1.0;
    double result = a;

    for (int i = 0; i < n; i++)
    {
        a *= getCoef(i);
        result += a;
    }

    return result;
}

double getCoef(const int i)
{
    return -1.0 / (i + 1);
}

double sumE(const double e)
{
    double a = 1.0;
    double result = 0;

    for (int i = 0; fabs(a) >= e; i++)
    {
        result += a;
        a *= getCoef(i);
    }

    return result;
}
