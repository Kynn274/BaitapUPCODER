#include <iostream>
#include <string>
using namespace std;


int main(){
	string a[100000];
	int n,l;
	cin>>n>>l;
	for(int i=0; i<n; i++)cin>>a[i];
	for(int i=0; i<n-1; i++)
		for(int j=i+1; j<n; j++)
			if(a[j]<a[i]) swap(a[i],a[j]);
	string kq="";
	for(int i=0; i<n; i++)kq=kq+a[i];
	cout<<kq;
}
