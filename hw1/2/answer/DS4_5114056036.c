#include <stdio.h>
#include <stdlib.h>

// HW2 第四題: Discard the Number
// 助教規定的結構
struct Node {
    int order, num;
    struct Node *next, *prev;
};

struct LinkedList {
    struct Node *head;
};

// 最大公因數 GCD
int gcd(int a, int b) {
    while (b != 0) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int main() {
    freopen("ans4.txt", "w", stdout);

    int m;
    while (scanf("%d", &m) == 1 && m > 0) {
        struct LinkedList list;
        list.head = (struct Node *)malloc(sizeof(struct Node));
        list.head->num = m;
        list.head->order = 1;
        list.head->next = list.head;
        list.head->prev = list.head;
        
        struct Node *current = list.head;
        int count = 1;
        
        // 讀取直到 -1 結尾 (假設題意測資)
        int x;
        while (scanf("%d", &x) == 1 && x != -1) {
            count++;
            struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
            newNode->num = x;
            newNode->order = count;
            
            newNode->prev = current;
            newNode->next = current->next;
            current->next->prev = newNode;
            current->next = newNode;
            
            current = newNode;
        }

        // 開始從捨棄互質數字邏輯處理
        current = list.head;
        struct Node *prevMemory = current;
        int discard_count = 0;
        current = current->next; // 從下一個開始檢查
        
        while (current != prevMemory) { // 模擬環狀搜尋
            if (gcd(prevMemory->num, current->num) == 1) { // 互質，捨棄
                struct Node *toDiscard = current;
                current->prev->next = current->next;
                current->next->prev = current->prev;
                
                printf("Discard %d\n", toDiscard->num);
                discard_count++;
                
                current = toDiscard->next;
                free(toDiscard);
            } else {
                prevMemory = current;
                current = current->next;
            }
        }
        
    }

    return 0;
}
