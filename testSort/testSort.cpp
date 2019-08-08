// testSort.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

template <class T>
void swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
vector<T> bubbleSort(vector<T>& nums) {
	int len = nums.size();
	for (int i = 1; i <= len - 1; i++) {
		for (int j = 0; j <= len - 1 - i; j++) {
			if (nums[j] > nums[j + 1])
				::swap(nums[j], nums[j + 1]);
		}
	}
	return nums;
}

template <typename T>
vector<T> selectSort(vector<T>& nums) {
	int len = nums.size();
	int minIndex, temp;
	for (int i = 0; i < len - 1; i++) {
		minIndex = i;
		for (int j = i + 1; j < len; j++) {
			if (nums[j] < nums[minIndex])
				minIndex = j;
		}
		temp = nums[i];
		nums[i] = nums[minIndex];
		nums[minIndex] = temp;
	}
	return nums;
}

template <typename T>
vector<T> insertSort(vector<T>& nums) {
	int len = nums.size();
	for (int i = 1; i < len; i++) {
		for (int j = i; j > 0; j--) {
			if (nums[j - 1] > nums[j])
				::swap<T>(nums[j - 1], nums[j]);
			else
				break;
		}
	}
	return nums;
}



template <class T>
ostream& operator<<(ostream& os, vector<T> nums) {
	for (int i = 0; i < nums.size(); i++)
		os << nums[i] << "  ";
	os << endl;
	return os;
}


int main()
{
	vector<int> nums{ 4, 7, 3, 2, 9, 1, 5, 10, 8 };
	//insertSort(nums);
	//bubbleSort(nums);
	selectSort(nums);

	cout << nums;
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
