#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool e=true;
int n;
int v[100][100];
int v_n=1;
int v_len;
int a[100];
int a_len=0;

int tinh(int i){
	int tong=0;
	for(int j=v_len-1; j>=0; j--){
		tong+=v[v_n-1][v_len-j-1]*pow(i,j);
	}
	return tong;
}
void tru_da_thuc(){
	v_n++;
	for(int i=0; i<v_len-1; i++){
		v[v_n-1][i]=v[v_n-2][i];
		v[v_n-2][i+1]=v[v_n-2][i+1]+a[a_len-1]*v[v_n-2][i];
	}
	v_len--;
}
void test(int &k){
	if(tinh(k)==0){
		a[a_len++]=k;
		tru_da_thuc();
		k=-1;
	}
}
void xuat_nghiem(bool e){
	for(int i=0; i<a_len-1; i++){
		for(int j=i+1; j<a_len; j++){
			if(a[j]>a[i]) swap(a[i],a[j]);
		}
	}
	if(a_len>0){
		if(e==false){
			if(a[0]<0)cout<<"(-x-"<<abs(a[0])<<')';
			else if(a[0]==0) cout<<'x';
			else if(a[0]>0) cout<<"(-x+"<<abs(a[0])<<')';
		}else{
			if(a[0]<0)cout<<"(x+"<<abs(a[0])<<')';
			else if(a[0]==0) cout<<'x';
			else if(a[0]>0) cout<<"(x-"<<abs(a[0])<<')';
		}
	}
	for(int i=1; i<a_len; i++){
		if(a[i]<0)cout<<"(x+"<<abs(a[i])<<')';
		else if(a[i]==0) cout<<'x';
		else if(a[i]>0) cout<<"(x-"<<abs(a[i])<<')';
	}
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
			cout<<"-";
			if(abs(hs)!=1) cout<<abs(hs);
		}else{
			cout<<"+";
			if(abs(hs)!=1) cout<<abs(hs);
		}
	}
}

void xuat_dt(int tmp[], int k){
	int j=0;
	while(tmp[j]==0 && j<=k+1){
		j++;
	}
	if(k-j<0) cout<<0;
	else{
		if(k-j==0){
		if(tmp[j]!=0) cout<<tmp[j];
	}else{
		if(tmp[j]!=1){
			if(tmp[j]==-1){
				cout<<'-';
			}else cout<<tmp[j];
		}
		xuat_x(k-j);
	}
	j++;
	for(j; j<=k; j++){
		if(k-j>=0 && tmp[j]!=0){
			if(k-j!=0){
				xuat_heso(tmp[j]);
				xuat_x(k-j);
			}else{
				if(tmp[j]>0) cout<<'+'<<tmp[j];
				else if(tmp[j]<0) cout<<'-'<<abs(tmp[j]);
			}
		}
	}
	}
	
}
int main(){
	int b[100];
	cin>>n;
	int i;
	for(i=0; i<n+1; i++){
		cin>>v[0][i];
		b[i]=v[0][i];
	}
	v[0][i]=v[0][i];
	v_len=n+1;
	while(b[0]==0&&v[0][0]==0&&n!=0){
		for(i=1; i<v_len; i++){
			b[i-1]=b[i];
			v[0][i-1]=v[0][i];
		}
		v_len--;
		n--;
	}
	if(b[0]<0){
		e=false;
		for(int i=0; i<v_len; i++){
			v[0][i]*=-1;
		}
	}
	if(n==0){
		cout<<b[0]<<"=("<<b[0]<<")";
	}else{
		for(int i=-10; i<=10; i++){
			test(i);
			if(a_len==n){
				break;
			}
		}
		xuat_dt(b,n);
		cout<<'=';
		xuat_nghiem(e);
		if(a_len<n){
			cout<<'(';
			xuat_dt(v[v_n-1],v_len-1);
			cout<<")";
			
		}
	}	
}
