#include<iostream>
using namespace std;

void rotate (int *arr,int d, int n){
int temp = 0;
	for(int j=0;j<d;j++){
		temp=arr[0];
		for(int i=1;i<n;i++){
			arr[i-1] = arr[i];
		}
		arr[++i] = temp;
	}
}

int main{



}