#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int lt[10][10];
long long gt(){
	for(int i=0; i<10; i++){
		lt[i][0]=1;
		for(int j=1; j<=8; j++)
			lt[i][j]=lt[i][j-1]*i;
	}
}

int main(){
	long long a,b;
	cin>>a>>b;
	bool e=false;
	gt();
	for(long long i=a; i<=b; i++){
		long long tong=0,a1=i,len=0,_a=i;
		while(a1!=0){
			a1/=10;
			len++;
		}
		a1=i;
		while(a1!=0){
			tong+=lt[a1%10][len];
			a1/=10;
			if(tong>i){
				i-=i%10;
				i+=9;
				break;
			}
		}
		if(tong==_a){
			cout<<i<<' ';
			e=true;
		}
	}
	if(e==false) cout<<-1;
}
