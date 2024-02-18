#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main(){
	vector<long long> check;
	check.push_back(0);
	check.push_back(0);
	for(int i=2; i<=200000; i++) check.push_back(1);
	for(int i=4; i<=200000; i++){
		for(int j=2; j<=sqrt(i); j++){
			if(i%j==0){
				check[i]=0;
				break;
			}
		}
	}
	long long A,B;
	cin>>A>>B;
	for(int i=A; i<=B; i++){
		if(check[i]==1) cout<<i<<endl;
	}
}
