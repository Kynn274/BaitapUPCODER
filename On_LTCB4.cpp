#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

int main(){
	string s;
	int iC=0;
	
	cin>>s;
	
	for(int i=0; i<s.size(); i++){
		iC++;
		if(s[i]!=s[i+1]){
			s.insert(i,to_string(iC));
			iC=0;
			i++;
		}
	}
	
	for(int i=0; i<s.size(); i++){
		if('a'<=s[i]&& s[i]<='z' || 'A'<= s[i]&&s[i] <='Z'){
			if('a'<=s[i+1]&& s[i+1]<='z' || 'A'<= s[i+1] && s[i+1] <='Z'){
				s.erase(i+1,1);
				i--;
			}
		}
		
	}
	if('a'<=s[0]&& s[0]<='z' || 'A'<= s[0]&&s[0] <='Z') s.erase(0,1);
	cout<<s;
}
