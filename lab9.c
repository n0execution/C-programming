#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

int f, m, j;

struct statistics
{
    char club[20];
    char player[20];
    float minutes;
    int goals;
} data;

FILE *file;
void creation_1();
void creation_2();
void reading_1();
void reading_2();
void deleting_1();
void editing();
void sorting();

int main()
{
    int lol = 1;
    do
    {
        int lock, key, k, i;
        lock = 1;
///////////////////////////////////////////////////////////////////////////FIRST MENU//////////////////////////////////////////////////////////////////////////////////////////
        do
        {
            start:
            system("cls");
            if(lock == 1)
            {
                printf("%cStart\n", 16);
                printf("Exit\n");
                if(getch() == 13)
                    break;
            }
            if(lock == 2)
            {
                printf("Start\n");
                printf("%cExit\n", 16);
                if(getch() == 13)
                    return 0;
            }
            key = getch();
            if(key == 72)
                lock--;
            if(key == 80)
            lock++;
            if(lock > 2)
                lock = 1;
            if(lock < 1)
                lock = 2;
        }
        while(lol!=2);

////////////////////////////////////////////////////////////////////////////SECOND MENU////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        mode:
        lock = 1;
        int key1;
        do
        {
            system("cls");
            printf("Choose the mode of the program:\n\n");
            if(lock == 1)
            {
                printf("%cFile mode\n", 16);
                printf("Record mode\n");
                key1 = getch();
                if(key1 == 13)
                {
                    k = 0;
                    break;
                }
                if(key1 == 8)
                    goto start;
            }
            if(lock == 2)
            {
                printf("File mode\n");
                printf("%cRecord mode\n", 16);
                key1 = getch();
                if(key1 == 13)
                {
                    k = 1;
                    break;
                }
                if(key1 == 8)
                    goto start;
            }
            key = getch();
            if(key == 72)
                lock--;
            if(key == 80)
            lock++;
            if(lock > 2)
                lock = 1;
            if(lock < 1)
                lock = 2;
        }
        while(lol != 2);

////////////////////////////////////////////////////////////////////////////THIRD MENU 1//////////////////////////////////////////////////////////////////////////////////////////
        lock = 1;
        if(k == 0)
            do
            {
                system("cls");
                printf("Select the action you want to do:\n\n");
                if(lock == 1)
                {
                    printf("%cCreate\n", 16);
                    printf("Read\n");
                    printf("Delete");
                    key1 = getch();
                    if(key1 == 13)
                    {
                        creation_1();
                        break;
                    }
                    if(key1 == 8)
                        goto mode;
                }
                if(lock == 2)
                {
                    printf("Create\n");
                    printf("%cRead\n", 16);
                    printf("Delete");
                    key1 = getch();
                    if(key1 == 13)
                    {
                        reading_1();
                        break;
                    }
                    if(key1 == 8)
                        goto mode;
                }
                if(lock == 3)
                {
                    printf("Create\n");
                    printf("Read\n");
                    printf("%cDelete", 16);
                    key1 = getch();
                    if(key1 == 13)
                    {
                        deleting_1();
                        break;
                    }
                    if(key1 == 8)
                        goto mode;
                }
                key = getch();
                if(key == 72)
                    lock--;
                if(key == 80)
                lock++;
                if(lock > 3)
                    lock = 1;
                if(lock < 1)
                    lock = 3;
            }
            while(lol != 2);

////////////////////////////////////////////////////////////////////////////THIRD MENU 2//////////////////////////////////////////////////////////////////////////////////////////

        record:
        lock = 1;
        if(k == 1)
            do
            {
                system("cls");
                printf("Select the action you want to do:\n\n");
                if(lock == 1)
                {
                    printf("%cCreate\n", 16);
                    printf("Read\n");
                    printf("Edit\n");
                    printf("Sort\n");
                    printf("Insert\n");
                    printf("Delete");
                    key1 = getch();
                    if(key1 == 13)
                    {
                        creation_2();
                        break;
                    }
                    if(key1 == 8)
                        goto mode;
                }
                if(lock == 2)
                {
                    printf("Create\n");
                    printf("%cRead\n", 16);
                    printf("Edit\n");
                    printf("Sort\n");
                    printf("Insert\n");
                    printf("Delete");
                    key1 = getch();
                    if(key1 == 13)
                    {
                        reading_2();
                        break;
                    }
                    if(key1 == 8)
                        goto mode;
                }
                if(lock == 3)
                {
                    printf("Create\n");
                    printf("Read\n");
                    printf("%cEdit\n", 16);
                    printf("Sort\n");
                    printf("Insert\n");
                    printf("Delete");
                    key1 = getch();
                    if(key1 == 13)
                    {
                        editing();
                        break;
                    }
                    if(key1 == 8)
                        goto mode;
                }
                if(lock == 4)
                {
                    printf("Create\n");
                    printf("Read\n");
                    printf("Edit\n");
                    printf("%cSort\n", 16);
                    printf("Insert\n");
                    printf("Delete");
                    key1 = getch();
                    if(key1 == 13)
                    {
                        sorting();
                        break;
                    }
                    if(key1 == 8)
                        goto mode;
                }
                if(lock == 5)
                {
                    printf("Create\n");
                    printf("Read\n");
                    printf("Edit\n");
                    printf("Sort\n");
                    printf("%cInsert\n", 16);
                    printf("Delete");
                    key1 = getch();
                    if(key1 == 13)
                    {
                        insert();
                        break;
                    }
                    if(key1 == 8)
                        goto mode;
                }
                 if(lock == 6)
                {
                    printf("Create\n");
                    printf("Read\n");
                    printf("Edit\n");
                    printf("Sort\n");
                    printf("Insert\n");
                    printf("%cDelete");
                    key1 = getch();
                    if(key1 == 13)
                    {
                        deleting_2();
                        break;
                    }
                    if(key1 == 8)
                        goto mode;
                }
                key = getch();
                if(key == 72)
                    lock--;
                if(key == 80)
                lock++;
                if(lock > 6)
                    lock = 1;
                if(lock < 1)
                    lock = 6;
            }
            while(lol != 2);
            Sleep(1500);
    }
    while(lol != 0);
    return 0;
}


