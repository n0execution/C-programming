#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
main()
{
    int hello = 0;
    do
    {
        system("cls");
        double x, x1, x2, eps, dx, rdx, delta, xtaylor, diff, xtabl, r1, r2, d, f;
        int n, k, a;
        if(hello == 0)
        {
            printf("This program calculates sine by Taylor schedule");
			hello++;
            getch();
            system("cls");
        }
        printf("Enter minimum value x1:\n");
        scanf("%lf", &x1);
        if(getchar() !='\n')
        {
            printf("Error! Do not enter symbols.\n");
            fflush(stdin);
            continue;
        }
        if(fabs(x1) > 2300)
        {
            printf("Error! Entered angle must be from -2300 to 2300.\nTry again.\n");
            continue;
        }
        a = 0;
        while(a == 0)
        {
            printf("Enter maximum value x2.\n");
            scanf("%lf", &x2);
            if(getchar() !='\n')
            {
            printf("Error! Do not enter symbols.\n");
                fflush(stdin);
                getch();
                printf("Try again.\n");
                continue;
            }
            if(fabs(x2) > 2300)
            {
            printf("Error! Entered angle must be from -2300 to 2300.\n");
                getch();
                printf("Try again.\n");
                continue;
            }
            a++;
        }
        while(a == 1)
        {
            printf("Enter the step of change:\n");
            scanf("%lf", &dx);
            if(getchar() !=  '\n')
            {
            printf("Error! Do not enter symbols.\n");
                fflush(stdin);
                getch();
                printf("Try again.\n");
                continue;
            }
            if(x1 < x2 && dx < 0)
            {
                printf("Error! In this case step must be more than zero.\n");
                getch();
                printf("Try again.\n");
                continue;
            }
            if(x1 > x2 && dx > 0)
            {
                printf("Error! In this case step must be less than zero.\n");
                getch();
                printf("Try again.\n");
                continue;
            }
            if(dx == 0)
            {
                printf("Error! In this case step must not be zero.\n");
                getch();
                printf("Try again.\n");
                continue;
            }
            a++;
        }
        while (a == 2)
        {
            printf("Enter accuracy from 1å-6 to 1:\n");
            scanf("%lf", &eps);
            if(getchar() !=  '\n')
            {
            printf("Error! Do not enter symbols.\n");
                fflush(stdin);
                getch();
                printf("Try again.\n");
                continue;
            }
            if(eps <= 0)
            {
                printf("Error! Accuracy must be more than zero.\n");
                getch();
                printf("Try again.\n");
                continue;
            }
            if(eps < 1e-6)
            {
                printf("Error!.\n");
                getch();
                printf("Try again.\n");
                continue;
            }
            else if(eps >= 1)
            {
                printf("Error! Accuracy must be less than one.\n");
                getch();
                printf("Try again.\n");
                continue;
            }
            a++;
        }
        k = 0;
        int counter = 0;
        printf("%22s %12s %19s %12s\n\n", "Degree", "Sine", "Cosine(table)", "Difference");
        while(x1 < (x2 + dx / 2.0))
        {
            r1 = (x1 * M_PI) / 180.0;
            x = r1;
            delta = r1;
            xtaylor = r1;
            n = 1;
            xtabl = sin(x);
            while(fabs(delta) >= eps)
            {
                delta = (-1) * delta *  ((x * x ) / ((n + 1.) * (n + 2.)));
                xtaylor = xtaylor + delta;
                n = n + 2;
            }
            diff = xtabl - xtaylor;
            printf("\n\t%15lf %15.10lf %15.10lf %15.10lf\n", x1, xtaylor, xtabl, fabs(diff));
            x1 = x1 + dx;
            counter++;
            if(counter%10==0)
            {
                printf("\n\n\t------Press any key to continue.------\n\n");
                getch();
           }
        }
            while(x1 > x2 + dx /2 && dx < 0)
            {
            r1 = (x1 * M_PI) / 180.0;
            x = r1;
            delta = r1;
            xtaylor = r1;
            n = 1;
            xtabl = sin(x);
            while(fabs(delta) >= eps)
            {
                delta = (-1) * delta *  ((x * x ) / ((n + 1.) * (n + 2.)));
                xtaylor = xtaylor + delta;
                n = n + 2;
            }
            f = x1;
            x1 = x1 + dx;
            diff = xtabl - xtaylor;
            printf("\n\t%15lf %15lf %15lf %15lf\n", f,  xtaylor,  xtabl,  diff);
            counter++;
            if(counter%10==0)
            {
                printf("\n\n\t------Press any key to continue.------\n\n");
                getch();
            }
            }
        getch();
        system("cls");
        printf("If you want to continue, please press any key, otherwise - press \"ESC\".\n");
    }
    while(getch() != 27);
    return 0;
}
