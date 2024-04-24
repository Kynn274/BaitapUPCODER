#include <iostream>
using namespace std;

int main(){
	long long a[1000],b[1000];
	long long _min_a, _min_b;
	long long n;
	cin>>n;
	for(long long i=0; i<n; i++) cin>>a[i]>>b[i];
	_min_a=a[0];
	_min_b=b[0];
	for(long long i=1; i<n; i++){
		if(a[i]<_min_a) _min_a=a[i];
		if(b[i]<_min_b) _min_b=b[i];
	}
	cout<<_min_a*_min_b;
}
