#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// HW2 第三題: Team Queue
// 助教規定的結構
typedef struct Node {
    int data;
    int team;
    struct Node *next, *pre;
} Node;

typedef struct Queue {
    Node *front, *rear;
} Queue;

// 全域變數，避免測資的 ID 太大把 Stack 撐爆，並支援到 100 萬的 ID
int teamMap[1000000];

// 初始化 Queue
void initQueue(Queue *q) {
    q->front = q->rear = NULL;
}

// 加入佇列：如果有同隊友，插在他後面；否則排到最後面
void enqueue(Queue *q, int val, int teamId) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = val;
    newNode->team = teamId;
    newNode->next = newNode->pre = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }

    Node *curr = q->rear;
    while (curr != NULL && curr->team != teamId) {
        curr = curr->pre; // 從後面往前找同隊友
    }

    if (curr != NULL) { // 找到隊友，插在他後面
        newNode->next = curr->next;
        newNode->pre = curr;
        if (curr->next != NULL) {
            curr->next->pre = newNode;
        } else {
            q->rear = newNode; // 更新最後尾巴
        }
        curr->next = newNode;
    } else { // 沒找到隊友，排最後面
        newNode->pre = q->rear;
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// 拿出佇列最前方元素
int dequeue(Queue *q) {
    if (q->front == NULL) return -1;
    Node *temp = q->front;
    int val = temp->data;
    
    q->front = q->front->next;
    if (q->front != NULL) {
        q->front->pre = NULL;
    } else {
        q->rear = NULL;
    }
    
    free(temp);
    return val;
}

int main() {
    freopen("ans3.txt", "w", stdout);

    int t;
    while (scanf("%d", &t) == 1 && t != 0) {
        
        // 預設所有人都不屬於任何隊伍 (-1)
        memset(teamMap, -1, sizeof(teamMap));
        
        for (int i = 0; i < t; i++) {
            int numMembers;
            scanf("%d", &numMembers);
            for (int j = 0; j < numMembers; j++) {
                int memberId;
                scanf("%d", &memberId);
                // 確保讀到的 ID 不會超過我們宣告的陣列大小 (1,000,000)
                if (memberId >= 0 && memberId < 1000000) {
                    teamMap[memberId] = i;
                }
            }
        }

        Queue q;
        initQueue(&q);
        char cmd[10];
        
        while (scanf("%s", cmd) == 1 && cmd[0] != 'S') { // "STOP"
            if (cmd[0] == 'E') { // "ENQUEUE"
                int x;
                scanf("%d", &x);
                int teamId = (x >= 0 && x < 1000000) ? teamMap[x] : -1;
                enqueue(&q, x, teamId);
            } else if (cmd[0] == 'D') { // "DEQUEUE"
                printf("%d\n", dequeue(&q));
            }
        }
        printf("\n");
        fflush(stdout); // 即時輸出到檔案
        
        // 釋放記憶體：把還在 Queue 裡面的清空，避免 Memory Leak
        while (q.front != NULL) {
            dequeue(&q);
        }
    }

    return 0;
}
