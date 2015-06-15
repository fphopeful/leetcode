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
 * 注意开头有空格的情况；
 * 注意-0012a45为-12；
 * 注意正数超出范围则为正数的最大值；
 * 注意负数超出范围则为负数的最小值；
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
 * 下面这种写法代码更清晰：
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
 * 另外的一种解法：由于只是判断int是否越界，所有可以定义一个long long类型的变量来做辅助判断，会更加方便，
 * 但是这种解法有局限性，如果是 string => long long，这种方法则找不到一个比long long 位数更多的量。
 */
/*
 * 注意的知识点：
 * 1、isdigit(*str)即可判断一个字符是否为数字字符；
 * 2、(numeric_limits<int>::max)() 与 INT_MAX 均表示int的上限值；
 * 3、(numeric_limits<int>::min)() 与 INT_MIN 均表示int的下限值；
 */
