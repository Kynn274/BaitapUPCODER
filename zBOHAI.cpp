#include <iostream>
#include <cmath>
using namespace std;

int tinhM(int M){
	int tong=0;
	for(int i=1; i<=M; i++)
		if(M%i==0) tong+=i;
	return tong;
}

int tinhN(int N){
	int tich=1;
	while(N!=0){
		tich*=(N%10);
		N/=10;
	}
	return tich;
}
int main(){
	int N,M;
	cin>>N>>M;
	if(tinhN(N)==tinhM(M)) cout<<"YES";
	else cout<<"NO";
}

