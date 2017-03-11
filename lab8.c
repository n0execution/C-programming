#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <math.h>

void contur_1(double R1, double R2, double L, double C, double W);
void contur_2(double R1, double R2, double L, double C, double W);
void contur_3(double R1, double R2, double L, double C, double W);
void contur_4(double R1, double R2, double L, double C, double W);
double f1, f2, df;
double R, R1, R2;
double L, C;
double F, W;
struct Complex
{
    double dod1, dod2
} X;

int main()
{
    printf("This program calculates complex resistance.\n");
    getch();
    do
    {
        system("cls");
        int contur, counter;
        int m, n, ek;
        void (*p) (double, double, double, double, double);
        printf("Enter number of contour from 1 дto 4.\n");
        scanf("%d", &contur);
        if(getchar() != '\n')
        {
            printf("Error! Do not enter rational numbers or symbols.\n");
            fflush(stdin);
            getch();
            continue;
        }
        if(contur != 1 && contur != 2 && contur != 3 && contur != 4)
        {
            printf("Error! Enter numbers from 1 to 4.\n");
            getch();
            continue;
        }
        m = 0;
        while(m == 0)
        {
            printf("Enter first and second value of frequency (Hz) in range (0; 1000].\n");
            scanf("%lf %lf", &f1, &f2);
            if(getchar() != '\n')
            {
                printf("Error! Do not enter symbols.\n");
                fflush(stdin);
                continue;
            }
            if(f1 > f2)
            {
                printf("Error! First value shouldn't be more than second.\n");
                continue;
            }
            if(f1<= 0 || f2 <= 0 || f1 > 1000 || f2 > 1000)
            {
                printf("Error! Value is out of range.\n");
                continue;
            }
            if((f1 > 0 && f1 < 1e-6) ||(f1 > 0 && f1 < 1e-6) )
            {
                printf("Error! Try again.\n");
                getch();\
                continue;
            }
            m++;
        }
        while(m == 1)
        {
            printf("Enter step of frequency's change.\n");
            scanf("%lf", &df);
            if(getchar() !=  '\n')
            {
                printf("Error! Do not enter symbols.\n");
                fflush(stdin);
                getch();
                continue;
            }
            if(df <= 0)
            {
                printf("Error! Step should be more than zero.\n");
                getch();
                continue;
            }
            if(df > 0 && df < 1e-6)
            {
                printf("Error! Step should be more than 1е-6\n");
                getch();
                continue;
            }
            m++;
        }
        while(m == 2)
        {
            ek = 0;
            if(contur == 1 || contur == 2)
            {
                printf("Enter first resistance(Om) in range (0; 1000].\n");
            }
            else
            {
                printf("Enter first resistance (Om) in range (0; 1000].\n");
                ek = 1;
            }
            scanf("%lf", &R1);
            if(getchar() != '\n')
            {
                printf("Error! Do not enter symbols.\n");
                fflush(stdin);
                getch();
                continue;
            }
            if(R1 > 1000 || R1 <= 0 )
            {
                printf("Error! Value is out of range.\n");
                continue;
            }
            if(R1 > 0 && R1 < 1e-6)
            {
                printf("Error! Value should be more than 1е-6\n");
                getch();
                continue;
            }
            if(ek == 1)
                do
                {
                    n = 0;
                printf("Enter second resistance(Om) in range (0; 1000].\n");
                    scanf("%lf", &R2);
                    if(getchar() != '\n')
                    {
                printf("Error! Do not enter symbols.\n");
                        fflush(stdin);
                        getch();
                        continue;
                    }
                    if(R2 > 1000 || R2 <= 0 )
                    {
                printf("Error! Value is out of range.\n");
                        continue;
                    }
                    if(R1 > 0 && R1 < 1e-6)
                    {
                printf("Error! Value should be more than 1е-6\n");
                        getch();
                        continue;
                    }
                    n++;
                }
                while(n = 0);
                m++;
        }
        while(m == 3)
        {
            printf("Enter inductance (Gn) in range (0; 1000].\n");
            scanf("%lf", &L);
            if(getchar() != '\n')
            {
                printf("Error! Do not enter symbols.\n");
                fflush(stdin);
                getch();
                continue;
            }
            if(L > 1000 || L <= 0 )
            {
                printf("Error! Value is out of range.\n");
                continue;
            }
            if(L > 0 && L < 1e-6)
            {
                printf("Error! Value should be more than 1е-6\n");
                getch();
                continue;
            }
            m++;
        }
        while(m == 4)
        {
            printf("Enter capacity (mcF) in range (0; 1000].\n");
            scanf("%lf", &C);
            if(getchar() != '\n')
            {
                printf("Error! Do not enter symbols.\n");
                fflush(stdin);
                getch();
                continue;
            }
            if(C > 1000 || C <= 0 )
            {
                printf("Error! Value is out of range.\n");
                continue;
            }
            if(C > 0 && C < 1e-6)
            {
                printf("Error! Value should be more than 1е-6\n");
                getch();
                continue;
            }
            m++;
        }
        switch(contur)
        {
            case 1: p = contur_1;
                break;
            case 2: p = contur_2;
                break;
            case 3: p = contur_3;
                break;
            case 4: p = contur_4;
            break;
        }
        F = 1. / (2. * M_PI * sqrt(L * C));
        W = 1 / sqrt(L * C);
        p(R1, R2, L, C, W);
        printf("_______________________________________________________________________________________________________");
		printf("The resonant frequency: %g		Complex resistance: %g + i*%g\n", F, X.dod1, X.dod2);
		printf("_______________________________________________________________________________________________________");
		printf("„астота\t\t\t\t\tComplex resistance\t\t\t\n");
        printf("_______________________________________________________________________________________________________");

		do
		{
		    W = 2 * M_PI * f1;
		    p(R1, R2, L, C, W);
		    printf("%lf\t\t\t\t%g + i*%g\t\n", f1, X.dod1, X.dod2);
		    f1 += df;
			counter++;
			if(counter%10==0)
            {
                printf("\n\n\t------Press any key to continue.------\n\n");
                getch();
           }
		}
		while(f1 <= f2);
		 printf("_______________________________________________________________________________________________________");
		getch();
		system("cls");
        printf("If you want to continue, please press any key, otherwise - press \"ESC\".\n");
    }
    while(getch() != 27);
}

