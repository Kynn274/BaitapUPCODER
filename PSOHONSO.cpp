#include <iostream>
#include <cmath>
using namespace std;

class honso{
	int a;
	int tu,mau;
public:
	honso(int _a=0, int _b=0, int _c=1){
		a=_a;
		tu=_b;
		mau=_c;
	}
	honso(honso&p){
		a=p.a;
		tu=p.tu;
		mau=p.mau;
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
	void rg(){
		int u=ucln(tu,mau);
		tu=tu/u;
		mau=mau/u;
	}
	void chuyendoi(){
		tu=a*mau+tu;
		a=0;
		rg();
	}
	bool operator!=(honso p){
		if(tu!=p.tu || mau!=p.mau || a!=p.a) return true;
		else return false;
	}
	void rechuyendoi(){
		a+=tu/mau;
		tu=tu%mau;
		rg();
	}
	int tong(){
		return a+tu+mau;
	}
	bool operator>(honso p){
		return tong()>p.tong();
	}
	void nhap_honso(){
		cin>>a>>tu>>mau;
	}
	void xuat_honso(){
		if(a!=0) cout<<a<<" ";
		cout<<tu<<"/"<<mau;
	}
};

int main(){
	honso a;
	honso b;
	string c;
	a.nhap_honso();
	b.nhap_honso();
	cin>>c;
	if(c=="false"){
		if(a!=b) cout<<"TRUE\n";
		else cout<<"FALSE\n";
		if(a>b) cout<<"TRUE\n";
		else cout<<"FALSE\n";
		a.chuyendoi();
		b.chuyendoi();
		a.xuat_honso();
		cout<<endl;
		b.xuat_honso();
	}else{
		if(a!=b) cout<<"TRUE\n";
		else cout<<"FALSE\n";
		if(a>b) cout<<"TRUE\n";
		else cout<<"FALSE\n";
		a.rechuyendoi();
		a.xuat_honso();
		cout<<endl;
		b.rechuyendoi();
		b.xuat_honso();
	}
}
