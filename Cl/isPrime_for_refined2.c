#include <stdio.h>

int isPrime(int x, int knownPrimes[], int numberOfKnownPrimes);

int main()
{
    const int number = 100;
    int prime[number];
    // int prime[number] = {2};
    prime[0] = 2;
    int count = 1;
    int i = 3;

    while (count < number) {
        if (isPrime(i, prime, count)) {
            prime[count++] = i;
        }
        i ++;
    }

    for (i=0; i < number; i ++) {
        printf("%d", prime[i]);
        if ((i + 1) % 5) printf("\t");  // \t == tab
        else printf("\n");            
    }

    return 0;
}

int isPrime(int x, int knownPrimes[], int numberOfKnownPrimes)
{
    int ret = 1;
    int i;

    for (i = 0; i < numberOfKnownPrimes; i ++) {
        if (x % knownPrimes[i] == 0) {  // 
            ret = 0;
            break;
        }
    }

    return ret;
}