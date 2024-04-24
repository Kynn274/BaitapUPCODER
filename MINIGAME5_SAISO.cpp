#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
	int m;
	cin>>m;
	if(m==1){
		double a;
		cin>>a;
		cout<<fixed<<setprecision(2)<<double(a);
	}else if(m==2){
		double x,A;
		cin>>x>>A;
		cout<<fixed<<setprecision(2)<<double(x*A);
	}else if(m==3){
		double x,A,n,a;
		cin>>x>>A>>n>>a;
		cout<<fixed<<setprecision(2)<<double(x*A+n*a);
	}
}
