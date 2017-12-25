//寻找旋转数组中的最小值

#include <iostream>
#include <exception>

using namespace std;

/** MyCoding 比较麻烦
int minNumber(int *arr, int len){
	if (len <= 0 || arr == NULL)
		throw exception("Array is NULL\n");
	int start = 0;
	int end = len - 1;
	int mid = (start + end) / 2;
	if (arr[mid] > arr[start]){
		int m = mid + 1;
		while (m < end && arr[m] > arr[mid]) ++m;
		return m;
	}
	else if (arr[mid] < arr[start]){
		int m = mid - 1;
		while (m > start && arr[m] < arr[mid]) --m;
		return m + 1;
	}
	else
		throw exception("Array Error\n");
}
*/

int inOrder(int *arr, int p1, int p2){
	int min = p1;
	for (int i = p1 + 1; i <= p2; ++i){
		if (arr[i] < arr[min])
			arr[min] = arr[i];
	}
	return min;
}

int minNumber(int *a, int len){
	if (len <= 0 || a == NULL)
		throw new exception("Array is NULL\n");
 	int p1 = 0;
	int p2 = len - 1;
	int min = 0;
	while (a[p1] >= a[p2]){
		if (p2 - p1 == 1){
			min = p2;
			break;
		}
		int mid = (p1 + p2) / 2;
		//若三个数相同，则只能顺序查找
		if (a[mid] == a[p1] && a[p1] == a[p2])
			return inOrder(a, p1, p2);
		if (a[mid] >= a[p1])
			p1 = mid;
		else if (a[mid] <= a[p2])
			p2 = mid;
	}
	return min;
}

void main08(){
	//const int len = 0;
	//int *arr = NULL;

	const int len = 6;
	int arr[len] = { 1,1,2,0,0,1};

	const int len2 = 5;
	int arr2[len2] = { 1,0,1,1,1}; //特殊

	//const int len = 9;
	//int arr[len] = { 5, 6, 7, 8, 9, 1,2,3,4};

	int ind = minNumber(arr2, len2);
	for (int i = 0; i < len2; ++i)
		cout << arr2[i] << " ";
	cout <<endl<< "The min number: " << arr2[ind] << endl;
	cout << "The index: " << ind + 1 << endl;

}