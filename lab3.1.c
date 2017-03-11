#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    system("cls");
    printf("\nВітаю. за допомогою цієї програми Ви можете обчислити число, що дорівнює корню\nзаданого степеня деякого числа із заданою точністю.\n");
    getch();
    system("cls");
    do
    {
        system("cls");
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        double x, k, delta, y, yi, eps;
        int i, step;
        printf("\nВведіть число, корінь з якого хочете шукати.\n");
        scanf("%lf", &x);
        if(getchar() != '\n')
        {
            printf("Помилка! Не вводіть символи.\n");
            fflush(stdin);
            getch();
            return main();
        }
        printf("Введіть степінь корня.\n");
        scanf("%lf", &k);
        if(getchar() != '\n')
        {
            printf("Помилка! Не вводіть символи.\n");
            fflush(stdin);
            getch();
            return main();
        }
        printf("Введіть точність обчислення. Наприклад, 1e-4. Або ж 0.001.\nНе вводіть точність, що > 1e-8, або <= 0.\n");
        scanf("%lf", &eps);
        if(getchar() != '\n')
        {
            printf("Помилка! Не вводіть символи.\n");
            fflush(stdin);
            getch();
            return main();
        }
        if (eps >= 1)
        {
            printf("Помилка! Задана точність не може бути більша або дорівнювати одиниці.\n");
            getch();
            return main();
        }
        if (eps <= 0)
        {
            printf("Помилка! Задана точність не може бути менша або дорівнювати нулю.\n");
            getch();
            return main();
        }
        if(eps < 1e-8)
        {
            printf("Помилка! Занадто велика задана точність.\n");
            getch();
            return main();
        }
       step = k;
       if ((x == 0 && step < 0) || (step < 0 && step % 2 == 0 && x < 0)||(step > 0 && step % 2==0 && x < 0) || step == 0)
        {
            printf("Помилка! Спробуйте ще раз.\n");
            fflush(stdin);
            getch();
            return main();
        }
        int n = 0;
        double p = eps;
        while(p<1)
        {
            p *= 10;
            n++;
        }
        y = 1;
        delta = 1;
        if(k<0)
        {
            k = -k;
            y = 1 / y;
        }
        yi = y;
        while(delta > eps)
        {
            for(i = 0; i < (k - 2); i++)
            {
                yi = y * yi;
            }
            delta=(1 / k) * ((x / yi) - y);
            y += delta;
            if (delta < 0)
            {
                delta = -delta;
            }
            yi = y;
        }
         if(k == 1 || x == 0)
            y = x;
        printf("Відповідь: %.*lf\n", n, y);
        getch();
        system("cls");
        printf("Якщо Ви хочете продовжити, натисніть будь-яку клавішу. В іншому випадку - натисніть \"ESC\".\n");
    }
while(getch() != 27);
return 0;
}
