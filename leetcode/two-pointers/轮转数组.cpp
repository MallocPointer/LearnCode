// https://leetcode.cn/problems/rotate-array/submissions/750483736/?envType=problem-list-v2&envId=two-pointers

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> res = nums;
        int n = nums.size();
        for (int i = 0; i < n; i++) res.push_back(res[i]);
        int go = n - k % n;
        for (int i = 0; i < n; i++) nums[i] = res[go + i];
    }
};

int main(void) {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Solution s;
    s.rotate(nums, 3);

    for (int x : nums) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}