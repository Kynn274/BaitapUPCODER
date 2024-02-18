#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;
bool kt(string a){
	transform(a.begin(),a.end(),a.begin(),::tolower);
	for(int i=0; i<a.size(); i++){
		if(a[i]<'0'||a[i]>'9'&&a[i]<'A'||a[i]>'Z'&&a[i]<'a'||a[i]>'z'){
			a.erase(i,1);
			i--;
		}
	}
	int len=a.size()/2;
	for(int i=0; i<len; i++){
		if(a[i]!=a[a.size()-1-i]) return false;
	}
	return true;
}
int main(){
	string a;
	getline(cin,a);
	if(kt(a)) cout<<"YES";
	else cout<<"NO";
}
