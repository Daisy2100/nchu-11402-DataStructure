#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int t;
    if (scanf("%d", &t) != 1) return 0;

    while (t--) {
        int n;
        if (scanf("%d", &n) != 1) return 0;

        int *que = (int *)malloc(sizeof(int) * (n + 1));
        int *stk = (int *)malloc(sizeof(int) * (n + 1));
        if (!que || !stk) {
            fprintf(stderr, "Memory allocation failed\n");
            free(que);
            free(stk);
            return 1;
        }

        int ql = 0, qr = 0;
        int stp = 0;
        int is_q = 1;
        int is_s = 1;

        for (int i = 0; i < n; ++i) {
            int type, x;
            if (scanf("%d", &type) != 1) {
                free(que);
                free(stk);
                return 0;
            }
            if (type == 1) {
                if (scanf("%d", &x) != 1) {
                    free(que);
                    free(stk);
                    return 0;
                }
                que[qr++] = x;
                stk[stp++] = x;
            } else if (type == 2) {
                if (scanf("%d", &x) != 1) {
                    free(que);
                    free(stk);
                    return 0;
                }
                if (is_q) {
                    if (ql >= qr || que[ql] != x) {
                        is_q = 0;
                    }
                    if (ql < qr) ql++;
                }
                if (is_s) {
                    if (stp <= 0 || stk[stp - 1] != x) {
                        is_s = 0;
                    }
                    if (stp > 0) stp--;
                }
            }
        }

        if (is_q && !is_s) {
            puts("queue");
        } else if (is_s && !is_q) {
            puts("stack");
        } else {
            puts("impossible");
        }

        free(que);
        free(stk);
    }

    return 0;
}
