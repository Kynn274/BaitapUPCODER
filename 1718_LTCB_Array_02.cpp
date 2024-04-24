#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool snt(int n){
	if(n<=1) return false;
	if(n==2||n==3||n==5) return true;
	else{
		for(int i=2; i<=sqrt(n); i++)
			if(n%i==0) return false;
		return true;
	}
}

bool scp(int n){
	double tmp=(double) sqrt(n);
	if(tmp==(int) tmp) return true;
	else return false;
}

bool shc(int n){
	int tong=0;
	for(int i=1; i<n; i++)
		if(n%i==0) tong+=i;
	if(tong==n&&n!=0) return true;
	return false;
}

int main(){
	int n,a[10000];
	vector<int> v,v1,v2;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a[i];
		if(snt(a[i])) v.push_back(a[i]);
		if(scp(a[i])) v1.push_back(a[i]);
		if(shc(a[i])) v2.push_back(a[i]);
	}
	
	if(v.size()!=0){
		for(int i=0; i<v.size()-1; i++) 
			cout<<v[i]<<' ';
		cout<<v[v.size()-1]<<endl;
	}
	else cout<<"NULL\n";
			
	if(v1.size()!=0){
		for(int i=0; i<v1.size()-1; i++) 
			cout<<v1[i]<<' ';
		cout<<v1[v1.size()-1]<<endl;
	}
	else cout<<"NULL\n";
			
	if(v2.size()!=0){
		for(int i=0; i<v2.size()-1; i++) 
			cout<<v2[i]<<' ';
		cout<<v2[v2.size()-1];
	}
	else cout<<"NULL";
	
	return 0;
}
