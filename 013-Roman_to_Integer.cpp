/* 
 * Problem 13:	Roman to Integer
 *
 * Given a roman numeral, convert it to an integer.
 *
 * Input is guaranteed to be within the range from 1 to 3999.
 */

/* 
 * roman to int �� int to roman �Ľⷨ�Լ򵥣���ѭ����ķ��򼴿ɣ�
 * ��Ҫ���������ֵĹ������С���ұ�����ұߣ�����֮�� 
 */

class Solution {
public:
    int romanToInt(string s) {
        int res = 0, len = s.size();
        map<char, int> roman;
        roman['I'] = 1;
        roman['V'] = 5;
        roman['X'] = 10;
        roman['L'] = 50;
        roman['C'] = 100;
        roman['D'] = 500;
        roman['M'] = 1000;
        for (int i = 0; i < len; i++) {
            if (i + 1 < len && roman[s[i]] < roman[s[i+1]])
                res -= roman[s[i]];
            else
                res += roman[s[i]];
        }
        return res;
    }
};
