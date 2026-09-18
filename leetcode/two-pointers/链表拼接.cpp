// https://leetcode.cn/problems/merge-two-sorted-lists/description/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int> vec;

        while (list1 != NULL) {
            vec.push_back(list1->val);
            list1 = list1->next;
        }

        while (list2 != NULL) {
            vec.push_back(list2->val);
            list2 = list2->next;
        }

        sort(vec.begin(), vec.end());

//      ListNode *head = new ListNode();
        ListNode *tail = new ListNode(0);   // 从tail之后开始进行拼接
        ListNode *head = tail;
        for (auto i = vec.begin(); i != vec.end(); ++i) {
            tail->next = new ListNode(*i);
            tail = tail->next;
        }

        return head->next;
    }
};


int main(void) {
    class Solution s;



    return 0;
}