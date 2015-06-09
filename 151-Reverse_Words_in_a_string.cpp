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
 * 1、需要另外开辟一段与s等长string res：从后往前遍历s，逐个单词往res中填充。（已实现在下面）
 * 2、不需要另外开辟与s等长的string空间：先将整个字符串反转，然后将每个单词反转。（有待实现）
 *
 * 另两种思路，使用栈解决：
 * 3、另外开辟一个栈，以字母为单位从尾部开始进栈，一个单词结束之后出栈。这种方法时间复杂度和空间复杂度都没有优势。
 * 4、另外开辟一个栈，从头开始遍历，逐个单词进栈，全部进栈结束之后，再逐个单词出栈。（与第1种方法思想类似）
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

//string.push_back(c),string.insert(pos, c),和vector一样.但是string只有erase,没有pop_back().而且,map.insert(),set.insert()不需要给出位置.
//string.erase三种用法
//s.erase(pos,n); 删除从pos开始的n个字符，比如erase(0,1)就是删除第一个字符
//s.erase(position);删除position处的一个字符(position是个string类型的迭代器)
//s.erase(first,last);删除从first到last之间的字符（first和last都是迭代器）
