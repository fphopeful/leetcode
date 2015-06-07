/* 
 * Problem 151:	Reverse Words in a String
 * Given an input string, reverse the string word by word.
 *
 * For example,
 * Given s = "the sky is blue",
 * return "blue is sky the".
 *
 * Update (2015-02-12):
 * For C programmers: Try to solve it in-place in O(1) space.
 */

/* 
 * 两种思路，使用链表解决：
 * 1、需要另外开辟一段与s等长string res：从后往前遍历s，逐个单词往res中填充。时间复杂度相对较低。（已实现在下面）
 * 2、不需要另外开辟与s等长的string空间：先将整个字符串反转，然后将每个单词反转。时间复杂度稍高。（有待实现）
 *
 * 第三种思路，使用栈解决：
 * 3、另外开辟一个栈，从尾部开始进栈，一个单词结束之后出栈。时间复杂度相对较低，并且开辟的空间比第1种思路空间复杂度低。（有待实现）
 */

class Solution {
public:
    void reverseWords(string &s) {
		string res = "";
		int len = s.size();
		int i, j;
		int front, behind;

		//避免旧串尾部空格
		i = len - 1;
		while (s[i] == ' ')
			i--;

		behind = i;
        for ( ; i >= 0; i--) {
            if (s[i] == ' ') {
                front = i + 1;
                for (j = front; j <= behind; j++)
                    	res.push_back(s[j]);
				//避免旧串中间连续空格
                while (i != 0 && s[i - 1] == ' ')
					i--;
				//避免旧串头部空格
			    if (i != 0)
			        res.push_back(' ');
			    behind = i - 1;
            }
        }

		//处理最后一个单词
		if (s[i + 1] != ' ') {
			front = i + 1;
			for (j = front; j <= behind; j++)
				res.push_back(s[j]);
		}
		s = res;
    }
};
