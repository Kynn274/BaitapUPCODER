#include <iostream>
#include <cmath>
using namespace std;

long long sotien=0;
long long Q, H, S, D;
long long N;
long long _Q,_H,_S,_D;

int main(){
	cin>>Q>>H>>S>>D>>N;
	_Q=8*Q;
	_H=4*H;
	_S=2*S;
	_D=D;
	long long priority=1e9;
	if(N>=2){
		priority=min(priority,_Q);
		priority=min(priority,_H);
		priority=min(priority,_S);
		priority=min(priority,_D);
		while(N>=2){
			N-=2;
			sotien+=priority;
		}
	}
	priority=1e9;
	if(N>=1){
		priority=min(priority,_Q/2);
		priority=min(priority,_H/2);
		priority=min(priority,_S/2);
		while(N>=1){
			N-=1;
			sotien+=priority;
		}
	}
	priority=1e9;
	if(N>=0.5){
		priority=min(priority,_Q/4);
		priority=min(priority,_H/4);
		while(N>=0.5){
			N-=0.5;
			sotien+=priority;
		}
	}
	priority=Q;
	while(N>=0.25){
		N-=0.25;
		sotien+=priority;
	}
	cout<<sotien;
}
