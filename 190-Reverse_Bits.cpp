/* 
 * Problem 190:	Reverse Bits 
 * Reverse bits of a given 32 bits unsigned integer.
 *
 * For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), 
 * return 964176192 (represented in binary as 00111001011110000010100101000000).

 * Follow up:
 * If this function is called many times, how would you optimize it?
 * 
 * Related problem: Reverse Integer
 */

/* 
 * ÿ��ѭ����
 * 1����res����1λ������������res��λ�ϵ�������λ�ţ����ճ����λ����
 * 2����n�����λͨ��λ���������ơ���res�����λ��
 * 3����n����1λ��������n�����λ������������ʱ�ε�λ��Ϊ���λ����
 */

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        int i;
        for (i = 0; i < 32; i++) {
            res = res << 1;
            if (n & 1)
                res = res | 1;
            n = n >> 1;
        }
        return res;
    }
};

/*
 * ��һ��˼·��ÿ���õ�ĩβ������,�������Ƶ�31-iλ,Ȼ�����ۼӡ�
 */
