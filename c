#include <stdio.h>
 
/* Функция для ввода положительного сопротивления */
double inputResistance(const char *message)
{
    double value;
    int result;
    int symbol;
 
    while (1)
    {
        printf("%s", message);
 
        /* Пытаемся считать вещественное число */
        result = scanf("%lf", &value);
 
        /* Проверяем, что введено число больше нуля */
        if (result == 1 && value > 0)
        {
            return value;
        }
 
        printf("Ошибка! Сопротивление должно быть положительным числом.\n");
 
        /* Очищаем строку ввода */
        while ((symbol = getchar()) != '\n' && symbol != EOF)
        {
        }
    }
}
 
int main(void)
{
    double R1;
    double R2;
    double R3;
    double R;
 
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
