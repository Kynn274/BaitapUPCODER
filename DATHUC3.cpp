#include <iostream>
using namespace std;

struct BacHai{
	int a,b,c;
};
istream & operator>>(istream & is, BacHai & f){
	is>>f.a>>f.b>>f.c;
	return is;
}
ostream & operator<<(ostream & os, BacHai f){
	os<<f.a<<"x^2"<<'+'<<f.b<<"x+"<<f.c;
	return os;
}
double tinh(BacHai f,int x){
	return f.a*x*x+f.b*x+f.c;
}
BacHai operator+(BacHai a, BacHai b){
	BacHai f;
	f.a=a.a+b.a;
	f.b=a.b+b.b;
	f.c=a.c+b.c;
	return f;
}
bool operator==(BacHai f1, BacHai f2){
	return f1.a==f2.a&&f1.b==f2.b&&f1.c==f2.c;
}
struct BacNhat{
	int a,b;
};
istream & operator>>(istream & is, BacNhat & p){
	is>>p.a>>p.b;
	return is;
}
ostream & operator<<(ostream & os, BacNhat p){
	os<<p.a<<"x+"<<p.b;
	return os;
}
double tinh(BacNhat f, int x){
	return f.a*x+f.b;
}
BacHai operator*(BacNhat f1, BacNhat f2){
	BacHai f;
	f.a=f1.a*f2.a;
	f.b=f1.a*f2.b+f1.b*f2.a;
	f.c=f1.b*f2.b;
	return f;
}
int main(){
	BacHai f1,f2;
	BacNhat f3,f4;
	int x;
	cin>>f1>>f2>>f3>>f4>>x;
	cout<<f1<<endl<<tinh(f1,x)<<endl;
	cout<<f2<<endl<<tinh(f2,x)<<endl;
	BacHai f5;
	f5=f1+f2;
	cout<<f5<<endl<<tinh(f5,x)<<endl;
	BacHai f6;
	f6=f3*f4;
	cout<<'('<<f3<<")*("<<f4<<")="<<f6<<endl<<tinh(f6,x)<<endl;
	if(f1==f6){
		if(f2==f6) cout<<"TRUE3";
		else cout<<"TRUE1";
	}else{
		if(f2==f6) cout<<"TRUE2";
		else cout<<"FALSE";
	}
	return 0;
}
