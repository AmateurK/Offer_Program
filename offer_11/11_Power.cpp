#include <iostream>

using namespace std;
/*
	��д�⺯�� Power():
	�ж�base�ǲ���0������if(base==0),������
*/

bool Equal(double base, double sign){
	if ((base - sign) > -0.000000001
		&& (base - sign) < 0.000000001)
		return true;
	else
		return false;
}

double Power(double base, int exponent){
	//if (base == 0.0 && exponent == 0)
	//	return 1;
	//else if (base == 0.0)
	//	return 0;

	if (Equal(base, 0.0) && exponent == 0)
		return 1;
	else if (Equal(base, 0.0))
		return 0;

	double sum = base; // double ����
	if (exponent > 0){
		for (int i = 1; i < exponent; ++i)
			sum = sum * base;
	}
	else{
		for (int i = 1; i < -exponent; ++i)
			sum = sum * base;
		sum = 1.0 / sum;
	}
	return sum;
}

void main11(){
	double base = 0.000000000006;
	int exponent = -9;
	double result = Power(base, exponent); //ע���������ͱ���һ�� double
	cout << base << "^(" << exponent << ") = " << result << endl;

	cout << endl;
}