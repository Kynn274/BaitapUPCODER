#include <iostream>
#include <cmath>
using namespace std;

struct Diem{
	int x, y;
};
istream & operator>>(istream & is, Diem & p){
 	is>>p.x>>p.y;
 	return is;
}
double operator-(Diem a, Diem b){
	return (double) sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

struct Tron{
	Diem O;
	int r;
};

istream & operator>>(istream & is, Tron & p){
	is>>p.O>>p.r;
	return is;
}

bool cat(Tron a, Tron b){
	return abs(a.r-b.r)<a.O-b.O && a.O-b.O<abs(a.r+b.r);
}


int main(){
	int n;
	Tron a[1000];
	int iC=0;
	
	cin>>n;
	
	for(int i=0; i<n; i++) cin>>a[i];
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(cat(a[i],a[j])) iC++;
		}
	}
	cout<<iC;
}
