#include <iostream>
#include <cmath>
using namespace std;

void tinh(int a,int b,int& l,int d){
	if(b<=(a+d-1)){
		l=b-a;
	}else{
		l=d;
	}
}

int main(){
	int n,times[1000],distance;
	cin>>n;
	for(int i=0; i<n; i++) cin>>times[i];
	times[n]=100000;
	cin>>distance;
	int tong=0;
	for(int i=0; i<n; i++){
		int tmp;
		tinh(times[i],times[i+1],tmp,distance);
		tong+=tmp;
	}
	cout<<tong;
}
