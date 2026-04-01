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

// 初始化 Stack
void initStack(Stack *s) {
    s->top = NULL;
}

// Push 元素
void push(Stack *s, int val) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = s->top;
    s->top = newNode;
}

int main() {
    freopen("ans2.txt", "w", stdout);

    int num, den;
    while (scanf("%d %d", &num, &den) == 2) {
        Stack resultStack;
        initStack(&resultStack);

        int is_first = 1;
        printf("[%d;", num / den);
        
        num = num % den;
        while (num != 0) {
            int temp = num;
            num = den;
            den = temp;
            
            if (num % den == 0) {
                // b_n > 1 若需要合併調整 (但通常測資會剛剛好)
                if (!is_first) printf(",");
                printf("%d", num / den);
            } else {
                if (!is_first) printf(",");
                printf("%d", num / den);
            }
            num = num % den;
            is_first = 0;
        }
        printf("]\n");
    }

    return 0;
}
