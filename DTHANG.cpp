#include <iostream>
#include <cmath>
using namespace std;

class _line{
	int a;
	int b;
	int c;
public:
	_line(int _a=0, int _b=0, int _c=0){
		a=_a;
		b=_b;
		c=_c;
	}
	_line(_line&p){
		a=p.a;
		b=p.b;
		c=p.c;
	}
	friend istream&operator>>(istream & is, _line&p){
		is>>p.a>>p.b>>p.c;
		return is;
	}
	friend ostream& operator<<(ostream&os, _line p){
		if(p.a!=0){
			if(p.a==1) os<<'x';
			else if(p.a==-1) os<<"-x";
			else os<<p.a<<'x';
			if(p.b!=0){
				if(p.b==1) os<<" + y";
				else if(p.b==-1) os<<" - y";
				else if(p.b>1) os<<" + "<<abs(p.b)<<'y';
				else if(p.b<1) os<<" - "<<abs(p.b)<<'y';
			}
			if(p.c!=0){
				if(p.c>0) os<<" + "<<abs(p.c);
				else os<<" - "<<abs(p.c);
			}
		}else{
			if(p.b!=0){
				if(p.b==1) os<<'y';
				else if(p.b==-1) os<<"-y";
				else os<<p.b<<'y';
				if(p.c!=0){
					if(p.c>0) os<<" + "<<abs(p.c);
					else os<<" - "<<abs(p.c);
				}
			}else{
				os<<p.c;
			}
		}
		os<<" = 0";	
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
	void vitri(_line p){
		int _c=-1*c;
		int _pc=-1*p.c;
		
		int D=a*p.b-b*p.a;
		int Dx=_c*p.b-_pc*b;
		int Dy=a*_pc-p.a*_c;
		
		if(D!=0){
			if(a*p.a+b*p.b==0)cout<<'V'<<endl;
			else cout<<'C'<<endl;
			if(Dx%D==0)cout<<'('<<Dx/D<<',';
			else{
				int u=ucln(abs(Dx),abs(D));
				if(D<0)cout<<'('<<(Dx*-1)/u<<'/'<<(-1*D)/u<<',';
				else cout<<'('<<Dx/u<<'/'<<D/u<<',';
			}
			if(Dy%D==0) cout<<Dy/D<<')';
			else{
				int u=ucln(abs(Dy),abs(D));
				if(D<0)cout<<(Dy*-1)/u<<'/'<<(-1*D)/u<<')';
				else cout<<Dy/u<<'/'<<D/u<<')';
			}
		}else{
			if(Dx==0 && Dy==0) cout<<"T\n0";
			else{
				cout<<"S\n";
				double x,y;
				goidiem(x,y);	
				double d= double(abs(p.a*x+p.b*y+p.c)/sqrt(p.a*p.a+p.b*p.b));	
				cout<<roundf(d * 1000) / 1000;
			}
		}
	}
	void goidiem(double &x, double &y){
		x=0;
		y=(double)(c*-1)/b;
	}
};
int main(){
	_line d1;
	_line d2;
	cin>>d1>>d2;
	cout<<d1<<endl<<d2<<endl;
	d1.vitri(d2);
}
