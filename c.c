#define _USE_MATH_DEFINES // for C
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

enum Figure
{
    TRAPEZOID = 1,
    CIRCLE = 2
};

/**
 * @brief Считывает с клавиатуры значение с плавающей точкой
 * @return Считанное значение
 */
double getDouble();

/**
 * @brief Вычисляет площадь трапеции
 * @param side1 - значение первого основания
 * @param side2 - значение второго основания
 * @param height - значение высоты
 * @return Рассчитанное значение
 */
double sTrapezoid(const double side1, const double side2, const double height);

/**
 * @brief Вычисляет площадь круга
 * @param radius - значение радиуса
 * @return Рассчитанное значение
 */
double sCircle(const double radius);

/**
 * @brief Проверяет, что введено положительное число
 * @param side - считанное значение
 */
void checkSide(const double side);

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно, иначе не 0
 */
int main()
{
    enum Figure figure;
    int choice = 0;

    printf("Выберите фигуру (%d - трапеция, %d - круг):\n", TRAPEZOID, CIRCLE);

    if (scanf("%d", &choice) != 1)
    {
        printf("Ошибка");
        exit(EXIT_FAILURE);
    }

    figure = (enum Figure)choice;

    switch (figure)
    {
        case TRAPEZOID:
        {
            double side1 = getDouble();
            double side2 = getDouble();
            double height = getDouble();

            checkSide(side1);
            checkSide(side2);
            checkSide(height);

            printf("Площадь трапеции = %lf\n", sTrapezoid(side1, side2, height));
            break;
        }
        case CIRCLE:
        {
            double radius = getDouble();

            checkSide(radius);

            printf("Площадь круга = %lf\n", sCircle(radius));
            break;
        }
        default:
            printf("Ошибка");
            exit(EXIT_FAILURE);
    }

    return 0;
}

double getDouble()
{
    double side = 0.0;

    if (scanf("%lf", &side) != 1)
    {
        printf("Ошибка");
        exit(EXIT_FAILURE);
    }

    return side;
}

void checkSide(const double side)
{
    if (side <= 0)
    {
        printf("Ошибка");
        exit(EXIT_FAILURE);
    }
}

double sTrapezoid(const double side1, const double side2, const double height)
{
    return (side1 + side2) * height / 2;
}

double sCircle(const double radius)
{
    return M_PI * pow(radius, 2);
}
