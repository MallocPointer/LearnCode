// https://leetcode.cn/problems/course-schedule/description/?envType=problem-list-v2&envId=topological-sort

// 测试用例依旧AI

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inEdge(numCourses, 0);
        int n = prerequisites.size();
        for  (int i = 0; i < n ; i++) inEdge[prerequisites[i][0]]++;   // 最后inEdge对应是0的就可以作为拓扑起点
        queue<int> que;

        vector<bool> visited(numCourses, false);

        for (int i = 0; i < numCourses; i++) if (inEdge[i] == 0) que.push(i);

        while (!que.empty()) {
            int node = que.front();
            que.pop();

            // 这里第一次错了，因为需要入度变为0的时候才能入队，否则会发生重复入队问题
            // for (int i = 0; i < n; i++) if (prerequisites[i][1] == node) que.push(prerequisites[node][0]);
            for (int i = 0; i < n; i++) {
                if (prerequisites[i][1] == node) {
                    int next = prerequisites[i][0];
                    if (--inEdge[next] == 0) que.push(next);   // 当发现此节点的入度为0了，才加入队列
                }
            }

            visited[node] = true;
        }

        for (int i = 0; i < numCourses; i++) if (!visited[i]) return false;
        return true;
    }
};

int main (void) {
    Solution s;
    // 示例 1：numCourses = 2, prerequisites = [[1,0]] -> true
    {
        int numCourses = 2;
        vector<vector<int>> prerequisites = {{1, 0}};
        cout << "示例1: " << (s.canFinish(numCourses, prerequisites) ? "true" : "false") << endl;
    }
    // 示例 2：numCourses = 2, prerequisites = [[1,0],[0,1]] -> false
    {
        int numCourses = 2;
        vector<vector<int>> prerequisites = {{1, 0}, {0, 1}};
        cout << "示例2: " << (s.canFinish(numCourses, prerequisites) ? "true" : "false") << endl;
    }
    // 附加：无先修课程 -> true
    {
        int numCourses = 3;
        vector<vector<int>> prerequisites = {};
        cout << "无先修: " << (s.canFinish(numCourses, prerequisites) ? "true" : "false") << endl;
    }
    // 附加：链式先修 3->2->1->0 -> true
    {
        int numCourses = 4;
        vector<vector<int>> prerequisites = {{1, 0}, {2, 1}, {3, 2}};
        cout << "链式: " << (s.canFinish(numCourses, prerequisites) ? "true" : "false") << endl;
    }
    return 0;
}