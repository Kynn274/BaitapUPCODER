#include <iostream>
#include <string>
using namespace std;

struct team{
	string name;
	int like;
	int comment;
	int share;
	int overall;
	void operator=(team p){
		name=p.name;
		like=p.like;
		comment=p.comment;
		share=p.share;
		overall=p.overall;
	}
};

int main(){
	team a[100];
	string tmp;
	int i=0;
	while(cin>>tmp){
		if(tmp=="000"){
			break;
		}else{
			a[i].name=tmp;
			cin>>a[i].like>>a[i].comment>>a[i].share;
			a[i].overall=a[i].like+a[i].comment*2+a[i].share*3;
			i++;
		}		
	}
	for(int j=0; j<i-1; j++){
		for(int t=j+1; t<i; t++){
			if(a[j].overall<a[t].overall){
				swap(a[t],a[j]);
			}
		}
	}
	for(int i=0; i<3; i++){
		cout<<a[i].name<<endl;
	}
}
