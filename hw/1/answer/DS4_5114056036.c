#include <stdio.h>

// --- 小幫手函式：用來把數字「顛倒」 ---
// 這裡必須用 long long (超大整數)，因為數字相加好幾次之後，很可能會超過一般 int 的範圍！
long long reverseNum(long long num) {
    long long rev = 0; 
    
    // 當數字還沒被扒光之前，也就是大於 0 就繼續
    while (num > 0) {
        // 1. (num % 10) 可以抓出原本數字的「最後一位數」
        // 2. rev * 10 負責把已經反轉的結果「往左推一位」，騰出個位數的空間
        // 3. 兩者相加，就把剛剛抓出來的數字塞進反轉結果的個位數了！
        rev = rev * 10 + (num % 10);
        
        // 4. 原本的數字除以 10，也就是把剛剛處理完的最後一位數「砍掉」
        num /= 10;
    }
    return rev; // 回傳顛倒過後的新數字
}

int main(void) {
    // 把螢幕輸出的結果全部存進 ans4.txt 檔案裡，終端機不會印東西
    freopen("ans4.txt", "w", stdout);

    int t;
    // 讀取「總共有幾組測資」，如果讀取失敗(例如檔案結束)就直接結束程式
    if (scanf("%d", &t) != 1) return 0;

    // t-- 代表：執行 t 次，每次 t 會減 1，直到 t 變成 0 就結束
    while (t--) {
        long long p;
        scanf("%lld", &p);
        
        int iters = 0; // 用來記錄「總共相加了幾次」，一開始是 0 次
        
        // 不斷執行直到 p 是迴文數為止
        // 注意重點：題目規定要「先相加、再判斷」，所以如果一開始輸入 11 (雖然已經是迴文)
        // 還是得先相加一次變成 22 才能停下來！
        while (1) {
            // 1. 先產生目前數字的顛倒版本
            long long rev = reverseNum(p);
            
            // 2. 毫不猶豫，先把它們相加，次數 + 1
            p += rev;
            iters++;
            
            // 3. 相加完之後，再拿「新的結果 p」去檢查它是不是迴文數
            long long new_rev = reverseNum(p);
            if (p == new_rev) {
                break; // 如果中獎了，立刻脫逃無窮迴圈！
            }
        }
        
        // 跳出迴圈後，印出任務的最終結果：
        // %d 是印出加了幾次 (iters)
        // %lld 是印出最後變成迴文數的結果 (p)
        printf("%d %lld\n", iters, p);
    }
    return 0;
}
