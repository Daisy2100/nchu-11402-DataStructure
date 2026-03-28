#include <stdio.h>

int main(void) {
    freopen("ans3.txt", "w", stdout);

    int n;
    // 不斷讀取大小，遇到 0 結束
    while (scanf("%d", &n) == 1 && n != 0) {
        // 設定固定大小的陣列來計算每行(row)和每列(col)的總和，直接初始化為 0
        int row_sums[100] = {0};
        int col_sums[100] = {0};

        // 一邊讀取矩陣資料，一邊累加進對應的行、列總和
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int value;
                scanf("%d", &value);
                row_sums[i] += value;
                col_sums[j] += value;
            }
        }

        int odd_rows = 0, odd_cols = 0;
        int odd_r_idx = -1, odd_c_idx = -1;

        // 檢查有幾個奇數的行與列
        for (int i = 0; i < n; i++) {
            if (row_sums[i] % 2 != 0) {
                odd_rows++;
                odd_r_idx = i;
            }
            if (col_sums[i] % 2 != 0) {
                odd_cols++;
                odd_c_idx = i;
            }
        }

        // 根據奇數行列的數量做最後裁決
        if (odd_rows == 0 && odd_cols == 0) {
            printf("OK\n");
        } else if (odd_rows == 1 && odd_cols == 1) {
            // 注意題目通常要求座標由 1 開始，所以印出時 + 1
            printf("Change (%d,%d)\n", odd_r_idx + 1, odd_c_idx + 1);
        } else {
            printf("Corrupt\n");
        }
    }
    return 0;
}
