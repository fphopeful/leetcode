/*
 * Problem 152:	Maximum Product Subarray  
 *
 * Find the contiguous subarray within an array (containing at least one number) which has the largest product.
 *
 * For example, given the array [2,3,-2,4],
 * the contiguous subarray [2,3] has the largest product = 6.
 */

/* 经典的做法是动态规划，在后面也会给出这种方法的代码和思路 */
/* 下面是我的另一种思路，也只需要对数组进行一次扫描即可 */
/* 我的这种解法，时间复杂度起码不输于动态规划，在leetcode上提交甚至会比动归块，没有具体分析过 */
/* 在leetcode上提交时，记得将所有注释去掉，以免影响测试速度 */
/* 动态规划的方法，在最后也给出了 */

/*
1. 以数字串中的0和结束位置为标记分割出每个区域，即erea，对每个erea求最大乘积;
2. 对每个erea求出的最大乘积，得到最大那个乘积即为题中所需求解的结果;如果数字串中出现过0，则比较的时候还要算上0;
3. 在每个erea中，又分为三部分，即3个block:
	3.1 以出现的第1个负数、出现的最后一个负数，为2个分割线，分割成3个block;
	3.2 即可得到first_blk_pro | first_neg | mid_blk_pro | last_neg | last_blk_pro;
	3.3 如果mid_blk_pro为正数，则该erea最大乘积为上述五个数值的乘积;
	3.4 如果mid_blk_pro为负数，则该erea最大乘积为下面两者的最大值：
		3.4.1 first_blk_pro * first_neg * mid_blk_pro;
		3.4.2 mid_blk_pro * last_neg * last_blk_pro;
	3.5 还有一些特例情况需要处理，在代码中已经标出.
*/

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int maxProduct(int* nums, int numsSize) {
    int max_erea_pro = 0, erea_pro = 1;
    int first_blk_pro = 1, last_blk_pro = 1, mid_blk_pro = 1;
    int first_neg_idx = -1, last_neg_idx = -1;
    int i = 0, count = 0;
	int sign = 0;

    for (i = 0; i < numsSize; i++) {
        //遇到0,则为分割线,处理前面的区域
        if (nums[i] == 0) {
			//如果前面的erea出现过负数
            if (first_neg_idx != -1) {
					//默认为前面的erea起码出现过两个负数, 其他情况分别单列处理

					//算出erea最后一个负数出现之后的乘积
                    last_blk_pro = erea_pro / mid_blk_pro;
					//算出erea中第一个负数和最后一个负数之间的数字的乘积
                    mid_blk_pro = mid_blk_pro / nums[last_neg_idx];
                    //算出erea中第一个负数之前的数字的乘积
                    first_blk_pro = first_blk_pro / nums[first_neg_idx];
                    //算出erea的最大乘积       
                    if (mid_blk_pro > 0)
                        erea_pro = first_blk_pro * nums[first_neg_idx] * mid_blk_pro * 
                                    nums[last_neg_idx] * last_blk_pro;
                    if (mid_blk_pro < 0)
                        erea_pro = max(first_blk_pro * nums[first_neg_idx] * mid_blk_pro,
                                     mid_blk_pro * nums[last_neg_idx] * last_blk_pro);
                    
					//如果erea中只出现过一个负数
                    if (first_neg_idx == last_neg_idx)
                        erea_pro = max(first_blk_pro, last_blk_pro);
                    
					//如果erea中只有一个数
                    if (count == 1)
                        erea_pro = nums[i - 1];
			}
			//如果erea中没有任何数字
			if (count == 0)
				erea_pro = 0;
			//初始化的max_erea_pro为0，而erea_pro可能为负数，所以首次算max_erea_pro需要单列处理
			if (sign == 0) {
				max_erea_pro = erea_pro;
				sign = 1;
			}

			//让max_erea_pro永远保持最大
            if (max_erea_pro < erea_pro) {
                max_erea_pro = erea_pro;
            }
			//如果max_erea_pro小于0，而nums为0时，才能进入本流程，所以将0考虑在内,最大的erea_pro则为0
			if (max_erea_pro < 0)
				max_erea_pro = 0;

			//重新初始化,处理下一个erea
            erea_pro = 1;
            first_neg_idx = -1;
            last_neg_idx = -1;
            first_blk_pro = 1;
            last_blk_pro = 1;
            mid_blk_pro = 1;
            count = 0;
            continue;
        }

		count++;
		//常规处理
		erea_pro = erea_pro * nums[i];

        //遇到负数的处理
        if (nums[i] < 0) {
            if (first_neg_idx == -1) {
				//如果遇到的是第一个负数
                first_neg_idx = i;
                last_neg_idx = i;
                first_blk_pro = erea_pro;
                erea_pro = 1;
            } else {
				//将每次遇到的负数都暂定为最后一个负数
				//直到遇到真正的最后一个负数,last_neg_idx才稳定下来
                last_neg_idx = i;
                mid_blk_pro = erea_pro;
            }
        }
    }

	//数组结束的处理,与nums[i]为0的处理类似
    if (first_neg_idx != -1) { 
        last_blk_pro = erea_pro / mid_blk_pro;
                    
        mid_blk_pro = mid_blk_pro / nums[last_neg_idx];
                        
        first_blk_pro = first_blk_pro / nums[first_neg_idx];
                           
        if (mid_blk_pro > 0)
			erea_pro = first_blk_pro * nums[first_neg_idx] * mid_blk_pro * 
						nums[last_neg_idx] * last_blk_pro;
        if (mid_blk_pro < 0)
            erea_pro = max(first_blk_pro * nums[first_neg_idx] * mid_blk_pro,
                        mid_blk_pro * nums[last_neg_idx] * last_blk_pro);
                                     
        if (first_neg_idx == last_neg_idx)
            erea_pro = max(first_blk_pro, last_blk_pro);

		if (count == 1)
            erea_pro = nums[i - 1];
	}
	if (count == 0)
		erea_pro = 0;
	if (sign == 0) {
		max_erea_pro = erea_pro;
		sign = 1;
	}
    if (max_erea_pro < erea_pro) {
        max_erea_pro = erea_pro;
    }
	//因为数组结束时不是遇到元素0,所以不会有下面的判断
	//if (max_erea_pro < 0)
		//max_erea_pro = 0;

    return max_erea_pro;
}

/* 
 * 动态规划方法如下
 * 状态转移方程：
 *		max_copy[i - 1] = max_local[i - 1]
 *		max_local[i] = Max(Max(max_local[i - 1] * A[i], A[i]),  min_local * A[i])
 *		min_local[i] = Min(Min(max_copy[i - 1] * A[i], A[i]),  min_local * A[i])
 */
/*
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}

int maxProduct(int *A, int n) {
    if (n == 0) return 0;
    int maxv = A[0], minv = A[0], result = A[0];
    for (int i=1; i<n; i++) {
      int nmaxv = maxv * A[i], nminv = minv * A[i];
      maxv = max(max(nmaxv, nminv), A[i]);
      minv = min(min(nmaxv, nminv), A[i]);
      result = max(result, maxv);
    }
    return result;
 }
 */
