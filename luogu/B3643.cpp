#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void doList(int v1, int v2, vector<vector<int>> &adjList) {
	adjList[v1].push_back(v2);
	adjList[v2].push_back(v1);
}

void doMat(int v1, int v2, vector<vector<int>> &adjMat) {
	adjMat[v1][v2] = 1;
	adjMat[v2][v1] = 1;
}

void coutList(vector<vector<int>> &adjList) {
	for (int i = 0; i < adjList.size(); i++) {
		cout << adjList[i].size();
		for (auto x : adjList[i])
			cout << " " << x + 1;
		cout << '\n';	
	}
}

void coutMat(vector<vector<int>> &adjMat) {
	int n = adjMat.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j > 0) cout << " ";
			cout << adjMat[i][j];
		}
		cout << '\n';
	}
}

int main(void) {
	int vertex, edge;
	cin >> vertex >> edge;
	
	// 初始化邻接表以及邻接矩阵
	vector<vector<int>> adjList(vertex);
	vector<vector<int>> adjMat(vertex, vector<int>(vertex, 0));

	while (edge--) {
		int v1, v2;
		cin >> v1 >> v2;

		v1--;
		v2--;

		doList(v1, v2, adjList);
		doMat(v1, v2, adjMat);
	}

	for (int i = 0; i < vertex; i++)
		sort(adjList[i].begin(), adjList[i].end());

	coutMat(adjMat);
	coutList(adjList);

//	system("pause");
	return 0;
}