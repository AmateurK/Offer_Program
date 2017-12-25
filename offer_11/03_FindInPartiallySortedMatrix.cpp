// ��ά�����еĲ���
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
	/* ��Key�����ڣ�����������ѭ�������������ƣ�
	*	��ʱ��Ȼ�������ҵ����½ǵ����������±�����һ��Ϊ0
	*/
	//if (row == LEN - 1 || col == LEN - 1) 
	//	return false;	
}

/*
*  The Best Way
	1�����ȼ���βΣ�ȷ������������������Ч��
	2��������ִ���true��false��������һ������found��¼
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