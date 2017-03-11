#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
int hello = 0;
int main()
{
    do
    {
        system("cls");
        const int N;
        int i, n, j, nMin, nMax, a;
        double t, b;
        if (hello == 0)
        {
            printf("This program sorts an array by inrease and decrease.\n");
            getch();
            hello++;
        }
        printf("Enter the amount of array's elements, it shouldn't be more than 100:\n");
        if(!(scanf("%d", &N)) || (getchar() != '\n'))
        {
            printf("Error! Do not enter rational numbers or symbols.\n");
            fflush(stdin);
            continue;
        }
        if (N <= 0)
        {
            printf("Error! N must be positive.\n");
            continue;
        }
        if(N > 100)
        {
            printf("Error! The number of elements shouldn't be more than 100.\n");
            continue;
        }
        double A[N];
        printf("Enter %d elements of array A:\n", N);
        printf("The number must be in range (-99999; -1e-6) U (1e-6;  99999) U {0}.\n");
        for(i = 0; i < N; i++)
        {
            printf("A[%d] = ", i+1);
            scanf("%lf", &A[i]);
            if(getchar() != '\n')
            {
                printf("Error! Do not enter symbols.\n");
                fflush(stdin);
                getch();
                printf("Try again.\n");
                --i;
                continue;
            }
            if(A[i] < -9999 || A[i] > 9999)
            {
                printf("Error! Do not enter numbers out of a range.\n");
                getch();
                printf("Try again.\n");
                --i;
                continue;
            }
            if((A[i] > -1e-6 && A[i]<0) || (A[i] < 1e-5&&A[i]>0))
            {
                printf("Error! Do not enter in range (-1e-5; 0) U (0; 1e-5).\n");
                getch();
                printf("Try again.\n");
                --i;
                continue;
            }
        }
        printf("Enter 1 if you want to sort array by increase and 2 - otherwise.\n");
        a = 0;
        while (a == 0)
        {
            if(!(scanf("%d", &n)) ||getchar() != '\n')
            {
            printf("Error! Do not enter rational numbers or symbols.\n");
                fflush(stdin);
                getch();
                printf("Try again.\n");
                continue;
            }
            if(n != 1 && n != 2)
            {
                printf("Error! Enter only 1 or 2.\n");
                getch();
                printf("Try again.\n");
                continue;
            }
            a++;
        }
        for(i = 0; i < N-1; i++)
        {
            nMin = i;
            for(j = i + 1; j < N; j++)
            if(A[j] < A[nMin])
            nMin = j;
            if(nMin != i)
            {
                t = A[i];
                A[i] = A[nMin];
                A[nMin] = t;
            }
        }
        if(n == 2)
        {
            for(i = 0; i < N/2; i++)
            {
                b = A[i];
                A[i] = A[N-1-i];
                A[N-1-i] = b;
            }
        }
        printf("Sorted array:\n");
        for(i = 0; i < N; i++)
        printf("A[%d] = %lf\n", i+1, A[i]);
        getch();
        system("cls");
        printf("If you want to continue, please press any key, otherwise - press \"ESC\".\n");
    }
    while(getch() != 27);
    return 0;
}
