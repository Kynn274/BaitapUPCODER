#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

struct Diem{
	int x,y;
};
istream & operator>>(istream & is, Diem& p){
	is>>p.x>>p.y;
	return is;
}
ostream & operator<<(ostream & os, Diem p){
	os<<'('<<p.x<<','<<p.y<<')';
	return os;
}
bool operator==(Diem a, Diem b){
	return a.x==b.x&&a.y==b.y;
}
double operator-(Diem a, Diem b){
	return double(sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)));
}

struct HCN{
	Diem a,b,c,d;
};
istream & operator>>(istream & is, HCN&p){
	is>>p.a>>p.b>>p.c>>p.d;
	return is;
}
ostream & operator<<(ostream & os, HCN&p){
	os<<p.a<<' '<<p.b<<' '<<p.c<<' '<<p.d;
	return is;
}
double DT_HCN(HCN p){
	double dai=p.a-p.b;
	double rong=p.a-p.d;
	return dai*rong;
}
double operator+(HCN p1, HCN p2){
	return DT_HCN(p1)+DT_HCN(p2);
}
bool operator<(HCN p1, HCN p2){
	return DT_HCN(p1)<DT_HCN(p2);
}
bool operator>(HCN p1, HCN p2){
	return DT_HCN(p1)>DT_HCN(p2);
}

struct TGV{
	Diem a,b,c;
};
istream & operator>>(istream & is, TGV&p){
	is>>p.a>>p.b>>p.c;
	return is;
}
ostream & operator<<(ostream & os, TGV p){
	os<<p.a<<' '<<p.b<<' '<<p.c;
	return os;
}

int main(){
}
