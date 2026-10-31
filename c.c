#include <stdio.h>
#include <stdlib.h>

/* Функция для ввода положительного сопротивления */
double inputResistance(const char *message);

int main(void)
{
    double R1 = 0.0;
    double R2 = 0.0;
    double R3 = 0.0;
    double R = 0.0;

    printf("Расчёт сопротивления параллельного соединения\n");
    printf("---------------------------------------------\n");

    /* Ввод сопротивлений */
    R1 = inputResistance("Введите сопротивление R1, Ом: ");
    R2 = inputResistance("Введите сопротивление R2, Ом: ");
    R3 = inputResistance("Введите сопротивление R3, Ом: ");

    R = (R1 * R2 * R3) /
        (R1 * R2 + R1 * R3 + R2 * R3);

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

    while (1)
    {
        /* Проверяем, что указатель не пустой */
        if (message == NULL)
        {
            printf("Ошибка: сообщение не задано.\n");
            exit(EXIT_FAILURE);
        }

        printf("%s", message);

        /* Пытаемся считать вещественное число */
        result = scanf("%lf", &value);

        /* Проверяем, что введено число больше нуля */
        if (result == 1 && value > 0)
        {
            return value;
        }

        if (result != 1)
        {
            printf("Ошибка: введено некорректное значение.\n");
            exit(EXIT_FAILURE);
        }

        printf("Ошибка! Сопротивление должно быть положительным числом.\n");
    }
}
