#include <iostream>
#include <cmath>
using namespace std;

struct PS{
	int tu,mau;
};
istream & operator>>(istream & is, PS&p){
	is>>p.tu>>p.mau;
	return is;
}

ostream & operator<<(ostream & os, PS p){
	if(p.tu==0){
		os<<0;
	}else{
	    if(p.tu>0 && p.mau<0){
	        os<<'-'<<p.tu<<'/'<<abs(p.mau);
	    }else if(p.tu<0 && p.mau<0){
	        os<<abs(p.tu)<<"/"<<abs(p.mau);
	    }else os<<p.tu<<"/"<<p.mau;
	}
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

PS operator+(PS a, PS b){
	PS p;
	p.mau=a.mau*b.mau;
	p.tu=a.tu*b.mau+a.mau*b.tu;
	int u=ucln(p.tu,p.mau);
	p.tu=p.tu/u;
	p.mau=p.mau/u;
	return p;
}
PS operator-(PS a, PS b){
	PS p;
	p.mau=a.mau*b.mau;
	p.tu=a.tu*b.mau-a.mau*b.tu;
	int u=ucln(p.tu,p.mau);
	p.tu=p.tu/u;
	p.mau=p.mau/u;
	return p;
}
PS operator*(PS a, PS b){
	PS p;
	p.mau=a.mau*b.mau;
	p.tu=a.tu*b.tu;
	int u=ucln(p.tu,p.mau);
	p.tu=p.tu/u;
	p.mau=p.mau/u;
	return p;
}
PS operator/(PS a, PS b){
	PS p;
	p.mau=a.mau*b.tu;
	p.tu=a.tu*b.mau;
	int u=ucln(p.tu,p.mau);
	p.tu=p.tu/u;
	p.mau=p.mau/u;
	return p;
}

int main(){
	PS a,b;
	cin>>a>>b;
	if(a.mau==0||b.mau==0){
		cout<<-1;
	}else{
		cout<<a+b<<endl;
		cout<<a-b<<endl;
		cout<<a*b<<endl;
		if(b.tu!=0){
			cout<<a/b;
		}
	}
	return 0;
}
