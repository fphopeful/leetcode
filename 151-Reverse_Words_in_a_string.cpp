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
 * 1����Ҫ���⿪��һ����s�ȳ�string res���Ӻ���ǰ����s�����������res����䡣����ʵ�������棩
 * 2������Ҫ���⿪����s�ȳ���string�ռ䣺�Ƚ������ַ�����ת��Ȼ��ÿ�����ʷ�ת�����д�ʵ�֣�
 *
 * ������˼·��ʹ��ջ�����
 * 3�����⿪��һ��ջ������ĸΪ��λ��β����ʼ��ջ��һ�����ʽ���֮���ջ�����ַ���ʱ�临�ӶȺͿռ临�Ӷȶ�û�����ơ�
 * 4�����⿪��һ��ջ����ͷ��ʼ������������ʽ�ջ��ȫ����ջ����֮����������ʳ�ջ�������1�ַ���˼�����ƣ�
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

//string.push_back(c),string.insert(pos, c),��vectorһ��.����stringֻ��erase,û��pop_back().����,map.insert(),set.insert()����Ҫ����λ��.
//string.erase�����÷�
//s.erase(pos,n); ɾ����pos��ʼ��n���ַ�������erase(0,1)����ɾ����һ���ַ�
//s.erase(position);ɾ��position����һ���ַ�(position�Ǹ�string���͵ĵ�����)
//s.erase(first,last);ɾ����first��last֮����ַ���first��last���ǵ�������
