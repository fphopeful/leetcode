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
 * 每次循环：
 * 1、将res右移1位（即，将进入res的位上的数往高位放，并空出最低位）；
 * 2、将n的最低位通过位操作“复制”到res的最低位；
 * 3、将n左移1位（即，将n的最低位的数丢弃，此时次低位变为最低位）。
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
 * 另一种思路：每次拿到末尾的数字,就先左移到31-i位,然后再累加。
 */
