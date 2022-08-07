// C++ program to find maximum sum from a subset of
// nodes of binary tree
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node structure */
struct node
{
	int data;
	struct node *left, *right;
};

/* Utility function to create a new Binary Tree node */
struct node* newNode(int data)
{
	struct node *temp = new struct node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

// Declaration of methods

unordered_map<struct node*,int> dp;

int func(node *root)
{
	if(!root)
	return 0;
	if(dp[root])
	return dp[root];
	
	int inc = root->data;
	if(root->left)
	{
		inc+= func(root->left->left);
		inc+= func(root->left->right);
	}
	if(root->right)
	{
		inc+= func(root->right->right);
		inc+= func(root->right->left);
	}
	
	int exc = func(root->left) + func(root->right);
	
	dp[root]=max(inc,exc);
	return dp[root];
}

// Driver code to test above methods
int main()
{
	node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->right->left = newNode(4);
	root->right->right = newNode(5);
	root->left->left = newNode(1);

	cout << func(root) << endl;
	return 0;
}

