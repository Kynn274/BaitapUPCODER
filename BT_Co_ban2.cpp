#include <iostream>
#include <cmath>
using namespace std;

int ucln(int a, int b){
	int r;
	while(b!=0){
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}

int bcnn(int a, int b){
	return (a*b)/ucln(a,b);
}
int main(){
	int a,b;
	cin>>a>>b;
	cout<<ucln(a,b)<<' '<<bcnn(a,b);
}
