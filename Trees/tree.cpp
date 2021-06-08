#include<iostream>
#include<limits.h>
using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
	bool isVisited = false;				//can be used for traversals
};

struct Node* create_node(int data)		//returns the pointer of new node with the data in it
{
	Node *n;
	n = new Node;
	n->data = data; 
	n->left = NULL;
	n->right = NULL;
	return n; 
}

void add_node(Node *node,int data)
{
	if(node->left == NULL && data <= node->data )
	{
		node->left = create_node(data);
	}
	else if(node->right == NULL && data > node->data)
	{
		node->right = create_node(data);
	}
	else
	{
		if(data <= node->data)
			add_node(node->left,data);
		if(data > node->data)
			add_node(node->right,data);
	}
}




int main()
{
	int input;
	Node *root;
	root = new Node;
	root->data = INT_MAX;
	while(cin>>input)
	{
		if(root->data == INT_MAX)
			root->data = input;
		else
			add_node(root, input);
	}
}