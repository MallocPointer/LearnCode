#include <iostream>
#include <vector>
#include <string>

using namespace std;

class People {
public:
	int dir;        // 0: 向内, 1: 向外
	string name;
	People* prev;
	People* next;

	People(int d, const string& n)
		: dir(d), name(n), prev(nullptr), next(nullptr) {}
};

int main() {
	int n, m;
	cin >> n >> m;

	vector<People*> p(n);
	for (int i = 0; i < n; i++) {
		int d;
		string s;
		cin >> d >> s;
		p[i] = new People(d, s);
	}

	for (int i = 0; i < n; i++) {
		p[i]->next = p[(i + 1) % n];
		p[i]->prev = p[(i - 1 + n) % n];
	}

	People* cur = p[0];

	while (m--) {
		int cmd, step;
		cin >> cmd >> step;

		bool moveNext = (cur->dir ^ cmd);
		step %= n;    //防止出现超多步数导致的TLE
		while (step--) {
			cur = moveNext ? cur->next : cur->prev;
		}
	}

	cout << cur->name << endl;

//	system("pause");
	return 0;
}
