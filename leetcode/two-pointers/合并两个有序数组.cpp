// https://leetcode.cn/problems/merge-sorted-array/submissions/747441914/?envType=problem-list-v2&envId=two-pointers

//  虽然我没用双指针.... 但也是O(n + m) 最优了

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        nums1.resize(m);
        nums2.resize(n);
        int new_N = m + n;
        vector<int> res(0);
        int now1 = 0, now2 = 0;
        int cnt = 0;
        while (cnt < new_N) {
            if (now1 < m && (now2 >= n || nums1[now1] <= nums2[now2])) {
                res.push_back(nums1[now1]);
                now1++;
//              cnt++;
            }else {
                res.push_back(nums2[now2]);
                now2++;
//              cnt++;
            }
            cnt++;
        }
        nums1 = res;
    }
};



int main (void) {




    return 0;
}