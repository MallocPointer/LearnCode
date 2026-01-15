//https://www.luogu.com.cn/problem/P1009
//本题multiply和add的参数不同的原因是加法一位一位加，乘法每一位都和全部乘

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//高精度乘法
void multiply(vector<int> &a, int b) {
	int carry = 0;   //进位

	for (int i = 0; i < a.size(); i++) {
		int temp = a[i] * b + carry;
		a[i] = temp % 10;
		carry = temp / 10;
	}

	while (carry) {
		a.push_back(carry % 10);
		carry /= 10;
	}
}

//高精度加法
void add(vector<int> &a, vector<int> &b) {
	int maxSize = max(a.size(), b.size());
	a.resize(maxSize, 0);   //高位补0 便于循环中直接用b.size()比对

	int carry = 0;   //用于进位
	for (int i = 0; i < maxSize; i++) {
		int temp = (i < b.size() ? b[i] : 0) + a[i] + carry;
		a[i] = temp % 10;   //这里如果是保存在b中，则需要适配b.resize(maxSize,0); 
		carry = temp / 10;
	}

	// 每位之间的加法不会存在多出两位及以上的情况 所以可以直接if而不是while
	if (carry) a.push_back(carry);
}



int main(void) {
	int n;
	cin >> n;

	vector<int> fact(1, 1); // fact = 1! 初始为 1
	vector<int> sum(1, 0);  // sum = 0

	for (int i = 1; i <= n; i++) {
		multiply(fact, i); // fact = i!
		add(sum, fact);    // sum += fact
	}

	// 高位在后 需要倒序输出
	for (int i = sum.size() - 1; i >= 0; i--) {
		cout << sum[i];
	}
	cout << endl;

//	system("pause");
	return 0;
}
