#include <iostream>
using namespace std;

struct Ham{
	int n;
	int a[1000];
};
istream & operator>>(istream & is, Ham&f){
	is>>f.n;
	for(int i=0; i<f.n+1; i++) cin>>f.a[i];
	return is;
}
ostream & operator<<(ostream & os, Ham f){
	if(f.n!=0){
		if(f.n>0){
		if(f.n==1){
			if(f.a[0]==1) os<<"x";
			if(f.a[0]>1) os<<f.a[0]<<"x";
			if(f.a[0]==-1) os<<"-x";
			if(f.a[0]<-1) os<<f.a[0]<<"x";
		}else{
			if(f.a[0]==1) os<<"x^"<<f.n;
			if(f.a[0]>1) os<<f.a[0]<<"x^"<<f.n;
			if(f.a[0]==-1) os<<"-x^"<<f.n;
			if(f.a[0]<-1) os<<f.a[0]<<"x^"<<f.n;
		}
		}else{
			os<<0;
		}
	}else{
		os<<f.a[0];
	}
	for(int i=1; i<=f.n; i++){
		if(f.a[i]!=0){
			if(f.n-i!=0){
				if(f.n-i==1){
					if(f.a[i]==1) os<<"+x";
					if(f.a[i]>1) os<<'+'<<f.a[i]<<"x";
					if(f.a[i]==-1) os<<"-x";
					if(f.a[i]<-1) os<<f.a[i]<<"x";
				}else{
					if(f.a[i]==1) os<<"+x^"<<f.n-i;
					if(f.a[i]>1) os<<'+'<<f.a[i]<<"x^"<<f.n-i;
					if(f.a[i]==-1) os<<"-x^"<<f.n-i;
					if(f.a[i]<-1) os<<f.a[i]<<"x^"<<f.n-i;
				}
			}else{
				if(f.a[i]>=1) os<<'+'<<f.a[i];
				if(f.a[i]<=-1) os<<f.a[i];
			}
		}
	}
	return os;
}
void daoham(Ham&f){
	for(int i=0; i<=f.n; i++){
		f.a[i]*=(f.n-i);
	}
	f.n--;
}
void xuly(Ham& f){
	while(f.a[0]==0){
		for(int i=1; i<f.n+1; i++){
			f.a[i-1]=f.a[i];
		}
		f.n--;
	}
}
int main(){
	Ham a;
	cin>>a;
	xuly(a);
	cout<<a<<endl;
	daoham(a);
	cout<<a<<endl;
	daoham(a);
	cout<<a;
}
