//最大堆类成员函数的实现

#include <iostream>
#include "MaxHeap.h"
using namespace std;

/*
private:
int size; //最大堆的元素数目
int * array;  //最大堆数组的首地址指针

MaxHeap(int array[], int n); //用已有数组初始化一个最大堆
void buildHeap();   //构建最大堆
void siftDown(int index);  //向下筛选法
void swap(int index1, int index2);  //交换位置为index1与index2的元素
void removeMax();  //删除堆顶的最大值--与数组最后一个元素交换位置并重新构建最大堆
int leftChild(int index);  //返回左孩子的位置
int rightChild(int index);  //返回右孩子的位置
*/

MaxHeap::MaxHeap(int array[], int n){
	this->array = array;
	size = n;
	buildHeap();
}

void MaxHeap::buildHeap(){
	for (int i = size / 2 - 1; i >= 0; --i){
		siftDown(i);
	}
}

void MaxHeap::siftDown(int index){
	int max_ind = leftChild(index);
	while (max_ind < size){
		if (max_ind < size - 1 && array[rightChild(index)] > array[max_ind])
			max_ind++;
		if (array[index] > array[max_ind])
			break;
		swap(index, max_ind);
		index = max_ind;
		max_ind = leftChild(index);
	}
}

void MaxHeap::swap(int index1, int index2){
	int tmp = array[index1];
	array[index1] = array[index2];
	array[index2] = tmp;
}

void MaxHeap::removeMax(){
	swap(0, size - 1);
	size--;
	siftDown(0);
}

int MaxHeap::leftChild(int index){
	return index * 2 + 1;
}

int MaxHeap::rightChild(int index){
	return index * 2 + 2;
}