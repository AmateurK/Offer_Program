//д���������ַ����е�ÿ���ո��滻��20%
// �����ҳ����еĿո�����Ȼ��������ƣ������������ַ�
/* �����ַ����ܻ��޷���ʾ����ҪASCII��ת����%32�ո�*/

#include <iostream>
#include <cstring>
using namespace std;

char* replacestr(char str[]){
	//û��Ҫ�����µ����飬��Ϊstr�㹻��ֱ�Ӻ���Ԫ�ؼ���
	
	if (str == NULL  || strlen(str) == 0)/*ע�⣺���жϴ���Ĳ����Ƿ�գ�*/
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