//Ϊһ����д��ֵ���������

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

CMyString::CMyString(const CMyString& str){//��str��ֵ����ǰ����
	m_pData = new char(strlen(str.m_pData) + 1);
	strcpy(m_pData, str.m_pData);
}

CMyString::~CMyString(){
	delete[] m_pData;
}

CMyString& CMyString::operator= (const CMyString& str){
	/*
	*	���жϱ���ֵ�Ķ��󣬶����Ƿ��Ѿ���ͬ
		����ͬ�Ļ����ͷŵ�ǰ�洢�ռ䣬������Ϊ��
		Ȼ�����¿���str�����С�Ŀռ䣬��str���ݸ��ƹ�ȥ
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