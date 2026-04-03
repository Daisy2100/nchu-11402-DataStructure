#include <stdio.h>
#include <stdlib.h>

// HW2 第二題: 連分數展開
// 助教規定的結構
typedef struct Node {
    int val;
    struct Node *next;
} Node;

typedef struct {
    Node *top;
} Stack;

// 初始化 Stack (或者作為一般 Linked List 使用)
void initStack(Stack *s) {
    s->top = NULL;
}

// 尾部插入 元素 (當作一般串列使用，因為輸出要正向)
void push_back(Stack *s, int val) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;
    
    if (s->top == NULL) {
        s->top = newNode;
        return;
    }
    
    Node *curr = s->top;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = newNode;
}

void clearStack(Stack *s) {
    while (s->top != NULL) {
        Node *temp = s->top;
        s->top = s->top->next;
        free(temp);
    }
}

int main() {
    freopen("ans2.txt", "w", stdout);

    int num, den;
    
    /*
     * 💡 測試執行小提醒 (如何跳出迴圈並產生結果)：
     * 1. 若在終端機「手動貼上」測資：程式會因為 scanf == 2 一直等下一個輸入。
     *    輸入完畢後，請按下「Ctrl + Z」再按「Enter」(這是在 Windows 送出 EOF 結束訊號)。
     * 2. 若要「瞬間測試」整份測資檔：請直接在終端機下此指令：
     *    ./DS2_5114056036.exe < ../problem/testcase2.txt
     */
    while (scanf("%d %d", &num, &den) == 2) {
        Stack resultStack;
        initStack(&resultStack);

        // 第0項
        push_back(&resultStack, num / den);
        
        num = num % den;
        while (num != 0) {
            int temp = num;
            num = den;
            den = temp;
            
            // 將計算結果加入串列
            push_back(&resultStack, num / den);
            num = num % den;
        }
        
        // 從 List (Stack) 取出資料並印出
        Node *curr = resultStack.top;
        if (curr != NULL) {
            printf("[%d", curr->val);
            curr = curr->next;
            
            if (curr != NULL) {
                printf(";");
                int is_first = 1;
                while (curr != NULL) {
                    if (!is_first) printf(",");
                    printf("%d", curr->val);
                    is_first = 0;
                    curr = curr->next;
                }
            }
        }
        printf("]\n");
        fflush(stdout); // 立刻把輸出寫入檔案中，避免在終端機內等待 EOF 時檔案沒內容

        clearStack(&resultStack);
    }

    return 0;
}
