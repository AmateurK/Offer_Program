#include <iostream>

using namespace std;
/*
	高效的斐波那契的循环式解法
	递归式缺点：层数太多会溢出，计算重复，效率低
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
	cout << "循环：" << num1 << endl;

	int num2 = FiboInRecusively(N);	
	cout << "递归：" << num2 << endl;

	cout << endl;
}