void creation_1()
{
    system("cls");
    char name[256];
    int l;
    do
    {
        system("cls");
        printf("Enter the name of new file. The number of symbols shouldn't be more than 40.\n");
        scanf("%s", &name);
        l = strlen(name);
        l--;
        if(l > 40)
        {
            printf("Error! Do not enter so much characters in name.\n");
            getch();
            fflush(stdin);
            continue;
        }
        strcat(name, ".cp9");
        if((file = fopen(name, "w+"))== NULL)
        {
            printf("Error. The programm could not create the file %s. Maybe you've entered symbols such as \"/, \, ?, :, *, ;, ', \"\".\n", name);
            getch();
            continue;
        }
        else
            printf("The file %s is successfully created.\n", name);
        Sleep(2000);
        fclose(file);
        l = 0;
    }
    while(l != 0);
}

void reading_1()
{
    system("cls");
    char c, name[256];
    int l, count = 0;
    do
    {
        system("cls");
        printf("Enter the name of file. The number of symbols shouldn't be more than 40.\n");
         scanf("%s", &name);
        l = strlen(name);
        l--;
        if(l > 40)
        {
            printf("Error! Do not enter so much characters in name.\n");
            getch();
            fflush(stdin);
            continue;
        }
        strcat(name, ".cp9");
        if((file = fopen(name, "r+"))== NULL)
        {
            printf("Error. The programm could not open file %s. ", name);
            getch();
            continue;
        }
        while (!feof(file))
        {
            c = fgetc(file);
            if(c == '\n')
                count++;
        }
        fclose(file);
        if(count == 0)
        {
            printf("This file is empty.\n\n", count);
            getch();
            break;
        }
        if((file = fopen(name, "r+"))== NULL)
        {
            printf("Error. The programm could not open file %s. ", name);
            getch();
            continue;
        }
            while (!feof(file))
        {
            c = fgetc(file);
            fprintf(stdout, "%c", c);
        }
        getch();
        int k;
        fclose(file);
        l = 0;
    }
    while(l != 0);
}

