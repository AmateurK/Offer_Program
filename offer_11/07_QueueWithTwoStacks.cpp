#include <iostream>
#include <exception>
#include <stack>

using namespace std;

template<typename T> class CQueue{
private:
	stack<T> stack1;
	stack<T> stack2;

public:
	CQueue();
	~CQueue();
	void appendTail(const T& element);
	T deleteHead();
	int size();
};

template<typename T> CQueue<T>::CQueue(){};

template<typename T> CQueue<T>::~CQueue(){};

template<typename T> void CQueue<T>::appendTail(const T& element){
	stack1.push(element);
}

template<typename T> T CQueue<T>::deleteHead(){
	if (stack2.size() <= 0){
		while (stack1.size() > 0){
			T& data = stack1.top();
			stack1.pop();
			stack2.push(data);
		}
	}
	if (stack2.size() == 0)
		throw exception("queue is empty.");

	T head = stack2.top();
	stack2.pop();

	return head;
}
template<typename T> int CQueue<T>::size(){
	return stack1.size() + stack2.size();
}

void main07(){
	CQueue<int> cq;
	int elem[10] = {0};
	cout << "enter order: ";
	for (int i = 5; i > 0; --i){
		cq.appendTail(i);
		cout << i << " ";
	}

	cout << endl << "out order: ";
	for (int i = 0; i < 5; ++i){
		elem[i] = cq.deleteHead();
		cout << elem[i] << " ";
	}

	return;
}