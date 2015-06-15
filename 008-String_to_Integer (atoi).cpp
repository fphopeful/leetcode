/*
 * Problem 8:	String to Integer (atoi) 
 *
 * Implement atoi to convert a string to an integer.
 *
 * Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself 
 * what are the possible input cases.
 *
 * Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to 
 * gather all the input requirements up front.
 */

/* 
 * ע�⿪ͷ�пո�������
 * ע��-0012a45Ϊ-12��
 * ע������������Χ��Ϊ���������ֵ��
 * ע�⸺��������Χ��Ϊ��������Сֵ��
 */

//Solution
class Solution {
public:
    int myAtoi(string str) {
        int len = str.size();
        int res = 0;
        int i = 0;
        bool sign = true;
        int max_int = (numeric_limits<int>::max)();
        int min_int = (numeric_limits<int>::min)();
        while (str[i] == ' ')
            i++;
        if (str[i] == '+') { 
            i++;
        } else if (str[i] == '-') {
            sign = false;
            i++;
        } else {
            int tmp = str[i] - '0';
            if (!(tmp <= 9 && tmp >=0))
                return 0;
        }
        for ( ; i < len; i++) {
            int tmp = str[i] - '0';
            if (!(tmp <= 9 && tmp >=0))
                break;
            if (sign == true && 
		((max_int - tmp < res * 10) || 
		 (res != 0 && max_int / res < 10)))
                return max_int;
            if (sign == false && 
		((max_int - tmp < res * 10 - 1) || 
		 (res != 0 && max_int / res < 10)))
                return min_int;
            res = res * 10 + tmp;
        }
        if (sign == false && res < 0)
            return min_int;
        if (sign == true && res < 0)
            return max_int;
        res = (sign == true) ? res : -res;
        return res;
    }
};

/*
 * ��������д�������������
 *
class Solution {
public:
    int atoi(const char *str) {
        if(str == NULL) return 0;
        int res = 0;
        bool sign = true;
        while(*str == ' ') str++;
        if(*str == '+' || *str == '-') {
            sign = *str == '+';
            str++;
        }
        while(isdigit(*str)) {
            if(res > INT_MAX/10 || (res == INT_MAX / 10 && *str - '0' > INT_MAX % 10)){
                return sign ? INT_MAX : INT_MIN;
            }
            res =  res * 10 + *str - '0';
            str++;
        }
        return  sign ? res : -res;
    }
};
*/
/*
 * �����һ�ֽⷨ������ֻ���ж�int�Ƿ�Խ�磬���п��Զ���һ��long long���͵ı������������жϣ�����ӷ��㣬
 * �������ֽⷨ�о����ԣ������ string => long long�����ַ������Ҳ���һ����long long λ�����������
 */
/*
 * ע���֪ʶ�㣺
 * 1��isdigit(*str)�����ж�һ���ַ��Ƿ�Ϊ�����ַ���
 * 2��(numeric_limits<int>::max)() �� INT_MAX ����ʾint������ֵ��
 * 3��(numeric_limits<int>::min)() �� INT_MIN ����ʾint������ֵ��
 */
