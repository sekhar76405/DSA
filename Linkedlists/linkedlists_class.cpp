//Topic Singly LinkedList
//Link: https://www.geeksforgeeks.org/data-structures/linked-list/
//from 1 to 6 problems

//--------------------------------------------------------------------------------------------------------------------------------------------
// key points to be kept in mind:
// temp-> data  represents (*temp).data that means that temp is a Node type pointer
// temp.data represents that temp is an complete object and we are accesing the data
// Node *temp represent that a Node type pointer is created named temp. now we can store an obj address in temp
//--------------------------------------------------------------------------------------------------------------------------------------------


#include<iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *next;	
} *head = NULL;		//head pointer of Node type (Head is not an obj, just a Node type pointer that points to Node obj/similar type pointers)

Node* create(int data){
	Node *new_node = new Node();
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

// to insert at the end of the list
void insertAtEnd(int data) {
	if(head == NULL)		//if the list is empty, we add the first new created Node to head
		head = create(data);
	else {
		Node *temp = head;
		while(temp->next != NULL) {	//if nodes are there, we traverse till end of the list object
			temp = temp->next;
		}
		temp->next = create(data); //then change its 'next' pointer with the return of create() func
	}	
}

// to insert after a specified node
void insertAtNode(Node *node, int data) {
	if(node->next == NULL)		//checking if there is a node after the specified node
		insertAtEnd(data);		//if not, then it is similar to insert at the end of the list
	else {
		Node *temp = node->next;
		node->next = create(data);	//(node->next) is the new created node 
		(node->next)->next = temp;  //(node->next)->next AKA [create(node) returned address] -> next
	}
}

// to insert at the front of the list
void insertAtFront(int data) {
	if(head == NULL)		//checking if head is Null
		insertAtEnd(data);		//if yes, list is empty and then it is similar to insert at the end of the list
	else {
		Node *temp = head;
		head = create(data);
		head->next = temp;
	}
}

// to search a key data and return the address of that node
Node* search(int data) {
	Node* temp = head;
	while(temp != NULL) {
		if(data == temp->data)
			return temp; 		//data found, return the address of that node having data

		temp = temp->next;
	}
	free(temp);
	return NULL;		// whole list traversed but still not found the data
} 

// to delete a data containing node in the list
void deleteNode(int data) {
	Node* temp = search(data);	// first we got the address of the node to be deleted
	if(temp == NULL) {	// just checking if search() did not return NULL, i.e. data not found to delete
		cout<<"Did not find Key = "<<data<<" to delete in the list.\n";
	 	return ;
	}	

	
	Node* previous = head;
	//checking if the node to be deleted is the 1st Node i the List or Not 
	if(previous == temp)	//if yes, that means prev = temp = head, i.e. start of the List
	{
	    head = head->next;	//deleting the 1st node means head points to next (2nd) node.
	    return ;		//exit the fuction there only
	}	

	//finding the previous node address
	while(previous->next != temp) {
		previous = previous->next;
	}


	if(temp->next == NULL)		//if the selected node is last node of the list
		previous->next = NULL;	//then we simply change previous node next pointer to NULL, so that it doesnot point temp now  
	else
		previous->next = temp->next; //saving the next upcoming node address to the prev Node next pointer
}



// to print the whole list
void printList() {
	Node *temp = head;
	cout<<"Printing the List: \n";
	while(temp != NULL) {
		cout<<temp->data<<"\t";
		temp=temp->next;
	}
	cout<<"\n List Ended.\n";
	free(temp);
}

int main()
{
	insertAtEnd(10);
	insertAtEnd(20);
	insertAtEnd(30);
	insertAtNode((head->next),40);
	insertAtFront(50);
	printList();
	
	deleteNode(50);
	printList();
	return 0;
}