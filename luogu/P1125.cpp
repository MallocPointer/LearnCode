#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isPrime(int x)
{
	if (x < 2) return false;
	for (int i = 2; i * i <= x; i++)
	{
		if (x % i == 0) return false;
	}
	return true;
}

int main()
{
	string s;
	cin >> s;

	vector<int> cnt(26, 0);

	//统计字母出现次数
	for (char c : s)
	{
		cnt[c - 'a']++;
	}

	int maxn = 0;
	int minn = 100; //单词长度小于100

	//找最大和最小 但最小要跳过0次的
	for (int i = 0; i < 26; i++)
	{
		if (cnt[i] > 0)
		{
			if (cnt[i] > maxn) maxn = cnt[i];
			if (cnt[i] < minn) minn = cnt[i];
		}
	}

	int diff = maxn - minn;

	if (isPrime(diff))
	{
		cout << "Lucky Word" << endl;
		cout << diff << endl;
	}
	else
	{
		cout << "No Answer" << endl;
		cout << 0 << endl;
	}
	
//	system("pause");
	return 0;
}
