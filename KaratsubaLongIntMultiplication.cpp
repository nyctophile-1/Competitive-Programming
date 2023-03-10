#include<iostream>
#include<math.h>
using namespace std;

long long int KaratsubaIntMultiply(int x,int y){
	if((x<10) || (y<10)){
		return x*y;
	}
	else{
		int l= max(to_string(x).length(),to_string(y).length());
		int h =l/2;
		int x0=x % int(pow(10,h));
		cout<<endl<<"x0:"<<x0;
		int x1=x/int(pow(10,h));
		cout<<endl<<"x1:"<<x1;
		int y0= y% int(pow(10,h));
		cout<<endl<<"y0:"<<y0;
		int y1=y/int(pow(10,h));
		cout<<endl<<"y1:"<<y1;
		
		long long int xy0 =KaratsubaIntMultiply(x0,y0);
		cout<<endl<<"xy0:"<<xy0;
		long long int xy1 =KaratsubaIntMultiply(x1,y1);
		cout<<endl<<"xy1:"<<xy1;
		
		long long int temp = KaratsubaIntMultiply(x0+x1,y0+y1);
		cout<<endl<<"temp:"<<temp;
		
		return (xy0 +xy1*(pow(10,(2*h)))+ (temp-xy0-xy1)*(pow(10,h)));
		
	}
}

int	 main(){
	int x=23476;
	int y=6544;
	long long int ans =KaratsubaIntMultiply(x,y);
	cout<<"\nANS :"<<ans;
	return 0;
	//string z =IntMultiply(x,y);
}
