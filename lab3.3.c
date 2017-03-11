#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <math.h>

int main()
{
    printf("This program calculates cubic equation.\n");
    getch();
    do
    {
        system("cls");
        double a, b, c;
        double p, q, d, y1, y2, y3, aa, bb, u, v, fi, r, ut, zero, x, x1, x2, x3;
        printf("Enter а.\n");
        if (!scanf("%lf", &a) || getchar() != '\n')
        {
            printf("Error! Do not enter rational numbers or symbols.\n");
            fflush(stdin);
            continue;
        }
        printf("¬вед≥ть b.\n");
        if (!scanf("%lf", &b) || getchar() != '\n')
        {
            printf("Error! Do not enter rational numbers or symbols.\n");
            fflush(stdin);
            continue;
        }
        printf("¬вед≥ть c.\n");
        if (!scanf("%lf", &c) || getchar() != '\n')
        {
            printf("Error! Do not enter rational numbers or symbols.\n");
            continue;
        }
        p = b - (pow(a, 2)/3.);
        q = ((2. * pow(a, 3.)) / 27.) - ((a * b) / 3.) + c;
        d = ((pow (p, 3.)) / 27.) + ((pow(q, 2.)) / 4.);
        if (d > 0)
        {
            if(p==0)
            {
                printf("Error! This method doesn't calculate the equation.\n");
                continue;
            }
            u = cbrt((-q / 2.) + sqrt(d));
            v = -p/(3*u);
            x1 = (u + v) - (a / 3.);
            aa = (-1.)*((u + v) / 2.);
            x2 = aa - (a / 3.);
            bb = ((sqrt(3)) * (u - v)) / 2.;
            printf("D > 0. One real row: \nx1 = %lf\n", x1);
            printf("and two complex: \nx2 = %lf + i*%lf,\nx3 = %lf - i*%lf.\n", x2, bb, x2, bb);
        }
        else if (d == 0)
        {
            if (p == 0 && q == 0)
            {
                x = -a/3.0;
                printf("D = 0. One real row: \nx = %lf.\n", x);
            }
            else
            {
                y1 = (3. * q) / p;
                y2 = (-3. * q) / (2. * p);
                y3 = y2;
                x1 = y1 - (a / 3.);
                x2 = y2 - (a / 3.);
                printf("D = 0. Three real rows: \nx1 = %lf,", x1);
                printf("\nx2 = %lf\nx3 = %lf.\n", x2, x2);
            }
        }
        else if (d < 0)
        {
            r = sqrt((pow((-1) * p,  3.)) / 27.);
            fi = acos ((-1) *(q / (2. * r)));
            y1 = (2. * fabs(cbrt(r))) * (cos (fi / 3.));
            y2 = 2. * fabs(cbrt(r)) * cos ((fi + 2. * M_PI) / 3.);
            y3 = 2. * fabs(cbrt(r)) * cos ((fi + 4. * M_PI) / 3.);
            x1 = y1 - a / 3.;
            x2 = y2 - a / 3.;
            x3 = y3 - a / 3.;
            printf("D < 0. Three real rows: \nx1 = %lf,\n", x1);
            printf("x2 = %lf, \nx3 = %lf", x2, x3);
        }
        getch();
        system("cls");
        printf("If you want to continue, please press any key, otherwise - press \"ESC\".\n");
    }
    while(getch() != 27);
    return 0;
}
