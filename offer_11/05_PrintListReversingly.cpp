//����һ�������ͷ��㣬�����ӡ�ڵ�ֵ
/*  
*	β�巨�½�����ע�⣺
*
* �����²���ڵ�ʱ��ı�ͷָ�룬���Դ���Ĳ���
* Ӧ����ָ���ָ�룬������˺�����pHead��Ȼ�ǿ�ָ�룻

��ָ�����������ݸ�������ʱ��
ֻ�ܱ���ָ��ָ��Ķ���*P���ı��ֵ
���ܱ���ָ�뱾��P���������޸�
����Ҫ�޸�ָ�뱾���ʱ����ʹ��ָ��ָ���ָ����Ϊ������Ҳ���Ǵ�ֵ�봫ַ�Ĳ�����ڡ�
*/
/*
*	�����ӡע�⣺
 1���������޸��������Խ���������
 2���������޸ģ�����ջʵ�ַ�����������ߵݹ�ʵ�֡�
*/
#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

struct ListNode{
	int m_value;
	ListNode* m_next;
};

void addToTail(ListNode **pHead, int key){
	ListNode* pNew = new ListNode();
	pNew->m_value = key;
	pNew->m_next = NULL;

	if (*pHead == NULL)
		*pHead = pNew;

	else{  /*�������룬ͷ���Ӧ�ñ��������*/
		ListNode *pCur = *pHead;
		while (pCur->m_next != NULL)
			pCur = pCur->m_next;

		pCur->m_next = pNew;
	}
}

void removeNode(ListNode **pHead, int value){

	if (*pHead == NULL || pHead == NULL) /*�ٽ������ж�*/
		return;

	ListNode * tmp = *pHead;
	ListNode * pre = tmp;

	while (tmp->m_next != NULL){		
		if (tmp->m_value == value){
			pre->m_next = tmp->m_next;
			ListNode * dnode = tmp;
			delete dnode;
			break; /*tmpָ��Ľڵ��ڴ��Ѿ����ͷţ����жϵĻ�������쳣*/
		}			
		pre = tmp;
		tmp = tmp->m_next;
	}
}

void print_Intertively(ListNode *head){
	if (head == NULL)
		return;

	stack<ListNode*> nodes;
	ListNode *tmp = head;
	while (tmp != NULL){
		nodes.push(tmp);
		tmp = tmp->m_next;
	}
	while (!nodes.empty()){
		ListNode *curr = nodes.top(); /*�õ�ջ��Ԫ��*/
		cout << curr->m_value << " "; 
		nodes.pop(); /*��ջ����վ*/
	}cout << endl;
}

void print_Recursively(ListNode *head){

	if (head != NULL){
		if (head->m_next != NULL)
			print_Recursively(head->m_next);
		cout << head->m_value << " ";
	}	
}

void main05(){

	ListNode *head = NULL;
	for (int i = 0; i < 7; ++i){
		addToTail(&head, i + 1); //β�巨������
	}

	ListNode *tmp = head;
	while (tmp != NULL){
		cout << tmp->m_value << " ";
		tmp = tmp->m_next;
	}	
	cout << endl << endl;
	
	//�����ӡ
	print_Intertively(head);
	print_Recursively(head);


	cout << endl << endl;

	removeNode(&head, 5); //ɾ�� 5
	tmp = head;
	while (tmp != NULL){
		cout << tmp->m_value << " ";
		tmp = tmp->m_next;
	}


	cout << endl << endl;
}