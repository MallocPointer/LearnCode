// https://www.luogu.com.cn/problem/P3879
// 必须第14行用ignore吃掉换行符 否则会干扰21行的getline

#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace  std;

int main(void) {
	int number;
	cin >> number;
	cin.ignore();

	vector<string> article;   // 用于储存句子
	vector<set<string>> word;   // 用于储存所有句子内部的单词

	for (int i = 0; i < number; i++) {
		string now;
		getline(cin, now);   // 若句首有空格也读入
		article.push_back(now);
		word.push_back(set<string>());   // 先明确此内容存在
	}

	//单词拆解
	for (int i = 0; i < article.size(); i++) {
		string cur = "";
		for (char c : article[i]) {
			if (isalpha(c)) {   // 判断是不是英文字母
				cur += c;
			}
			else {
				if (!cur.empty()) {
					word[i].insert(cur);
					cur.clear();
				}
			}
		}
		if (!cur.empty()) {
			word[i].insert(cur);
		}
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		string now_str;
		cin >> now_str;

		for (int i = 0; i < article.size(); i++) {
			if (word[i].count(now_str)) {
				cout << i + 1 << " "; 
			}
		}
		cout << "\n";
	}

//	system("pause");
	return 0;
}