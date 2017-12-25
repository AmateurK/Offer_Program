#include <iostream>

using namespace std;
/*
	重写库函数 Power():
	判断base是不是0，不能if(base==0),会有误差。
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

	double sum = base; // double 类型
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
	double result = Power(base, exponent); //注意结果的类型保持一致 double
	cout << base << "^(" << exponent << ") = " << result << endl;

	cout << endl;
}