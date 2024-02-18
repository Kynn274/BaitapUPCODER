#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,k,max=0,premax=-1,min,min1;
    cin>>n>>k;
    int a[100];
    for(int i=0; i<n; i++){
        cin>>a[i];
        if(a[i]>max) max=a[i];
    }
    min=max;
    for(int i=0; i<n; i++){
        if(a[i]>premax&&a[i]<max) premax=a[i];
    }
    if(premax==-1) cout<<-1<<endl;
    else{
        for(int i=0; i<n; i++) if(a[i]==premax) cout<<i<<' ';
        cout<<endl;
    }
    max=-1;
    for(int i=0; i<n; i++) if(a[i]>max&&a[i]<=k) max=a[i];
    if(max==-1) cout<<max<<endl;
    else{
    for(int i=n-1;i>=0; i--)
        if(max==a[i]){
            cout<<i<<endl;
            break;
        }
    }
    if(min<=k) cout<<"00";
    else{
		int tmp=min;
		int iCount=-1;
		while(iCount!=0){
			iCount=0;
			for(int i=0; i<n; i++){
				if(a[i]<min&&a[i]>k){
					min=a[i];
					iCount++;
				}
			}
			for(int i=0; i<n; i++)
				if(a[i]==min){
				    cout<<min<<' ';
				    a[i]=0;
				}
			min=tmp;
		}
    }
    
}
