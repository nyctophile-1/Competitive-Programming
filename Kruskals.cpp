#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int N = 15;
vector<int> parent(N);
vector<int> sz(N);


void makeset(int x){
	parent[x]=x;
	sz[x]=1;
}
int findset(int x){
	if(x==parent[x]){
		return x;
	}
	parent[x]=findset(parent[x]);
	return parent[x];	
}
void unionset(int a,int b){
	a = findset(a);
	b = findset(b);
	if(a!=b){
		if(sz[a]<sz[b])
			swap(a,b);
		parent[b]=a;
		sz[a]+=sz[b];
//		cout<<"\nUnion Created";
	}
}

int main(){
	int vertices=8;
	int m=9;
	for(int i=0;i<N;i++){
		makeset(i);
	}
	vector<vector<int>> edges;
	//w,u,v
	edges.push_back({5,1,2});
	edges.push_back({6,2,3});
	edges.push_back({2,4,3});
	edges.push_back({1,8,5});
	edges.push_back({9,1,4});
	edges.push_back({5,3,5});
	edges.push_back({10,5,6});	
	edges.push_back({7,6,7});
	edges.push_back({1,7,8});
	
	sort(edges.begin(),edges.end());
	int cost=0;
//	for(auto i:edges){
//		cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
//	}
	for(auto i:edges){
		int w = i[0];
		int u = i[1];
		int v = i[2];
		int x = findset(u);
		int y = findset(v);
		if(x==y){
			continue;
		}
		else{
			cout<<u<<" "<<v<<endl;
			unionset(u,v);
			cost+=w;
		}
	}
	cout<<"\n\nCost:"<<cost;
}
