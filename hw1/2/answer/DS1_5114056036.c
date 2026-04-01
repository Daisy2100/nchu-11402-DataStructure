#include <stdio.h>
#include <stdlib.h>

// HW2 第一題: Sort Chain
// 助教規定的結構
typedef struct Node {
    int data;
    struct Node *next;
} Node;

int M;

// 比較函數：依照題目規則
// 回傳 1 代表 a 應該排在 b 前面，-1 代表相反，0 代表相等
int compare(int a, int b) {
    int mod_a = a % M;
    int mod_b = b % M;
    
    if (mod_a != mod_b) {
        return (mod_a < mod_b) ? 1 : -1;
    }
    // 餘數相同
    int is_odd_a = abs(a % 2) != 0;
    int is_odd_b = abs(b % 2) != 0;
    
    if (is_odd_a && !is_odd_b) return 1; // 奇數在偶數前
    if (!is_odd_a && is_odd_b) return -1;
    if (is_odd_a && is_odd_b) {
        return (a > b) ? 1 : -1; // 兩個奇數，大的在前
    }
    // 兩個偶數，小的在前
    return (a < b) ? 1 : -1;
}

// 插入串列並保持排序
Node* insert_sorted(Node* head, int val) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = val;
    new_node->next = NULL;

    if (!head || compare(val, head->data) == 1) {
        new_node->next = head;
        return new_node;
    }

    Node* current = head;
    while (current->next != NULL && compare(val, current->next->data) != 1) {
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
    return head;
}

void free_list(Node* head) {
    while (head) {
        Node* tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main() {
    freopen("ans1.txt", "w", stdout);

    int N;
    while (scanf("%d %d", &N, &M) == 2) {
        printf("%d %d\n", N, M);
        if (N == 0 && M == 0) break;

        Node* head = NULL;
        for (int i = 0; i < N; i++) {
            int val;
            scanf("%d", &val);
            head = insert_sorted(head, val);
        }

        Node* curr = head;
        while (curr) {
            printf("%d\n", curr->data);
            curr = curr->next;
        }
        free_list(head);
    }

    return 0;
}
