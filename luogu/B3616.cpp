#include <iostream>
#include <queue>
using namespace std;

int main(void) {
	int n;   // n组数据
	cin >> n;

	queue<int> q;

	while (n--) {
		int op;
		cin >> op;

		switch(op) {
		case 1:
			int num;
			cin >> num;
			q.push(num);
			break;
		case 2:
			if (q.empty()) {
				cout << "ERR_CANNOT_POP" << endl;
			}
			else {
				q.pop();
			}
			break;
		case 3:
			if (q.empty()) {
				cout << "ERR_CANNOT_QUERY" << endl;
			}
			else cout << q.front() << endl;
			break;
		case 4:
			cout << q.size() << endl;
			break;
		default:
			break;
		}
	}


//	system("pause");
	return 0;
}