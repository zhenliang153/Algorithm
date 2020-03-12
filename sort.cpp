#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

//using namespace std;
using std::vector;
using std::swap;

/*
 排序算法——sort algorithm
 插入排序——insertion sort
 折半插入排序——binary insertion sort, http://xlinux.nist.gov/dads/HTML/binaryinsort.html
 希尔排序——shell sort
 选择排序——selection sort
 堆排序——heap sort
 归并排序（或合并排序）——merge sort
 基数排序——radix sort
 外排序——external sort(or external sorting)
*/

//遍历打印
template<typename T>
void printArr(vector<T> &arr)
{
	for(T num: arr)
		std::cout << num << " ";
	std::cout << std::endl;	
}

//打印区间
template<typename T>
void printArr(vector<T> &arr, int begin, int end)
{
	for(int i = begin; i < end; i++)
		std::cout << arr.at(i) << " ";
	std::cout << std::endl;	
}

//冒泡排序
template<typename T>
void bubbleSort(vector<T> &arr, int begin, int end)
{
	for(int i = begin; i < end; i++)
		for(int j = i + 1; j < end; j++)
			if(arr.at(i) > arr.at(j))
				swap(arr.at(i), arr.at(j));
}

//选择排序
template<typename T>
void selectSort(vector<T> &arr, int begin, int end)
{
	for(int i = begin; i < end; i++)
	{
		int indexMin = i;
		for(int j = i + 1; j < end; j++)
			if(arr.at(j) < arr.at(indexMin))
				indexMin = j;
		if(i != indexMin)
			swap(arr.at(i), arr.at(indexMin));
	}
}

//插入排序
template<typename T>
void insertSort(vector<T> &arr, int begin, int end)
{
	for(int i = begin + 1; i < end; i++)
	{
		int j = i - 1, temp = arr.at(i);
		while(true)
		{
			if(temp >= arr.at(j))
			{
				if(arr.at(j + 1) != temp)
					arr.at(j + 1) = temp;
				break;
			}
			arr.at(j + 1) = arr.at(j);
			if(j == begin)
			{
				arr.at(j) = temp;
				break;
			}
			j--;
		}
	}
}

//快速排序
template<typename T>
void quickSort(vector<T> &arr, int begin, int end)
{
	if(begin >= end - 1)
		return;
 
	int lIndex = begin, rIndex = end - 1;
	int index = arr.at(lIndex);	//基准元素

	while(lIndex < rIndex)
	{
		while(lIndex < rIndex)
		{
			if(arr.at(rIndex) < index)
			{
				arr.at(lIndex++) = arr.at(rIndex);
				break;
			}
			rIndex--;
		}

		while(lIndex < rIndex)
		{
			if(arr.at(lIndex) >= index)
			{
				arr.at(rIndex--) = arr.at(lIndex);
				break;
			}
			lIndex++;
		}
	}

	arr.at(lIndex) = index;
	
	printArr(arr);
	quickSort(arr, begin, lIndex);
	quickSort(arr, rIndex + 1, end);
}

//堆排序
template<typename T>
//向下调整
void HeapAdjust(vector<T> &arr, int parent, int len)
{
	int child = parent * 2 + 1;
	while(child < len) {
		if(child + 1 < len && arr.at(child + 1) < arr.at(child)) {
			child++;
		}
		if(arr.at(parent) <= arr.at(child)) {
			return;
		}
		swap(arr.at(parent), arr.at(child));
		parent = child;
		child = parent * 2 + 1;
	}
}
template<typename T>
void heapSort(vector<T> &arr)
{
	int len = arr.size();
	if(len <= 1) {
		return;
	}
	int parent = (len - 1 - 1) >> 1;
	//初始化小根堆
	for(int i = parent; i >= 0; i--) {
		HeapAdjust(arr, i, len);
	}
	//向下调整
	for(int i = len - 1; i >= 0; i--) {
		swap(arr.at(0), arr.at(i));
		HeapAdjust(arr, 0, i);
	}
	std::reverse(arr.begin(), arr.end());
}

//归并排序
template<typename T>
void mergeSort(vector<T> &arr, int begin, int end)
{

}

int main()
{
	const int COUNTS = 10;
	srand((unsigned int)time(NULL));
	vector<int> arr;
#if 0
	for(int i = 0; i < COUNTS; i++)
	       arr.emplace_back(rand() % 100);	
	std::cout << "=====Before bubbleSort=====" << std::endl;
	printArr(arr);
	bubbleSort(arr, 0, arr.size());
	std::cout << "=====After bubbleSort=====" << std::endl;
	printArr(arr);
	arr.clear();
#endif

#if 0
	for(int i = 0; i < COUNTS; i++)
	       arr.emplace_back(rand() % 100);	
	std::cout << "=====Before selectSort=====" << std::endl;
	printArr(arr);
	selectSort(arr, 0, arr.size());
	std::cout << "=====After selectSort=====" << std::endl;
	printArr(arr);
	arr.clear();
#endif

#if 0
	for(int i = 0; i < COUNTS; i++)
	       arr.emplace_back(rand() % 100);	
	std::cout << "=====Before insertSort=====" << std::endl;
	printArr(arr);
	insertSort(arr, 0, arr.size());
	std::cout << "=====After insertSort=====" << std::endl;
	printArr(arr);
	arr.clear();
#endif

#if 0
	for(int i = 0; i < COUNTS; i++)
	       arr.emplace_back(rand() % 100);	
	std::cout << "=====Before quickSort=====" << std::endl;
	printArr(arr);
	quickSort(arr, 0, arr.size());
	std::cout << "=====After quickSort=====" << std::endl;
	printArr(arr);
	arr.clear();
#endif

#if 1
	for(int i = 0; i < COUNTS; i++)
	       arr.emplace_back(rand() % 100);
	std::cout << "=====Before heapSort=====" << std::endl;
	printArr(arr);
	heapSort(arr);
	std::cout << "=====After heapSort=====" << std::endl;
	printArr(arr);
	arr.clear();
#endif

	return 0;
}
