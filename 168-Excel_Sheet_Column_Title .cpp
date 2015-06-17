/*
 * Problem 168:	Excel Sheet Column Title 
 *
 * Given a positive integer, return its corresponding column title as appear in an Excel sheet.
 * 
 * For example:
 *
 *  1 -> A
 *  2 -> B
 *  3 -> C
 *  ...
 *  26 -> Z
 *  27 -> AA
 *  28 -> AB 
 */

/* 
 * 主要是'Z'的处理比较容易出错  
 */

//Solution
class Solution {
public:
    string convertToTitle(int n) {
        string res = "";
        while (n > 0) {
            res.insert(0, 1, num2char((n - 1) % 26));
            n = (n - 1) / 26;
        }
        return res;
    }
    inline char num2char(int num)
    {
        return num + 'A';
    }
};

/*
 * 注意string的insert的用法
 */
