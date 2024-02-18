#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string wine[]={"ABSINTH", "TEQUILA", "VODKA", "WHISKEY", "WINE", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE"};
bool isWine(string a){
	for(int i=0; i<11; i++) 
		if(a==wine[i]) 
			return true;
	return false;
}
bool isNum(string a){
	for(int i=0; i<a.size(); i++){
		if(a[i]>'9'||'0'>a[i]) 
			return false;
	}
	return true;
}
int main(){
	int n,iCount=0,tmp;
	string a[100];
	cin>>n;
	stringstream ss;
	for(int i=0; i<n; i++) 
		cin>>a[i];
	for(int i=0; i<n; i++){
		if(isWine(a[i])) 
			iCount++;
		else{
			if(isNum(a[i])){
				ss<<a[i];
				ss>>tmp;
				ss.clear();
				if(tmp<18) iCount++;
			}
		}
	}
	cout<<iCount;
}
