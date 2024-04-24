#include <iostream>
#include <cmath>
using namespace std;

int dx[]={1,2,2 ,1 ,-1,-2,-2,-1};
int dy[]={2,1,-1,-2,-2,-1,1 ,2};
int n;
int iC=0;

bool check[100][100];

void cre(){
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      check[i][j]=true;
}

bool kt(int x, int y){
  return (x>=0 && x<n && y>=0 && y<n && check[x][y]!=false);
}

void xuly(int k, int x, int y){
  cout<<x<<' '<<y<<' '<<k<<endl;
  if(k==n*n){
    iC++;
  }else{
    for(int i=0; i<8; i++){
      int _x=x+dx[i];
      int _y=y+dy[i];
      if(kt(_x, _y)){
        k++;
        check[_x][_y]=false;
        xuly(k, _x, _y);
        check[_x][_y]=true;
        k--;
      }
    }
  }
}
int main(){
  cin>>n;
  
  cre();
  
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      check[i][j]=false;
      xuly(0,i,j);
      cre();
    }
  }
  
  cout<<iC;
}
