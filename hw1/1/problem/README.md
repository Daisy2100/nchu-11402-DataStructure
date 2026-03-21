Homework #1 
RELEASEDATE: 2026/03/17 
DUEDATE:2026/03/31, 23:59 on iLearning 3.0 
1. 請將作業繳交至iLearning 3.0 
2. 可使用C或C++ 
3. 請對每題產生答案的檔案，命名為ans題號 (例如: 
第一題，請產生ans1.txt檔案) 
4. 每題的程式碼檔案請命名為DS題號_學號 (例如: 
學號為7114056138，第一題程式碼檔名命名為
DS1_7114056138.c) 
5. 如對作業有任何疑問，請依照以下聯絡方式詢問助
教 
Teaching Assistant: 
⚫ Name: 黃意丞 
⚫ Email: g114056138@mail.nchu.edu.tw 
⚫ Lab: WCCCLab (S901) 
1 
1 Guess the Data Structure (pt. 25) 
There is a bag-like data structure, supporting two operations: 
⚫ 1 x: Throw an element x into the bag. 
⚫ 2: Take out an element from the bag. 
Given a sequence of operations with return values, you’re going 
to guess the data structure. It is a stack, a queue or something 
else that you can hardly determine. 
Input 
The first line of input gives the number of test cases, T 
(1≤T≤50). Each test case begins with a line containing a single 
integer n (1 ≤ n ≤ 1000). Each of the next n lines is either a type
1 command, or an integer 2 followed by an integer x. That 
means after executing a type-2 command, we get an element x 
without error. The value of x is always a positive integer not 
larger than 100. 
Output 
For each test case, output one of the following: 
2 
stack, queue or impossible 
Sample Input 
3 
6 
1 1 
1 2 
1 3 
2 1 
2 2 
2 3 
2  
1 1 
2 2 
4 
1 2 
3 
1 1 
2 1 
2 2 
Sample Output 
queue 
impossible 
stack 
2 Find the Pairs (pt. 25) 
This problem is to write a program that reports the number of all 
the pairs of prime numbers satisfying the n = p1 + p2 for a given 
even number. 
A sequence of even numbers is given as input. Corresponding to 
each number, the program should output the number of pairs 
4 
mentioned above. Notice that we are interested in the number of 
essentially different pairs and therefore you should not count 
(p1, p2) and (p2, p1) separately as two different pairs. 
Input 
An integer is given in each input line. You may assume that 
each integer is even, and is greater than or equal to 4 and less 
than 215. The end of the input is indicated by a number ‘0’. 
Output 
Each output line should contain an integer number. No other 
characters should appear in the output. 
Sample Input 
6 
10 
12 
0 
Sample Output 
5 
1 
2 
1 
3 Error Correction (pt. 25) 
A boolean matrix has the parity property when each row and 
each column has an even sum, i.e. contains an even number of 
bits which are set. 
Your job is to write a program that reads in a matrix and checks 
if it has the parity property. If not, your program should check if 
the parity property can be established by changing only one bit. 
If this is not possible either, the matrix should be classified as 
corrupt. 
Input 
6 
The input data will contain one or more test cases. The first line 
of each test case contains one integer n (n < 100), representing 
the size of the matrix. On the next n lines, there will be n 
integers per line. No other integers than ‘0’ and ‘1’ will occur in 
the matrix. Input will be terminated by a value of 0 for n. 
Output 
For each matrix in the input data, print one line. If the matrix 
already has the parity property, print ‘OK’. If the parity property 
can be established by changing one bit, print ‘Change (i, j)’ 
where i is the row and j the column of the bit to be changed. 
Otherwise, print ‘Corrupt’. 
Sample Input 
4 
1 0 1 0 
0 0 0 0 
1 1 1 1 
0 1 0 1 
7 
4 
1 0 1 0 
0 0 1 0 
1 1 1 1 
0 1 0 1 
4 
1 0 1 0 
0 1 1 0 
1 1 1 1 
0 1 0 1 
0 
Sample Output 
OK 
Change (2,3) 
Corrupt 
8 
4 Reverse and Add (pt. 25) 
The “reverse and add” method is simple: give a number, reverse 
its digits and add it to the original. If the sum is not a 
palindrome, repeat this procedure. 
Your job is to write a program that give the resulting palindrome 
and the number of iterations (additions) to compute the 
palindrome. You might assume that all test data on this problem: 
• will have an answer, 
• will be computable with less than 1000 iterations (additions), 
• will yield a palindrome that is not greater than 4,294,967,295. 
Input 
The first line will have a number N (0 < N ≤ 100) with the 
number of test cases, the next N lines will have a number P to 
compute its palindrome. 
9 
Output 
For each of the N tests you will have to write a line with the 
following data: minimum number of iterations (additions) to get 
to the palindrome and the resulting palindrome itself separated 
by one space. 
Sample Input 
3 
195 
265 
750 
Sample Output 
4 9339  
5 45254  
3 6666 
10 
Submission File: 
請繳交一個壓縮檔，檔名為DS_學號 (例如: 學號為
7114056138，則壓縮檔名為DS_7114056138.zip)，將檔案上
傳至iLearning 3.0，內容包含 
⚫ 所有題目的程式碼 
⚫ README.txt，如果有任何疑問或建議