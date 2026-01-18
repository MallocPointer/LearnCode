#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student {
private:
	string name;
	int Chinese, Math, English;
	int All;

public:
	Student() {
		Chinese = Math = English = All = 0;
	}

	Student(string name, int Chinese, int Math, int English) {
		this->name = name;
		this->Chinese = Chinese;
		this->Math = Math;
		this->English = English;
		Sum();
	}

	void Sum() {
		All = Chinese + Math + English;
	}

	bool operator>(const Student& other) const {
		return All > other.All;
	}

	void Print() const {
		cout << name << " " << Chinese << " " << Math << " " << English << endl;
	}
};

int main(void) {
	int n;
	cin >> n;

	vector<Student> students;
	students.reserve(n);

	for (int i = 0; i < n; i++) {
		string name;
		int Chinese, Math, English;
		cin >> name >> Chinese >> Math >> English;
		students.push_back(Student(name, Chinese, Math, English));
	}

	Student best = students[0];
	for (int i = 1; i < n; i++) {
		if (students[i] > best) {
			best = students[i];
		}
	}

	best.Print();

//	system("pause");
	return 0;
}
