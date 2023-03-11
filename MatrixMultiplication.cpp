#include<iostream>
#include<vector>
using namespace std;

//int table[10]={0};
int MCM(int Arr[],int i,int j,vector<vector<int>> &dp){
	if(i==j){
		return 0;
	}
	if(dp[i][j]!=-1){
		return dp[i][j];
	}
	int min=1e09;
	for(int k=i;k<j;k++){
		int steps = MCM(Arr,i,k,dp)+MCM(Arr,k+1,j,dp)+ Arr[i-1]*Arr[k]*Arr[j];
		if(steps<min) min=steps;
	}
	return dp[i][j]=min;
}

int main(){
	
	int Arr[]={1,2,3,4};
	
	int N=sizeof(Arr)/sizeof(Arr[0]);
	vector<vector<int>> dp(N,vector<int>(N,-1));// 2D array with all values -1
	cout<<MCM(Arr,1,N-1,dp);
	return 0;
}
