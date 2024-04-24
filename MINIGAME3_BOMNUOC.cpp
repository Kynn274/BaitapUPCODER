#include <iostream>
using namespace std;

int main(){
	int n,t;
	int a[1000];
	cin>>n>>t;
	for(int i=0; i<n; i++) cin>>a[i];
	int moc=0;
	while(t>0){
		t-=a[moc];
		moc++;
	}
	if(moc>=n) cout<<-1;
	else cout<<moc+1;
}
