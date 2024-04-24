#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool snt(int n){
	if(n<2) return false;
	if(n==2 || n==3 || n==5) return true;
	else{
		for(int i=2; i<=sqrt(n); i++)
			if(n%i==0) return false;
		return true;
	}
}

int main(){
	int n,m;
	vector<int> v;
	
	cin>>m>>n;
	
	for(int i=m; i<=n; i++){
		if(snt(i)) v.push_back(i);
	}
	
	if(v.size()==0) cout<<-1;
	else{
	    for(int i=0; i<v.size()-1; i++)
	        cout<<v[i]<<' ';
	    cout<<v[v.size()-1];
	}
}
