#include <iostream>

using namespace std;
/*
	����һ����N�������Ķ������е�1�ĸ���
	�٣�ÿ������N����N & 1���㣻
	�ڣ�ÿ������1����N & new1���㣻
	�ۣ�ÿ���� N= N & (N-1)���㣬������ұߵ�1���0
*/

int NumberOf1_1(int n){ //����ȡ
	int cnt = 0;
	while (n){
		if (n & 1)
			++cnt;
		n = n >> 1;
	}
	return cnt;
}

int NumberOf1_2(int n){
	int cnt = 0;
	int oper = 1;
	while (oper){
		if (n & oper)
			++cnt;
		oper = oper << 1;
	}
	return cnt;
}

int NumberOf1_3(int n){
	int cnt = 0;
	while (n){
		n = n & (n - 1);
		++cnt;
	}
	return cnt;
}

void main10(){
	int number = -32;
//	int cnt1 = NumberOf1_1(number); //��������������ѭ����
//	cout << "1�ĸ�����" << cnt1 << endl;

	int cnt2 = NumberOf1_2(number);
	cout << "1�ĸ�����" << cnt2 << endl;

	int cnt3 = NumberOf1_2(number);
	cout << "1�ĸ�����" << cnt3 << endl;

	cout << endl;
}
