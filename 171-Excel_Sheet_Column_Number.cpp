/*
 * Problem 205:	Isomorphic Strings 
 *
 * Related to question Excel Sheet Column Title
 *
 * Given a column title as appear in an Excel sheet, return its corresponding column number.
 *
 * For example:
 *
 *  A -> 1
 *  B -> 2
 *  C -> 3
 *  ...
 *  Z -> 26
 *  AA -> 27
 *  AB -> 28 .
 */

/* 
 * 将其看成26进制数即可  
 */

//Solution
class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        int len = s.size();
        for (int i = 0; i < len; i++) {
            res = res * 26;
            res = res + ch2num(s[i]);
        }
        return res;
    }
    int ch2num(char ch)
    {
        int num;
        num = ch - 'A' + 1;
        return num;
    }
};
