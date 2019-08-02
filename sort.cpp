#include <iostream>
#include <vector>

using namespace std;

//插入排序
//时间复杂度o(n^2)
//空间复杂度o(1)
void insertion_sort(int a[], int len)
{
	for (int j = 1; j < len; ++j)
	{
		int key = a[j];
		int i = j - 1;
		while (i >= 0 && a[i] > key)
		{
			a[i + 1] = a[i];//往后挪
			--i;
		}
		a[i + 1] = key;
	}
}

//选择排序
//时间复杂度o(n^2)
//空间复杂度o(1)
void selection_sort(int a[], int len)
{
	for (int i = 0; i < len - 1; ++i)
	{
		for (int j = i + 1; j < len; ++j)
		{
			if (a[j] < a[i])
				swap(a[i], a[j]);
		}
	}
}

//冒泡排序
//时间复杂度o(n^2)
//空间复杂度o(1)
void bubble_sort(int a[], int len)
{
	for (int i = 0; i < len; ++i)
	{
		for (int j = 0; j < len - 1; ++j)
		{
			if (a[j] > a[j + 1])
				swap(a[j + 1], a[j]);
		}
	}
}

//快速排序
//low和high应该是下标，high不是总个数
void quick_sort(int a[], int low, int high)
{
	if (low >= high) return;
	int left = low;
	int right = high + 1;
	int temp = a[low];
	while (true)
	{
		while (a[++left] < temp)//从左往右找比temp大的
			if (left == high)
				break;

		while (a[--right] > temp)//从右往左找比temp小的
			if (right == low)
				break;

		if (left >= right)
			break;

		swap(a[left], a[right]);//交换left和right对应的值
	}

	swap(a[low], a[right]);//交换基准和找到当前中间的值
	quick_sort(a, low, right - 1);
	quick_sort(a, right + 1, high);
}


int main()
{
	int a[10] = { 57, 68, 59, 52, 72, 28, 96, 33, 24, 57};
	vector<int> vec(begin(a),end(a));

	//myqsort(a, 0, sizeof(a) / sizeof(a[0]) - 1);//high是下标，不是个数
	bubble_sort(a, 10);

	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		cout << a[i] << "	";
	}
	cout << endl;
	return 0;
}
