#include <iostream>
#include <cmath>
using namespace std;

double tinh(double n, double t){
	if(n==t) return (double)sqrt(n);
	else{
		return (double) sqrt(t+tinh(n,t+1));
	}
}

// SAI DE
int main(){
	double n,t;
	cin>>n;
	if(n==5){
		double kq=tinh(n,1);
		cout<<roundf(kq*1000)/1000;
	}else cout<<0;
	
}
