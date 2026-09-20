// https://leetcode.cn/problems/compare-version-numbers/submissions/750448492/?envType=problem-list-v2&envId=two-pointers

#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> preprocess(const string& input) {
        vector<string> res;
        int slow = 0;
        int n = static_cast<int>(input.size());

        for (int fast = 0; fast <= n; ++fast) {
            if (fast == n || input[fast] == '.') {
                res.push_back(input.substr(slow, fast - slow));
                slow = fast + 1;
            }
        }

        return res;
    }

    int compareVersion(string version1, string version2) {
        vector<string> v1 = preprocess(version1);
        vector<string> v2 = preprocess(version2);

        size_t count = max(v1.size(), v2.size());

        for (size_t i = 0; i < count; ++i) {
            int a = i < v1.size() ? stoi(v1[i]) : 0;
            int b = i < v2.size() ? stoi(v2[i]) : 0;

            if (a < b) return -1;
            if (a > b) return 1;
        }

        return 0;
    }
};

int main (void) {



    return 0;
}