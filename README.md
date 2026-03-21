# NCHU 11402 資料結構 (Data Structure)

這是一個紀錄與放置中興大學（NCHU）11402學期「資料結構」課程作業（Homework）與小考（Quiz）的專案目錄。

## 📂 專案結構 (Project Structure)

目前專案包含了課程的第一份作業與第一次小考：

### 📝 作業 (Homeworks)
- **[hw1/](./hw1/)**: Homework #1 (Due: 2026/03/31)
  - 此作業共包含 4 題，滿分 100 分（各 25 分）：
    1. **Guess the Data Structure**: 給予資料存入與取出的順序，猜測資料結構是 Stack、Queue 還是無法判定。
    2. **Find the Pairs**: 給定一個偶數 $n$，計算滿足 $n = p_1 + p_2$ 的質數對數目。
    3. **Error Correction**: 檢查二維 boolean 矩陣行的加總與列的加總是否皆為偶數（Parity Property），並判斷是否能透過只修改一個 bit 來修復。
    4. **Reverse and Add**: 反轉數字並相加，求出變成迴文 (Palindrome) 所需的最少操作次數與最終的迴文數。
  - **[hw1/1/](./hw1/1/)**: 第 1 部分
    - [problem/](./hw1/1/problem/): 題目與測資 (`README.md`, `testcase*.txt`)
    - [answer/](./hw1/1/answer/): 實作與答案 (`DS*.cpp`, `ans*.txt`)
  - **[hw1/2/](./hw1/2/)**: 第 2 部分
    - [problem/](./hw1/2/problem/): 預留空間
    - [answer/](./hw1/2/answer/): 預留空間

### 📄 小考 (Quizzes)
- **[quiz/](./quiz/)**: 課堂小考紀錄
  - **[quiz1](./quiz/1/)**: 包含第一次小考之題目卷 (`quiz1.pdf`)
  - `quiz/2/`: 預留目錄空間

---

## 🛠️ 開發與繳交規範 (Development & Submission Guidelines)

此規範基於 Homework #1 之要求：

1. **語言限制**：可使用 C 或 C++ 進行開發。
2. **檔案命名**：
   - 程式碼：每題程式碼須命名為 `DS題號_學號.c` (或 `.cpp`)（例如：`DS1_7114056138.c`）。
   - 輸出檔：程式產生之每一題答案須輸出至對應檔案，命名為 `ans題號.txt`（例如：第一題的答案輸出為 `ans1.txt`）。
3. **作業繳交**：
   - 將所有題目的程式碼集合，若有特殊需求可包含 `README.txt`。
   - 所有內容壓縮成一個壓縮檔，且檔名格式需為 `DS_學號.zip` (例如：`DS_7114056138.zip`)。
   - 將壓縮檔繳交至作業平台 iLearning 3.0。

---

## 📬 聯絡資訊 (Contact Info)

若對作業或批改結果有任何疑問，可透過以下方式聯絡助教：
- **Teaching Assistant**: 黃意丞
- **Email**: g114056138@mail.nchu.edu.tw
- **Lab**: WCCCLab (S901)
