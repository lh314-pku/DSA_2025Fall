#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

int op_level(char op) {
	// 一级运算
	if (op == '+' || op == '-') {
		return 1;
	}
	// 二级运算（优先）
	else if (op == '*' || op == '/') {
		return 2;
	}
	// 其他
	else {
		return 0;
	}
}

int op_num(int a, int b, char op) {
	switch (op) {
	case '+': return a + b;
	case '-': return a - b;
	case '*': return a * b;
	case '/': return a / b;
	default: return 0;
	}
}
// 处理整数运算

int compute(const string& expression) {
	stack<int> values; // 运算数
	stack<char> ops;   // 操作符
	int length = expression.size();
	for (size_t i = 0; i < length; i++) {
		// 数字
		if ('0' <= expression[i] && expression[i] <= '9') {
			int val = 0;
			// 不断后移累加到一起
			while (i < length && '0' <= expression[i] && expression[i] <= '9') {
				val = val * 10 + (expression[i] - '0');
				i++;
			}
			values.push(val);
			// 回退
			i--;
		}
		// 左括号
		else if (expression[i] == '(') {
			ops.push(expression[i]);
		}
		// 右括号
		else if (expression[i] == ')') {
			while (!ops.empty() && ops.top() != '(') {
				int val2 = values.top();
				values.pop();
				int val1 = values.top();
				values.pop();
				char op = ops.top();
				ops.pop();

				values.push(op_num(val1, val2, op));
			}
			// 弹出左括号
			if (!ops.empty()) 
				ops.pop();
		}
		// 操作符
		else {
			while (!ops.empty() && op_level(ops.top()) >= op_level(expression[i])) {
				int val2 = values.top();
				values.pop();
				int val1 = values.top();
				values.pop();
				char op = ops.top();
				ops.pop();

				values.push(op_num(val1, val2, op));
			}
			ops.push(expression[i]);
		}
	}
	// 处理剩余运算符
	while (!ops.empty()) {
		int val2 = values.top();
		values.pop();
		int val1 = values.top();
		values.pop();
		char op = ops.top();
		ops.pop();
		values.push(op_num(val1, val2, op));
	}

	return values.top();
}

int main() {
	int n = 0;
	cin >> n;
	while (n--) {
		string expression;
		cin >> expression;
		cout << compute(expression) << endl;
	}
	return 0;
}