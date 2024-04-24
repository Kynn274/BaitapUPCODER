#include <iostream>
using namespace std;

int main(){
	int a,e,k;
	cin>>a>>e>>k;
	cout<<a+e+k<<' ';
	if(a>e) cout<<a+k<<' '<<e+k;
	else cout<<e+k<<' '<<a+k;
	return 0;
}