void deleting_1()
{
    system("cls");
    char name[256];
    int l;
    do
    {
        system("cls");
        printf("Enter the name of file. The number of symbols shouldn't be more than 40.\n");
        scanf("%s", &name);
        l = strlen(name);
        l--;
        if(l > 40)
        {
            printf("Error! Do not enter so much characters in name.\n");
            getch();
            fflush(stdin);
            continue;
        }
        strcat(name, ".cp9");
        if(remove(name) != NULL)
        {
            printf("Error! The programm could not delete file %s.\n", name);
            getch();
            continue;
        }
        else
        printf("The file %s is successfuly removed from your computer.\n", name);
        l = 0;
    }
    while(l != 0);
}

void creation_2()
{
    char name[256];
    int l, o;
    do
    {
        system("cls");
        printf("Enter the name of file. The number of symbols shouldn't be more than 40.\n");
        scanf("%s", &name);
        l = strlen(name);
        l--;
        if(l > 40)
        {
            printf("Error! Do not enter so much characters in name.\n");
            getch();
            fflush(stdin);
            continue;
        }
        strcat(name, ".cp9");
        if((file = fopen(name, "a+"))== NULL)
        {
            printf("Error. The programm could not open file %s. ", name);
            getch();
            continue;
        }
        else
        {
            int error = 1;
            while(error == 1)
            {
                error = 1;
                printf("Enter the name of football club:\n");
                scanf("%s", &data.club);
                if(strlen(data.club) > 20)
                {
                    printf("Error! Too big name. Try again.\n");
                    getch();
                    fflush(stdin);
                    continue;
                }
                error++;
            }
            while(error == 2)
            {
                error = 2;
                printf("Enter the name of footballer:\n");
                scanf("%s", &data.player);
                if(strlen(data.player) > 20)
                {
                    printf("Error! Too big name of the footballer. Try again.\n");
                    getch();
                    fflush(stdin);
                    continue;
                }
                error++;
            }
            while(error == 3)
            {
                error = 3;
                printf("Enter the number of minutes played by this footballer in this season:\n");
                scanf("%f", &data.minutes);
                if(getchar () != '\n')
                {
                    printf("Error! Do not enter symbols.\n");
                    fflush(stdin);
                    getch();
                    continue;
                }
                if(data.minutes < 0)
                {
                    printf("Error!  Do not enter negative numbers.\n");
                    getch();
                    continue;
                }
                error++;
            }
            while(error == 4)
            {
                error = 4;
                printf("Enter the number of goals scored by this footballer in this season:\n");
                scanf("%d", &data.goals);
                if(getchar() != '\n')
                {
                    printf("Error! Do not enter symbols or fractional numbers.\n");
                    fflush(stdin);
                    getch();
                    continue;
                }
                if(data.goals < 0)
                {
                    printf("Error!  Do not enter negative numbers.\n");
                    getch();
                    continue;
                }
                error++;
            }
        }
            fprintf(file, "%20s%20s%20g%20d\n", data.club, data.player, data.minutes, data.goals);
            printf("The record in file is created.\n");
            fclose(file);
        Sleep(1500);
        system("cls");
        printf("Do you want to create another one? Yes - press any button, no - press \"ESC\".\n");
    }
    while(getch() != 27);
}

void reading_2()
{
    char c,  name[256], D[100][256], Trash[256];
    int l, i, o, count = 0;
    do
    {
        system("cls");
        printf("Enter the name of file. The number of symbols shouldn't be more than 40.\n");
        scanf("%s", &name);
        l = strlen(name);
        l--;
        if(l > 40)
        {
            printf("Error! Do not enter so much characters in name.\n");
            getch();
            fflush(stdin);
            continue;
        }
        strcat(name, ".cp9");
        if((file = fopen(name, "r+"))== NULL)
        {
            printf("Error. The programm could not open file %s. ", name);
            getch();
            continue;
        }
        while (!feof(file))
        {
            c = fgetc(file);
            if(c == '\n')
                count++;
        }
        if(count == 0)
        {
            printf("This file has %d records.\n\n", count);
            getch();
            break;
        }
        else
            printf("This file has %d records.\n\n", count);
        fclose(file);
        printf("Enter the number of record that you want to read.\n");
        int rec;
        while (scanf("%d",&rec) != 1 || getchar() != '\n' || rec < 1 || rec > count)
        {
            printf("Error! Try again.\n");
            fflush(stdin);
        }
        if((file = fopen(name, "r+"))== NULL)
        {
            printf("Error. The programm could not open file %s. ", name);
            getch();
            continue;
        }
        for (i = 0; i < count; i++)
            {
                if (i < rec - 1)
                    fgets(D[i], 256, file);
                else if (i == rec - 1)
                    fgets(Trash, 256, file);
                else if (i >= rec)
                    fgets(D[i], 256, file);
            }
        printf("%s", Trash);
        fclose(file);
        Sleep(1100);
        o = 0;
    }
    while(o != 0);
}

