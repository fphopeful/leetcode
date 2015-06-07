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
 * ����ʹ��set���Ժܷ���Ľ��,�һ���Ҫ��������set��ʹ��;
 * ������ⲻʹ��set��ģ����е����ݣ�����Ҫ�Լ�д���������Ƚ��鷳;
 *
 * hashset��set������
 * hashset�ص�����set������ĸ�ϣ���Ҫʵ�ּ��Ϲ��ܣ�ֻ�����ײ㺯����hashtable�ṩ����set���ɺ�������ײ㣬���ߵ�Ψһ�������setĬ�����ź���ģ���hashset���ǣ�
 * ����hash�����ֵ�һЩ�ṹ���ײ㶼����hashtable���ṩ�ģ����ӵĶ����ɺ�������ṩ��
 * hashset ���Ǳ�׼c++����ģ�set��ѯ��o(log(n)),Ҫ��hash�Ļ���������o(1),����Ҫ����ͻ�����Ч���ǲ��ȶ��ģ�
 * hashtable.hashtableֻ�ܴ���char,int,short�����ͣ����ܴ���string,double,float���ͣ���Ҫ����Ļ������Լ���hash function��
 *
 * ������������
 * ���ݼ��Ƚ�С��ʱ�򣬻�����set�ȽϺã���Ϊhashset���Ǳ�׼C++����ģ����Ҵ�������������ƣ�
 * ���ݼ��Ƚϴ��ʱ�򣬻�����hashset����Ϊʱ�临�ӶȱȽϵ͡�
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
