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
 * ����˼·��ʹ����������
 * 1����Ҫ���⿪��һ����s�ȳ�string res���Ӻ���ǰ����s�����������res����䡣ʱ�临�Ӷ���Խϵ͡�����ʵ�������棩
 * 2������Ҫ���⿪����s�ȳ���string�ռ䣺�Ƚ������ַ�����ת��Ȼ��ÿ�����ʷ�ת��ʱ�临�Ӷ��Ըߡ����д�ʵ�֣�
 *
 * ������˼·��ʹ��ջ�����
 * 3�����⿪��һ��ջ����β����ʼ��ջ��һ�����ʽ���֮���ջ��ʱ�临�Ӷ���Խϵͣ����ҿ��ٵĿռ�ȵ�1��˼·�ռ临�Ӷȵ͡����д�ʵ�֣�
 */

class Solution {
public:
    void reverseWords(string &s) {
		string res = "";
		int len = s.size();
		int i, j;
		int front, behind;

		//����ɴ�β���ո�
		i = len - 1;
		while (s[i] == ' ')
			i--;

		behind = i;
        for ( ; i >= 0; i--) {
            if (s[i] == ' ') {
                front = i + 1;
                for (j = front; j <= behind; j++)
                    	res.push_back(s[j]);
				//����ɴ��м������ո�
                while (i != 0 && s[i - 1] == ' ')
					i--;
				//����ɴ�ͷ���ո�
			    if (i != 0)
			        res.push_back(' ');
			    behind = i - 1;
            }
        }

		//�������һ������
		if (s[i + 1] != ' ') {
			front = i + 1;
			for (j = front; j <= behind; j++)
				res.push_back(s[j]);
		}
		s = res;
    }
};
