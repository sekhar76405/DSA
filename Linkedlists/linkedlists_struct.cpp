#include<iostream>
using namespace std;

struct Node {
	int data;
	Node *link;
} *start;
struct Node* create_node(int data)
{
	Node *node;
	node = new Node;
	node->data = data;
	node->link = NULL;
	return node;
}
void insert(struct Node *curr_node, int data)
{
	if(curr_node == NULL)
	{
		start = create_node(data);
		cout<<"Node created\n";
	}
	else
	{
		while(curr_node->link != NULL)
			curr_node = curr_node->link;
		curr_node->link = create_node(data);
	}
}
void display(Node *start)
{
	struct Node *node;
	if(start == NULL)
	{
		cout<<"\n List is empty. \n";
		return ;
	}
	node = start;
	while(node != NULL)
	{
		cout<<node->data<<" ";
		node = node->link;
	}
	cout<<"\n List is ended. \n";
}
int main()
{
    start = NULL;
	int temp=0;
	cout<<"Enter the 10 elements to be inserted in the list: \n";
	for(int i=0;i<3;i++)
	{
		cin>>temp;
		insert(start,temp);
	}
	display(start);
	return 0;
}