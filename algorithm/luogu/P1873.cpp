// https://www.luogu.com.cn/problem/P1873

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using llong = long long;

int main(void) {
	int N, M;
	cin >> N >> M;
	vector<llong> arr;
	arr.resize(N);
	llong sum = 0;
	for (int i = 0; i < N; i++){
		cin >> arr[i];
		sum += arr[i];
	}
		
	sort(arr.begin(), arr.end());

	llong res = 0;
	llong left = 0;   // 锯子最低高度
	llong right = arr.back();   // 锯子最高高度

	while (left <= right) {
		llong mid = (left + right) / 2;

		sum = 0;   // 每次重新计算
		for (int i = 0; i < N; i++) {
			if (arr[i] > mid) {
				sum += arr[i] - mid;
			}
		}

		if (sum >= M) {   // 可以再抬高
			res = mid;
			left = mid + 1;
		}
		else {   // 砍太高了
			right = mid - 1;
		}
	}
	
	cout << res << endl;
//	system("pause");
	return 0;
}