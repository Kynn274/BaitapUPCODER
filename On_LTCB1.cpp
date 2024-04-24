#include <iostream>
using namespace std;

int main(){
	int a,b;
	bool check=false;
	
	cin>>a>>b;
	
	int tong=a+b;
	int hieu=a-b;
	int tich=a*b;
	
	if(tong>=0){
		cout<<tong<<' ';
		check=true;
	}
	if(hieu>=0){
		cout<<hieu<<' ';
		check=true;
	}
	if(tich>=0){
		cout<<tich;
		check=true;
	}
	
	if(check==false) cout<<"impossible";
}
