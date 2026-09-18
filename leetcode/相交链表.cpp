// https://leetcode.cn/problems/intersection-of-two-linked-lists/submissions/750066275/?envType=problem-list-v2&envId=two-pointers


// 我或许可以开一个hash/set存地址，发现此地址被访问两次，则再遍历一次，就能得到答案， 但是本次仅击败16.38%的人，或许可以找找有优化
// 瓶颈就在 unordered_set 的常数：每次 insert/find 都要算哈希、找桶、可能 rehash 扩容、堆分配
// 所以，不优化了，时间复杂度已经O(m + n)理论最小值 我直接git push
// 对了 main函数里的测试样例是让AI给写的

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* ret(ListNode* cur, unordered_set<ListNode*> &visited) {
        // 找不到就返回节点，准备插入，能找到就返回NULL
        if (visited.find(cur) == visited.end()) return cur;
        return NULL;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> visited;
        ListNode *cur = headA;
        bool flag = false;
        ListNode *target = NULL;

        // 第一次遍历 直接把A中的所有节点地址全加入set
        while (cur != NULL) {
            visited.insert(cur);
            cur = cur->next;
        }



        cur = headB;   // 第一次修改的地方，把*去掉了，需要地址的赋值，而不是数据
        while (cur != NULL) {
//            ListNode *temp = cur;
            if (ret(cur, visited) == NULL) {   // 说明已经被访问过
//                visited.insert(cur);
                target = cur;
                flag = true;
                break;
            }
            cur = cur->next;
        }

        if (flag) return target;
        return NULL;
    }
};


int main(void) {
    Solution sol;
    // 示例1：有交点，期望 8
    ListNode *c1 = new ListNode(8);
    ListNode *c2 = new ListNode(4);
    ListNode *c3 = new ListNode(5);
    c1->next = c2;
    c2->next = c3;
    ListNode *a1 = new ListNode(4);
    ListNode *a2 = new ListNode(1);
    a1->next = a2;
    a2->next = c1;
    ListNode *b1 = new ListNode(5);
    ListNode *b2 = new ListNode(6);
    ListNode *b3 = new ListNode(1);
    b1->next = b2;
    b2->next = b3;
    b3->next = c1;
    ListNode *res = sol.getIntersectionNode(a1, b1);
    cout << "示例1(期望8): ";
    if (res != NULL) cout << res->val << endl;
    else             cout << "NULL" << endl;
    // 示例3：无交点，期望 NULL
    ListNode *d1 = new ListNode(2);
    ListNode *d2 = new ListNode(6);
    ListNode *d3 = new ListNode(4);
    d1->next = d2;
    d2->next = d3;
    ListNode *e1 = new ListNode(1);
    ListNode *e2 = new ListNode(5);
    e1->next = e2;
    res = sol.getIntersectionNode(d1, e1);
    cout << "示例3(期望NULL): ";
    if (res != NULL) cout << res->val << endl;
    else             cout << "NULL" << endl;
    return 0;
}