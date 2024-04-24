#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct vitri{
	double x,y;
};

double operator-(vitri a, vitri b){
	return (double)((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
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
};

int main(){
	int n;
	cin>>n;
	Bike a[1000];
	for(int i=0; i<n; i++)a[i].nhap();
	for(int i=0; i<n; i++){
		a[i].xuat();
		cout<<endl;
	}
}
