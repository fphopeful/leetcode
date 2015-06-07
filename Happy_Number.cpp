/* 
 * Problem 202:	Happy Number
 * Write an algorithm to determine if a number is "happy".
 *
 * A happy number is a number defined by the following process: Starting with any positive integer, 
 * replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), 
 * or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.
 *
 * Example: 19 is a happy number
 * 
 * 12 + 92 = 82
 * 82 + 22 = 68
 * 62 + 82 = 100
 * 12 + 02 + 02 = 1
 */

/* 
 * 此题使用set可以很方便的解出,我还需要继续熟练set的使用;
 * 如果此题不使用set等模板库中的内容，则需要自己写查找树，比较麻烦;
 *
 * hashset和set的区别：
 * hashset重点在于set几个字母上，主要实现集合功能，只不过底层函数由hashtable提供，而set是由红黑树作底层，两者的唯一区别就是set默认是排好序的，而hashset不是；
 * 加有hash几个字的一些结构，底层都是由hashtable来提供的，不加的都是由红黑树来提供；
 * hashset 不是标准c++里面的，set查询是o(log(n)),要是hash的话理想上是o(1),不过要看冲突，这个效率是不稳定的；
 * hashtable.hashtable只能处理char,int,short等类型，不能处理string,double,float类型，想要处理的话必须自己加hash function。
 *
 * 基于上述区别：
 * 数据集比较小的时候，还是用set比较好，因为hashset不是标准C++里面的，并且处理的类型有限制；
 * 数据集比较大的时候，还是用hashset，因为时间复杂度比较低。
 */

class Solution {
public:
    bool isHappy(int n) {
        set<int> nums;
        int sum = 0;
        if (n <= 0)
            return false;
        while(1) {
            while (n > 0) {
                sum = sum + (n%10) * (n % 10);
                n = n / 10;
            }
            if (sum == 1)
                return true;
            if (nums.find(sum) != nums.end()) {
                return false;
            } else {
                nums.insert(sum);
                n = sum;
                sum = 0;
            }
        }
    }
};