void editing()
{
    char D[100][256], name[256];
    char Trash[256], c;
    int record;
    int l, i;
    do
    {
        system("cls");
        printf("Enter the name of file. The number of symbols shouldn't be more than 40.\n");
        scanf("%s", &name);
        l = strlen(name);
        l--;
        if(l > 40)
        {
            printf("Error! Do not enter so much characters in name.\n");
            getch();
            fflush(stdin);
            continue;
        }
        strcat(name, ".cp9");
        if((file = fopen(name, "r+"))== NULL)
        {
            printf("Error. The programm could not open file %s. ", name);
            getch();
            continue;
        }
        int count = 0;
        while (!feof(file))
        {
            c = fgetc(file);
            if(c == '\n')
                count++;
        }
        if(count == 0)
        {
            printf("This file has %d records.\n\n", count);
            getch();
            break;
        }
        else
            printf("This file has %d records.\n\n", count);
        fclose(file);
        Sleep(1000);
        printf("Enter the number of record that you want to edit.\n");
        while (scanf("%d",&record) != 1 || getchar() != '\n' || record < 1 || record > count)
        {
            printf("Error! Try again.\n");
            fflush(stdin);
        }
        int error = 1;
            while(error == 1)
            {
                printf("Enter the name of football club:\n");
                scanf("%s", &data.club);
                if(strlen(data.club) > 20)
                {
                    printf("Error! Too big name. Try again.\n");
                    getch();
                    fflush(stdin);
                    continue;
                }
                error++;
            }
            while(error == 2)
            {
                printf("Enter the name of footballer:\n");
                scanf("%s", &data.player);
                if(strlen(data.player) > 20)
                {
                    printf("Error! Too big name of the footballer. Try again.\n");
                    getch();
                    fflush(stdin);
                    continue;
                }
                error++;
            }
            while(error == 3)
            {
                printf("Enter the number of minutes played by this footballer in this season:\n");
                scanf("%f", &data.minutes);
                if(getchar () != '\n')
                {
                    printf("Error! Do not enter symbols.\n");
                    fflush(stdin);
                    getch();
                    continue;
                }
                if(data.minutes < 0)
                {
                    printf("Error!  Do not enter negative numbers.\n");
                    getch();
                    continue;
                }
                error++;
            }
            while(error == 4)
            {
                error = 4;
                printf("Enter the number of goals scored by this footballer in this season:\n");
                scanf("%d", &data.goals);
                if(getchar() != '\n')
                {
                    printf("Error! Do not enter symbols or fractional numbers.\n");
                    fflush(stdin);
                    getch();
                    continue;
                }
                error++;
            }
        if((file = fopen(name, "r+"))== NULL)
        {
            printf("Error. The programm could not open file %s. ", name);
            getch();
            continue;
        }
        else
        {
            fseek(file, 0L, SEEK_SET);
            for (i = 0; i < count; i++)
            {
                if (i < record - 1)
                    fgets(D[i], 256, file);
                else if (i == record - 1)
                    fgets(Trash, 256, file);
                else if (i >= record)
                    fgets(D[i], 256, file);
            }
            fclose(file);
            if((file = fopen(name, "w"))== NULL)
            {
                printf("Error. The programm could not open file %s. ", name);
                getch();
                continue;
            }
            else
            {
                for (i = 0; i < count; i++)
                {
                    if (i == record - 1)
                        fprintf(file, "%20s%20s%20g%20d\n", data.club, data.player, data.minutes, data.goals);
                    else fprintf(file,"%s", D[i]);
                }
                printf("The record  is successfuly edited. \n");
            }
        }
        fclose(file);
        Sleep(1100);
        l = 0;
    }
    while(l != 0);
}

