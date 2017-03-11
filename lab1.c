#include<stdio.h>
#include<conio.h>
int roman(int,int,char);
int main()
{
int a;
printf("This programm is used for translating Arabic numbers into Roman.\n");
printf("Enter a positive integer which is less than 4000 and press 'Enter':\n");
int i=0;
while (i<1)
    {
      if (!(scanf("%d",&a))||(getchar() != '\n'))
        {
        printf("\nError! Do not enter a fractional number or a symbol. Enter an integer.\n");
        getch();
        fflush(stdin);
        }

    else if(a>4000)
        {
        printf("\nError! Integer must be less then 4000! Try again.\n");
        fflush(stdin);
        getch();
        }
    else if(a<1)
        {
        printf("\nError! You entered a negative number or a zero! Try again.\n");
        fflush(stdin);
        getch();
        }
    else
    {
    a=roman(a,1000,'M');
    a=roman(a,500,'D');
    a=roman(a,100,'C');
    a=roman(a,50,'L');
    a=roman(a,10,'X');
    a=roman(a,5,'V');
    a=roman(a,1,'I');
    i++;
    }
    }
    getch();
    return 0;
}


int roman(int a, int b, char c)
{
    while (a>=b)
    {
        putchar(c);
        a = a - b;
    }
    return(a);
}
