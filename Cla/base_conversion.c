#include <stdio.h>

#define NEXTLINE printf("\n");

long long base10(void);


int main(void)
{
    long long number;
    long long* result;
    int base;
    int tbase;

    printf("Enter original base, target base and the number to converse.For example: \n\
2 16 101 means the number 101 is going to be conversed from base 2 to base 16.\n");
    scanf("%d %d", &base, &tbase);

    number = base10();

    printf("%lld\n", number);


    NEXTLINE

    printf("Enter any key to continue.\n");
    getchar();
    getchar();

    // NEXTLINE

    // int a, q = 1;
    // long long r = 0;
    // scanf("%d", &a);
    // for (long long i = 1; q != 0; i *= 10) {
    //     q = a / 2;

    //     r += a % 2 * i;

    //     a = q;
    // }
    
    // printf("%lld", r);

    // NEXTLINE

    // int a;
    // scanf("%x", &a);
    // printf("%d\n", a);

    return 0;
}


long long base10(void)
{
    long long number;
    scanf("%lld", &number);
    return number;
}