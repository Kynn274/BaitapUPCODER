#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int a,b,c;
	int _max=0;
	_max=max(_max,a);
	_max=max(_max,b);
	_max=max(_max,c);
	
	_max1=0;
	if(a>_max1 && a<_max) _max1=a;
	if(b>_max1 && b<_max) _max1=b;
	if(c>_max1 && c<_max) _max1=c;
	
	if(_max1%2==0) cout<<_max1<<" la so chan";
	else cout<<_max1<<" la so le";
}
