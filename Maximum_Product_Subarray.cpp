/*
 * Problem 152:	Maximum Product Subarray  
 *
 * Find the contiguous subarray within an array (containing at least one number) which has the largest product.
 *
 * For example, given the array [2,3,-2,4],
 * the contiguous subarray [2,3] has the largest product = 6.
 */

/* ����������Ƕ�̬�滮���ں���Ҳ��������ַ����Ĵ����˼· */
/* �������ҵ���һ��˼·��Ҳֻ��Ҫ���������һ��ɨ�輴�� */
/* �ҵ����ֽⷨ��ʱ�临�Ӷ����벻���ڶ�̬�滮����leetcode���ύ������ȶ���飬û�о�������� */
/* ��leetcode���ύʱ���ǵý�����ע��ȥ��������Ӱ������ٶ� */
/* ��̬�滮�ķ����������Ҳ������ */

/*
1. �����ִ��е�0�ͽ���λ��Ϊ��Ƿָ��ÿ�����򣬼�erea����ÿ��erea�����˻�;
2. ��ÿ��erea��������˻����õ�����Ǹ��˻���Ϊ�����������Ľ��;������ִ��г��ֹ�0����Ƚϵ�ʱ��Ҫ����0;
3. ��ÿ��erea�У��ַ�Ϊ�����֣���3��block:
	3.1 �Գ��ֵĵ�1�����������ֵ����һ��������Ϊ2���ָ��ߣ��ָ��3��block;
	3.2 ���ɵõ�first_blk_pro | first_neg | mid_blk_pro | last_neg | last_blk_pro;
	3.3 ���mid_blk_proΪ���������erea���˻�Ϊ���������ֵ�ĳ˻�;
	3.4 ���mid_blk_proΪ���������erea���˻�Ϊ�������ߵ����ֵ��
		3.4.1 first_blk_pro * first_neg * mid_blk_pro;
		3.4.2 mid_blk_pro * last_neg * last_blk_pro;
	3.5 ����һЩ���������Ҫ�����ڴ������Ѿ����.
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
        //����0,��Ϊ�ָ���,����ǰ�������
        if (nums[i] == 0) {
			//���ǰ���erea���ֹ�����
            if (first_neg_idx != -1) {
					//Ĭ��Ϊǰ���erea������ֹ���������, ��������ֱ��д���

					//���erea���һ����������֮��ĳ˻�
                    last_blk_pro = erea_pro / mid_blk_pro;
					//���erea�е�һ�����������һ������֮������ֵĳ˻�
                    mid_blk_pro = mid_blk_pro / nums[last_neg_idx];
                    //���erea�е�һ������֮ǰ�����ֵĳ˻�
                    first_blk_pro = first_blk_pro / nums[first_neg_idx];
                    //���erea�����˻�       
                    if (mid_blk_pro > 0)
                        erea_pro = first_blk_pro * nums[first_neg_idx] * mid_blk_pro * 
                                    nums[last_neg_idx] * last_blk_pro;
                    if (mid_blk_pro < 0)
                        erea_pro = max(first_blk_pro * nums[first_neg_idx] * mid_blk_pro,
                                     mid_blk_pro * nums[last_neg_idx] * last_blk_pro);
                    
					//���erea��ֻ���ֹ�һ������
                    if (first_neg_idx == last_neg_idx)
                        erea_pro = max(first_blk_pro, last_blk_pro);
                    
					//���erea��ֻ��һ����
                    if (count == 1)
                        erea_pro = nums[i - 1];
			}
			//���erea��û���κ�����
			if (count == 0)
				erea_pro = 0;
			//��ʼ����max_erea_proΪ0����erea_pro����Ϊ�����������״���max_erea_pro��Ҫ���д���
			if (sign == 0) {
				max_erea_pro = erea_pro;
				sign = 1;
			}

			//��max_erea_pro��Զ�������
            if (max_erea_pro < erea_pro) {
                max_erea_pro = erea_pro;
            }
			//���max_erea_proС��0����numsΪ0ʱ�����ܽ��뱾���̣����Խ�0��������,����erea_pro��Ϊ0
			if (max_erea_pro < 0)
				max_erea_pro = 0;

			//���³�ʼ��,������һ��erea
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
		//���洦��
		erea_pro = erea_pro * nums[i];

        //���������Ĵ���
        if (nums[i] < 0) {
            if (first_neg_idx == -1) {
				//����������ǵ�һ������
                first_neg_idx = i;
                last_neg_idx = i;
                first_blk_pro = erea_pro;
                erea_pro = 1;
            } else {
				//��ÿ�������ĸ������ݶ�Ϊ���һ������
				//ֱ���������������һ������,last_neg_idx���ȶ�����
                last_neg_idx = i;
                mid_blk_pro = erea_pro;
            }
        }
    }

	//��������Ĵ���,��nums[i]Ϊ0�Ĵ�������
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
	//��Ϊ�������ʱ��������Ԫ��0,���Բ�����������ж�
	//if (max_erea_pro < 0)
		//max_erea_pro = 0;

    return max_erea_pro;
}

/* 
 * ��̬�滮��������
 * ״̬ת�Ʒ��̣�
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
