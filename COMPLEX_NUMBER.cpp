#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

struct SoPhuc{
	int thuc,ao;
};

istream & operator>>(istream & is, SoPhuc & z){
	is>>z.thuc>>z.ao;
	return is;
}
ostream & operator<<(ostream & os, SoPhuc z){
	if(z.ao!=0){
		if(z.thuc!=0){
			os<<z.thuc;
			if(z.ao==-1) os<<"-i";
			if(z.ao<-1) os<<z.ao<<"i";
			if(z.ao==1) os<<"+i";
			if(z.ao>1) os<<'+'<<z.ao<<'i';
		}else{
			if(z.ao==-1) os<<"-i";
			if(z.ao<-1) os<<z.ao<<"i";
			if(z.ao==1) os<<"i";
			if(z.ao>1) os<<z.ao<<'i';
		}
	}else{
		os<<z.thuc;
	}
	return os;
}
SoPhuc operator+(SoPhuc a, SoPhuc b){
	SoPhuc m;
	m.thuc=a.thuc+b.thuc;
	m.ao=a.ao+b.ao;
	return m;
}
SoPhuc operator-(SoPhuc a, SoPhuc b){
	SoPhuc m;
	m.thuc=a.thuc-b.thuc;
	m.ao=a.ao-b.ao;
	return m;
}
double modun(SoPhuc a){
	return double(sqrt(a.thuc*a.thuc+a.ao*a.ao));
}

int main(){
	SoPhuc *a=new SoPhuc[100];
	int iCount=0;
	while(cin>>a[iCount]){
		iCount++;
	}
	for(int i=0; i<iCount; i++)	cout<<"{"<<a[i]<<"} ";
	cout<<endl;
	for(int i=0; i<iCount; i++)	cout<<fixed<<setprecision(2)<<modun(a[i])<<' ';
	SoPhuc tong;
	tong.thuc=a[0].thuc;
	tong.ao=a[0].ao;
	for(int i=1; i<iCount; i++){
		tong=tong+a[i];
	}
	cout<<endl<<'{'<<tong<<'}';
}
