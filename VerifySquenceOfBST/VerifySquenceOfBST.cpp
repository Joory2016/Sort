// VerifySquenceOfBST.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
};

class Solution {
public:
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		vector<vector<int> > res;
		vector<int> path;
		findPath(root, expectNumber, 0, res, path);
		return res;
	}

private:

	void findPath(TreeNode* node, int expectNumber, int currSum, vector<vector<int> >& res, vector<int>& path) {
		currSum += node->val;
		path.push_back(node->val);

		bool isLeaf = (node->left == nullptr) && (node->right == nullptr);
		if (currSum == expectNumber && isLeaf)
			res.push_back(path);

		if (node->left != nullptr)
			findPath(node->left, expectNumber, currSum, res, path);
		if (node->right != nullptr)
			findPath(node->right, expectNumber, currSum, res, path);

		path.pop_back();

	}
};

//class Solution {
//public:
//	bool VerifySquenceOfBST(vector<int> sequence) {
//		int len = sequence.size();
//		if (len == 0)
//			return false;
//		return check(sequence, 0, len);
//	}
//
//
//
//
//private:
//	bool check(vector<int>& s, int l, int r) {
//		if (l >= r)
//			return false;
//		if (r <= 0 || l >= s.size())
//			return false;
//		int root = s[r - 1];
//
//		int i = l;
//		for (; i < r - 1; i++) {
//			if (s[i] > root)
//				break;
//		}
//
//		int j = i;
//		for (; j < r - 1; ++j) {
//			if (s[j] < root)
//				return false;
//		}
//
//		bool left = true;
//		if (i > 0)
//			left = check(s, l, i);
//
//		bool right = true;
//		if (i < r - 1)
//			right = check(s, i, s.size()-1);
//
//		return (left && right);
//	}
//
//};


int main()
{
	try {
		vector<int> se{ 5,7,6,9,11,10,8 };
		bool res = Solution().VerifySquenceOfBST(se);
	}
	catch (exception ex) {
		cout << ex.what() << endl;
	}


    
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
