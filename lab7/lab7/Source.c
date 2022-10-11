#include<locale.h>
#include<stdio.h>
#include<math.h>
void main()
{
	setlocale(LC_ALL, "RUS");
    float a, b;
    char c, t;
    printf("¬ведите букву или цифру: ");
    scanf("%c", &t);
    switch ((t >= 'a' && t <= 'z') || (t >= 'A' && t <= 'Z'))
    {
    case 1:
        printf("¬ведена буква.\n");
        puts("введите число, операцию, число");
    }
    switch (t >= '1' && t <= '9')
    {
    case 1:
        printf("¬ведена цифра.\n");
        puts("введите число, операцию, число");
    }
    scanf("%f %c %f", &a, &c, &b);
    switch (c)
    {

    case '+':
        printf("%g", a + b);
        break;

    case '-':
        printf("%g", a - b);
        break;

    case '*':
        printf("%g", a * b);
        break;
    case '/':
        printf("%g", a /b);
        break;
    case '$':
        printf("%g", pow(a, b));
        break;
    }
}