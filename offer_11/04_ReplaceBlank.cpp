//写函数，将字符串中的每个空格替换成20%
// 首先找出所有的空格数，然后整体后移，最后填充三个字符
/* 特殊字符可能会无法显示，需要ASCII码转换，%32空格*/

#include <iostream>
#include <cstring>
using namespace std;

char* replacestr(char str[]){
	//没必要定义新的数组，因为str足够大，直接后移元素即可
	
	if (str == NULL  || strlen(str) == 0)/*注意：先判断传入的参数是否空！*/
		return NULL;

	int len = strlen(str);
	int count = 0;
	int i = 0;
	while (count < len && i < len){
		if (str[i++] == ' ')
			++count;
	}

	int length = len + count * 2;
	i = len;

	while (i >= 0){
		if (str[i] != ' ')
			str[length--] = str[i];
		else if (str[i] == ' '){
			str[length--] = '0';
			str[length--] = '2';
			str[length--] = '%';
		}
		--i;			
	}
	return str;	
}

void main04(){

	char str[20] = "I am happy";

	for (int i = 0; i < strlen(str); ++i){
		cout << str[i];
	}cout << endl;

	int len = strlen(str);
	char* s1 = replacestr(str);

	for (int i = 0; i < strlen(str); ++i){
		cout << str[i];
	}



	cout << endl;
}