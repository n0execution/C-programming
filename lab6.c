#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

int main()
{
    printf("This program solves system of linear algebraic equations.\n");
    getch();
    do
    {
        system("cls");
        int n;
        int a = 0;
        int i, j;
        double *X;
        double **A;
        double *B;
        double SUM;
        double summ, delta,  eps;
        printf("Enter size of matrix from 1 to 9:\n");
        if(!(scanf("%d", &n)) || getchar() != '\n')
        {
            printf("Error! Do not enter rational numbers or symbols.\n");
            fflush(stdin);
            continue;
        }
        if(n <= 0)
        {
            printf("Error! Size of matrix should be more than 0.\n");
            continue;
        }
        if(n > 9)
        {
            printf("Error! Size should be more than 9.\n");
            continue;
        }
        A = (double **) calloc (n, sizeof (double *));
        for ( i = 0; i < n; i++)
                A[i] = (double *) calloc (n, sizeof (double));
        B = (double *) calloc(n, sizeof(double));
        X = (double *) calloc(n, sizeof(double));
            printf("Enter matrix vector A:\n");
            for(i = 0; i < n; i++ )
            {
                SUM = 0;
                for(j = 0; j < n; j++)
                {
                    printf("A[%d][%d] = ", i+1, j+1);
                    scanf("%lf", &A[i][j]);
                    if(getchar() != '\n')
                    {
                        printf("Error! Do not enter symbols.\n");
                        fflush(stdin);
                        --j;
                        continue;
                    }
                    if(A[i][j] < -100000 || (A[i][j] < 0 && A[i][j] > -1e-6) || (A[i][j] > 0 && A[i][j] < 1e-6) || A[i][j] > 100000)
                    {
                        printf("Error!.\n");
                        --j;
                        continue;
                    }
                    if(i == j)
                        if(A[i][i] == 0)
                        {
                            printf("Error! Diagonal element should be not zero.\n");
                            --j;
                            continue;
                        }

                    if(i != j)
                        SUM += A[i][j];
                }
                if(fabs(A[i][i]) <= fabs(SUM))
                {
                    printf("Error!\n");
                    getch();
                    i--;
                    printf("Try again.\n");
                    continue;
                }
            }
        printf("Enter vector B:\n");
        for(i = 0; i < n; i++)
        {
            printf("B[%d] = ", i+1);
            scanf("%lf", &B[i]);
            if(getchar() != '\n')
            {
                printf("Error! Do not enter symbols.\n");
                fflush(stdin);
                --i;
                continue;
            }
        }
        printf("Entered matrix:\n");
        for(i=0; i<n; i++)
        {
            int p = 0;
            for(j=0; j<n; j++)
            {
                if(p > 0)
                    if(A[i][j] >= 0)
                        printf("+");
                printf("%g(x%d)", A[i][j], j+1);
                p++;
                if(j == n - 1)
                    printf("=");
            }
            printf("%g", B[i]);
            printf("\n");
        }
        int lol = 0;
        while (lol == 0)
        {
            printf("Enter the accuracy from 1e-6 to 1.\n");
            scanf("%lf", &eps);
            if(getchar() != '\n')
            {
                printf("Error! Do not enter symbols.\n");
                fflush(stdin);
                getch();
                printf("Try again.\n");
                continue;
            }
            if(eps >= 1)
            {
                printf("Error! Very big accuracy.\n");
                getch();
                printf("Try again.\n");
                continue;
            }
            if(eps < 1e-6)
            {
                printf("Error! Very small accuracy.\n");
                getch();
                printf("Try again.\n");
                continue;
            }
            lol++;
        }
        int iteration;
        double maxdelta;
        delta = 0;
        iteration = 10000;
        for(i = 0; i < n; i++)
            X[i] = B[i] / A[i][i];
        while(iteration)
        {
            maxdelta = 0;
            for(i = 0; i < n; i++)
            {
                summ = 0;
                for(j = 0; j < n; j++)
                {
                    if(j == i)
                        continue;
                    summ += (A[i][j] * X[j]);
                }
                summ = (B[i] - summ) / A[i][i];
                delta = fabs(summ - X[i]);
                if(delta>maxdelta)
                    maxdelta = delta;
                X[i] = summ;
            }
            if(maxdelta<eps)
                break;
            --iteration;
        }
        double d = eps;
        int kek = 0;
        while(d < 1)
        {
            d = d * 10;
            kek++;
        }
        for(i = 0; i < n; i++)
            printf("x%d = %.*lf\n", i+1, kek, X[i]);
        for(i = 0; i < n; i++)
            free(A[i]);
        free(A);
        free(B);
        free(X);
        getch();
        system("cls");
        printf("If you want to continue, please press any key, otherwise - press \"ESC\".\n");
}
    while(getch() != 27);
    return 0;
}
