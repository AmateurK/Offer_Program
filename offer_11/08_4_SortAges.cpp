#include <iostream>

using namespace std;

void SortAges(int* arr, int len){
	if (arr == NULL || len <= 0)
		return;

	const int maxAge = 99;
	int timesAge[maxAge + 1] = {0};

	for (int i = 0; i < len; ++i){
		if (arr[i] > 99 || arr[i] < 0)
			throw exception("invalid ages£¡");
		else
			++timesAge[arr[i]];
	}

	int idx = 0;
	for (int i = 0; i < maxAge; ++i){
		for (int j = 0; j < timesAge[i]; ++j){
			arr[idx] = i;
			++idx;
		}
	}
}

void main084(){
	int arr[10] = { 30, 35, 42, 51, 44, 30, 42, 34, 60, 30 };
	int len = 10;

	for (int i = 0; i < len; ++i)
		cout << arr[i] << " ";
	cout << endl;

	SortAges(arr, len);
	for (int i = 0; i < len; ++i)
		cout << arr[i] << " ";
	cout << endl;
}