/*
  lab_9_2_1.cpp
  Завдання 9.2, частина 1, варіант 23.
*/
#include <stdio.h>
#include "macros.h"

#ifndef Z
#define Z 2 // значення z за замовчуванням
#endif

int main()
{
    double x, y, w;
    const double z = Z; // значення z (для використання у виразах)

    printf("z = %d\n", Z);
    printf("x = ");
    scanf("%lf", &x);
    printf("y = ");
    scanf("%lf", &y);

#if (Z > 1) && (Z < 3)
    // гілка 1: 1 < z < 3
    puts("branch: max(|x|+|y|+|z|, x^3)");
    w = MAX(ABS(x) + ABS(y) + ABS(z), CUBE(x));
    PRINTR(w);
#elif (Z > 3)
    // гілка 2: z > 3
    puts("branch: min(2x+y, (2y-z)^2)");
    w = MIN(2 * x + y, SQR(2 * y - z));
    PRINTR(w);
#else
    // z <= 1 або z = 3 – функція не визначена
    puts("error: function is not defined for this z");
    (void)w;
#endif

    return 0;
}