/* 
 * Given an integer, convert it to a roman numeral.
 *
 * Input is guaranteed to be within the range from 1 to 3999.
 */

/* 
 * 主要是弄清罗马数字的编码方法
 */

class Solution {
public:
    string intToRoman(int num) {
        string res = "";
        map<int, char> roman;
        roman[1] = 'I';
        roman[5] = 'V';
        roman[10] = 'X';
        roman[50] = 'L';
        roman[100] = 'C';
        roman[500] = 'D';
        roman[1000] = 'M';
        for (int i = 1000; i > 0; i /= 10) {
            int tmp = num / i * i;
            if (tmp == i * 1) {
                res.append(1, roman[i]);
            } else if (tmp == i * 2) {
                res.append(2, roman[i]);
            } else if (tmp == i * 3) {
                res.append(3, roman[i]);
            } else if (tmp == i * 4) {
                res.append(1, roman[i]);
                res.append(1, roman[i * 5]);
            } else if (tmp == i * 5) {
                res.append(1, roman[i * 5]);
            } else if (tmp == i * 6) {
                res.append(1, roman[i * 5]);
                res.append(1, roman[i]);
            } else if (tmp == i * 7) {
                res.append(1, roman[i * 5]);
                res.append(2, roman[i]);
            } else if (tmp == i * 8) {
                res.append(1, roman[i * 5]);
                res.append(3, roman[i]);
            } else if (tmp == i * 9) {
                res.append(1, roman[i]);
                res.append(1, roman[i * 10]);
            } else {
                //do nothing;
            };
            num -= tmp;
        }
        return res;
    }
};

/*
下面这种方法非常好：
(解法转自https://github.com/leetcoders/LeetCode/blob/master/IntegertoRoman.h)

class Solution {
public:
    string intToRoman_2(int num) {
        int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
        string numerals[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
        string res;
        for (int i = 0; i < 13; ++i) {
            while (num >= values[i]) {
                num -= values[i];
                res += numerals[i];
            }
        }
        return res;
    }
};
*/
