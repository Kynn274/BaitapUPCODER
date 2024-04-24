#include <iostream>
#include <cmath>
using namespace std;

string matp[]={"04","08","059","061","0511","0710"};

bool kt_kitu(string s){
	for(int i=0; i<s.size(); i++){
		if(s[i]>'9'||s[i]<'0') return false;
	}
	return true;
}

bool kt_mavung(string s, int &t, string &s1){
	for(int i=0; i<6; i++){
		int len=matp[i].size();
		string tmp=s.substr(0,len);
		if(tmp==matp[i]){
			t=i;
			s1=s.substr(len, 10-len);
			return true;
		}
	}
	return false;
}
int main(){
	string s;
	cin>>s;
	
	if(s.size()==10){
		if(kt_kitu(s)){
			int m;
			string s1;
			if(kt_mavung(s,m,s1)){
				switch(m){
					case 0: cout<<"Ha Noi - "<<s1;
						break;
					case 1: cout<<"TPHCM - "<<s1;
						break;
					case 2: cout<<"Gia Lai - "<<s1;
						break;
					case 3: cout<<"Dong Nai - "<<s1;
						break;
					case 4: cout<<"Da Nang - "<<s1;
						break;
					case 5: cout<<"Can Tho - "<<s1;
						break;
				}
			}else cout<<"Khong hop le";
		}else cout<<"Khong hop le";
	}else cout<<"Khong hop le";
}
