#include <iostream>
using namespace std;

int iCount=1;
int m,n;
int val[100][100];
int main(){
	cin>>n>>m;
	int x=0,y=0;
	while(iCount<=n*m){
		for(int i=0; i<m; i++){
			val[x][y]=iCount++;
			y++;
		}
		x++;
		y--;
		if(iCount<n*m){
			for(int i=0; i<m; i++){
				val[x][y]=iCount++;
				y--;
			}
			x++;
			y++;
		}	
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++)
			cout<<val[i][j]<<' ';
		cout<<endl;
	}
}
