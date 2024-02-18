#include <iostream>
using namespace std;

int check[100][100];
int n,m;
int val[100][100];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int iCount=1;
bool _check(int x, int y){
	return (x>=0 && x<n && y>=0 && y<m && check[x][y]!=0);
}
void run(int x, int y){
	int _x=x,_y=y;
	if(iCount>n*m){
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				cout<<val[i][j]<<' ';
			}
			cout<<endl;
		}
	}else{
		for(int i=0; i<4; i++){
			_x=_x+dx[i];
			_y=_y+dy[i];
			while(_check(_y,_x)){
				val[_y][_x]=iCount++;
				check[_y][_x]=0;
				_x=_x+dx[i];
				_y=_y+dy[i];
			}
			_x-=dx[i];
			_y-=dy[i];
		}
		run(_x,_y);
	}
}
int main(){
	cin>>n>>m;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			check[i][j]=1;
	check[0][0]=0;
	val[0][0]=iCount;
	iCount++;
	run(0,0);
}


