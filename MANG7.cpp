#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int n,a[100][100];
	cin>>n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>a[i][j];
		}
	}
	for(int i=0; i<n; i++){
		cout<<a[i][i]<<' ';
	}
}
