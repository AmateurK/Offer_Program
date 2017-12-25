//�������Ա������ʵ��

#include <iostream>
#include "MaxHeap.h"
using namespace std;

/*
private:
int size; //���ѵ�Ԫ����Ŀ
int * array;  //����������׵�ַָ��

MaxHeap(int array[], int n); //�����������ʼ��һ������
void buildHeap();   //��������
void siftDown(int index);  //����ɸѡ��
void swap(int index1, int index2);  //����λ��Ϊindex1��index2��Ԫ��
void removeMax();  //ɾ���Ѷ������ֵ--���������һ��Ԫ�ؽ���λ�ò����¹�������
int leftChild(int index);  //�������ӵ�λ��
int rightChild(int index);  //�����Һ��ӵ�λ��
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