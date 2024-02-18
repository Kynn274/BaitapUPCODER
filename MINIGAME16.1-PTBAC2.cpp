#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main(){
	double a,b,c;
	cin>>a>>b>>c;
	double tmp1=-b;
	if(a==0){
		if(b==0){
			if(c==0) cout<<-1;
			else cout<<0;
		}else{
			cout<<1<<endl;
			if(c==0 && b>0)cout<<fixed<<setprecision(10)<<(double(c/b));
			else cout<<fixed<<setprecision(10)<<-(double(c/b));
		}
	} 
	else{
		double delta=double(b*b-4*a*c);
		if(delta<0) cout<<0;
		else{
			if(delta==0){
				cout<<1<<endl;
				double x=double(tmp1/(2*a));
				if(x==0) cout<<fixed<<setprecision(10)<<double(0);
				else cout<<fixed<<setprecision(10)<<x;
			}else{
			    cout<<2<<endl;
				double x1=double(tmp1+sqrt(delta))/(2*a);
				double x2=double(tmp1-sqrt(delta))/(2*a);
				if(a>=0){
				    if(x2==0)cout<<fixed<<setprecision(10)<<double(0)<<endl;
				    else cout<<fixed<<setprecision(10)<<x2<<endl;
				    if(x1==0)cout<<fixed<<setprecision(10)<<double(0);
				    else cout<<fixed<<setprecision(10)<<x1;
				}else{
				    if(x1==0)cout<<fixed<<setprecision(10)<<double(0)<<endl;
				    else cout<<fixed<<setprecision(10)<<x1<<endl;
				    if(x2==0)cout<<fixed<<setprecision(10)<<double(0);
				    else cout<<fixed<<setprecision(10)<<x2;
				}
				
			}
		}
	}
}
