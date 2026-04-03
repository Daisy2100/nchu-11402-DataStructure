#include <stdio.h>
#include <stdlib.h>

// --- 助教規定的起手式結構 ---
struct Node
{
    int order, num;
    struct Node *next, *prev;
};

struct LinkedList
{
    struct Node *head;
};

// 迭代版輾轉相除法求最大公因數 (GCD)
int gcd(int a, int b)
{
    while (b)
    {
        a %= b;
        int t = a;
        a = b;
        b = t;
    }
    return a;
}

void solve()
{
    int m;
    if (scanf("%d", &m) != 1)
        return;

    struct LinkedList list;
    list.head = NULL;
    struct Node *tail = NULL;

    // 建立雙向環狀鏈結串列
    for (int i = 1; i <= m; i++)
    {
        int val;
        scanf("%d", &val);
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->order = i;
        newNode->num = val;
        newNode->next = newNode->prev = NULL;

        if (list.head == NULL)
        {
            list.head = newNode;
            tail = newNode;
            newNode->next = newNode;
            newNode->prev = newNode; // 自己指自己，形成環
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = list.head;
            list.head->prev = newNode;
            tail = newNode;
        }
    }

    int *discarded = (int *)malloc(m * sizeof(int));
    int discard_count = 0;

    if (m == 1)
    {
        if (gcd(list.head->num, list.head->num) == 1)
        {
            discarded[discard_count++] = list.head->order;
            free(list.head);
            list.head = NULL;
        }
    }
    else
    {
        struct Node *rem = list.head;       // rem: xi
        struct Node *cur = list.head->next; // cur: xj
        int steps_without_discard = 0;
        int current_m = m;

        while (current_m > 1 && steps_without_discard < current_m)
        {
            if (gcd(rem->num, cur->num) == 1)
            {
                discarded[discard_count++] = cur->order;
                struct Node *to_delete = cur;

                cur->prev->next = cur->next;
                cur->next->prev = cur->prev;

                if (to_delete == list.head)
                {
                    list.head = to_delete->next;
                }

                struct Node *next_node = cur->next;
                free(to_delete);
                current_m--;

                rem = next_node;
                cur = rem->next;
                steps_without_discard = 0;
            }
            else
            {
                rem = cur;
                cur = cur->next;
                steps_without_discard++;
            }
        }

        if (current_m == 1)
        {
            if (gcd(list.head->num, list.head->num) == 1)
            {
                discarded[discard_count++] = list.head->order;
                free(list.head);
                list.head = NULL;
            }
        }
    }

    // 輸出結果
    printf("%d", discard_count);
    for (int i = 0; i < discard_count; i++)
    {
        printf(" %d", discarded[i]);
    }
    printf("\n");
    fflush(stdout); // 確保即時寫入檔案

    // 釋放殘留節點
    if (list.head != NULL)
    {
        struct Node *cur = list.head;
        do
        {
            struct Node *tmp = cur;
            cur = cur->next;
            free(tmp);
        } while (cur != list.head);
    }
    free(discarded);
}

int main()
{
    // 【修改點】：註解掉本機的 txt 讀取，改為直接從系統標準輸入 (終端機貼上測資)
    // freopen("../problem/testcase4.txt", "r", stdin);

    // 保留輸出到 ans4.txt 的規定 (符合作業要求)
    freopen("ans4.txt", "w", stdout);

    int t;
    if (scanf("%d", &t) == 1)
    {
        while (t--)
        {
            solve();
        }
    }
    return 0;
}