#include <iostream>
using namespace std;

int main(){
	int a[100],iCount=0,tong=0;
	while(cin>>a[iCount]){
		tong+=a[iCount];
		iCount++;
	}
	for(int i=0; i<iCount-1; i++){
		for(int j=i+1; j<iCount; j++){
			if(a[j]<a[i]) swap(a[i],a[j]);
		}
	}
	if(iCount<3) cout<<"NO";
	else{
		cout<<iCount<<endl<<tong<<endl;
		for(int i=0; i<iCount; i++) cout<<a[i]<<' ';
	}
}
