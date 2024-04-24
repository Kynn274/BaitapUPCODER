#include <iostream>
using namespace std;

int main(){
	int n;
	int tong=0;
	string s;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>s;
		if(s=="X++") tong++;
		if(s=="++X") ++tong;
		if(s=="X--") tong--;
		if(s=="--X") --tong;
	}
	cout<<tong;
}
