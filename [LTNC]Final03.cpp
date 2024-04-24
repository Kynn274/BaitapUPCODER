#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
	string s;
	
	getline(cin,s);
	
	while(s[0]==' ') s.erase(0,1);
	while(s[s.size()-1]==' ') s.erase(s.size()-1,1);
	
	for(int i=0; i<s.size(); i++) 
		if(s[i]==' '&& s[i+1]==' '){
			s.erase(i+1,1);
			i--;
		}
	
	vector<int> v;
	for(int i=0; i<s.size(); i++) 
		if(s[i]==' ') v.push_back(i);
	
	string ho,ten,tendem;
	if(v.size()==1){
		ho=s.substr(0,v[0]);
		ten=s.substr(v[0]+1, s.size()-v[0]-1);
		cout<<ho<<endl<<ten;
	}else{
		ho=s.substr(0,v[0]);
		tendem=s.substr(v[0]+1,v[v.size()-1]-v[0]-1);
		ten=s.substr(v[v.size()-1]+1, s.size()-v[v.size()-1]-1);
		cout<<ho<<endl<<tendem<<endl<<ten;
	}
}
