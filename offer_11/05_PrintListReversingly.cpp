//输入一个链表的头结点，反向打印节点值
/*  
*	尾插法新建链表注意：
*
* 由于新插入节点时会改变头指针，所以传入的参数
* 应该是指针的指针，否则出了函数，pHead仍然是空指针；

在指针做参数传递给函数的时候：
只能保留指针指向的对象（*P）改变的值
不能保留指针本身（P）所做得修改
在需要修改指针本身的时候，需使用指向指针的指针作为参数，也便是传值与传址的差别所在。
*/
/*
*	倒序打印注意：
 1、若允许修改链表，可以将链表逆置
 2、若不能修改，则用栈实现反向输出，或者递归实现。
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

	else{  /*从最后插入，头结点应该遍历到最后*/
		ListNode *pCur = *pHead;
		while (pCur->m_next != NULL)
			pCur = pCur->m_next;

		pCur->m_next = pNew;
	}
}

void removeNode(ListNode **pHead, int value){

	if (*pHead == NULL || pHead == NULL) /*临界条件判断*/
		return;

	ListNode * tmp = *pHead;
	ListNode * pre = tmp;

	while (tmp->m_next != NULL){		
		if (tmp->m_value == value){
			pre->m_next = tmp->m_next;
			ListNode * dnode = tmp;
			delete dnode;
			break; /*tmp指向的节点内存已经被释放，不中断的话会出现异常*/
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
		ListNode *curr = nodes.top(); /*得到栈顶元素*/
		cout << curr->m_value << " "; 
		nodes.pop(); /*将栈顶出站*/
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
		addToTail(&head, i + 1); //尾插法建链表
	}

	ListNode *tmp = head;
	while (tmp != NULL){
		cout << tmp->m_value << " ";
		tmp = tmp->m_next;
	}	
	cout << endl << endl;
	
	//逆序打印
	print_Intertively(head);
	print_Recursively(head);


	cout << endl << endl;

	removeNode(&head, 5); //删除 5
	tmp = head;
	while (tmp != NULL){
		cout << tmp->m_value << " ";
		tmp = tmp->m_next;
	}


	cout << endl << endl;
}