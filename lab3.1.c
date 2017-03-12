#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
main()
{
    system("cls");
    printf("\nThis program will help you to calculate the number with entered power and accuracy.\n");
    getch();
    system("cls");
    do
    {
        system("cls");
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        double x, k, delta, y, yi, eps;
        int i, step;
        printf("\nEnter the number:\n");
        scanf("%lf", &x);
        if(getchar() != '\n')
        {
            printf("Error! Do not enter symbols.\n");
            fflush(stdin);
            getch();
            return main();
        }
        printf("Enter the power:\n");
        scanf("%lf", &k);
        if(getchar() != '\n')
        {
            printf("Error! Do not enter symbols.\n");
            fflush(stdin);
            getch();
            return main();
        }
        printf("Enter accuracy. Do not enter accuracy more than 1e-8 or not more than 0.\n");
        scanf("%lf", &eps);
        if(getchar() != '\n')
        {
            printf("Error! Do not enter symbols.\n");
            fflush(stdin);
            getch();
            return main();
        }
        if (eps >= 1)
        {
            printf("Error!.\n");
            getch();
            return main();
        }
        if (eps <= 0)
        {
            printf("Error!\n");
            getch();
            return main();
        }
        if(eps < 1e-8)
        {
            printf("Error! Too big accuracy.\n");
            getch();
            return main();
        }
       step = k;
       if ((x == 0 && step < 0) || (step < 0 && step % 2 == 0 && x < 0)||(step > 0 && step % 2==0 && x < 0) || step == 0)
        {
            printf("Error! Try again.\n");
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
        printf("Answer: %.*lf\n", n, y);
        getch();
        system("cls");
        printf("If you want to continue, please press any key, otherwise - press \"ESC\".\n");
    }
while(getch() != 27);
return 0;
}
