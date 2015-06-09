/* 
 * Problem 189:	Rotate Array
 * Rotate an array of n elements to the right by k steps.
 * 
 * For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
 *
 * Note:
 * Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
 * 
 * [show hint]
 *
 * Hint:
 * Could you do it in-place with O(1) extra space?
 * Related problem: Reverse Words in a String II
 */

/* 
 * ��Ŀ����һ��û�������������kֵ�Ƿ���Դ���n����������һ��Ҫ�ǵø����Թٹ�ͨ������⡣
 *
 * ����1��ÿ�ζ�ɾ��0����ֵ��������ֵ�ӵ�β����
 *
 * ���������д����
 */

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        k = k % size;
        int len = size - k;
        for (int i = 0; i < len; i++) {
            int tmp;
            tmp = nums[0];
            nums.erase(nums.begin());
            nums.push_back(tmp);
        }
    }
};

/*
 * ע��nums.erase() / nums.begin() / nums.push_back()���÷���
 */
