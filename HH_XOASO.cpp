#include <sstream>
#include <iostream>
using namespace std;

int main(){
	int n,iCount=0;
	cin>>n;
	for(int i=3; i<=n-2; i++){
		for(int j=i+1; j*j+i*i<=n*n; j++){
			for(int t=j+1; t<=n; t++){
				if(i*i+j*j==t*t){
					cout<<i<<' '<<j<<' '<<t<<endl;
					iCount++;
				}
			}
		}
	}
	if(iCount==0) cout<<-1;
	
}
