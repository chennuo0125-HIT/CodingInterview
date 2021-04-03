#include <cstdio>

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL){}
};

TreeNode* buildTree(int* preorder, int* midorder, int length)
{
	// 对无效数组的冗余判断
	if (NULL == preorder || NULL == midorder || 0 == length) return NULL;
		
	// 生成根节点
	TreeNode* root = new TreeNode(preorder[0]);

	if (1 == length) return root;

	// 在中序序列中查找根节点，根节点位置之前的数组是左子树，根节点位置之后的数组是右子树
	int left_length = 0;
	while (left_length < length && midorder[left_length] != root->val)
		left_length++;
		
	root->left = buildTree(&preorder[1], &midorder[0], left_length);
	root->right = buildTree(&preorder[left_length+1], &midorder[left_length+1], length - left_length -1);
		
	return root;
}

void printNode(TreeNode* node)
{
	if (node == NULL) return;
	
	printf("%d\n", node->val);

	printNode(node->left);
	printNode(node->right);
}

void deleteNode(TreeNode* node)
{
	deleteNode(node->left);
	deleteNode(node->right);
}

int main ()
{
	int length = 8;
	int preorder[length] = {1, 2, 4, 7, 3, 5, 6, 8};
	int midorder[length] = {4, 7, 2, 1, 5, 3, 8, 6};
	
	TreeNode* root = buildTree(preorder, midorder, 8);

	printNode(root);

	return true;
}
