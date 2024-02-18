#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <algorithm>
using namespace std;

struct Diem{
	float x;
	float y;
};
istream& operator>>(istream & is, Diem&p){
	is>>p.x>>p.y;
	return is;
}
ostream& operator<<(ostream & os, Diem p){
	os<<'('<<p.x<<','<<p.y<<')';
	return os;
}
void distance(Diem a, Diem b){
	float x=a.x-b.x;
	float y=a.y-b.y;
	cout<<fixed<<setprecision(3)<<sqrt(x*x+y*y);
}
int main(){
	Diem a,b,c;
	cin>>a>>b>>c;
	cout<<a<<' '<<b<<' '<<c<<endl;
	distance(a,b);
}

