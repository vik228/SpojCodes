#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
struct tree
{
	char data;
	tree *left, *right; 
};
int k = 0;
string s;
tree* build_tree (tree* node)
{
	if (s[k] == 'n')
	{
		node = new tree;
		node->data = 'n';
		k = k+1;
		tree *left_subtree,*right_subtree;
		node->left = build_tree (node->left);
		node->right = build_tree (node->right);
	}
	else if (s[k] == 'l')
	{
		node = new tree;
		node->data = 'l';
		k+= 1;
		node->left = NULL;
		node->right = NULL;
	}
	return node;
}
void inorder (tree* node)
{
	if (node != NULL)
	{
		inorder (node->left);
		printf ("%c",node->data);
		inorder (node->right);
	}
}
int depth (tree* node)
{
	int l,r;
	if (node->left != NULL)
	{
		l = depth (node->left);
	}
	if (node->right != NULL)
	{
		r = depth (node->right);
	}
	if (node->left == NULL and node->right == NULL)
		return 0;
	if (l > r)
		return l+1;
	else
		return r+1;
}
int main()
{
	int T;
	scanf ("%d",&T);
	while (T--)
	{
		cin >> s;
		tree* head = NULL;
		head = build_tree(head);
		inorder (head);
		cout << "\n";
		printf ("%d\n",depth(head));
		s.clear();
		k = 0;
	}
	return 0;
}

