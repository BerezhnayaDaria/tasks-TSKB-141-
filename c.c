#define _USE_MATH_DEFINES // for C
#include <stdio.h>
#include <math.h>

/**
 * @brief Вычисляет объём шара с заданным радиусом
 * @param radius Радиус шара
 * @return Рассчитанное значение объёма
 */
double getVolume(const double radius);

/**
 * @brief Вычисляет площадь поверхности шара
 * @param radius Радиус шара
 * @return Рассчитанное значение площади поверхности
 */
double getArea(const double radius);

/**
 * @brief Считывает с клавиатуры значение с плавающей точкой
 * @return Считанное значение
 */
double getDouble();

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно
 */
int main()
{
    double radius = getDouble();

    printf("Radius is %lf\n", radius);
    printf("Volume is %lf\n", getVolume(radius));
    printf("Area is %lf\n", getArea(radius));

    return 0;
}

double getVolume(const double radius)
{
    return 4.0 / 3.0 * M_PI * pow(radius, 3);
}

double getArea(const double radius)
{
    return 4.0 * M_PI * pow(radius, 2);
}

double getDouble()
{
    double radius = 0.0;

    printf("Enter radius: ");
    scanf("%lf", &radius);

    return radius;
}
