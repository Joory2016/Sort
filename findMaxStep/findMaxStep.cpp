// findMaxStep.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;



int d[4][2] = { {0,-1}, {0,1}, {1,0}, {-1,0} };
vector<vector<bool>> visited;
int step = 1;

void getMap(vector<vector<int>>& maps, int N, int M) {
	for (int i = 0; i < N; i++) {
		vector<int> temp;
		for (int j = 0; j < M; j++) {
			int t;
			cin >> t;
			temp.push_back(t);
		}
		maps.push_back(temp);
	}
}

bool inArea(int N, int M, int x, int y) {
	return x >= 0 && y >= 0 && x < N && y <= M;
}

void findMaxStep(vector<vector<int>>& maps, int N, int M, int x,int y) {
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int newx = x + d[i][0];
		int newy = y + d[i][1];
		if (inArea(N, M, newx, newy) && !visited[newx][newy])
			if (maps[newx][newy] > maps[x][y]) {
				step += 1;
				findMaxStep(maps, N, M, newx, newy);
			}
	}
}


int main()
{
	int N, M, K;
	cin >> N >> M >> K;
	vector<vector<int>> maps;
	getMap(maps, N, M);
	visited = vector<vector<bool>> (N, vector<bool>(M, false));
	findMaxStep(maps, N, M, 0, 0);

	cout << step << endl;
    std::cout << "Hello World!\n"; 
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
