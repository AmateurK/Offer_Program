#include <iostream>

using namespace std;
/*
	输入一个数N，求它的二进制中的1的个数
	①：每次左移N，做N & 1运算；
	②：每次右移1，做N & new1运算；
	③：每次做 N= N & (N-1)运算，会把最右边的1变成0
*/

int NumberOf1_1(int n){ //不可取
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
//	int cnt1 = NumberOf1_1(number); //负数会陷入无限循环中
//	cout << "1的个数：" << cnt1 << endl;

	int cnt2 = NumberOf1_2(number);
	cout << "1的个数：" << cnt2 << endl;

	int cnt3 = NumberOf1_2(number);
	cout << "1的个数：" << cnt3 << endl;

	cout << endl;
}
