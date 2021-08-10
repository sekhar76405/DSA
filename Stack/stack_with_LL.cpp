#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
} *top = NULL;

Node* create_Node(int data){
    Node *newnode = new Node;
    newnode-> data = data;
    newnode->next = NULL;
    return newnode;
}

void push(int data){
    if(top == NULL){
        top == create_Node(data);
    }
    else{
        Node *temp;
        temp = top;
        top = create_Node(data);
        top->next  = temp;
    }

} 

int main(){




    return 0;
}