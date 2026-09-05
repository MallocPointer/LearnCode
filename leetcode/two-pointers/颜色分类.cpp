// https://leetcode.cn/problems/sort-colors/?envType=problem-list-v2&envId=two-pointers

#include <iostream>
#include <vector>

using  namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] == 0) cnt0++;
            if (nums[i] == 1) cnt1++;
            if (nums[i] == 2) cnt2++;
        }

        int idx = 0;
        for (int i = 0; i < cnt0; i++) nums[idx++] = 0;
        for (int i = 0; i < cnt1; i++) nums[idx++] = 1;
        for (int i = 0; i < cnt2; i++) nums[idx++] = 2;
    }
};

int main (void) {



    return 0;
}