#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
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
	double getStringLength(){
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
	void delete_space(){
		for(int i=0; i<name.size(); i++){
			if(name[i]==' '&&name[i-1]==' '){
				name.erase(i,1);
				i--;
			}
		}
	}
	string getStringInverse(){
		reverse(name.begin(), name.end());
		return name;
	}
	double operator/(Name p){
		return getStringLength()/p.getStringLength();
	}
	string connectString(Name p){
		string tmp=name;
		tmp=tmp+" ";
		tmp=tmp+p.name;
		return tmp;
	}
};

int main(){
	Name a,b;
	cin>>a>>b;
	a.delete_space();
	b.delete_space();
	cout<<a.connectString(b)<<endl;
	cout<<a.getStringInverse()<<endl;
	cout<<b.getStringInverse()<<endl;
	cout<<fixed<<setprecision(2)<<double(a/b);
}
