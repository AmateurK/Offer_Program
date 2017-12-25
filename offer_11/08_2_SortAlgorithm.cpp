/* 几种典型的排序算法
*/

#include <iostream>
#include "MaxHeap.h"

using namespace std;

//快速排序
void quicksort(int a[], int low, int high){
	if (low >= high){
		return;
	}
	int first = low;
	int last = high;
	int key = a[low];
	while (first < last){
		while (first < last && a[last] >= key)	--last;
		a[first] = a[last];
		while (first < last && a[first] <= key)	++first;
		a[last] = a[first];
	}
	a[first] = key;
	quicksort(a, low, first - 1);
	quicksort(a, last + 1, high);
}

void quicksort1(int a[], int low, int high){
	if (low >= high){
		return;
	}
	int first = low;
	int last = high;
	int key = a[low];
	while (first < last){
		while (first < last && a[last] >= key)	--last;
		while (first < last && a[first] <= key)	++first;
		if (first < last){
			int tmp = a[first];
			a[first] = a[last];
			a[last] = tmp;
		}
	}
	a[low] = a[first];
	a[first] = key;
	quicksort1(a, low, first - 1);
	quicksort1(a, last + 1, high);
}

//冒泡排序
void bubblesort(int a[], int len){
	int flag = 1;
	for (int i = 0; i < len && flag == 1; ++i){
		flag = 0;
		for (int j = 0; j < len - i - 1; ++j){
			if (a[j] > a[j + 1]){
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
			flag = 1; //如果某一趟中没有发生交换，则不进行下次遍历
		}
	}
}

//选择排序
void selectsort(int a[], int len){
	for (int i = 0; i < len; ++i){
		int min = i;
		for (int j = i; j < len; ++j){
			if (a[min] > a[j]){
				min = j;
			}
		}
		if (min != i){
			int sign = a[min];
			a[min] = a[i];
			a[i] = sign;
		}
	}
}

//插入排序
void insectsort(int a[], int len){
	for (int i = 1; i < len; ++i){
		int tmp = a[i];
		int j = i - 1;
		while (j > -1 & a[j] > tmp){
			a[j + 1] = a[j];
			--j;
		}
		a[j + 1] = tmp;
	}
}

//归并排序
void merge(int a[], int b[], int low, int high, int mid){
	int i;
	int dx1 = low;
	int dx2 = mid + 1;
	for (i = low; (dx1 <= mid) && (dx2 <= high); ++i){
		if (a[dx1] < a[dx2]){
			b[i] = a[dx1++];
		}
		else{
			b[i] = a[dx2++];
		}
	}
	while (dx1 <= mid){
		b[i++] = a[dx1++];
	}
	while (dx2 <= high){
		b[i++] = a[dx2++];
	}
	for (int k = low; k <= high; ++k){
		a[k] = b[k];
	}
}
void mergesort(int a[], int b[], int low, int high){
	if (low < high){
		int mid = (low + high) / 2;
		mergesort(a, b, low, mid);
		mergesort(a, b, mid + 1, high);
		merge(a, b, low, high, mid);
	}
}

// 堆排序 Heap Sort
void heapsort(int a[], int len){
	MaxHeap maxh = MaxHeap(a, len);
	for (int i = 0; i < len - 1; ++i){
		maxh.removeMax();
	}
}

void main082(){

	int a[8] = { 34, 8, 6, 41, 80, 52, 41, 8 };
	int b[8];
	int low = 0, high = 7;
	int len = sizeof(a) / sizeof(a[0]);

	for (int i = 0; i < len; ++i){
		cout << a[i] << " ";
	}cout << "\n\n";


	//quicksort(a, 0, len-1);	
	//selectsort(a, len);
	//bubblesort(a, len);
	//insectsort(a, len);
	//mergesort(a, b, low, high); //易错
	heapsort(a, len);

	for (int i = 0; i < len; ++i){
		cout << a[i] << " ";
	}

	cout << "\n\n\n";
}