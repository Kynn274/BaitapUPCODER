#include <iostream>
using namespace std;

int main(){
	int n,m,max=-1e9;
	cin>>n>>m;
	int a[100][100];
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++){
			cin>>a[i][j];
			if(a[i][j]>max) max=a[i][j];
		}
	cout<<max;
}
