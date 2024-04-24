#include <iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	if(n==0) cout<<"NULL";
	else{
		int a[1000];
		for(int i=0; i<n; i++) cin>>a[i];
		for(int i=n-1; i>0; i--) cout<<a[i]<<' ';
		cout<<a[0];
	}
	return 0;
}
