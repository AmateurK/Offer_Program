#include <iostream>

using namespace std;
/*
	��Ч��쳲�������ѭ��ʽ�ⷨ
	�ݹ�ʽȱ�㣺����̫�������������ظ���Ч�ʵ�
*/

long long FibonacciInCycle(unsigned n){
	int result[2] = { 0, 1 };
	if (n < 2)
		return result[n];

	long long sum = 0;
	long long a = 0;
	long long b = 1;
	for (unsigned i = 2; i <= n; ++i){
		sum = a + b;
		a = b;
		b = sum;
	}
	return sum;
}

int FiboInRecusively(int n){
	if (n <= 0) return 0;
	if (n == 1) return 1;
	return FiboInRecusively(n - 1) + FiboInRecusively(n - 2);
}

void main09(){
	int N = 40;
	int num1 = FibonacciInCycle(N);
	cout << "ѭ����" << num1 << endl;

	int num2 = FiboInRecusively(N);	
	cout << "�ݹ飺" << num2 << endl;

	cout << endl;
}