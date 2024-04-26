#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int m, s;
  cin >> m >> s;
  
  string Max_num = "9";
  string Min_num = "1";
  if(m == 1 && s == 0){
    cout << "0 0";
    return 0;
  }
  
  while(Max_num.size() < m) Max_num = Max_num + "9";
  while(Min_num.size() < m) Min_num = Min_num + "0";
  
  int max_val = 9 * m;
  int min_val = 1;
  if(s < min_val || s > max_val){
    cout << "-1 -1";
    return 0;
  }
  
  max_val = max_val - s;
  min_val = s - min_val;
  
  int _max_n = max_val / 9;
  int _max_n1 = max_val % 9;
  int _min_n = min_val / 9;
  int _min_n1 = min_val % 9;
  
  int i = m - 1;
  for(int j = 0; j < _max_n; j++){
    Max_num[i] = '0';
    i--;
  }
  Max_num[i] -= _max_n1;
  i = m - 1;
  for(int j = 0; j < _min_n; j++){
    Min_num[i] = '9';
    i--;
  }
  Min_num[i] += _min_n1;
  
  cout << Min_num << ' ' << Max_num;
  
  return 0;
}
