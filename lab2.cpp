#include <stdio.h>
void triangle();

#include <conio.h>
#include <math.h>
#include <stdlib.h>
    main()
    {
    printf("Hello! This programm wil calculate an area, heights, medians and bisectors of\nthe triangle from entered values of sides.\n");
    printf("Enter any key to continue or if you want to end, enter ESC.\n");
    triangle();
    }
void triangle()
{
    while(getch()!=27)
    {
    system("cls");
    int count=0;
    float a, b, c;
    float P, p, S;
    float Ha, Hb, Hc;
    float Ma, Mb, Mc;
    float Ba, Bb, Bc;
    while (count<1)
    {
    printf("\nPlease, enter sides of the triangle.\n");
    scanf("%f", &a);

    if(getchar()!='\n')
    {
        printf("Error! Do not enter a symbol. Press any key to continue.");
        fflush(stdin);
        return triangle();
    }
    if(a<=0)
    {
        printf("Error! The side must be bigger than zero.");
        return triangle();
    }

    scanf("%f", &b);
    if(getchar()!='\n')
    {
        printf("Error! Do not enter a symbol. Press any key to continue.");
        fflush(stdin);
        return triangle();
    }
    if(b<=0)
    {
        printf("Error! The side must be bigger than zero. Press any key to continue.");
        return triangle();
    }
    scanf("%f", &c);

    if(getchar()!='\n')
    {
        printf("Error! Do not enter a symbol. Press any key to continue.");
        fflush(stdin);
        return triangle();
    }
    if(c<=0)
    {
        printf("Error! The side must be bigger than zero. Press any key to continue.");
        return triangle();
    }
    if((a+b)<=c||(a+c)<=b||(b+c)<=a)
    {
        printf("Error! The sum of two sides of triangle must be bigger than the third. Press any key to continue.");
        return triangle();
    }
    count++;
}
    P = a+b+c;
    p = P/2;
    S = sqrt(p*(p-a)*(p-b)*(p-c));

    Ha = 2*S/a;
    Hb = 2*S/b;
    Hc = 2*S/c;

    Ma = sqrt((2*b*b)+(2*c*c)-(a*a))/2;
    Mb = sqrt((2*a*a)+(2*c*c)-(b*b))/2;
    Mc = sqrt((2*a*a)+(2*b*b)-(c*c))/2;

    Ba = (2/(b+c))*(sqrt(b*c*p*(p-a)));
    Bb = (2/(a+c))*(sqrt(a*c*p*(p-b)));
    Bc = (2/(a+b))*(sqrt(a*b*p*(p-c)));

    printf("The perimeter of this triangle equals %f.\n", P);
    printf("The area of this triangle equals %f.\n", S);
    printf("The height to \"a\" equals %f\n", Ha);
    printf("The height to \"b\" equals %f\n", Hb);
    printf("The height to \"c\" equals %f\n", Hc);
    printf("The median to \"a\" equals %f\n", Ma);
    printf("The median to \"b\" equals %f\n", Mb);
    printf("The median to \"c\" equals %f\n", Mc);
    printf("The bisector to \"a\" equals %f\n", Ba);
    printf("The bisector to \"b\" equals %f\n", Bb);
    printf("The bisector to \"c\" equals %f\n", Bc);
    getch();
    system("cls");
    printf("If you want to end, press ESC.\n");
    printf("If you want to try again, press any key.");
}
}
