#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int main() {
	stack<char> st;
	vector<char> comp;
	string s;

	cin >> s;

	for (char ch : s) {
		if (ch == '@') break;
		comp.push_back(ch);
	}

	for (char ch : comp) { 
		if (ch == '(') {
			st.push(ch);
		}
		else if (ch == ')') {
			if (st.empty()) {
				cout << "NO" << endl;
				return 0;
			}
			st.pop();
		}
	}

	if (st.empty())
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

//	system("pause");
	return 0;
}
