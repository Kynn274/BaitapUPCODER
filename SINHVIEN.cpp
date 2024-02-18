#include <iostream>
#include <cmath>
#include <string>
using namespace std;

struct SinhVien{
	string HoTen;
	int NamSinh;
	double DTB;
};

istream & operator>>(istream & is, SinhVien & p){
	is>>p.HoTen>>p.NamSinh>>p.DTB;
	return is;
}
ostream & operator<<(ostream & os, SinhVien p){
	os<<p.HoTen<<' '<<p.NamSinh<<' '<<p.DTB<<endl;
}

bool operator<(SinhVien a, SinhVien b){
	return a.DTB<b.DTB;
}
SinhVien max_min(SinhVien a[], int t, int n){
	SinhVien tmp=a[0];
	for(int i=1; i<n; i++){
		if(t==1){
			if(tmp<a[i]) tmp=a[i];//max;
		}
		if(t==0){
			if(a[i]<tmp) tmp=a[i];//min;
		}
	}
	return tmp;
}

int main(){
	SinhVien a[100];
	int iCount=0;
	while(cin>>a[iCount]){
		iCount++;
	}
	cout<<"Diem cao nhat lop:\n";
	SinhVien tmp=max_min(a,1,iCount);
	int t=1;
	for(int i=0; i<iCount; i++){
		if(a[i].DTB==tmp.DTB){
			cout<<"#"<<t<<endl;
			cout<<a[i];
			t++;
		}
	}
	cout<<"Diem thap nhat lop:\n";
	tmp=max_min(a,0,iCount);
	t=1;
	for(int i=0; i<iCount; i++){
		if(a[i].DTB==tmp.DTB){
			cout<<"#"<<t<<endl;
			cout<<a[i];
			t++;
		}
	}
		
}
