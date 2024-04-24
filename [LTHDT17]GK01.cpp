#include <iostream>
#include <string>
using namespace std;

class slot{
	int id;
	string phonenum;
	string nhamang;
	int limit;
public:
	slot(int _id=0, string _phonenum="", string _nhamang="", int _limit=100){
		id=_id;
		phonenum=_phonenum;
		limit=_limit;
		nhamang=_nhamang;
	}
	slot(slot&p){
		id=p.id;
		phonenum=p.phonenum;
		limit=p.limit;
		nhamang=p.nhamang;
	}
	friend istream & operator>>(istream & is, slot & p){
		is>>p.id>>p.phonenum>>p.nhamang>>p.limit;
		return is;
	}
	friend ostream & operator<<(ostream & os, slot p){
		os<<'{'<<p.id<<':'<<p.phonenum<<':'<<p.nhamang<<':'<<p.limit<<'}';
		return os;
	}
};
int main(){
	int n;
	slot a[1000];
	
	cin>>n;
	for(int i=0; i<n; i++) cin>>a[i];
	for(int i=0; i<n; i++) cout<<a[i]<<endl;
}
