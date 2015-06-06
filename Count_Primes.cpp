/* 
 * Problem 204:	Count Primes 
 * Description:
 *
 * Count the number of prime numbers less than a non-negative number, n.
 */

/* 
 * ����˼·��
 * ʹ��"Sieve of Eratosthenes"����ʱ�临�Ӷ�����;
 * ��ϸ�������ַ�е�hint��https://leetcode.com/problems/count-primes/
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        int i;
        bool *is_primes = new bool[n];
        for (i = 2; i < n; i++)
            is_primes[i] = true;
        for (i = 2; i * i < n; i++) {
            int j;
            if (is_primes[i] == false)
                continue;
            for (j = i * i; j < n; j += i)
                is_primes[j] = false;
        }
        for (i = 2; i < n; i++) {
            if (is_primes[i] == true)
                count++;
        }
        return count;
    }
};
