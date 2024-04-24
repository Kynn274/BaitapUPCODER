#include <iostream>
#include <string>
using namespace std;

struct Diem{
	int x,y;
	string color;
};

istream & operator>>(istream & is, Diem & p){
	is>>p.x>>p.y>>p.color;
	return is;
}
ostream & operator<<(ostream & os, Diem p){
	os<<'('<<p.x<<','<<p.y<<",#"<<p.color<<')';
	return os;
}
int find(string s, Diem a[], int n){
	int iCount=0;
	for(int i=0; i<n; i++){
		if(s==a[i].color){
			iCount++;
		}
	}
	return iCount;			
}
void exchange(string s, Diem a[], int n){
	for(int i=0; i<n; i++){
		if(a[i].x>a[i].y){
			a[i].color=s;
		}
	}
}

int main(){
	int n;
	cin>>n;
	Diem *a=new Diem[n];
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	for(int i=0; i<n; i++){
		cout<<a[i]<<' ';
	}
	cout<<endl<<find("5DC3A8",a,n)<<endl;
	exchange("1F00F3",a,n);
	for(int i=0; i<n; i++){
		cout<<a[i]<<' ';
	}
}
