#include <iostream>
#include <string>
#include <algorithm>
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
};

int main(){
	Name a,b;
	cin>>a>>b;
	cout<<a<<endl<<b<<endl;
	if(a.getStringLength()>b.getStringLength()){
		cout<<"YES\n";
		cout<<a.stringUpperCase();
	}else{
		cout<<"NO\n";
		cout<<b.stringUpperCase();
	}
}
