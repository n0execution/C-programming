#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <math.h>
double f1(double x, double y);
double f2(double x, double y);

int main()
{
    printf("This program solves non-linear rows on defined range.\n");
    getch();
    do
    {
        int  method, equation;
        int k;
        double a1, a2, y, eps;
        double (*p)(double, double);
        system("cls");
        k = 0;

        while(k == 0)
        {
            printf("Enter minimal value in range [-1000; 0) U (0; 1000]:\n");
            scanf("%lf", &a1);
            if(getchar() != '\n')
            {
                printf("Error! Do not enter symbols.\n");
                fflush(stdin);
                getch();
                system("cls");
                continue;
            }
            if(fabs(a1) > 1000 || a1 == 0)
            {
                printf("Error! Do not enter number out of this range.\n");
                getch();
                system("cls");
                continue;
            }
            if((a1 < 0 && a1 > -1e-5) || (a1 > 0 && a1 < 1e-5))
            {
                printf("Error! Try again.\n");
                getch();
                system("cls");
                continue;
            }
            k++;
        }

        while(k == 1)
        {
            printf("Enter maximal value in range [-1000; 0) U (0; 1000]:\n");
            scanf("%lf", &a2);
            if(getchar() != '\n')
            {
                printf("Error! Do not enter symbols.\n");
                fflush(stdin);
                getch();
                system("cls");
                continue;
            }
            if(fabs(a2) > 1000 || a2 == 0)
            {
                printf("Error! Do not enter number out of this range.\n");
                getch();
                system("cls");
                continue;
            }
            if((a2 < 0 && a2 > -1e-5) || (a2 > 0 && a2 < 1e-5))
            {
                printf("Error! Try again.\n");
                getch();
                system("cls");
                continue;
            }
            if(a1 > a2)
            {
                printf("Error! First value shouldn't be more than second.\n");
                getch();
                system("cls");
                continue;
            }
            if((a1 + a2) == 0)
            {
                printf("Error! values shouldn't be opposite.\n");
                getch();
                system("cls");
                continue;
            }
            k++;
        }

        while(k == 2)
        {
            printf("Enter parameter in range [-1000; 1000]:\n");
            scanf("%lf", &y);
            if(getchar() != '\n')
            {
                printf("Error! Do not enter symbols.\n");
                fflush(stdin);
                getch();
                system("cls");
                continue;
            }
            if(fabs(y) > 1000)
            {
                printf("Error! Do not enter number out of this range.\n");
                getch();
                system("cls");
                continue;
            }
            if((y < 0 && y > -1e-5) || (y > 0 && y < 1e-5))
            {
                printf("Error! Try again.\n");
                getch();
                system("cls");
                continue;
            }
            k++;
        }

        while(k == 3)
        {
            printf("Enter accuracy from 1å-6 to 1.\n");
            scanf("%lf", &eps);
            if(getchar() != '\n')
            {
                printf("Error! Do not enter symbols.\n");
                fflush(stdin);
                getch();
                system("cls");
                continue;
            }
            if(eps >= 1)
            {
                printf("Error! Accuracy is too big.\n");
                getch();
                system("cls");
                continue;
            }
            if(eps < 1e-6)
            {
                printf("Error! Accuracy is too small.\n");
                getch();
                system("cls");
                continue;
            }
            k++;
        }

        while(k == 4)
        {
            printf("Enter 1 if you want to solve cos(y / x) - 2sin(1 / x) + 1 / x = 0\n");
            printf("and 2if you solve sin(lnx) - cos(lnx) + ylnx = 0.\n");
            scanf("%d", &equation);
            if(getchar() != '\n')
            {
                printf("Error! Do not enter symbols.\n");
                fflush(stdin);
                getch();
                system("cls");
                continue;
            }
            if(equation != 1 && equation != 2)
            {
                printf("Error! Enter only 1 or 2.\n");
                getch();
                system("cls");
                continue;
            }
            k++;
        }

        while (k == 5)
        {
            printf("Enter 1if you use method by half-division and 2 if you use Newton method.\n");
            scanf("%d", &method);
            if(getchar() != '\n')
            {
                printf("Error! Do not enter symbols.\n");
                fflush(stdin);
                getch();
                system("cls");
                continue;
            }
            if(method != 1 && method != 2)
            {
                printf("Error! Enter only 1 or 2.\n");
                getch();
                system("cls");
                continue;
            }
            k++;
        }

        if(equation == 1)
            p = f1;
        else
            p = f2;

        if(method == 1)
            bisection(y, a1, a2, eps, p);
        else
            newton(y, a1, a2, eps, p);

        getch();
        system("cls");
        printf("If you want to continue, please press any key, otherwise - press \"ESC\".\n");
    }
    while(getch() != 27);
    return(0);
}

double f1(double x, double y)
{
    return(cos(y / x) - 2.0 * sin(1.0 / x) + 1.0 / x);
}

double f2(double x, double y)
{
    return(sin(log(x)) -   cos(log(x)) + y * (log(x)));
}

void bisection(double y, double a, double b, double eps, double (*f)(double, double))
{
    double x=0, function_a=0, function_x=0;
    int m, l = 0;
    double d = eps;
    while(d < 1)
    {
        d = d * 10;
        l++;
    }
    do
    {
        x = (a + b) / 2;
        function_x = f(x, y);
        function_a = f(a, y);
        if(function_a * function_x > 0)
            a = x;
        else
            b = x;
    }
    while(fabs(a - b) > eps);
    if(f(x,y) > 1e-4)
    {
        printf("Error! Unfortunately, there are no rows in this equation.\n");
        m = 0;
    }
    if(m != 0)
        printf("Your answer: %.*lf", l,  x);
}

void newton(double y, double a, double b, double eps, double (*f)(double, double))
{
        int m, l = 0;
        double d = eps;
        while(d < 1)
        {
            d = d * 10;
            l++;
        }
    double delta=0, derivative=0, x, e=0.00000000000001;
    int n=0;
    x=b;
    do
    {
        derivative = (f(x + e, y) - f(x, y)) / e;
        delta = f(x, y) / derivative;
        x = x - delta;
        n++;
        if(n>100)
        {
            printf("Error! Can't solve in this case.");
            m = 0;
            break;
        }
    }
    while(fabs(delta) > eps);
    if(f(x,y) > 1e-4)
    {
        printf("Error! There are no rows in this range.\n");
        m = 0;
    }
    if(m != 0)
        printf("Your answer: %.*lf", l, x);
}
