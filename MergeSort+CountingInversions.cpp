#include<iostream>
#include<vector>
using namespace std;

int MergeSortedIntervals(vector<int>& v, int s, int m, int e) {
	vector<int> temp;
	int i, j;
	i = s;
	j = m + 1;
	int inv=0;
	while (i <= m && j <= e) {
		if (v[i] <= v[j]) {
			temp.push_back(v[i]);
			++i;
		}
		else {
			temp.push_back(v[j]);
			inv+=m-i+1;
			++j;
		}
	}

	while (i <= m) {
		temp.push_back(v[i]);
		++i;
	}
	while (j <= e) {
		temp.push_back(v[j]);
		++j;
	}
	for (int i = s; i <= e; ++i)
		v[i] = temp[i - s];
	return inv;
}

int MergeSort(vector<int>& v, int s, int e) {
	if (s < e) {
		int m = (s + e) / 2;
		int i1 = MergeSort(v, s, m);
		int i2 = MergeSort(v, m + 1, e);
		int i3 =MergeSortedIntervals(v, s, m, e);
		
		return i1+i2+i3;
	}
	else{
		return 0;
	}
}

int main(){
	vector<int> A={ 3,5,6,9,1,2,7,8 };
    for(int i=0;i<A.size();i++){
        cout<<" "<<A[i];
    }
   	int inv= MergeSort(A, 0, A.size()-1);
	cout << "\nVector Obtained After Sorting: ";
	for (int i = 0; i < A.size(); ++i) {
		cout << A[i] << ' ';
	}
	cout<<endl<<"Inversions :"<<inv;
	return 0;
}
