/*
 * Problem 38:	Count and Say 
 *
 * The count-and-say sequence is the sequence of integers beginning as follows:
 * 1, 11, 21, 1211, 111221, ...

 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * Given an integer n, generate the nth sequence.
 *
 * Note: The sequence of integers will be represented as a string.
 */

/* 
 * Notice:
 * 5 corresponds to 111221.
 * 6 Corresponds to 312211, not 21112211.
 * This problem's description is not clear about this.
 */

//Solution
class Solution {
public:
    string countAndSay(int n) {
		string before_count = "1";
		string after_count = "1";
		int i = 0, j = 0;
		
		// next number can only be calaculated based on the current number
		for (i = 1; i < n; i++) {
			int len = 0;
			len = before_count.length();
			after_count = "";
			for (j = 0; j < len; j++) {
				int count = 1;
				char tmp[3];
				while (j + 1 < len && before_count[j] == before_count[j + 1]) {
					j++;
					count++;
					if (count == 10) //never appear or not
						return "ERROR: count is 10";

				}
				tmp[0] = count + '0';
				tmp[1] = before_count[j];
				tmp[2] = '\0';
				after_count = after_count + tmp;
			}
			before_count = after_count;
		}
		return after_count;
	}
};

/*
 * 有待改进之处，string s可以直接使用:
 * s.push_back(ch)，将ch追加到string的尾部；
 * s.size()与s.length()更好，因为在vector之类的容器中也可以使用size();
 */
