/* 
 * Problem 150:	Evaluate Reverse Polish Notation 
 * Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 *
 * Valid operators are +, -, *, /. Each operand may be an integer or another expression.
 *
 * Some examples:
 * ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
 * ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 */

/* 
 * ʹ��ջ���������˼·��
 * ����������ѹջ��
 * �����������ջ�ж�����������ȡ�����㣬���ѹջ��
 */

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> s_num;
		int res = 0;
		stringstream ss;
		int len = tokens.size();
		for (int i = 0; i < len; i++) {
			if (tokens[i].compare("+") && tokens[i].compare("-") &&
				tokens[i].compare("*") && tokens[i].compare("/")) {
				s_num.push(tokens[i]);
			} else {
				string tmp;
				int left_num, right_num;
				//string => int
				ss.clear();
				ss.str("");
				ss << s_num.top();
				s_num.pop();
				ss >> right_num;

				//string => int
				ss.clear();
				ss.str("");
				ss << s_num.top();
				s_num.pop();
				ss >> left_num;
				
				if (!tokens[i].compare("*")) {
					res = left_num * right_num;
				} else if (!tokens[i].compare("/")) {
					res = left_num / right_num;
				} else if (!tokens[i].compare("+")) {
					res = left_num + right_num;
				} else if (!tokens[i].compare("-")) {
					res = left_num - right_num;
				} else {
					cout << "error" << endl;
				}
				//int => string
				ss.clear();
				ss.str("");
				ss << res;
				tmp = ss.str();
				s_num.push(tmp);
			}
		}
		//string => int
		ss.clear();
		ss.str("");
		ss << (s_num.top());
		ss >> res;
		return res;
    }
};

/*
 * string�÷���tokens[i].compare("*")���Ա�tokens[i]��"*",��ͬ����0����ͬ����1��
 * stringstream�÷���
 * ʹ����Ҫ����ͷ�ļ�<sstream>
 * ����һ��stringstream����ss������ʹ��֮ǰ��Ҫִ��ss.clear(); ss.str("");
 * ע��stringת��Ϊint��intת��Ϊstring���÷���
 */
/*
 * stringת����int��������ʹ��stoi���ɣ���ͷ�ļ�<string>�У���
 */
/*
 * switch .. case�﷨�У�case�����ǳ�����
 */