void sorting()
{
    char club[100][256], player[100][256], Trash[256], *addr1[100], *addr2[100], name[256], c;
    float minutes[100];
    int goals[100], count;
    int l;
    do
    {
        system("cls");
        printf("Enter the name of file. The number of symbols shouldn't be more than 40.\n");
        scanf("%s", &name);
        l = strlen(name);
        l--;
        if(l > 40)
        {
            printf("Error! Do not enter so much characters in name.\n");
            getch();
            fflush(stdin);
            continue;
        }
        strcat(name, ".cp9");
        if((file = fopen(name, "r+"))== NULL)
        {
            printf("Error. The programm could not open file %s. ", name);
            getch();
            continue;
        }
        count = 0;
        while (!feof(file))
        {
            c = fgetc(file);
            if(c == '\n')
                count++;
        }
        if(count == 0)
        {
            printf("This file has %d records.\n\n", count);
            getch();
            break;
        }
        else
            printf("This file has %d records.\n\n", count);
        Sleep(1000);
        fseek(file, 0L, SEEK_SET);
        int i;
        for(i = 0; i < count; i++)
        {
            fscanf(file,"%20s ", &club[i]);
            fscanf(file,"%20s ", &player[i]);
            fscanf(file,"%20f ", &minutes[i]);
            fscanf(file,"%20d\n",&goals[i]);
        }
        fclose(file);
         if((file = fopen(name, "w"))== NULL)
        {
            printf("Error. The programm could not open file %s. ", name);
            getch();
            continue;
        }
        for (i = 0; i < count - 1; i++)
        {
            addr1[i] = club[i];
            addr2[i] = player[i];
        }
        fclose(file);
        int import;
        int lock = 1;
        int key1, key, lol;
        sort:
            do
            {
                system("cls");
                printf("Select what you want to sort:\n\n");
                if(lock == 1)
                {
                    printf("%cClub\n", 16);
                    printf("Player\n");
                    printf("Minutes\n");
                    printf("Goals\n");
                    key1 = getch();
                    if(key1 == 13)
                    {
                        import = 1;
                        break;
                    }
                }
                if(lock == 2)
                {
                    printf("Club\n");
                    printf("%cPlayer\n", 16);
                    printf("Minutes\n");
                    printf("Goals\n");
                    key1 = getch();
                    if(key1 == 13)
                    {
                        import = 2;
                        break;
                    }
                }
                if(lock == 3)
                {
                    printf("Club\n");
                    printf("Player\n");
                    printf("%cMinutes\n", 16);
                    printf("Goals\n");
                    key1 = getch();
                    if(key1 == 13)
                    {
                        import = 3;
                        break;
                    }
                }
                if(lock == 4)
                {
                    printf("Club\n");
                    printf("Player\n");
                    printf("Minutes\n");
                    printf("%cGoals\n", 16);
                    key1 = getch();
                    if(key1 == 13)
                    {
                        import = 4;
                        break;
                    }
                }
                key = getch();
                if(key == 72)
                    lock--;
                if(key == 80)
                lock++;
                if(lock > 4)
                    lock = 1;
                if(lock < 1)
                    lock = 4;
            }
            while(lol != 2);
            lol = 1;
        lock = 1;
        int p;
        do
        {
            system("cls");
            if(lock == 1)
            {
                printf("%cIncrease\n", 16);
                printf("Decrease\n");
                if(getch() == 13)
                {
                    p = 1;
                    break;
                }
                if(key1 == 8)
                        goto sort;
            }
            if(lock == 2)
            {
                printf("Increase\n");
                printf("%cDecrease\n", 16);
                if(getch() == 13)
                {
                    p = 2;
                    break;
                }
                if(key1 == 8)
                        goto sort;
            }
            key = getch();
            if(key == 72)
                lock--;
            if(key == 80)
            lock++;
            if(lock > 2)
                lock = 1;
            if(lock < 1)
                lock = 2;
        }
        while(lol!=2);
                     if((file = fopen(name, "r+"))== NULL)
        {
            printf("Error. The programm could not open file %s. ", name);
            getch();
            continue;
        }

            if(import == 1)
            {
                sort_club(addr1, addr2, count, minutes, goals, p);
                for(i = 0; i < count - 1; i++)
                fprintf(file,"%20s%20s%20g%20d\n", addr1[i], addr2[i], minutes[i], goals[i]);
                printf("Records are successfully sorted.\n");
            }
            if(import == 2)
            {
                sort_player(addr1, addr2, count, minutes, goals, p);
                for(i = 0; i < count - 1; i++)
                fprintf(file,"%20s%20s%20g%20d\n", addr1[i], addr2[i], minutes[i], goals[i]);
                printf("Records are successfully sorted.\n");
            }
            if(import == 3)
            {
                sort_minutes(addr1, addr2, count, minutes, goals, p);
                for(i = 0; i < count - 1; i++)
                fprintf(file,"%20s%20s%20g%20d\n", addr1[i], addr2[i], minutes[i], goals[i]);
                printf("Records are successfully sorted.\n");
            }
            if(import == 4)
            {
                sort_goals(addr1, addr2, count, minutes, goals, p);
                for(i = 0; i < count - 1; i++)
                fprintf(file,"%20s%20s%20g%20d\n", addr1[i], addr2[i], minutes[i], goals[i]);
                printf("Records are successfully sorted.\n");
            }
        Sleep(1100);
        l = 0;
    }
    while(l != 0);
}

void sort_club(ar1, ar2, n_str, h, k, p)
char *ar1[], *ar2[];
int n_str, *h, p;
float *k;
{
    int a,b;
    char *t1, *t2;
    int h1;
    float k1;
    for(a = 0; a < n_str - 1; a++)
        for(b = a + 1; b < n_str; b++)
        {
            if(strcmp(ar1[a], ar1[b]) > 0)
            {
                t1 = ar1[a];
                ar1[a] = ar1[b];
                ar1[b] = t1;

                t2 = ar2[a];
                ar2[a] = ar2[b];
                ar2[b] = t2;

                h1 = h[a];
                h[a] = h[b];
                h[b] = h1;

                k1 = k[a];
                k[a] = k[b];
                k[b] = k1;
            }
        }
    if(p == 2)
    {
        for(a = 0; a < (n_str - 1) /2; a++)
        {
            t1 =  ar1[a];
            ar1[a] = ar1[n_str-1-a];
            ar1[n_str-1-a] = t1;

            t2 =  ar2[a];
            ar2[a] = ar2[n_str-1-a];
            ar2[n_str-1-a] = t2;

            h1 =  h[a];
            h[a] = h[n_str-1-a];
            h[n_str-1-a] = h1;

            k1 =  k[a];
            k[a] = k[n_str-1-a];
            k[n_str-1-a] = k1;
        }
    }
}

void sort_player(ar1, ar2, n_str, h, k, p)
char *ar1[], *ar2[];
int n_str, *h, p;
float *k;
{
    int a,b;
    char *t1, *t2;
    int h1;
    float k1;
    for(a = 0; a < n_str - 1; a++)
        for(b = a + 1; b < n_str; b++)
        {
            if(strcmp(ar2[a], ar2[b]) > 0)
            {
                t1 = ar1[a];
                ar1[a] = ar1[b];
                ar1[b] = t1;

                t2 = ar2[a];
                ar2[a] = ar2[b];
                ar2[b] = t2;

                h1 = h[a];
                h[a] = h[b];
                h[b] = h1;

                k1=k[a];
                k[a]=k[b];
                k[b]=k1;
            }
        }
    if(p == 2)
    {
        for(a = 0; a < (n_str - 1) /2; a++)
        {
            t1 =  ar1[a];
            ar1[a] = ar1[n_str-1-a];
            ar1[n_str-1-a] = t1;

            t2 =  ar2[a];
            ar2[a] = ar2[n_str-1-a];
            ar2[n_str-1-a] = t2;

            h1 =  h[a];
            h[a] = h[n_str-1-a];
            h[n_str-1-a] = h1;

            k1 =  k[a];
            k[a] = k[n_str-1-a];
            k[n_str-1-a] = k1;
        }
    }
}

