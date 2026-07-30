#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int num, toSys;
	cin >> num >> toSys;
	vector<char> aimNum;

	if (num == 0) {
		cout << "0" << endl;
		return 0;
	}

	while (num != 0) {
		int temp = num % toSys;
		temp %= toSys;   // 要的是余数
		char putin;
		if (temp >= 0 && temp <= 9) {
			putin = temp + '0';
		}
		else putin = (temp - 10) + 'A';

		aimNum.push_back(putin);
		num /= toSys;
	}
	reverse(aimNum.begin(), aimNum.end());
	for (int i = 0; i < aimNum.size(); i++) cout << aimNum[i];
	cout << endl;
//	system("pause");
	return 0;
}