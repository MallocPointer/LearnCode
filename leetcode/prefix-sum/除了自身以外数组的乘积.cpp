// https://leetcode.cn/problems/product-of-array-except-self/description/?envType=problem-list-v2&envId=prefix-sum

// main中的测试用例依旧都是AI给写的

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    const int MINF = -INT_MAX;
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return vector<int>({1});

        vector<int> pre(n, MINF), last(n, MINF);    // 每个分开的i就是以i为分界线的时候的前后缀积

        pre[0] = 1;
        for (int i = 1; i < n; i++) pre[i] = pre[i - 1] * nums[i - 1];
        // for (int i = 0; i < n; i++) cout << pre[i] << " ";
        last[n- 1] = 1;
        for (int i = n - 2; i>= 0; i--) last[i] = last[i + 1] * nums[i + 1];

        vector<int> ans;
        ans.push_back(last[0]);
        for (int i = 1; i < n - 1; i++) ans.push_back(pre[i] * last[i]);
        ans.push_back(pre[n - 1]);
        return ans;
    }

};

int main(void) {
    Solution s;
    // 测试用例 1
    vector<int> nums1 = {1, 2, 3, 4};
    vector<int> res1 = s.productExceptSelf(nums1);
    cout << "输入: [1,2,3,4]" << endl;
    cout << "输出: [";
    for (size_t i = 0; i < res1.size(); i++) {
        cout << res1[i];
        if (i != res1.size() - 1) cout << ",";
    }
    cout << "]" << endl << endl;
    // 测试用例 2
    vector<int> nums2 = {-1, 1, 0, -3, 3};
    vector<int> res2 = s.productExceptSelf(nums2);
    cout << "输入: [-1,1,0,-3,3]" << endl;
    cout << "输出: [";
    for (size_t i = 0; i < res2.size(); i++) {
        cout << res2[i];
        if (i != res2.size() - 1) cout << ",";
    }
    cout << "]" << endl << endl;
    // 测试用例 3：最小长度
    vector<int> nums3 = {2, 3};
    vector<int> res3 = s.productExceptSelf(nums3);
    cout << "输入: [2,3]" << endl;
    cout << "输出: [";
    for (size_t i = 0; i < res3.size(); i++) {
        cout << res3[i];
        if (i != res3.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    return 0;
}