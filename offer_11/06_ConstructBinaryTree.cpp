#include<iostream>

using namespace std;

struct BinaryTreeNode{
	int m_value;
	BinaryTreeNode* m_left;
	BinaryTreeNode* m_right;
};

BinaryTreeNode* ConstructCore(int* startPre, int* endPre, 
						      int* startIn,  int* endIn){
	int rootv = startPre[0];
	BinaryTreeNode* root = new BinaryTreeNode();
	root->m_value = rootv; 
	root->m_left = root->m_right = NULL;
	if (startPre == endPre){ //序列中只有一个值
		if (startIn == endIn && *endPre == *endIn)
			return root;
		else
			throw exception("Invalid input!");
	}
	
	int *rootIn = startIn;
	while (rootIn != endIn && *rootIn != rootv)
		++rootIn;
	if (rootIn == endIn && *rootIn != rootv) //序列中有多个值
		throw exception("Invalid input!");

	int leftlen = rootIn - startIn;
	int *leftend = startPre + leftlen;
	if (leftlen > 0)
		root->m_left = ConstructCore(startPre + 1, leftend, startIn, rootIn - 1);
	if (leftlen < endPre - startPre)
		root->m_right = ConstructCore(leftend + 1, endPre, rootIn + 1, endIn);

	return root;
}

BinaryTreeNode* Construct(int* preorder, int* inorder, int len){
	if (preorder == NULL || inorder == NULL || len <= 0)
		return NULL;
	return ConstructCore(preorder, preorder + len - 1, inorder, inorder + len - 1);
}

// ====================测试代码====================
void main06(){
	//const int length = 8;
	//int pre[length] = { 1, 2, 4, 7, 3, 5, 6, 8 };
	//int in[length] = { 4, 7, 2, 1, 5, 3, 8, 6 };

	//const int length = 5;
	//int preorder[length] = { 1, 2, 3, 4, 5 };
	//int inorder[length] = { 5, 4, 3, 2, 1 };

	//const int length = 5;
	//int preorder[length] = { 1, 2, 3, 4, 5 };
	//int inorder[length] = { 1, 2, 3, 4, 5 };

	//const int length = 1;
	//int preorder[length] = { 1 };
	//int inorder[length] = { 1 };

	const int length = 7;
	int preorder[length] = { 1, 2, 4, 5, 3, 6, 7 };
	int inorder[length] = { 4, 2, 8, 1, 6, 3, 7 };

	BinaryTreeNode* root = Construct(preorder, inorder, length);
	if (root != nullptr){
		printf("root value: %d\n", root->m_value);
		if (root->m_left != NULL)
			printf("root->left value: %d\n", root->m_left->m_value);
		if (root->m_right != NULL)
			printf("root->right value: %d", root->m_right->m_value);
	}
}