#include <iostream>
#include <string.h>
#include <stdio.h>
#include <iomanip>
using namespace std;

class tinh{
	int id;
	string name;
	long long danso;
	double dientich;
public:
	tinh(int _id=0, string _name="", int _danso=0, double _dientich=0){
		id=_id;
		name=_name;
		danso=_danso;
		dientich=_dientich;
	}
	tinh(tinh&p){
		id=p.id;
		name=p.name;
		danso=p.danso;
		dientich=p.dientich;
	}
	void nhap(){
		cin>>id;
		string s;
		getline(cin,s);
		int v[10];
		int iC=0;
		for(int i=0; i<s.size(); i++) if(s[i]==' ')v[iC++]=i;		
		danso=stoi(s.substr(v[iC-2]+1, v[iC-1]-v[iC-2]-1));
		dientich=stod(s.substr(v[iC-1]+1, s.size()-v[iC-1]-1));
		name=s.erase(v[iC-2],s.size()-v[iC-2]);
	}
	void xuat(){
		cout<<"("<<id<<") "<<name<<endl;
	}	

	bool operator>(tinh p){
		return danso>p.danso;
	}
	double operator+(tinh p){
		return (double)(dientich+p.dientich);
	}
	void operator=(tinh p){
		id=p.id;
		name=p.name;
		danso=p.danso;
		dientich=p.dientich;
	}
	double get_dientich(){
		return dientich;
	}
};
int main(){
	int n;
	tinh a[1000];
	
	cin>>n;
	for(int i=0; i<n; i++) a[i].nhap();
	
	tinh tmp=a[0];
	
	for(int i=1; i<n; i++){
		if(a[i]>tmp) tmp=a[i];
	}
	cout<<n<<endl;
	tmp.xuat();

	double tong=0;
	for(int i=0; i<n; i++){
		tong+=a[i].get_dientich();
	}
	cout<<fixed<<setprecision(0)<<tong;
}
