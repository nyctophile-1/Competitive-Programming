#include<iostream>
using namespace std;

int Arr[50]={-1};

int Fibonacci(int n){	//using Tabulation
	Arr[0]=1;
	Arr[1]=1;
	for(int i=2;i<=n;i++){
		Arr[i]=Arr[i-1]+Arr[i-2];
	}
	return Arr[n];
}

int FibonacciSpaceOptimized(int n){		//using Space Optimization
	int prev2=1;
	int prev =1;
	int curr;
	for(int i=2;i<=n;i++){
		curr=prev2+prev;
		prev2=prev;
		prev=curr;
	}
	return prev;
}

int main(){
	cout<<FibonacciSpaceOptimized(5);
}
