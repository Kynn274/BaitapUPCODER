#include <iostream>
using namespace std;

int main(){
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	int max=a;
	if(b>max) max=b;
	if(c>max) max=c;
	if(d>max) max=d;
	int premax=0;
	if(a>premax&&a<max) premax=a;
	if(b>premax&&b<max) premax=b;
	if(c>premax&&c<max) premax=c;
	if(d>premax&&d<max) premax=d;
	cout<<premax;
	return 0;
}
