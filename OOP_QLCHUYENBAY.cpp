#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class flight;
class Nguoi{
	friend flight;
protected:
	string ten;
	string gioitinh;
	int namsinh;
public:
	Nguoi(string _ten="", string _gioitinh="", int _namsinh=0){
		ten=_ten;
		gioitinh=_gioitinh;
		namsinh=_namsinh;
	}
	Nguoi(Nguoi&a){
		ten=a.ten;
		gioitinh=a.gioitinh;
		namsinh=a.namsinh;
	}
	virtual void nhap(){};
	virtual void xuat(){};
};

class khach:public Nguoi{
	friend flight;
protected:
	string vitri;
public:
	khach(string _ten="", string _gioitinh="", int _namsinh=0, string _vitri=""):Nguoi(_ten,_gioitinh,_namsinh){
		vitri=_vitri;
	}
	khach(khach&a):Nguoi(a){
		vitri=a.vitri;
	}
	void nhap(){
		cin>>gioitinh>>namsinh>>vitri;
		cin.ignore();
	}
	void set_ten(string _ten){
		ten=_ten;
	}
	string get_vitri(){
		return vitri;
	}
	void xuat(){
		cout<<"Ho Ten: ";
		/*transform(ten.begin(), ten.end(), ten.begin(), ::tolower);
		for(int i=0; i<ten.size(); i++) if(ten[i]==' '&& ten[i-1]==' '){ten.erase(i,1);i--;}
		ten[0]=ten[0]-32;
		for(int i=0; i<ten.size(); i++) if(ten[i]!=' '&& ten[i-1]==' '){ten[i]+=32;}*/
		cout<<ten<<endl;
		cout<<"Gioi Tinh: "<<gioitinh<<endl;
		cout<<"Nam Sinh: "<<namsinh<<endl;
		cout<<"Vi tri: "<<vitri<<endl;
	}
	void operator=(khach & p){
		ten=p.ten;
		gioitinh=p.gioitinh;
		namsinh=p.namsinh;
		vitri=p.vitri;
	}
};
string x[]={"A1","A2","A3","B1","B2","B3","C1","C2","C3"};
class flight{
	string flight_name;
	string flight_id;
	string noidi;
	string noiden;
	string tgian;
	string places[3][3];
	khach a[1000];
	int tong_khach;
public:
	flight(string _flight_name="", string _flight_id="", string _noidi="",string _noiden="", string _tgian="", int _tong_khach=0){
		flight_name=_flight_name;
		flight_id=_flight_name;
		noidi=_noidi;
		noiden=_noiden;
		tgian=_tgian;
		int t=0;
		for(int i=0; i<3; i++){
			for(int j=0; j<3; j++){
				places[i][j]=x[t++];
			}
		}
		tong_khach=_tong_khach;
	}
	flight(flight&p){
		flight_name=p.flight_name;
		flight_id=p.flight_name;
		noidi=p.noidi;
		noiden=p.noiden;
		tgian=p.tgian;
		int t=0;
		for(int i=0; i<3; i++){
			for(int j=0; j<3; j++){
				places[i][j]=x[t++];
			}
		}
		tong_khach=p.tong_khach;
		for(int i=0; i<tong_khach; i++) a[i]=p.a[i];
	}
	void nhap_flight(){
		getline(cin,flight_name);
		getline(cin,flight_id);
		getline(cin,noidi);
		getline(cin,noiden);
		getline(cin,tgian);
		int t=0;
		for(int i=0; i<3; i++){
			for(int j=0; j<3; j++){
				places[i][j]=x[t++];
			}
		}
		tong_khach=0;
		string tmp;
		while(getline(cin,tmp)){
			if(tmp=="-1"){
				break;
			}else{
				a[tong_khach].set_ten(tmp);
				a[tong_khach].nhap();
				tong_khach++;
			}
		}
	}
	void sapxep(){
		for(int i=0; i<tong_khach-1; i++){
			for(int j=i+1; j<tong_khach; j++){
				if(a[i].vitri>a[j].vitri){
					swap(a[i],a[j]);
				}
			}
		}
	}
	void xuat_flight(){
		cout<<"Ten Chuyen Bay: "<<flight_name<<endl;
		cout<<"Ma Chuyen Bay: "<<flight_id<<endl;
		cout<<"Ngay Bay: "<<tgian<<endl;
		cout<<"Noi Di: "<<noidi<<endl;
		cout<<"Noi Den: "<<noiden<<endl;
		if(tong_khach==0){cout<<0<<endl;}
		else{
			sapxep();
			for(int i=0; i<tong_khach; i++){
				a[i].xuat();
			}
		}
		int check[3][3];
		for(int i=0; i<3; i++)
			for(int j=0; j<3; j++)check[i][j]=1;
		int iCount=0;
		for(int i=0; i<tong_khach; i++){
			if(a[i].vitri=="A1")check[0][0]=0;
			else if(a[i].vitri=="A2")check[0][1]=0;
			else if(a[i].vitri=="A3")check[0][2]=0;
			else if(a[i].vitri=="B1")check[1][0]=0;
			else if(a[i].vitri=="B2")check[1][1]=0;
			else if(a[i].vitri=="B3")check[1][2]=0;
			else if(a[i].vitri=="C1")check[2][0]=0;
			else if(a[i].vitri=="C2")check[2][1]=0;
			else if(a[i].vitri=="C3")check[2][2]=0;
		}
		for(int i=0; i<3; i++)
			for(int j=0; j<3; j++)
				if(check[i][j]!=0)iCount++;
		if(iCount==0) cout<<0<<endl;
		else{
			for(int i=0; i<3; i++)
			for(int j=0; j<3; j++)
				if(check[i][j]!=0){
					if(iCount==0)cout<<places[i][j];
					else{
						cout<<places[i][j]<<' ';
						iCount--;
					}
				}
			cout<<endl;
		}
	}
	void _find(string vt){
		int iCount=0;
		for(int i=0; i<tong_khach; i++){
			if(a[i].vitri==vt){
				a[i].xuat();
				iCount++;
				break;
			}
		}
		if(iCount==0) cout<<0;
	}
};
int main(){
	flight a;
	a.nhap_flight();
	a.xuat_flight();
	string vt;
	cin>>vt;
	cout<<vt<<endl;
	a._find(vt);
}