void sort_minutes(ar1, ar2, n_str, h, k, p)
char *ar1[], *ar2[];
int n_str, *h, p;
float *k;
{
    int a,b;
    char *t1, *t2;
    int h1;
    float k1;
    for(a = 0; a < n_str - 1; a++)
        for(b = a + 1; b < n_str; b++)
        {
            if(k[a] > k[b])
            {
                t1 = ar1[a];
                ar1[a] = ar1[b];
                ar1[b] = t1;

                t2 = ar2[a];
                ar2[a] = ar2[b];
                ar2[b] = t2;

                h1 = h[a];
                h[a] = h[b];
                h[b] = h1;

                k1=k[a];
                k[a]=k[b];
                k[b]=k1;
            }
        }
    if(p == 2)
    {
        for(a = 0; a < (n_str - 1) /2; a++)
        {
            t1 =  ar1[a];
            ar1[a] = ar1[n_str-1-a];
            ar1[n_str-1-a] = t1;

            t2 =  ar2[a];
            ar2[a] = ar2[n_str-1-a];
            ar2[n_str-1-a] = t2;

            h1 =  h[a];
            h[a] = h[n_str-1-a];
            h[n_str-1-a] = h1;

            k1 =  k[a];
            k[a] = k[n_str-1-a];
            k[n_str-1-a] = k1;
        }
    }
}

void sort_goals(ar1, ar2, n_str, h, k, p)
char *ar1[], *ar2[];
int n_str, *h, p;
float *k;
{
    int a,b;
    char *t1, *t2;
    int h1;
    float k1;
    for(a = 0; a < n_str - 1; a++)
        for(b = a + 1; b < n_str; b++)
        {
            if(h[a] > h[b])
            {
                t1 = ar1[a];
                ar1[a] = ar1[b];
                ar1[b] = t1;

                t2 = ar2[a];
                ar2[a] = ar2[b];
                ar2[b] = t2;

                h1 = h[a];
                h[a] = h[b];
                h[b] = h1;

                k1=k[a];
                k[a]=k[b];
                k[b]=k1;
            }
        }
    if(p == 2)
    {
        for(a = 0; a < (n_str - 1) /2; a++)
        {
            t1 =  ar1[a];
            ar1[a] = ar1[n_str-1-a];
            ar1[n_str-1-a] = t1;

            t2 =  ar2[a];
            ar2[a] = ar2[n_str-1-a];
            ar2[n_str-1-a] = t2;

            h1 =  h[a];
            h[a] = h[n_str-1-a];
            h[n_str-1-a] = h1;

            k1 =  k[a];
            k[a] = k[n_str-1-a];
            k[n_str-1-a] = k1;
        }
    }
}

