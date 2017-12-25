#include <iostream>

using namespace std;
/* 易错点：
	1，枢纽值和下标一定要区分好！
	2，Partition()返回的是枢纽的下标！
*/

int Partition(int* arr, int low, int high){
	int key = arr[high]; // 1
	int lptr = low;
	int rptr = high;
	while (lptr < rptr){
		while (arr[lptr] <= key && lptr < rptr) ++lptr;
		arr[rptr] = arr[lptr];
		while (arr[rptr] >= key && rptr > lptr) --rptr;
		arr[lptr] = arr[rptr];
	}
	arr[lptr] = key;

	for (int i = 0; i < 8; ++i){
		cout << arr[i] << " ";
	}cout << endl;

	return lptr;  // 2
}

void QuickSort(int* arr, int low, int high){
	if (low < high){
		int idx = Partition(arr, low, high);
		QuickSort(arr, low, idx - 1);
		QuickSort(arr, idx + 1, high);
	}
}

void main081(){
	int arr[8] = { 3, 8, 7, 9, 2, 5, 6, 4 };
	int low = 0;
	int high = 7;
	QuickSort(arr, low, high);

	for (int i = 0; i < 8; ++i){
		cout << arr[i] << " ";
	}cout << endl;

}