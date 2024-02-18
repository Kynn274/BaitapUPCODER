#include <iostream>
#include <cmath>
using namespace std;

bool snt(int n){
	if(n<2) return false;
	if(n==2||n==3) return true;
	if(n>3){
		for(int i=2; i<=sqrt(n); i++){
			if(n%i==0) return false;
		}
		return true;
	}
}
int main(){
	int k;
	cin>>k;
	int iCount=0,a[100];
	while(cin>>a[iCount]){
		iCount++;
	}
	int max=-1;
	for(int i=0; i<iCount; i++){
		if(snt(a[i])&&a[i]<=k&&max<a[i])
			max=a[i];
	}
	cout<<max;
}
