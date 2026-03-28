#include <stdio.h>

// 將數字反轉的函式
long long reverseNum(long long num) {
    long long rev = 0;
    while (num > 0) {
        rev = rev * 10 + (num % 10);
        num /= 10;
    }
    return rev;
}

int main(void) {
    freopen("ans4.txt", "w", stdout);

    int t;
    // 讀取測資數量
    if (scanf("%d", &t) != 1) return 0;

    while (t--) {
        long long p;
        scanf("%lld", &p);
        
        int iters = 0; // 記錄相加次數
        
        // 不斷執行直到 p 是迴文數
        while (1) {
            long long rev = reverseNum(p);
            
            // 如果本身等於反轉後的數字，就是迴文，可以跳出
            if (p == rev) {
                break;
            }
            
            // 不然就把數字跟反轉數字相加，然後次數 + 1
            p += rev;
            iters++;
        }
        
        // 印出相加次數以及最後的迴文數
        printf("%d %lld\n", iters, p);
    }
    return 0;
}
