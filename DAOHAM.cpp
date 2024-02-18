#include <iostream>
#include <cmath>
using namespace std;

void nhap(int &k, int a[], int b[], float&x){
	cin>>k;
	for(int i=0; i<k; i++) cin>>a[i];
	for(int i=0; i<k; i++) cin>>b[i];
	cin>>x;
}
 void xuat_x(int mu){
	if(mu>0){
		if(mu==1) cout<<"x";
		else cout<<"x^"<<mu;
	}
}
void xuat_heso(int hs){
	if(hs!=0){
		if(hs<0){
			cout<<" - ";
			if(abs(hs)!=1) cout<<abs(hs);
		}else{
			cout<<" + ";
			if(abs(hs)!=1) cout<<abs(hs);
		}
	}
}

void xuat(int k, int a[], int b[]){
	int i=0;
	while(a[i]==0||b[i]<0){
		i++;
	}
	if(a[i]!=0) 
		if(b[i]!=0){
			if(a[i]!=1)cout<<a[i];
		}else cout<<a[i];
	xuat_x(b[i]);
	
	i++;
	for(i; i<k; i++){
		if(b[i]>=0 && a[i]!=0){
			xuat_heso(a[i]);
			xuat_x(b[i]);
		}
	}
}

float tinh(int k, int a[], int b[], float x ){
	float tong=0;
	float tich;
	for(int j=0; j<k; j++){
		tich=1;
		for(int i=0; i<b[j]; i++){
			tich*=x;
		}
		tong+=(a[j]*tich);
	}
	return tong;
}

void daoham(int k, int a[], int b[]){
	for(int i=0; i<k; i++){
		a[i]=a[i]*b[i];
		b[i]--;
	}
}
bool check(int k, int a[], int b[]){
    bool _check=false;
    for(int i=0; i<k ; i++) if(a[i]!=0) _check=true;
    return _check;
}
int main(){
	int k,a[100],b[100];
	float x;
	nhap(k,a,b,x);
	if(check(k,a,b)){
	    xuat(k,a,b);
	    cout<<endl;
	    cout<<tinh(k,a,b,x)<<endl;
	    daoham(k,a,b);
	    if(k==1&&b[0]<0) cout<<0;
	    else{
	        xuat(k,a,b);
	    }
	}
	else{
	    cout<<0<<endl;
	    cout<<0<<endl;
	    cout<<0;
	}
	
}
