#include<iostream>
#include<cmath>
using namespace std;
bool check(long long n){
	long long i=1;
	while(n>0){
		n-=i;
		i++;
	}
	if(n<0) return false;
	else return true;
}
int main(){
	long long n;
	cin>>n;
	if(check(n)&&n>=3) cout<<"YES";
	else cout<<"NO";
	return 0;
}
