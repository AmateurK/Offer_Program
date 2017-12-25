// 二维数组中的查找
/*
	1 2  8  9
	2 4  9 12
	4 7 10 13
	6 8 11 15
*/

#include <iostream>
#define LEN 4
using namespace std;

bool SearchKey(int a[][LEN], int key){

	bool flag = false;
	if (a == NULL)
		return flag;

	int row = 0;
	int col = LEN - 1;
	while (col >= 0 && row < LEN){
		if (a[row][col] == key){
			flag = true;
			break;
		}
		else if (a[row][col] == key)
			++row;
		else{
			while (a[row][col] > key && col >= 0)
				--col;
		}			
	}
	return flag;
	//while (a[row][col] < key && row < LEN){
	//	++row;
	//	sign = 1;
	//}
	//if (a[row][col] == key)
	//	flag = true;
	/* 若Key不存在，则会出现无限循环的情况，如何破？
	*	此时必然会最终找到左下角的数，行列下标总有一个为0
	*/
	//if (row == LEN - 1 || col == LEN - 1) 
	//	return false;	
}

/*
*  The Best Way
	1、首先检查形参，确保传进来的数组是有效的
	2、不会出现大量true或false，而是用一个变量found记录
*/
bool Find(int *matrix, int rows, int cols, int key){
	bool found = false;
	if (matrix != NULL && rows > 0 && cols > 0){
		int r = 0;
		int c = cols - 1;
		while (r < rows - 1 && c >= 0){
			if (matrix[r*c + c] == key){
				found == true;
				break;
			}
			else if (matrix[r*c + c] > key)
				--c;
			else
				++r;
		}
	}
	return found;
}

void main03(){

	int a[LEN][LEN];
	for (int i = 0; i < LEN; ++i)
		for (int j = 0; j < LEN; ++j)
			cin>> a[i][j];	
		
	cout << endl;

	//int a[LEN][LEN] = { { 1, 2, 8, 9 },{ 2, 4, 9, 12 },{ 4, 6, 10, 13 },{6, 8, 11, 15} };

	for (int i = 0; i < LEN; ++i){
		for (int j = 0; j < LEN; ++j)
			cout << a[i][j] << " ";
		cout << endl;
	}

	int key;
	cout << endl << "You want to find: ";
	cin >> key;

	bool flag = SearchKey(a, key);
	cout << flag << endl;


	cout << endl << endl;
}