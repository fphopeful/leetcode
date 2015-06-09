/* 
 * Problem 191:	Number of 1 Bits
 * Write a function that takes an unsigned integer and returns the number of ��1' bits it has (also known as the Hamming weight).
 *
 * For example, the 32-bit integer ��11' has binary representation 00000000000000000000000000001011, so the function should return 3.1
 */

/* 
 * ÿ�ν�����λ����һλ��ͳ�����λΪ1�Ĵ������ɡ� 
 */

class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t base = 1;
        int cnt = 0;
        while (n != 0) {
            if ((n & base) == 1)
                cnt++;
            n = n >> 1;
        }
        return cnt;
    }
};
