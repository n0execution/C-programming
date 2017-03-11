#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#define Y 365.25
#define M 30.56
#define PRINT "This day is"

main()
{
    printf("This program defines the day of week.\n");
    do//iterate untill "ESC" was pressed
    {
        system("cls");//clear the screen
        int date, year, year1, month, month1, day, n;

        printf("Enter the number:\n");
        if (!scanf("%d", &date)||getchar() != '\n')
        {
            printf("Error! Do not enter rational numbers or symbols.\n");
            fflush(stdin);
            continue;
        }

        if (date <= 0)
        {
            printf("Error! Enter only positive numbers.\n");
            continue;
        }
        if (date > 31)
        {
            printf("Error! Month has only 31 days.\n");
            continue;
        }

		

        printf("Enter the month.\n");
        if (!scanf("%d", &month)||getchar() != '\n')
        {
            printf("Error! Do not enter rational numbers or symbols.\n");
            fflush(stdin);
            continue;
        }

        if (month <= 0)
        {
            printf("Error! Enter only positive numbers.\n");
            continue;
        }
        if (month > 12)
        {
            printf("Error! There are only 12 months in year.\n");
            continue;
        }

		
        printf("¬вед≥ть р≥к.\n");
        if (!scanf("%d", &year)||getchar() != '\n')
        {
            printf("Error! Do not enter rational numbers or symbols.\n");
            fflush(stdin);
            continue;
        }

        else if (year <= 0)
        {
            printf("Error! Enter only positive numbers.\n");
            continue;
        }
        if (year > 2099 || year <1900)
        {
            printf("Error! Try again.\n");
            continue;
        }
        switch (month)
        {
            case 1:
            case 3:
            case 5:
            case 7:
            case 9:
            case 10:
            case 12:
            if(date > 31)
            {
                printf("Error! There are 31 days in this month.\n");
                continue;
            }
            break;
            case 4:
            case 6:
            case 8:
            case 11:
            if(date > 30)
            {
                printf("Error! There are 30 days in this month.\n");
                continue;
            }
            break;
            case 2:
            if ((year % 100 != 0 && year % 4 == 0)||(year % 100 == 0 && year % 400 == 0))
                    {if(date > 29)
                    {
                printf("Error! There are 29 days in this month.\n");
                        continue;
                    }}
            else
                if(date > 28)
                {
                printf("Error! There are 28 days in this month.\n");
                    continue;
                }
            break;
        }


        if (month > 2)
        n=0;
        else if (((year % 100 != 0 && year % 4 == 0)||(year % 100 == 0 && year % 400 == 0)) && month <= 2)
        n = 1;
        else
        n = 2;
        year1 = year * Y;
        month1 = month * M;
        day = (year1 + month1 + date + n) % 7;
        switch(day)
        {
            case 0:
            printf("%s Monday.\n", PRINT);
            break;

            case 1:
            printf("%s Tuesday.\n", PRINT);
            break;

            case 2:
            printf("%s Wednesday.\n", PRINT);
            break;

            case 3:
            printf("%s Thursday.\n", PRINT);
            break;

            case 4:
            printf("%s Friday.\n", PRINT);
            break;

            case 5:
            printf("%s Saturday.\n", PRINT);
            break;

            case 6:
            printf("%s Sunday.\n", PRINT);
            break;
        }
        getch();
        system("cls");
        printf("If you want to continue, please press any key, otherwise - press \"ESC\".\n");
    }
    while(getch() != 27);
    return 0;
}
