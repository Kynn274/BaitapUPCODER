#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

class Name{
	string name;
public:
	Name(string _name=""){name=_name;}
	Name(Name&a){name=a.name;}
	string get_name(){return name;}
	void set_name(string _name){name=_name;}
	friend istream& operator>>(istream& is, Name&p){
		getline(is,p.name);
		return is;
	}
	friend ostream& operator<<(ostream& os, Name p){
		os<<p.name;
		return os;
	}
	int getStringLength(){
		return name.size();
	}
	string stringUpperCase(){
		transform(name.begin(),name.end(),name.begin(),::toupper);
		return name;
	}
	int operator+(Name p){
		return getStringLength()+p.getStringLength();
	}
	int operator-(Name p){
		return getStringLength()-p.getStringLength();
	}
	string getStringInverse(){
		reverse(name.begin(), name.end());
		return name;
	}
};

int main(){
	Name a,b;
	cin>>a>>b;
	char c;
	cin>>c;
	cout<<a.getStringInverse()<<endl<<b.getStringInverse()<<endl;
	if(a.getStringLength()>b.getStringLength())cout<<"LONHON\n";
	else if(b.getStringLength()>a.getStringLength()) cout<<"BEHON\n";
	else cout<<"BANG\n";
	if(c=='+') cout<<a+b;
	else if(c=='-') cout<<abs(a-b);
}
