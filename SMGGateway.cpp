#include <iostream>
#include <string>
using namespace std;

struct slot{
	string id;
	string phone_num;
	string producer;
	void operator=(slot tmp){
		id=tmp.id;
		phone_num=tmp.phone_num;
		producer=tmp.producer;
	}
};

istream & operator>>(istream & is, slot&s){
	is>>s.id>>s.phone_num>>s.producer;
	return is;
}

ostream & operator<<(ostream & os, slot s){
	os<<s.id<<":"<<s.phone_num<<":"<<s.producer;
	return os;
}

int find(string num, slot a[], int n, slot b[]){
	int count=0;
	for(int i=0; i<n; i++){
		if(num[0]==a[i].phone_num[0] && num[1]==a[i].phone_num[1] && num[2]==a[i].phone_num[2]){
			b[count++]=a[i];
		}
	}
	return count;
}

int main(){
	int n;
	cin>>n;
	slot a[100];
	for(int i=0; i<n; i++) cin>>a[i];
	string num;
	cin>>num;
	slot b[100];
	int icount=find(num,a,n,b);
	for(int i=0; i<icount; i++){
		cout<<b[i]<<endl;
	}
	return 0;
}
