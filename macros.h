// macros.h
// власний заголовний файл з макросами для Завдання 9.2 (частина 1, варіант 23)
#pragma once

#include <stdio.h>

#define MAX(a, b) (((a) > (b)) ? (a) : (b)) // максимум з двох
#define MIN(a, b) (((a) < (b)) ? (a) : (b)) // мінімум з двох
#define ABS(a) (((a) < 0) ? -(a) : (a))     // модуль
#define SQR(a) ((a) * (a))                  // квадрат
#define CUBE(a) ((a) * (a) * (a))           // куб

// виведення повідомлення та значення дійсного числа
#define PRINTR(w) printf(#w " = %f\n", (double)(w))