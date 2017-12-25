//为一个类写赋值运算符函数

#include <iostream>
#include <cstring>
using namespace std;


class CMyString
{
public:
	//CMyString(char* pData = nullptr);
	CMyString(const CMyString& str);
	~CMyString();

	CMyString& operator = (const CMyString& str);

	void Print();

private:
	char* m_pData;
};

//CMyString::CMyString(char* pData = nullptr){
//	if (pData == nullptr){
//		m_pData = new char[1];
//		m_pData[0] = '\0';
//	}
//	else{
//		m_pData = new char(strlen(pData) + 1);
//		strcpy(m_pData, pData);
//	}
//}

CMyString::CMyString(const CMyString& str){//把str赋值给当前对象
	m_pData = new char(strlen(str.m_pData) + 1);
	strcpy(m_pData, str.m_pData);
}

CMyString::~CMyString(){
	delete[] m_pData;
}

CMyString& CMyString::operator= (const CMyString& str){
	/*
	*	先判断被赋值的对象，二者是否已经相同
		不相同的话先释放当前存储空间，再令其为空
		然后将重新开辟str对象大小的空间，把str内容复制过去
	*/
	if (this == &str){ 
		return *this;
	}
	delete[] m_pData;
	m_pData = nullptr;

	m_pData = new char(strlen(str.m_pData) + 1);
	strcpy(m_pData, str.m_pData);
	return *this;
}


void main01(){

}