void insert()
{
    char D[100][256],Trash[256], name[256], c;
    int record, l, count = 0;
    do
    {
        system("cls");
        printf("Enter the name of file. The number of symbols shouldn't be more than 40.\n");
        scanf("%s", &name);
        l = strlen(name);
        l--;
        if(l > 40)
        {
            printf("Error! Do not enter so much characters in name.\n");
            getch();
            fflush(stdin);
            continue;
        }
        strcat(name, ".cp9");
        if((file = fopen(name, "r+"))== NULL)
        {
            printf("Error. The programm could not open file %s. ", name);
            getch();
            continue;
        }
        while (!feof(file))
        {
            c = fgetc(file);
            if(c == '\n')
                count++;
        }
        if(count == 0)
        {
            printf("This file has %d records.\n\n", count);
            getch();
            break;
        }
        else
            printf("This file has %d records.\n\n", count);

        fclose(file);
        Sleep(1000);
        if((file = fopen(name, "r+"))== NULL)
            printf("Error. The programm could not open file %s. ", name);
        else
        {
            printf("Enter the number of  record before which you want to insert new record.\n");
            while (scanf("%d", &record) != 1 || getchar() != '\n' || record < 1 || record > count)
            {
                printf("Error! Try again..\n");
                fflush(stdin);
            }
            int error = 1;
            while(error == 1)
            {
                error = 1;
                printf("Enter the name of football club:\n");
                scanf("%s", &data.club);
                if(strlen(data.club) > 20)
                {
                    printf("Error! Too big name. Try again.\n");
                    getch();
                    fflush(stdin);
                    continue;
                }
                error++;
            }
            while(error == 2)
            {
                error = 2;
                printf("Enter the name of footballer:\n");
                scanf("%s", &data.player);
                if(strlen(data.player) > 20)
                {
                    printf("Error! Too big name of the footballer. Try again.\n");
                    getch();
                    fflush(stdin);
                    continue;
                }
                error++;
            }
            while(error == 3)
            {
                error = 3;
                printf("Enter the number of minutes played by this footballer in this season:\n");
                scanf("%f", &data.minutes);
                if(getchar () != '\n')
                {
                    printf("Error! Do not enter symbols.\n");
                    fflush(stdin);
                    getch();
                    continue;
                }
                if(data.minutes < 0)
                {
                    printf("Error!  Do not enter negative numbers.\n");
                    getch();
                    continue;
                }
                error++;
            }
            while(error == 4)
            {
                error = 4;
                printf("Enter the number of goals scored by this footballer in this season:\n");
                scanf("%d", &data.goals);
                if(getchar() != '\n')
                {
                    printf("Error! Do not enter symbols or fractional numbers.\n");
                    fflush(stdin);
                    getch();
                    continue;
                }
                error++;
            }
        int i;
        fseek(file, 0L, SEEK_SET);
        for (i=0; i < count + 1; i++)
        {
            if (i < record- 1)
                fgets(D[i],256,file);
            else if (i >= record)
                fgets(D[i],256,file);
        }
        fclose(file);
        if((file = fopen(name, "w+"))== NULL)
        {
            printf("Error. The programm could not open file %s. ", name);
            continue;
        }
        else
        {
            count++;
            for (i = 0; i < count; i++)
            {
                if (i == record-1)
                    fprintf(file, "%20s%20s%20g%20d\n", data.club, data.player, data.minutes, data.goals);
                else
                    fprintf(file,"%s", D[i]);
            }
            printf("The record is successfully inserted.\n");
            fclose(file);
        }
        }
        l = 0;
    }
    while(l != 0);
}

void deleting_2()
{
    char Trash[256], name[256], c;
    int l, record, count = 0;
    char D[100][256];
    do
    {
        system("cls");
        printf("Enter the name of file. The number of symbols shouldn't be more than 40.\n");
        scanf("%s", &name);
        l = strlen(name);
        l--;
        if(l > 40)
        {
            printf("Error! Do not enter so much characters in name.\n");
            getch();
            fflush(stdin);
            continue;
        }
        strcat(name, ".cp9");
        if((file = fopen(name, "r+"))== NULL)
        {
            printf("Error. The programm could not open file %s. ", name);
            getch();
            continue;
        }
        while (!feof(file))
        {
            c = fgetc(file);
            if(c == '\n')
                count++;
        }
        if(count == 0)
        {
            printf("This file has %d records.\n\n", count);
            getch();
            break;
        }
        else
            printf("This file has %d records.\n\n", count);
        fclose(file);
        Sleep(1000);
        printf("Enter the number of record that you want to delete.\n");
        while (scanf("%d", &record) != 1 || getchar() != '\n' || record < 1 || record > count)
        {
            printf("Error! Try again.\n");
            fflush(stdin);
        }
        if((file = fopen(name, "r+"))== NULL)
        {
            printf("Error. The programm could not open file %s. ", name);
            continue;
        }
        else
        {
            fseek(file, 0L, SEEK_SET);
            int i;
            for (i = 0; i < count; i++)
            {
                if (i < record - 1)
                    fgets(D[i],256,file);
                else if (i == record - 1)
                    fgets(Trash,256,file);
                else if (i >= record)
                    fgets(D[i-1],256,file);
            }
            fclose(file);
            if((file = fopen(name, "w+"))== NULL)
                printf("Error. The programm could not open file %s. ", name);
            else
            {
                for (i = 0; i < count - 1; i++)
                fprintf(file,"%s", D[i]);
                count--;
                printf("The record is successfully deleted.\n");
            }
            fclose(file);
        }
        l = 0;
    }
    while(l != 0);
}
