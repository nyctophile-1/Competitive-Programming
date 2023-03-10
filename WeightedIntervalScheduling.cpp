#include<iostream>
#include<algorithm>
using namespace std;

class job{
	public:
	int st;	//start time
	int ft;	//finish time
	int wt; //weight
};

bool jobCompare(job j1, job j2){
	return (j1.ft<j2.ft);
}

//Finding a job that doesnt conflict with JOB i
int latestJobConflict(job arr[],int i){
	for(int j=i-1;j>=0;j--){
		if((arr[j].ft)<=(arr[i].st)){
			return j;
		}
	}
	return -1;
}

//Function that returns the max profit of jobs
int findMaxProfit(job arr[],int n){
	
	sort(arr,arr+n,jobCompare);
	
	//memoisation
	int* table = new int[n];
	table[0]=arr[0].wt;
	
	for(int i=1;i<n;i++){
		//Find profit including current job
		int incProfit = arr[i].wt;
		int l = latestJobConflict(arr,i);
		if(l!=-1){
			incProfit+=table[l];
		}
		table[i]=max(incProfit,table[i-1]);
	}
	
	int result = table[n-1];
	delete[] table;
	return result;
	
}


int main(){
	job I[]={{3,10,20},
					{1,2,50},
					{6,19,100},
					{2,100,200}};
	
	int n = sizeof(I)/sizeof(I[0]);
	cout<<"\nOPT Profit is :"<<findMaxProfit(I,n);
	return 0;
	
	}

