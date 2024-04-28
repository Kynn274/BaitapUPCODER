#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n;

int duyet_row(vector<vector<int> > v){
  int  dem = 0;
  int _max = -1e9;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++)
      if(v[i][j] == 1) dem++;
      else{
        _max = max(_max, dem);
        dem = 0;
      }
    _max = max(_max, dem);
    dem = 0;
  }
  
  return _max;
}
int duyet_col(vector<vector<int> > v){
  int  dem = 0;
  int _max = -1e9;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(v[j][i] == 1) dem++;
      else{
        _max = max(_max, dem);
        dem = 0;
      }
    }
    _max = max(_max, dem);
    dem = 0;
  }
  return _max;
}
int duyet_left(vector<vector<int> > v){
  int  dem = 0;
  int _max = -1e9;
  
  int tmp = 0;
  int i, j;
  while(tmp < n){
    j = tmp++;
    i = 0;
    while(i < n && j < n){
      if(v[i++][j++] == 1) dem++;
      else{
        _max = max(_max, dem);
        dem = 0;
      }
    }
    _max = max(_max, dem);
    dem = 0;
  }
  
  tmp = 1;
  while(tmp < n){
    i = tmp++;
    j = 0;
    while(i < n && j < n){
      if(v[i++][j++] == 1) dem++;
      else{
        _max = max(_max, dem);
        dem = 0;
      }
    }
    _max = max(_max, dem);
    dem = 0;
  }
  return _max;
}
int duyet_right(vector<vector<int> > v){
  int  dem = 0;
  int _max = -1e9;
  
  int tmp = 0;
  int i, j;
  while(tmp < n){
    i = tmp++;
    j = 0;
    while(i >= 0 && j < n){
      if(v[i--][j++] == 1) dem++;
      else{
        _max = max(_max, dem);
        dem = 0;
      }
    }
    _max = max(_max, dem);
    dem = 0;
  }
  
  tmp = 1;
  while(tmp < n){
    j = tmp++;
    i = 0;
    while(j < n && i >= 0){
      if(v[i--][j++] == 1) dem++;
      else{
        _max = max(_max, dem);
        dem = 0;
      }
    }
    _max = max(_max, dem);
    dem = 0;
  }
  return _max;
}

int main() {
  cin >> n;
  vector<vector<int> > v(n, vector<int> (n));
  
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      cin >> v[i][j];
      
  int _max(-1e9);
  _max = max (_max, duyet_row(v));
  _max = max (_max, duyet_col(v));
  _max = max (_max, duyet_left(v));
  _max = max (_max, duyet_right(v));
  
  cout << _max;
  return 0;
}
