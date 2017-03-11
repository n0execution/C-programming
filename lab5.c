#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
int a;
void ordering(char**, int m);
int main()
{
    printf("This program sorts an array using pointers.\n");
    getch();
    do
    {
        system("cls");
        const int n;
        int i;
        printf("Enter the amount of array's elements, it shouldn't be more than 100:\n");
        if(!(scanf("%d", &n)) || (getchar() != '\n'))
        {
            printf("Error! Do not enter rational numbers or symbols.\n");
            fflush(stdin);
            getch();
            printf("Try again.\n");
            continue;
        }
        if (n <= 0)
        {
            printf("Error! N must be positive.\n");
            getch();
            printf("Try again.\n");
            continue;
        }
        if(n > 100)
        {
            printf("Error! The number of elements shouldn't be more than 100.\n");
            getch();
            printf("Try again.\n");
            continue;
        }
        char list[n][80];
        printf("Enter an array of strings. Do not enter more than 80 symbols in one string.\n");
        for(i = 0; i < n; i++)
        {
            printf("string %d:\n", i+1);
            fgets(list[i], 80, stdin);
            fflush(stdin);
        }
        int b = 0;
        printf("Enter 1 if you want to sort array by alphabet and 2 - otherwise.\n");
        while(b == 0)
        {
            if(!(scanf("%d", &a)) || getchar() != '\n')
            {
            printf("Error! Do not enter rational numbers or symbols.\n");
                fflush(stdin);
                getch();
                printf("Try again.\n");
                continue;
            }
            if(a != 1 && a != 2)
            {
                printf("Error! Enter only 1 or 2.\n");
                getch();
                printf("Try again.\n");
                continue;
            }
            b++;
        }
        char *string[n];
        for(i = 0; i < n; i++)
        string[i] = list[i];
        ordering(string, n);
        getch();
        system("cls");
        printf("Sorted array:\n");
        for(i = 0; i < n; i++)
        fputs(string[i], stdout);
        getch();
        system("cls");
        printf("If you want to continue, please press any key, otherwise - press \"ESC\".\n");
    }
    while(getch() != 27);
}
void ordering(addr, m)
char *addr[];
int m;
{
    char *temp;
    int i, hehe;
    for (i = 0; i < m - 1; i++)
    for (hehe = i + 1; hehe < m; hehe++)
    if(strcmp(addr[i], addr[hehe]) > 0)
    {
        temp = addr[i];
        addr[i] = addr[hehe];
        addr[hehe] = temp;
    }
    if(a == 2)
    {
        for(i = 0; i < m/2; i++)
        {
            temp =  addr [i];
            addr[i] = addr[m-1-i];
            addr[m-1-i] = temp;
        }
    }
}
