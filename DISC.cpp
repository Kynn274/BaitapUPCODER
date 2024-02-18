#include <iostream>
#include <vector>

using namespace std;

bool kt(vector<long long> check, long long b){
	for(int i=0; i<check.size(); i++){
		if(b==check[i]) return false;
	}
	return true;
}

int main(){
	int n,k;
	cin>>n>>k;
	vector<long long> a,b;
	for(long long i=0; i<n; i++){
		a.push_back(i+1); 
	}
	int tmp;
	for(long long i=0; i<k; i++){
		cin>>tmp;
		b.push_back(tmp); 
	}
	vector<long long> check;
	for(int i=b.size()-1; i>=0; i--){
		if(kt(check,b[i])){
			cout<<b[i]<<' ';
			check.push_back(b[i]);
			a[b[i]-1]=-1;
		}
	}
	
	for(int i=0; i<a.size(); i++){
		if(a[i]>0) cout<<a[i]<<' ';
	}
}
