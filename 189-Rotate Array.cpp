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
 * 题目中有一处没有描述清楚，即k值是否可以大于n。在面试中一定要记得跟面试官沟通清楚题意。
 *
 * 做法1：每次都删除0处的值，并将该值加到尾部。
 *
 * 其他做法有待添加
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
 * 注意nums.erase() / nums.begin() / nums.push_back()的用法。
 */
