#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

struct vitri{
	double x,y;
};

double operator-(vitri a, vitri b){
	return (double)abs((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
class Bike{
	int id;
	string driver_name;
	string bien_so;
	double km;
	vitri now;
public: 
	Bike(int _id=0, string _driver_name="", string _bien_so="", int _km=0){
		id=_id; 
		driver_name=_driver_name;
		bien_so=_bien_so;
		km=_km;
	}
	Bike(Bike&s){
		id=s.id; 
		driver_name=s.driver_name;
		bien_so=s.bien_so;
		km=s.km;
		now.x=s.now.x;
		now.y=s.now.y;
	}
	
	void nhap(){
		cin>>id>>bien_so>>driver_name>>km>>now.x>>now.y;
	}
	void xuat(){
		cout<<"{"<<id<<":"<<bien_so<<":"<<driver_name<<":"<<km<<":"<<now.x<<":"<<now.y<<"}";
	}
	double get_km(){return km;}
	double khoangcach(vitri khach){
		return now-khach;
	}
	void operator=(Bike s){
		id=s.id; 
		driver_name=s.driver_name;
		bien_so=s.bien_so;
		km=s.km;
		now.x=s.now.x;
		now.y=s.now.y;
	}
	void set_km(double _km){
		km=_km;
	}
};

int main(){
	int n;
	double distance, tmp=1e9;
	vitri khach;
	
	cin>>n>>khach.x>>khach.y>>distance;
	Bike a[1000];
	for(int i=0; i<n; i++)a[i].nhap();
	for(int i=0; i<n; i++){
		double m;
		m=a[i].khoangcach(khach);
		if(tmp>m) tmp=m;
	}
	
	double s=1e9;
	Bike one;
	for(int i=0; i<n; i++){
		double m;
		m=a[i].khoangcach(khach);
		//cout<<m<<endl;
		if(tmp==m){
			if(a[i].get_km()<s){
				s=a[i].get_km();
				one=a[i];
			}
		}
	}
	one.set_km(one.get_km()+distance);
	one.xuat();
	cout<<endl;
	if(distance<=2) cout<<11900;
	else cout<<11900+(distance-2)*3800;	
	
}
