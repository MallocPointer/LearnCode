// https://leetcode.cn/problems/remove-duplicates-from-sorted-array-ii/description/?envType=problem-list-v2&envId=two-pointers

/* 2026.9.5我手感不错啊，都是一发就过
 *本题第一次过，但是第一次模拟测试的时候错了
 *发现原因是不知道vector::erase的返回值是下一个有效元素的位置，又因为erase销毁迭代器导致无法下一个判断  这次记住了就是......
 *修改为it = nums.erase(it);就修复了
 *唯一不足的是时间使用处于后6.48% 我研究研究
 *
 *懂了，由于O(n)的扫描之后，erase每次都要把元素前移，所以最坏情况，时间复杂度是O(n^2)
 *让我换双指针法来写 命名为函数 int removeDuplicates2(vector<int>& nums);吧
 *采取快慢指针，快指针为读指针，慢指针为写指针，发现出现越界cnt > 2时候直接覆盖
 *这次也才前40.23% 还能优化
 *
 *算了不管了，直接git push 我都O(n)了 交！
 */



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int temp = nums[0];
        int cnt = 0;
        for (vector<int>::iterator it = nums.begin(); it != nums.end(); ) {
            if (*it == temp) {
                cnt++;
                if (cnt > 2) {
                    it = nums.erase(it);
                    continue;
                }
            }else {
                temp = *it;
                cnt = 1;
            }
            ++it;
//          if (temp != *it) cnt = 0;
        }
        return nums.size();
    }


    int removeDuplicates2(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;
        int slow = 2;
        for (int fast = 2; fast < n; fast++) {   // 窗口为2 因为题目要求 >2 才需要去掉
            if (nums[fast] != nums[slow - 2]) {
                nums[slow] = nums[fast];
                slow++;
            }

        }
        return slow;
    }

};


int main (void) {



    return 0;
}