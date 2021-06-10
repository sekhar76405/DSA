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

//function to delete all node in the list, i.e. to empty the list
void deleteAllNode(){
	if(head == NULL)	//checking for the edge case to stop recursion
		return ;
	Node *temp = head;
	if(temp->next == NULL) {	//if just 1 node is left in list then make manually head = NULL
		head = NULL;
		free(temp);		//deleting that one node
		return deleteAllNode();		//recursive call
	}

	// Now if we want to delete a Node we want its previous node address also as we did in deleteNode() func
	// so without having another loop to find the prev Node address 
	// we are just traersing till the previous node and using (previous_node -> next) as current last node
	// thus if previous_node = temp->next,, then curr node will be (temp->next)->next
	// everything is same in all the while loops for traversing. instead of temp->next we are using (temp->next)->next
	// to eliminate one extra loop time to find prev node address

	while((temp->next)->next != NULL){		//reaching the last node by using its previous node -> next
		(temp->next) = (temp->next)->next;
	}
	
	free((temp->next)); 	// deleteing the last node
	temp->next = NULL; 		//setting the previous node next pointer NULL
	return deleteAllNode();	//recursive call
}

//to find the length of the list
long int findLength(){
	if(head == NULL)	//if head is only null then simply return 0 
		return 0;
	else {				//else iterate till end of list
		long int len = 1;
		Node* temp = head;
		while(temp->next != NULL){
			temp = temp->next;
			len++;
		}
		return len;
	}
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
	cout<<"Length of the List = "<<findLength()<<endl;
	
	deleteNode(50);
	printList();
	
	deleteAllNode();
	printList();
	cout<<"Length of the List = "<<findLength()<<endl;

	insertAtEnd(10);
	printList();
	insertAtEnd(20);
	printList();
	cout<<"Length of the List = "<<findLength()<<endl;
	return 0;
}