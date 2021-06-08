#include<iostream>
using namespace std;

void push(int *stack, int &data, int &top, int &size)
{
    cout<<"hello\n";cout<<top<<endl;
	if(top == size-1)
		cout<<"Cannot Push, stack Overflow\n";
	else{
		top++;
		stack[top] = data;
	}
}
void pop(int *stack, int &top, int &size)
{
	if(top==-1)
		cout<<"Cannot Pop, stack Underflow\n";
	else
		top--;
}
void display(int *stack, int &top, int &size)
{
	if(top == -1)
	    cout<<"Stack Empty\n";
	else{
	for(int i=0;i<=top;i++)
		cout<<stack[i]<<" ";
	cout<<endl;	
	}
}
int main()
{
	int size=0,top=-1,temp=0;
	cout<<"Enter the size of the stack: ";
	cin>>size;
	int *stack = new int[size];
	// temp=3;
	// push(stack,temp,top,size);
	// temp = 5;
	// push(stack,temp,top,size);
	// display(stack,top,size);
	// push(stack,temp,top,size);
	// display(stack,top,size);
	// pop(stack,top,size);
	// display(stack,top,size);
	// pop(stack,top,size);
	// display(stack,top,size);

	return 0;
}