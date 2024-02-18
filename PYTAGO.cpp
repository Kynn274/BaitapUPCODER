#include <cmath>
#include <iostream>

using namespace std;

int main(){
	int n,iCount=0;
	cin>>n;
	if(n<=4)cout<<-1;
	else{
		for(int i=3; i<n; i++){
			for(int j=i+1; j<n; j++){
				int t=sqrt(i*i+j*j);
				if(i*i+j*j==t*t&& t<=n){
					cout<<i<<' '<<j<<' '<<t<<endl;
				}
			}
		}
	}
}