void contur_1(double R1, double R2, double L, double C, double W)
{
    double a, b, c, d;
    a = L / C;
    b = -R1 / (W * C);
    c = R1;
    d = W * L - 1 / (W * C);
    X.dod1 = (a * c + b * d) / (pow(c, 2) + pow(d, 2));
    X.dod2 = (b * c - a * d) / (pow(c, 2) + pow(d, 2));
}

void contur_2 (double R1, double R2, double L, double C, double W)
{
    double a, b, c, d;
    a = L /C;
    b = R1 / (W * C);
    c = R1;
    d = W * L - 1 / (W * C);
    X.dod1 = (a * c + b * d) / (pow(c, 2) + pow(d, 2));
    X.dod2 = (b * c - a * d) / (pow(c, 2) + pow(d, 2));
}

void contur_3 (double R1, double R2, double L, double C, double W)
{
    double a, b, c, d;
    a = R1 * R2;
    b = R1 * (W * L - 1 / (W * C));
    c = R1 + R2;
    d = W * L - 1 / (W * C);
    X.dod1 = (a * c + b * d) / (pow(c, 2) + pow(d, 2));
    X.dod2 = (b * c - a * d) / (pow(c, 2) + pow(d, 2));
}

void contur_4 (double R1, double R2, double L, double C, double W)
{
    double a, b, c, d;
    a = R1 * R2 + L / C;
    b = (W * L * R1) - R2 / (W * C);
    c = R1 + R2;
    d = W * L - 1 / (W * C);
    X.dod1 = (a * c + b * d) / (pow(c, 2) + pow(d, 2));
    X.dod2 = (b * c - a * d) / (pow(c, 2) + pow(d, 2));
}
