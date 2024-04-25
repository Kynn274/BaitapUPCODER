#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct dothi{
  int sodinh;
  int a[100][100];
};

void nhap(dothi & g, int & b, int & e){
  int canh;
  int _b, _e;
  cin >> g.sodinh >> canh >> b >> e;
  
  vector<int> tmp;
  for(int i = 0; i < canh; i++){
    for(int j = 0; j < canh; j++)
      g.a[i][j] = 0;
  }
  
  for(int i = 0; i < canh; i++){
    cin >> _b >> _e;
    g.a[_b - 1][_e - 1] = 1;
    g.a[_e - 1][_b - 1] = 1;
  }
}

void xuat(dothi g){
  cout << g.sodinh << endl;
  for(int i = 0; i < g.sodinh; i++){
    for(int j = 0; j < g.sodinh; j++)
      cout << g.a[i][j] << ' ';
    cout << endl;
  }
}

int Shortest_path(dothi g, int b, int e){
  vector<bool> check(g.sodinh, 0);
  check[b - 1] = 1;
  
  vector<int> L(g.sodinh, 1e9);
  vector<int> K(g.sodinh);
  
  L[b - 1] = K[b - 1] = 0;
  int point = b - 1;
  
  for(int i = 1; i < g.sodinh - 1; i++){
    for(int j = 0; j < g.sodinh; j++){
      if(check[j] == 0){
        if(g.a[point][j] != 0){
          int tmp = L[j];
          L[j] = min (L[j], L[point] + g.a[point][j]);
          if(L[j] != tmp) K[j] = point;
        }
      }
    }
    
    int tmp = 1e9;
    int v;
    for(int j = 0; j < g.sodinh; j++){
      if(L[j] < tmp && check[j] == 0 && j != point){
        tmp = L[j];
        v = j;
      }
    }
    point = v;
    check[point] = 1;
  }
  
  return L[e - 1];
} 

int main() {
    int b, e;
    dothi g;
    nhap(g, b, e);
    cout << Shortest_path(g, b, e);
    
    return 0;
}
