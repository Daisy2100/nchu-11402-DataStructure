#include <stdio.h>
#include <stdlib.h>

// --- 助教規定的起手式結構 ---
struct Node {
    int order, num;
    struct Node *next, *prev;
};

struct LinkedList {
    struct Node *head;
};
// ----------------------------

// 輾轉相除法求最大公因數 (GCD)
int gcd(int a, int b) {
    while (b) {
        a %= b;
        int t = a; a = b; b = t;
    }
    return a;
}

void solve() {
    int m;
    if (scanf("%d", &m) != 1) return;

    struct LinkedList list;
    list.head = NULL;
    struct Node *tail = NULL;

    // 1. 讀取輸入並建立「雙向環狀鏈結串列」
    for (int i = 1; i <= m; i++) {
        int val;
        scanf("%d", &val);
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->order = i;
        newNode->num = val;
        newNode->next = newNode->prev = NULL;

        if (list.head == NULL) {
            list.head = newNode;
            tail = newNode;
            newNode->next = newNode;
            newNode->prev = newNode; // 自己指自己，形成環
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = list.head;
            list.head->prev = newNode;
            tail = newNode;
        }
    }

    // 用陣列記錄被捨棄的順序
    int *discarded = (int *)malloc(m * sizeof(int));
    int discard_count = 0;

    // 2. 模擬過程
    if (m == 1) {
        // 邊界條件：如果一開始只有一個數字，自己跟自己比
        if (gcd(list.head->num, list.head->num) == 1) {
            discarded[discard_count++] = list.head->order;
            free(list.head);
            list.head = NULL;
        }
    } else {
        struct Node *rem = list.head;       // rem: last remembered number (xi)
        struct Node *cur = list.head->next; // cur: current number to look at (xj)
        int steps_without_discard = 0;      // 記錄有幾步沒有捨棄，用來判斷是否陷入無限迴圈
        int current_m = m;                  // 目前串列中還剩下幾個數字

        // 當串列中大於 1 個元素，且還沒有繞完整整一圈都沒事時，繼續執行
        while (current_m > 1 && steps_without_discard < current_m) {
            if (gcd(rem->num, cur->num) == 1) {
                // 【互質】：捨棄 current_node
                discarded[discard_count++] = cur->order;
                struct Node *to_delete = cur;
                
                // 指標斷開與重新連接
                cur->prev->next = cur->next;
                cur->next->prev = cur->prev;
                
                // 如果剛好刪除到 head，要把 head 移交給下一個
                if (to_delete == list.head) {
                    list.head = to_delete->next;
                }
                
                struct Node *next_node = cur->next;
                free(to_delete);
                current_m--;
                
                // 題目規定：「捨棄後，必須從下一個數字重新開始」
                // 因此下一個數字變成新的 remembered number
                rem = next_node;
                cur = rem->next;
                steps_without_discard = 0; // 成功捨棄，步數歸零
                
            } else {
                // 【不互質】：不能捨棄，目前數字變成新的 remembered number，繼續看下一個
                rem = cur;
                cur = cur->next;
                steps_without_discard++;
            }
        }
        
        // 檢查最後如果剛好只剩下 1 個元素，要自己跟自己做最後一次判定
        if (current_m == 1) {
            if (gcd(list.head->num, list.head->num) == 1) {
                discarded[discard_count++] = list.head->order;
                free(list.head);
                list.head = NULL;
            }
        }
    }

    // 3. 輸出結果 (先印出總捨棄數量，再依序印出原本的 index)
    printf("%d", discard_count);
    for (int i = 0; i < discard_count; i++) {
        printf(" %d", discarded[i]);
    }
    printf("\n");
    
    // 4. 釋放記憶體：把沒被捨棄的殘留節點清空，避免 Memory Leak
    if (list.head != NULL) {
        struct Node *cur = list.head;
        do {
            struct Node *tmp = cur;
            cur = cur->next;
            free(tmp);
        } while (cur != list.head);
    }
    free(discarded);
}

int main() {
    int t;
    if (scanf("%d", &t) == 1) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
