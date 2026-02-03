#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	string str;
	cin >> str;

	stack<char> data;
	// 倒序压栈 实现左到右处理
	for (int i = (int)str.size() - 1; i >= 0; --i) {
		data.push(str[i]);
	}

	stack<long long> st; // 存操作数

	do {
		if (data.empty()) break;

		// 若当前是数字，就一直读到 .
		if (data.top() >= '0' && data.top() <= '9') {
			long long num = 0;
			while (!data.empty() && data.top() != '.') {
				num = num * 10 + (data.top() - '0');
				data.pop();
			}
			// 弹出 .
			if (!data.empty() && data.top() == '.') data.pop();
			st.push(num);
		}
		else {
			char op = data.top();
			data.pop();

			if (op == '@') break;

			// 后缀表达式遇到运算符就弹出两个数
			long long b = st.top(); st.pop();
			long long a = st.top(); st.pop();

			if (op == '+') st.push(a + b);
			else if (op == '-') st.push(a - b);
			else if (op == '*') st.push(a * b);
			else if (op == '/') st.push(a / b);
		}
	} while (!data.empty());

	cout << st.top();

//	system("pause");
	return 0;
}
