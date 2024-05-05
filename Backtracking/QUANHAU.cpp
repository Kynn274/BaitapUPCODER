#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

struct vitri{
  int x, y;
};

int n;
vector<vector<vitri> > v;
bool check[100][100];
bool luuvet[100][100];

void cre(){
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      check[i][j]=true;
      luuvet[i][j]=true;
    }
  }
}

void danh_dau(int x, int y, bool t){
  for(int i=0; i<n; i++){
    check[x][i]=t;
    check[i][y]=t;
  }
  
  int i=x, j=y;
  while(i<n && j<n) check[i++][j++]=t;
  i=x,j=y;
  while(i>=0 && j>=0) check[i--][j--]=t;
  i=x, j=y;
  while(i>=0 && j<n) check[i--][j++]=t;
  i=x, j=y;
  while(i<n && j>=0) check[i++][j--]=t;
}

bool kt(vitri a){
  return (a.x<n && a.x>=0 && a.y<n && a.y>=0 && check[a.x][a.y]!=0);
}

void xuat(vector<vitri> tmp){
  char table[100][100];
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      table[i][j]='.';
    }
  }
  for(int i=0; i<tmp.size(); i++){
    table[tmp[i].x][tmp[i].y]='Q';
  }
  
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cout<<table[i][j];
    }
    cout<<endl;
  }
  cout<<endl;
}

void xuly(vector<vitri> tmp, vitri a){
  if(tmp.size()==n){
    v.push_back(tmp);
    tmp.clear();
  }else{
    for(int i=0; i<n; i++){
      a.x=i;
      if(kt(a)){
        tmp.push_back(a);
        danh_dau(a.x,a.y,false);
        a.y++;
        xuly(tmp,a);
        a.y--;
        danh_dau(a.x,a.y,true);
        tmp.pop_back();
        if(tmp.size()!=0){
          for(int i=0; i<tmp.size(); i++){
            danh_dau(tmp[i].x, tmp[i].y, false);
          }
        }
      }
    }
  }
}


int main(){
  cin>>n;
  vector<vitri> tmp;
  
  vitri a;
  
  cre();
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
        a.x=i;
        a.y=j;
        tmp.push_back(a);
        danh_dau(a.x, a.y, false);
        a.y++;
        xuly(tmp,a);
        a.y--;
        tmp.pop_back();
        danh_dau(a.x, a.y, true);
      
    }
  }
  
  int iC = 0;
  for(int i=0; i<v.size(); i++){
    if(v[i].size()==n) iC++;
  }
  
  cout << iC;
}
