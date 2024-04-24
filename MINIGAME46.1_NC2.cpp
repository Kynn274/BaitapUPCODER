#include <iostream>
using namespace std;

int main(){
	string s;
	cin>>s;
	int v=0;
	while(v>=0){
		v=-2;
		v=s.find("eraser");
		if(v>=0){
			s.erase(v,6);
		}
		//cout<<s<<endl;
	}
	v=0;
	while(v>=0){
		v=-2;
		v=s.find("erase");
		if(v>=0){
			s.erase(v,5);
		}
		//cout<<s<<endl;
	}
	v=0;
	while(v>=0){
		v=-2;
		v=s.find("dreamer");
		if(v>=0){
			s.erase(v,7);
		}
		//cout<<s<<endl;
	}
	v=0;
	while(v>=0){
		v=-2;
		v=s.find("dream");
		if(v>=0){
			s.erase(v,5);
		}
		//cout<<s<<endl;
	}
	
	
	
	if(s.size()==0) cout<<"YES";
	else cout<<"NO";
}
