#include <stdio.h>
#include <stdlib.h>

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

    int t, caseNum = 1;
    while (scanf("%d", &t) == 1 && t != 0) {
        printf("Scenario #%d\n", caseNum++);
        // 假設最多 100000 個 ID，直接對應 Team (0~99999)
        int teamMap[100000] = {0}; 
        
        for (int i = 0; i < t; i++) {
            int numMembers;
            scanf("%d", &numMembers);
            for (int j = 0; j < numMembers; j++) {
                int memberId;
                scanf("%d", &memberId);
                teamMap[memberId] = i;
            }
        }

        Queue q;
        initQueue(&q);
        char cmd[10];
        
        while (scanf("%s", cmd) == 1 && cmd[0] != 'S') { // "STOP"
            if (cmd[0] == 'E') { // "ENQUEUE"
                int x;
                scanf("%d", &x);
                enqueue(&q, x, teamMap[x]);
            } else if (cmd[0] == 'D') { // "DEQUEUE"
                printf("%d\n", dequeue(&q));
            }
        }
        printf("\n");
        
        // 釋放記憶體...
    }

    return 0;
}
