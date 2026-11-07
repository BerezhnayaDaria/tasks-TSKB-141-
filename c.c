#include <stdio.h>
#include <stdlib.h>

/**
* @brief функция для ввода положительного сопротивления
* @param message - сообщение для пользователя
* @return введённое значение сопротивления
*/
double inputResistance(const char *message);

/**
* @brief функция для расчёта общего сопротивления параллельного соединения
* @param R1 - первое сопротивление
* @param R2 - второе сопротивление
* @param R3 - третье сопротивление
* @return рассчитанное общее сопротивление
*/
double resistance(double const R1, double const R2, double const R3);

/**
* @brief точка входа в программу
* @return возвращает 0, если программа выполнена корректно
*/
int main()
{
    printf("Расчёт сопротивления параллельного соединения\n");
    printf("---------------------------------------------\n");

    /* Ввод сопротивлений */
    double R1 = inputResistance("Введите сопротивление R1, Ом: ");
    double R2 = inputResistance("Введите сопротивление R2, Ом: ");
    double R3 = inputResistance("Введите сопротивление R3, Ом: ");
    double R = resistance(R1, R2, R3);

    /* Вывод исходных данных и результата */
    printf("\nИсходные данные:\n");

    printf("R1 = %.2f Ом\n", R1);
    printf("R2 = %.2f Ом\n", R2);
    printf("R3 = %.2f Ом\n", R3);

    printf("\nРезультат вычисления:\n");
    printf("Общее сопротивление R = %.2f Ом\n", R);

    return 0;
}

/* Функция для ввода положительного сопротивления */
double inputResistance(const char *message)
{
    double value = 0.0;
    int result = 0;

    /* Проверяем, что указатель не пустой */
    if (message == NULL)
    {
        printf("Ошибка: сообщение не задано.\n");
        exit(EXIT_FAILURE);
    }

    printf("%s", message);

    /* Пытаемся считать вещественное число */
    result = scanf("%lf", &value);

    /* Проверяем корректность ввода */
    if (result != 1)
    {
        printf("Ошибка: введено некорректное значение.\n");
        exit(EXIT_FAILURE);
    }
    else if (value > 0)
    {
        return value;
    }
    else
    {
        printf("Ошибка! Сопротивление должно быть положительным числом.\n");
        exit(EXIT_FAILURE);
    }
}

/* Функция для расчёта общего сопротивления параллельного соединения */
double resistance(double const R1, double const R2, double const R3)
{
    return (R1 * R2 * R3) /
           (R1 * R2 + R1 * R3 + R2 * R3);
}
