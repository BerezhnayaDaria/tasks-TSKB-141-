#include <stdio.h>
#include <math.h>
#include <float.h>
#include <stdlib.h>

/**
 * @brief cчитывает с клавиатуры значение с плавающей точкой
 * @return cчитанное значение
 */
double GetDouble();

/**
 * @brief возводит число в квадрат, если оно неотрицательное и в четвертую степень, если отрицательное
 * @param value исходное число
 * @return преобразованное число
 */
double ProcessNumber(const double value);

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно, иначе не 0
 */
int main() {
    printf("Enter first number: ");
    const double a = GetDouble();
    
    printf("Enter second number: ");
    const double b = GetDouble();
    
    printf("Enter third number: ");
    const double c = GetDouble();

    printf("Result a = %lf\n", ProcessNumber(a));
    printf("Result b = %lf\n", ProcessNumber(b));
    printf("Result c = %lf\n", ProcessNumber(c));
    
    return 0;
}

double GetDouble(){
    double value = 0.0;
    if (scanf("%lf", &value) != 1){
        printf("Error");
        exit(1);
    }
    return value;
}

double ProcessNumber(const double value){
    if (value >= 0.0) {
        return pow(value, 2);
    }
    if (value < 0.0) {
        return pow(value, 4);
    }
    return value;
}
