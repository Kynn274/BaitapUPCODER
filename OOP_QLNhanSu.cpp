#include <string>
#include <iostream>
#include <stdio.h>
using namespace std;

class nhanvien{
protected:
	string id;
	string ten;
	double luong;
	
public:
	nhanvien(string _id="", string _ten="", double _luong=0){
		id=_id;
		ten=_ten;
		luong=_luong;
	}
	nhanvien(nhanvien & p){
		id=p.id;
		ten=p.ten;
		luong=p.luong;
	}
	virtual void nhap(){};
	virtual void xuat(){};
	virtual double tinhluong(){};
};

class bienche: public nhanvien{
	double phucap;
	double hsoluong;
public:
	bienche(string _id="", string _ten="", double _luong=0, double _phucap=0, double _hsoluong=0):nhanvien(_id,_ten,_luong){
		phucap=_phucap;
		hsoluong=_hsoluong;
	}
	bienche(bienche&p):nhanvien(p){
		phucap=p.phucap;
		hsoluong=p.hsoluong;
	}
	double tinhluong(){
		double luongchinh=luong*hsoluong;
		return double(luongchinh+phucap);
	}	
	void nhap(){
		cin>>id;
		cin.ignore();
		getline(cin,ten);
		cin>>luong>>hsoluong>>phucap;
	}
	void xuat(){
		cout<<"Loai nhan vien: BC\n";
		cout<<"Ma nhan vien: "<<id<<endl;
		cout<<"Ho ten: "<<ten<<endl;
		cout<<"Tong luong: "<<to_string(int(tinhluong()))<<endl;
	}
};

class hopdong: public nhanvien{
	double hso;
	double tiencong;
	int ngaylam;
public:
	hopdong(string _id="", string _ten="", double _luong=0, double _hso=0, double _tiencong=0, int _ngaylam=0):nhanvien(_id,_ten,_luong){
		hso=_hso;
		tiencong=_tiencong;
		ngaylam=_ngaylam;
	}
	hopdong(hopdong&p):nhanvien(p){
		hso=p.hso;
		tiencong=p.tiencong;
		ngaylam=p.ngaylam;
	}
	double tinhluong(){
		int ngayvuot=0;
		if(ngaylam>22) ngayvuot=ngaylam-22;
		double luongvuot=ngayvuot*hso*tiencong;
		return double(luongvuot+luong);
	}
	void nhap(){
		cin>>id;
		cin.ignore();
		getline(cin,ten);
		cin>>luong>>tiencong>>ngaylam>>hso;
	}
	void xuat(){
		cout<<"Loai nhan vien: HD\n";
		cout<<"Ma nhan vien: "<<id<<endl;
		cout<<"Ho ten: "<<ten<<endl;
		cout<<"Tong luong: "<<to_string(int(tinhluong()))<<endl;
	}
};

int main(){
	int n;
	string loai;
	double tong=0;
	cin>>n;
	nhanvien *a[n];
	for(int i=0; i<n; i++){
		cin>>loai;
		if(loai=="BC"){
			a[i]=new bienche;
		}else if(loai=="HD"){
			a[i]=new hopdong;
		}
		a[i]->nhap();
	}
	double max_luong=0;
	for(int i=0; i<n; i++){
		double tmp=a[i]->tinhluong();
		if(tmp>max_luong){
			max_luong=tmp;
		}
		tong+=tmp;
	}
	for(int i=0; i<n; i++){
		if(a[i]->tinhluong()==max_luong) {
			a[i]->xuat();
			cout<<endl;
		}
	}
	cout<<"Tong luong tat ca nhan vien: "<<to_string(int(tong));
	
}
