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
 * 使用栈解决，解题思路：
 * 遇到数字则压栈；
 * 遇到运算符则将栈中顶层两个数字取出运算，结果压栈。
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
 * string用法：tokens[i].compare("*")，对比tokens[i]与"*",相同返回0，不同返回1；
 * stringstream用法：
 * 使用需要包含头文件<sstream>
 * 复用一个stringstream对象ss，则在使用之前需要执行ss.clear(); ss.str("");
 * 注意string转换为int，int转换为string的用法。
 */
/*
 * string转换到int，还可以使用stoi即可（在头文件<string>中）。
 */
/*
 * switch .. case语法中，case必须是常量。
 */
