#include <iostream>
#include <string>
using namespace std;

class khach{
protected:
	string ten;
	int tgian;
	int sophong;
	double dongia;
	string loai;
public:
	khach(string _ten="", int _tgian=0, int _sophong=0, double _dongia=0){
		ten=_ten;
		tgian=_tgian;
		sophong=_sophong;
		dongia=_dongia;
	}
	khach(khach&p){
		ten=p.ten;
		tgian=p.tgian;
		sophong=p.sophong;
		dongia=p.dongia;
	}
	double tinhtien(string kind){
		if(kind=="VIP"){
			return double(dongia*tgian-dongia*tgian*0.1);
		}else if(kind=="T"){
			return double(dongia*tgian);
		}
	}
	void nhap(){
		cin>>loai;
		cin.ignore();
		getline(cin,ten);
		cin>>tgian>>sophong;
	}
	void set_dongia(double _dongia){dongia=_dongia;}
	void xuat(){
		cout<<"Loai khach: ";
		if(loai=="VIP") cout<<"VIP\n";
		else if(loai=="T") cout<<"Thuong\n";
		cout<<"Ho Ten: "<<ten<<endl;
		cout<<"Thoi gian su dung: "<<tgian<<endl;
		cout<<"So phong: "<<sophong<<endl;
		cout<<"So tien phai tra: "<<tinhtien(loai);
	}
};

int main(){
	int n;
	double dongia;
	cin>>n>>dongia;
	khach a[1000];
	for(int i=0; i<n; i++){
		a[i].nhap();
		a[i].set_dongia(dongia);
	}
	for(int i=0; i<n-1; i++){
		cout<<i+1<<". ";
		a[i].xuat();
		cout<<endl;
	}
	cout<<n<<". ";
	a[n-1].xuat();
}
