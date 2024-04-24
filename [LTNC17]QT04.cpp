#include <iostream>
#include <fstream>
using namespace std;

int fibo(int n){
	if(n==1 || n==2) return 1;
	else{
		return fibo(n-1)+fibo(n-2);
	}
}

int exist(int k, int a[], int &vt){
	for(int i=0; i<20; i++){
		if(k==a[i]){
			vt=i+1;
			return 0;
		}
	}
	vt=-1;
	return 0;
}
int main(){
	int day[10000];
	int vt[10000];
	int a[1000];
    ifstream ip;
    ip.open("DAYSO.INP");
    ofstream op("DAYSO.OUT");
    
    int n=0;
	
	for(int i=1; i<=20; i++){
		a[i-1]=fibo(i);
	}
	
	while(ip>>day[n]){
		int tmp;
		tmp=exist(day[n],a,vt[n]);
		n++;
	}
	
	int _max=-1;
	int vt1=-1;
	
	for(int i=0; i<n; i++){
		if(vt[i]!=-1){
			op<<day[i]<<' ';
			if(day[i]>_max){
				_max=day[i];
				vt1=vt[i];
			}
		}
	}
	op<<endl<<_max<<' '<<vt1;
	ip.close();
	op.close();
}
