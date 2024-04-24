#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class phanso{
	double a, b;
public: 
	phanso(int _a=0, int _b=1){
		a=_a;
		b=_b;
	}
	phanso(phanso&p){
		a=p.a;
		b=p.b;
	}
	double getGiaTri(){
		return double(a/b);
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
	void psRutGon(){
		int u=ucln(a,b);
		a/=u;
		b/=u;
	}
	void psNghichDao(){
		swap(a,b);
	}
	void xuat(){
	    if(b<0){
	        a*=-1;
            b*=-1;
	    }
		cout<<int(a)<<'/'<<int(b);
	}
	int tong(phanso p){
		return a+p.b;
	}
	void nhap(){
		cin>>a>>b;
	}
};
int main(){
	phanso a;
	phanso b;
	a.nhap();
	b.nhap();
	a.xuat();
	cout<<endl;
	b.xuat();
	cout<<endl;
	cout<<a.tong(b)<<endl;
	cout<<fixed<<setprecision(3)<<a.getGiaTri()<<' '<<b.getGiaTri()<<endl;
	a.psRutGon();
	a.xuat();
	cout<<endl;
	b.psNghichDao();
	b.psRutGon();
	b.xuat();
}
