#include <iostream>
#include <iomanip>
using namespace std;

class khach{
protected:
	string status;
	string name;
	string phonenum;
	int tgian_muon;
	int soluong;
	string loai[100];
	double tonggia;
	double tiendua;
public:
	khach(string _status="NO", string _name="", string _phonenum="", int _tgian_muon=0, int _soluong=0, double _tonggia=0, double _tiendua=0){
		status=_status;
		name=_name;
		phonenum=_phonenum;
		tgian_muon=_tgian_muon;
		soluong=_soluong;
		tonggia=_tonggia;
		tiendua=_tiendua;
	}
	khach(khach&a){
		status=a.status;
		name=a.name;
		phonenum=a.phonenum;
		tgian_muon=a.tgian_muon;
		soluong=a.soluong;
		for(int i=0; i<a.soluong; i++) loai[i]=a.loai[i];
		tonggia=a.tonggia;
		tiendua=a.tiendua;
	}
	double tinhtien(){
		double tong=0;
		for(int i=0; i<soluong; i++){
			if(loai[i]=="SGK") tong+=2000;
			else if(loai[i]=="TT") tong+=3000;
			else if(loai[i]=="KH") tong+=1500;
			else if(loai[i]=="TiT") tong+=4000;
			else if(loai[i]=="TC") tong+=1000;
		}
		tong*=tgian_muon;
		return tong;
	}
	virtual double tong_don(){}
	virtual double tichdiem(){}
	virtual double tientra(){}
	virtual void xuat(){}
	virtual void nhap(){
		cin>>status;
		cin.ignore();
		getline(cin,name);
		cin>>phonenum>>tgian_muon>>soluong;
		for(int i=0; i<soluong; i++) cin>>loai[i];
		cin>>tiendua;
	}
	void get_stt(string stt){
		status=stt;
	}
};

class available: public khach{
	double diem;
public:
	available(string _status="NO", string _name="", string _phonenum="", int _tgian_muon=0, int _soluong=0, double _tonggia=0, double _tiendua=0, double _diem=0):khach(_status,_name,_phonenum,_tgian_muon,_soluong,_tonggia,_tiendua){
		diem=_diem;
	}
	available(available&a):khach(a){
		diem=a.diem;
	}
	void tich_diem(){
		diem+=tinhtien()/1000;
	}
	double tong_don(){
		if(tgian_muon<7) return tinhtien()-tinhtien()*0.1;
		else return tinhtien()-tinhtien()*0.2;
	}
	double tientra(){
		if(diem<100) return tong_don()-tinhtien()*0.05;
		else if(100<=diem&&diem<=200) return tong_don()-tinhtien()*0.1;
		else if(diem<200) return tong_don()-tinhtien()*0.15;
	}
	void xuat(){
		cout<<"The Thu Vien: "<<status<<endl;
		cout<<"Ho Va Ten: "<<name<<endl;
		cout<<"So Dien Thoai: "<<phonenum<<endl;
		cout<<"Thoi Gian Muon: "<<tgian_muon<<" Ngay\n";
		cout<<"So Luong Sach: "<<soluong<<endl;
		cout<<"Loai Sach: ";
		if(loai[0]=="SGK") cout<<"Sach Giao Khoa";
		else if(loai[0]=="TT") cout<<"Truyen Tranh";
		else if(loai[0]=="KH") cout<<"Sach Khoa Hoc";
		else if(loai[0]=="TiT") cout<<"Tieu Thuyet";
		else if(loai[0]=="TC") cout<<"Tap Chi";
		for(int i=1; i<soluong; i++){
			if(loai[i]=="SGK") cout<<" Sach Giao Khoa";
			else if(loai[i]=="TT") cout<<" Truyen Tranh";
			else if(loai[i]=="KH") cout<<" Sach Khoa Hoc";
			else if(loai[i]=="TiT") cout<<" Tieu Thuyet";
			else if(loai[i]=="TC") cout<<" Tap Chi";
		}
		cout<<"\nTong Tien: "<<tientra()<<" VND\n";
		tich_diem();
		cout<<"Khac: "<<diem<<endl;
		cout<<"Tien Thoi: ";
		if(tiendua>=tientra()) cout<<tiendua-tientra()<<" VND";
		else cout<<-1<<" VND";
	}
	void nhap(){
		cin.ignore();
		getline(cin,name);
		cin>>phonenum>>tgian_muon>>soluong;
		for(int i=0; i<soluong; i++) cin>>loai[i];
		cin>>tiendua;
		cin>>diem;
	}
};

class unavailable:public khach{
	double tiencoc;
public:
	unavailable(string _status="NO", string _name="", string _phonenum="", int _tgian_muon=0, int _soluong=0, double _tonggia=0, double _tiendua=0, double _tiencoc=0):khach(_status,_name,_phonenum,_tgian_muon,_soluong,_tonggia,_tiendua){
		tiencoc=_tiencoc;
	}
	unavailable(unavailable&a):khach(a){
		tiencoc=a.tiencoc;
	}
	double tientra(){
		return tinhtien()+tiencoc;
	}
	void nhap(){
		cin.ignore();
		getline(cin,name);
		cin>>phonenum>>tgian_muon>>soluong;
		for(int i=0; i<soluong; i++) cin>>loai[i];
		cin>>tiendua;
		cin>>tiencoc;
	}
	
	void xuat(){
		cout<<"The Thu Vien: "<<status<<endl;
		cout<<"Ho Va Ten: "<<name<<endl;
		cout<<"So Dien Thoai: "<<phonenum<<endl;
		cout<<"Thoi Gian Muon: "<<tgian_muon<<" Ngay\n";
		cout<<"So Luong Sach: "<<soluong<<endl;
		cout<<"Loai Sach: ";
		if(loai[0]=="SGK") cout<<"Sach Giao Khoa";
		else if(loai[0]=="TT") cout<<"Truyen Tranh";
		else if(loai[0]=="KH") cout<<"Sach Khoa Hoc";
		else if(loai[0]=="TiT") cout<<"Tieu Thuyet";
		else if(loai[0]=="TC") cout<<"Tap Chi";
		for(int i=1; i<soluong; i++){
			if(loai[i]=="SGK") cout<<" Sach Giao Khoa";
			else if(loai[i]=="TT") cout<<" Truyen Tranh";
			else if(loai[i]=="KH") cout<<" Sach Khoa Hoc";
			else if(loai[i]=="TiT") cout<<" Tieu Thuyet";
			else if(loai[i]=="TC") cout<<" Tap Chi";
		}
		cout<<"\nTong Tien: "<<tientra()<<" VND\n";
		cout<<"Khac: "<<tiencoc<<endl;
		cout<<"Tien Thoi: ";
		if(tiendua>=tientra()) cout<<tiendua-tientra()<<" VND";
		else cout<<-1<<" VND";
	}
};
int main(){
	int n;
	cin>>n;
	khach *a[1000];
	string stt;
	for(int i=0; i<n; i++){
		cin>>stt;
		if(stt=="YES"){
			a[i]=new available;
		}else if(stt=="NO"){
			a[i]=new unavailable;		
		}
		a[i]->get_stt(stt);
		a[i]->nhap();	
	}
	cout<<1<<"/ ";
	a[0]->xuat();
	for(int i=1; i<n; i++){
		cout<<"\n\n"<<i+1<<"/ ";
		a[i]->xuat();
	}
}
