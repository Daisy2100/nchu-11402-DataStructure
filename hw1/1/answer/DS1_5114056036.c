#include <stdio.h>

int main()
{
    freopen("ans1.txt", "w", stdout);
    
    int t;
    // 1. 讀取總共有幾組實驗
    if (scanf("%d", &t) != 1)
        return 0;

    while (t--)
    {
        int n;
        scanf("%d", &n);

        // 準備兩個陣列當箱子，假設最多放 1000 個數字
        int que[1000], stk[1000];

        // 管理員指針
        int head = 0, tail = 0; // Queue 用：頭跟尾
        int top = 0;            // Stack 用：最上方的位置

        // 偵探旗標：先假設兩個都成立 (1 是真, 0 是假)
        int is_q = 1;
        int is_s = 1;

        for (int i = 0; i < n; i++)
        {
            int type, x;
            scanf("%d %d", &type, &x);

            if (type == 1)
            {
                // --- 動作 1：把數字 x 丟進去 ---
                que[tail++] = x; // 排隊：排在最後面，尾巴往後移
                stk[top++] = x;  // 疊盤：疊在最上面，高度往上升
            }
            else if (type == 2)
            {
                // --- 動作 2：拿出來檢查，看是不是 x ---

                // 檢查 Queue (應該拿最前面的人 head)
                if (head >= tail || que[head] != x)
                {
                    is_q = 0; // 根本沒人排隊，或排頭不是 x，剔除！
                }
                else
                {
                    head++; // 沒事，讓排頭離開，換下一個人
                }

                // 檢查 Stack (應該拿最上面的人 top-1)
                if (top <= 0 || stk[top - 1] != x)
                {
                    is_s = 0; // 箱子空了，或最上面不是 x，剔除！
                }
                else
                {
                    top--; // 沒事，把最上面的盤子拿走，高度下降
                }
            }
        }

        // --- 最後宣判 ---
        if (is_q && !is_s)
        {
            printf("queue\n");
        }
        else if (is_s && !is_q)
        {
            printf("stack\n");
        }
        else
        {
            // 兩者都像、或者兩者都不像，通通印 impossible
            printf("impossible\n");
        }
    }
    return 0;
}