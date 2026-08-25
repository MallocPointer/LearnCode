#include <iostream>
#include <vector>
#include <bitset>
#include <string>
#include <algorithm>

using namespace std;
using llong = long long;

/*
 * 按照题目最大值为5（101）来看
 * 分别是
 * 1 001
 * 2 010
 * 3 011
 * 4 100
 * 5 101
 */

string toBinary(llong M) {
    if (M == 0) return "0";
    string s;
    while (M > 0) {
        s += char('0' + M % 2);
        M /= 2;
    }
    reverse(s.begin(), s.end());
    return s;
}


int main() {
    int maxN;
    cin >> maxN;
    string bin = toBinary(maxN - 1);
    int len = bin.length();
    vector<vector<int>> arr(maxN + 1, vector<int>(len));   // 1为基础 0直接丢弃
    for (int i = 1; i <= maxN; i++) {
//      string s = toBinary(i);
        for (int j =len - 1; j >= 0; j--) {
            arr[i][j] = (i >> (len - 1 - j)) & 1;  // 从高位到低位逐位取出
        }
    }
    cout << len << endl;
    for (int i = len - 1; i >= 0; i--) {
//      int cnt = 0;
        vector<int> temp;
        for (int j = 1; j <= maxN; j++) {
            if (arr[j][i] == 1) {
//              cnt++;
                temp.push_back(j);
            }
        }
        cout << temp.size();
        for (int k = 0; k < temp.size(); k++) cout << " " << temp[k];
        cout << endl;
    }


    return 0;
}