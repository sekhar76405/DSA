#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
} *top = NULL;

void create_Node(int data){
    Node *newnode = new Node;
    newnode-> data = data;
    newnode->next = NULL;
}


int main(){




    return 0;
}