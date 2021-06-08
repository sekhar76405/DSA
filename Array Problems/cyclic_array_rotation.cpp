#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void swap(int *a, int *b) {
	int *c;
	*c = *a; *a = *b; *b = *c;
}

void cyclic_rotate(int *arr, int n) {
	for(int i=n-1;i>0;i--){
		swap(&arr[i],&arr[i-1]);
	}
}

int main() {

	int arr[] = {9, 8, 7, 6, 4, 2, 1, 3};
	int n = sizeof(arr)/sizeof(arr[0]);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
	cyclic_rotate(arr, n);

	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
}