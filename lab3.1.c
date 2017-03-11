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
    printf("\n³���. �� ��������� ���� �������� �� ������ ��������� �����, �� ������� �����\n�������� ������� ������� ����� �� ������� �������.\n");
    getch();
    system("cls");
    do
    {
        system("cls");
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        double x, k, delta, y, yi, eps;
        int i, step;
        printf("\n������ �����, ����� � ����� ������ ������.\n");
        scanf("%lf", &x);
        if(getchar() != '\n')
        {
            printf("�������! �� ������ �������.\n");
            fflush(stdin);
            getch();
            return main();
        }
        printf("������ ������ �����.\n");
        scanf("%lf", &k);
        if(getchar() != '\n')
        {
            printf("�������! �� ������ �������.\n");
            fflush(stdin);
            getch();
            return main();
        }
        printf("������ ������� ����������. ���������, 1e-4. ��� � 0.001.\n�� ������ �������, �� > 1e-8, ��� <= 0.\n");
        scanf("%lf", &eps);
        if(getchar() != '\n')
        {
            printf("�������! �� ������ �������.\n");
            fflush(stdin);
            getch();
            return main();
        }
        if (eps >= 1)
        {
            printf("�������! ������ ������� �� ���� ���� ����� ��� ���������� �������.\n");
            getch();
            return main();
        }
        if (eps <= 0)
        {
            printf("�������! ������ ������� �� ���� ���� ����� ��� ���������� ����.\n");
            getch();
            return main();
        }
        if(eps < 1e-8)
        {
            printf("�������! ������� ������ ������ �������.\n");
            getch();
            return main();
        }
       step = k;
       if ((x == 0 && step < 0) || (step < 0 && step % 2 == 0 && x < 0)||(step > 0 && step % 2==0 && x < 0) || step == 0)
        {
            printf("�������! ��������� �� ���.\n");
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
        printf("³������: %.*lf\n", n, y);
        getch();
        system("cls");
        printf("���� �� ������ ����������, �������� ����-��� ������. � ������ ������� - �������� \"ESC\".\n");
    }
while(getch() != 27);
return 0;
}
