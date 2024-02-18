#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double d,s,e;
    cin>>d>>s>>e;
    if(d<0 || s<8 || s>23 || e<9 || e>24 || s>e) cout<<-1;
    else{
        //dong cua truoc 17h
        if(e<=17){
        	if(e-s<=3){
        		cout<<d*(e-s)*0.9;
        	}else{
        		cout<<d*(3+(e-s-3)*0.7)*0.9;
			}
		}else if(s>=17){
			if(e-s<=3){
        		cout<<d*(e-s);
        	}else{
        		cout<<d*(3+(e-s-3)*0.7);
			}
		}else if(s<17 && e>17){
			if(e-s<=3){
				cout<<d*((17-s)*0.9+(e-17));
			}else{
				if(e-s>3){
					if(17-s>3){
						cout<<d*(3*0.9+((17-s-3)*0.9+(e-17))*0.7);
					}else{
						cout<<d*((17-s)*0.9+(s+3-17)+(e-s-3)*0.7);
					}
				}
			}
		}
    }
}
