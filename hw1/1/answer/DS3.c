#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    while (scanf("%d", &n) == 1 && n != 0) {
        int *row_sums = (int *)calloc(n, sizeof(int));
        int *col_sums = (int *)calloc(n, sizeof(int));
        if (!row_sums || !col_sums) {
            fprintf(stderr, "Memory allocation failed\n");
            free(row_sums);
            free(col_sums);
            return 1;
        }

        int i, j;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                int value;
                if (scanf("%d", &value) != 1) {
                    free(row_sums);
                    free(col_sums);
                    return 0;
                }
                row_sums[i] += value;
                col_sums[j] += value;
            }
        }

        int odd_rows = 0, odd_cols = 0;
        int odd_r_idx = -1, odd_c_idx = -1;

        for (i = 0; i < n; i++) {
            if (row_sums[i] % 2 != 0) {
                odd_rows++;
                odd_r_idx = i;
            }
            if (col_sums[i] % 2 != 0) {
                odd_cols++;
                odd_c_idx = i;
            }
        }

        if (odd_rows == 0 && odd_cols == 0) {
            puts("OK");
        } else if (odd_rows == 1 && odd_cols == 1) {
            printf("Change (%d,%d)\n", odd_r_idx + 1, odd_c_idx + 1);
        } else {
            puts("Corrupt");
        }

        free(row_sums);
        free(col_sums);
    }
    return 0;
}
