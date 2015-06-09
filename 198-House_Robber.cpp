/* 
 * Problem 198:	House Robber 
 * You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, 
 * the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and 
 * it will automatically contact the police if two adjacent houses were broken into on the same night.
 *
 * Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of 
 * money you can rob tonight without alerting the police..
 */

/* 
 * ��̬�滮
 * dp[i][0]��ʾ���˵�i��houseʱ��͵�����moneyֵ��
 * dp[i][1]��ʾ���˵�i��houseʱ͵�����moneyֵ��
 * ״̬ת�Ʒ��̣�
 * 	dp[i+1][0] = max(dp[i][0], dp[i][1]);
 * 	dp[i+1][1] = dp[i][0] + nums[i+1];
 * �����������ʽ�п��Բ����������ÿһ��dp����ֱ���������������ɣ�
 */

class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        int dp0 = 0, dp1 = 0;
        for (int i = 0; i < len; i++) {
            int tmp = dp0;
            dp0 = max(dp0, dp1);
            dp1 = tmp + nums[i];
        }
        return max(dp0, dp1);
    }
};
