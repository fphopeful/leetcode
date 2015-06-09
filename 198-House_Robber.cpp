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
 * 动态规划
 * dp[i][0]表示到了第i个house时不偷，最大money值；
 * dp[i][1]表示到了第i个house时偷，最大money值。
 * 状态转移方程：
 * 	dp[i+1][0] = max(dp[i][0], dp[i][1]);
 * 	dp[i+1][1] = dp[i][0] + nums[i+1];
 * 而在这个递推式中可以不用数组存下每一个dp，而直接用两个变量即可；
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
