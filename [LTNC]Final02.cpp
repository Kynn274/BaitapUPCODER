#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
using namespace std;

int main(){
	string s;
	char c;
	
	cin>>s>>c;
	
	while(s[0]==c) s.erase(0,1);
	while(s[s.size()-1]==c) s.erase(s.size()-1,1);
	
	for(int i=0; i<s.size(); i++){
		if(s[i]==c&&s[i+1]==c){
			s.erase(i+1,1);
			i--;
		}
	}
		
	vector<int> v;
	for(int i=0; i<s.size(); i++)
		if(s[i]==c) v.push_back(i);
	
	string tmp;
	vector<string> v1;
	tmp=s.substr(0,v[0]);
	v1.push_back(tmp);
	
	for(int i=0; i<v.size()-1; i++){
		tmp.clear();
		tmp=s.substr(v[i]+1,v[i+1]-v[i]-1);
		v1.push_back(tmp);
	}
	v1.push_back(s.substr(v[v.size()-1]+1,s.size()));
	cout<<v1.size()<<endl;
	for(int i=0; i<v1.size(); i++) cout<<v1[i]<<endl;
}
