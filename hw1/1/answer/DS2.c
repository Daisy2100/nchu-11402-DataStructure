#include <stdio.h>
#include <stdlib.h>

#define MAXN 32768

int is_prime[MAXN];
int primes[4000];
int primes_count = 0;

void sieve(void) {
    int i, j;
    for (i = 0; i < MAXN; i++) is_prime[i] = 1;
    is_prime[0] = is_prime[1] = 0;
    for (i = 2; i * i < MAXN; i++) {
        if (is_prime[i]) {
            for (j = i * i; j < MAXN; j += i) {
                is_prime[j] = 0;
            }
        }
    }
    primes_count = 0;
    for (i = 2; i < MAXN; i++) {
        if (is_prime[i]) {
            primes[primes_count++] = i;
        }
    }
}

int main(void) {
    sieve();
    int n;
    while (scanf("%d", &n) == 1 && n != 0) {
        int count = 0;
        int i;
        for (i = 0; i < primes_count && primes[i] <= n / 2; i++) {
            int p = primes[i];
            if (is_prime[n - p]) {
                count++;
            }
        }
        printf("%d\n", count);
    }
    return 0;
}
