#include <iostream>
#include <cmath>
using namespace std;

struct PhanSo{
	int tu,mau;
};
istream & operator>>(istream & is, PhanSo & p){
	is>>p.tu>>p.mau;
	return is;
}
ostream & operator<<(ostream & os, PhanSo p){
	os<<p.tu<<'/'<<p.mau;
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
void rg(PhanSo &p){
	if(p.mau<0){
		p.mau*=-1;
		p.tu*=-1;
	}
	int u=ucln(abs(p.tu),abs(p.mau));
	p.tu/=u;
	p.mau/=u;
}


struct SoPhuc{
	int thuc,ao;
};
istream & operator>>(istream & is, SoPhuc & p){
	is>>p.thuc>>p.ao;
	return is;
}
ostream & operator<<(ostream & os, SoPhuc p){
	if(p.ao!=0){
		if(p.thuc!=0){
			os<<p.thuc;
			if(p.ao<0){
				if(p.ao==-1)os<<"-i";
				else os<<'-'<<abs(p.ao)<<'i';
			}else{
				if(p.ao==1)os<<"+i";
				else os<<'+'<<abs(p.ao)<<'i';
			}
		}else{
			if(p.ao<0){
				if(p.ao==-1)os<<"-i";
				else os<<'-'<<abs(p.ao)<<'i';
			}else{
				if(p.ao==1)os<<"i";
				else os<<abs(p.ao)<<'i';
			}
		}
	}else{
		os<<p.thuc;
	}
	return os;
}
SoPhuc operator+(SoPhuc a, SoPhuc b){
	SoPhuc u;
	u.thuc=a.thuc+b.thuc;
	u.ao=a.ao+b.ao;
	return u;
}
SoPhuc operator+(SoPhuc a, PhanSo b){
	SoPhuc u;
	rg(b);
	u.thuc=a.thuc+b.tu;
	u.ao=a.ao+b.mau;
	return u;
}
SoPhuc operator+(SoPhuc a, int b){
	SoPhuc u;
	u.thuc=a.thuc+b;
	u.ao=a.ao;
	return u;
}
int main(){
	SoPhuc a;
	cin>>a;
	char x;
	cin>>x;
	if(x=='i'){
		int b;
		cin>>b;
		cout<<a<<endl;
		cout<<b<<endl;
		cout<<a+b;
	}else if(x=='z'){
		SoPhuc b;
		cin>>b;
		cout<<a<<endl;
		cout<<b<<endl;
		cout<<a+b;
	}else if(x=='p'){
		PhanSo b;
		cin>>b;
		cout<<a<<endl;
		rg(b);
		cout<<b<<endl;
		cout<<a+b;
	}	
}
