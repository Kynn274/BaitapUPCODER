#include <iostream>
#include <cmath>
using namespace std;
bool snt(int a){
	if(a<2) return 0;
	if(a==2||a==3) return 1;
	if(a>3){
		for(int i=2; i<=sqrt(a); i++)
			if(a%i==0) return 0;
		return 1;
	}
}

bool scp(int a){
	double tmp=double(sqrt(a));
	if(tmp==int(tmp)) return 1;
	return 0;
}
int main(){
	int n,a[100];
	cin>>n;
	for(int i=0; i<n; i++) cin>>a[i];
	for(int i=0; i<n; i++)
		if(scp(a[i])) cout<<a[i]<<' ';
	cout<<endl;
	for(int i=0; i<n; i++)
		if(snt(a[i])) cout<<a[i]<<' ';
}
