#include<iostream>
using namespace std;

class Items{
	public:
	int wt;
	int v;
	~Items(){
		
	}
};

int Knapsack(Items I[],int n,int MW){//returns max profit
	if(MW<=0)	return 0;
	else if(n<=0)	return 0;
	else if(I[n].wt>MW)	return 0;
	else{
		return max((Knapsack(I,n-1,MW)),Knapsack(I,n-1,MW-(I[n].wt))+I[n].v);
	}
}

int main(){
	Items I[]={{10,60},{20,100},{30,120}};
	int n=sizeof(I)/sizeof(I[0]);
	int maxWt=50;
	cout<<Knapsack(I,n-1,maxWt);
	//delete[] I;
	return 0;
}
