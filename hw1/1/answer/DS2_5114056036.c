#include <stdio.h>

// 判斷是否為質數的簡單函數
int is_prime(int num) {
    if (num < 2) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main(void) {
    freopen("ans2.txt", "w", stdout);

    int n;
    // 不斷讀取輸入直到遇到 0
    while (scanf("%d", &n) == 1 && n != 0) {
        int count = 0;
        
        // 將 n 拆成 i 與 n - i，並檢查兩者是否都是質數
        // 為了避免重複計算，只需檢查到 n / 2
        for (int i = 2; i <= n / 2; i++) {
            if (is_prime(i) && is_prime(n - i)) {
                count++;
            }
        }
        
        printf("%d\n", count);
        fflush(stdout);
    }
    return 0;
}
