#include <iostream>
#include <string.h>
#include <stdio.h>
#include <cmath>
using namespace std;

void sx(string &a, int k){
	for(int i=0; i<a.size()-1; i++)
		for(int j=i+1; j<a.size(); j++)
			if(k==0){ // lon toi be
				if(a[i]<a[j]) swap(a[i], a[j]);
			}else{ // be toi lon
				if(a[i]>a[j]) swap(a[i], a[j]);
			}
}
int main(){
	string a;
	cin>>a;
	string b=a;
	sx(b,0);
	int m=stoi(b);
	sx(b,1);
	int n=stoi(b);
	int k=stoi(a);
	if(k==m-n){
		cout<<"YES\n";
		cout<<m<<' '<<n;
	}else{
		cout<<"NO\n";
		cout<<m<<' '<<n;
	}
}
