#include <stdio.h>

long long reverseNum(long long num) {
    long long rev = 0;
    while (num > 0) {
        rev = rev * 10 + num % 10;
        num /= 10;
    }
    return rev;
}

int main(void) {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        long long p;
        if (scanf("%lld", &p) != 1) return 0;
        int iters = 0;
        while (1) {
            long long rev = reverseNum(p);
            if (p == rev) {
                break;
            }
            p += rev;
            iters++;
        }
        printf("%d %lld\n", iters, p);
    }
    return 0;
}
