#include <iostream>
using namespace std;

struct PhanSo{
	int tu,mau;
};
istream & operator>>(istream & is, PhanSo &p){
	is>>p.tu>>p.mau;
	return is;
}
ostream & operator<<(ostream & os, PhanSo p){
	if(p.mau!=0) os<<p.tu<<'/'<<p.mau;
	return os;
}
int ucln(int a, int b){
	int r;
	while(b!=0){
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}
void rg(PhanSo & p){
	int u=ucln(p.tu,p.mau);
	p.tu/=u;
	p.mau/=u;
}
bool operator>(PhanSo p1, PhanSo p2){
	return p1.tu*p2.mau>p1.mau*p2.tu;
}

int main(){
	int n;
	cin>>n;
	PhanSo a[n];
	for(int i=0; i<n; i++){
		cin>>a[i];
		rg(a[i]);
	}
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(a[i]>a[j]){
				swap(a[i],a[j]);
			}
		}
	}
	for(int i=0; i<n; i++) cout<<a[i]<<' ';
}
