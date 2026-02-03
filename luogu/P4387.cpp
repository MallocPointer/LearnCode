//https://www.luogu.com.cn/record/260714572

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(void) {
	int times;   // 询问次数
	cin >> times;

	for (int i = 0; i < times; i++) {
		int n;
		cin >> n;
		vector<int> pushed(n);
		vector<int> poped(n);

		for (int j = 0; j < n; j++) cin >> pushed[j];
		for (int j = 0; j < n; j++) cin >> poped[j];

		stack<int> st;
		int l = 0;
		for (int k = 0; k < n; k++) {
			st.push(pushed[k]);
			while (!st.empty() && l < n && st.top() == poped[l]) {
				st.pop();
				l++;
			}
		}
		if (l == n && st.empty()) {
			cout << "Yes" << endl;
		}
		else cout << "No" << endl;
	}


//	system("pause");
	return 0;
}