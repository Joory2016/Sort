// youxiu.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int nums;
	cin >> nums;
	for (int i = 0; i < nums; i++) {
		string S,T;
		cin >> S >> T;
		string revS;
		int flag = true;
		for (int i = 0; i < S.length(); i++) {
			if (S[i] == '1'&& flag)
				continue;
			else
				flag = false;
			if (!flag) {
				if (S[i] == '1')
					revS += '0';
				else if (S[i] == '0')
					revS += '1';
			}
		}
		while (true) {
			string tempS1 = S;
			string tempS2 = revS;
			tempS1 += revS;
			tempS2 += S;
			if (tempS1 == T) {
				cout << "YES" << endl;
				break;
			}
			if (tempS1.length() > T.length()) {
				cout << "NO" << endl;
				break;
			}
			if (tempS2 == T) {
				cout << "YES" << endl;
				break;
			}
			if (tempS2.length() > T.length()) {
				cout << "NO" << endl;
				break;
			}
		}
	}
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
