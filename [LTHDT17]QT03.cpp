#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

class NhanVien{
protected:
	string id;
	string hoten;
	int songaylam;
	
public:
	NhanVien(string _id="", string _hoten="", int _songaylam=0){
		id=_id;
		hoten=_hoten;
		songaylam=_songaylam;
	}
	NhanVien(NhanVien & p){
		id=p.id;
		hoten=p.hoten;
		songaylam=p.songaylam;
	}
	virtual double tienthuong(){};
	virtual double tinhluong(){};
	
	void set1(string _hoten){
		hoten=_hoten;
	}
	void set2(int _songay){
		songaylam=_songay;
	}
	virtual void set3(double tmp){};
	void xuat(){
		cout<<fixed<<setprecision(0)<<hoten<<','<<songaylam<<','<<tienthuong()<<','<<tinhluong();
	}
};

class banhang: public NhanVien{
	double hsothuong;
public: 
	banhang(string _id="", string _hoten="", int _songaylam=0, double _hsothuong=0):NhanVien(_id,_hoten,_songaylam){
		hsothuong=_hsothuong;
	}
	banhang(banhang&p):NhanVien(p){
		hsothuong=p.hsothuong;
	}
	double tienthuong(){
		return 150000*hsothuong;
	}
	double tinhluong(){
		return (double) tienthuong()+100*songaylam;
	}
	void set3(double tmp){
		hsothuong=tmp;
	}
};

class sanxuat: public NhanVien{
	double sosp;
public:
	sanxuat(string _id="", string _hoten="", int _songaylam=0, int _sosp=0):NhanVien(_id,_hoten,_songaylam){
		sosp=_sosp;
	}
	sanxuat(sanxuat&p):NhanVien(p){
		sosp=p.sosp;
	}
	double tienthuong(){
		return (double) 20000*sosp;
	}
	double tinhluong(){
		return (double) tienthuong()+100*songaylam;
	}
	void set3(double tmp){
		sosp=tmp;
	}
};

class vanphong: public NhanVien{
	double tgian_congtac;
public:
	vanphong(string _id="", string _hoten="", int _songaylam=0, int _tgian_congtac=0):NhanVien(_id,_hoten,_songaylam){
		tgian_congtac=_tgian_congtac;
	}
	vanphong(vanphong&p):NhanVien(p){
		tgian_congtac=p.tgian_congtac;
	}
	double tienthuong(){
		if(tgian_congtac<6) return 1000000;
		else{
			double tmp=(double) (50000*tgian_congtac/6);
			return max((double )1000000,tmp);
		}
	}
	double tinhluong(){
		return (double) tienthuong()+100*songaylam;
	}
	void set3(double tmp){
		tgian_congtac=tmp;
	}
};



int main(){
	int n;
	cin>>n;
	cin.ignore();
	NhanVien * a[1000];
	for(int i=0; i<n; i++){
		string s;
		getline(cin,s);
		int v[100];
		int iC=0;
		for(int i=0; i<s.size(); i++)
			if(s[i]==',') v[iC++]=i;
		string b;
		string c;
		int d;
		double e;

		b=s.substr(0,v[0]);
		c=s.substr(v[0]+1, v[1]-v[0]-1);
		d=stoi(s.substr(v[1]+1, v[2]-v[1]-1));
		e=stod(s.substr(v[2]+1, s.size()-1-v[2]));
		
	 //   cout<<b<<endl<<c<<endl<<d<<endl<<e<<endl;
		if(b=="1") a[i]=new banhang;
		else if(b=="2") a[i]=new sanxuat;
		else if(b=="3") a[i]=new vanphong;
		a[i]->set1(c);
		a[i]->set2(d);
		a[i]->set3(e);
	}
	
	for(int i=0; i<n; i++){
		a[i]->xuat();
		cout<<endl;
	}
}
