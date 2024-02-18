#include <iostream>
#include <cmath>
using namespace std;
long long value[100][100];
int main(){
    int n,a;
    cin>>n>>a;
    for(int i=n-1; i>=0; i--){
        for(int j=n-1; j>=0; j--){
            value[i][j]=a;
            a++;
        }
    }
    for(int i=1; i<n; i+=2){
        for(int j=0; j<n; j++){
            cout<<value[j][i]<<' ';
        }
        cout<<endl;
    }
    int maxcol,minval;
    if(n-1%2==0) maxcol=n-2;
    else maxcol=n-1;
    minval=value[0][maxcol];
    for(int i=1; i<n; i++){
        if(value[i][maxcol]%2!=0&&value[i][maxcol]<minval){
            minval=value[i][maxcol];
        }
    }
    if(minval%2!=0) cout<<minval<<endl;
    else cout<<"NULL"<<endl;
    int tong=0;
    for(int i=0; i<n; i+=(n-1)){
        for(int j=0; j<n; j+=(n-1)){
            if(value[i][j]%2==0)
                tong+=value[i][j];
        }
    }
    cout<<tong;
}
