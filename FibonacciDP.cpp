#include<iostream>
using namespace std;

int Arr[100]={0};
int Fibonacci(int n){
	if((n==1)or(n==2)){
		return 1;
	}
	else if(Arr[n]!=0){
		return Arr[n];
	}
	else{
		Arr[n]=Fibonacci(n-1)+Fibonacci(n-2);
		return Arr[n];
	}
	return -1;
}

int main(){
	cout<<Fibonacci(8)<<endl;
	return 0;
}
