#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long m, n, num;
vector<long long> _left_x;
vector<long long> _left_y;
vector<long long> _right_x;
vector<long long> _right_y;

void get_left(long long m, long long n){
  long long tmp(0);
  while(tmp < n){
    _left_y.push_back(tmp);
    _left_x.push_back(0);
    tmp++;
  }

  tmp = 1;
  while(tmp < m){
    _left_x.push_back(tmp);
    _left_y.push_back(0);
    tmp++;
  }
}

void get_right (long long m, long long n){
  long long tmp(0);
  while(tmp < m){
    _right_x.push_back(tmp);
    _right_y.push_back(0);
    tmp++;
  }
  
  tmp = 1;
  while(tmp < n){
    _right_y.push_back(tmp);
    _right_x.push_back(m - 1);
    tmp++;
  }
}

bool find_string_row(string s, long long m, long long n, vector<vector<char> > v){
  string tmp = "", tmp1 = "", tmp2 = "";
  long long len = s.size();
  long long _x = -1;
  long long _y = -1;
  long long chieu = 0;
  
  for(long long i = 0; i < m; i++){
    for(long long j = 0; j < n; j++)
      tmp = tmp + v[i][j];
    for(long long j = 0; j <= n - len; j++){
      tmp1 = tmp.substr(j, len);
      tmp2 = tmp1;
      reverse(tmp2.begin(), tmp2.end());
      if(s == tmp1 || s == tmp2){
        _x = i;
        _y = j;
        if(s == tmp1) chieu = 1;
        else chieu = -1;
        break;
      }
    }

    if(_x != -1){
      cout << "YES\n";
      vector<long long> y;
      for(long long j = 0; j < len; j++)
        y.push_back(_y + j);
      if(chieu == 1)
        for(long long j = 0; j < len; j++)
          cout << '(' << _x + 1 << ',' << y[j] + 1 << ')' << ' ';
      else 
        for(long long j = len - 1; j >= 0; j--)
          cout << '(' << _x + 1 << ',' << y[j] + 1 << ')' << ' ';
      cout << endl;
      return true;
    }
    tmp.clear();
  }
  return false;
}

bool find_string_col(string s, long long m, long long n, vector<vector<char> > v){
  string tmp = "", tmp1 = "", tmp2 = "";
  long long len = s.size();
  long long _x = -1;
  long long _y = -1;
  long long chieu = 0;
  
  for(long long i = 0; i < n; i++){
    for(long long j = 0; j < m; j++)
      tmp = tmp + v[j][i];
    for(long long j = 0; j <= m - len; j++){
      tmp1 = tmp.substr(j, len);
      tmp2 = tmp1;
      reverse(tmp2.begin(), tmp2.end());
      if(s == tmp1 || s == tmp2){
        _x = j;
        _y = i;
        if(s == tmp1) chieu = 1;
        else chieu = -1;
        break;
      }
    }

    if(_x != -1){
      cout << "YES\n";
      vector<long long> x;
      for(long long j = 0; j < len; j++)
        x.push_back(_x + j);
      if(chieu == 1)
        for(long long j = 0; j < len; j++)
          cout << '(' << x[j] + 1 << ',' << _y + 1 << ')' << ' ';
      else 
        for(long long j = len - 1; j >= 0; j--)
          cout << '(' << x[j] + 1 << ',' << _y + 1 << ')' << ' ';
      cout << endl;
      return true;
    }
    tmp.clear();
  }
  return false;
}
  
bool find_string_left(string s, long long m, long long n, vector<vector<char> > v){
  long long size = _left_x.size();
  string tmp = "", tmp1 = "", tmp2 = "";
  long long len = s.size();
  long long _x = -1, _y = -1;
  long long chieu = 0;
  
  for(long long i = 0; i < size; i++){
    long long dong = _left_x[i], cot = _left_y[i];
    while(dong < m && cot < n)
      tmp = tmp + v[dong++][cot++];
    long long len1 = tmp.size();
    for(long long j = 0; j <= len1 - len; j++){
      tmp1 = tmp.substr(j, len);
      tmp2 = tmp1;
      reverse(tmp2.begin(), tmp2.end());
      if(s == tmp1 || s == tmp2){
        _x = _left_x[i];
        _y = _left_y[i];
        if(s == tmp1) chieu = 1;
        else chieu = -1;
        break;
      }
    }
    
    if(_x != -1){
      cout << "YES\n";
      vector<long long> x;
      vector<long long> y;
      for(long long j = 0; j < len; j++){
        x.push_back(_x + j);
        y.push_back(_y + j);
      }
      if(chieu == 1)
        for(long long j = 0; j < len; j++)
          cout << '(' << x[j] + 1 << ',' << y[j] + 1 << ')' << ' ';
      else 
        for(long long j = len - 1; j >= 0; j--)
          cout << '(' << x[j] + 1 << ',' << y[j] + 1 << ')' << ' ';
      cout << endl;
      return true;
    }
    tmp.clear();
  }
  return false;
}

bool find_string_right(string s, long long m, long long n, vector<vector<char> > v){
  long long size = _right_x.size();
  string tmp = "", tmp1 = "", tmp2 = "";
  long long len = s.size();
  long long _x = -1, _y = -1;
  long long chieu = 0;
  
  for(long long i = 0; i < size; i++){
    long long dong = _right_x[i], cot = _right_y[i];
    while(dong >= 0 && cot < n)
      tmp = tmp + v[dong--][cot++];
    long long len1 = tmp.size();
    for(long long j = 0; j <= len1 - len; j++){
      tmp1 = tmp.substr(j, len);
      tmp2 = tmp1;
      reverse(tmp2.begin(), tmp2.end());
      if(s == tmp1 || s == tmp2){
        _x = _left_x[i];
        _y = _left_y[i];
        if(s == tmp1) chieu = 1;
        else chieu = -1;
        break;
      }
    }
    
    if(_x != -1){
      cout << "YES\n";
      vector<long long> x;
      vector<long long> y;
      for(long long j = 0; j < len; j++){
        x.push_back(_x - j);
        y.push_back(_y + j);
      }
      if(chieu == 1)
        for(long long j = 0; j < len; j++)
          cout << '(' << x[j] + 1 << ',' << y[j] + 1 << ')' << ' ';
      else 
        for(long long j = len - 1; j >= 0; j--)
          cout << '(' << x[j] + 1 << ',' << y[j] + 1 << ')' << ' ';
      cout << endl;
      return true;
    }
    tmp.clear();
  }
  return false;
}
int main() {
  cin >> m >> n >> num;
  vector<vector<char> > v(m, vector<char>(n));
  vector<string> s(num);
  
  for(long long i = 0; i < m; i++)
    for(long long j = 0; j < n; j++)
      cin >> v[i][j];
      
  for(long long i = 0; i < num; i++)
    cin >> s[i];
  
  get_left (m, n);
  get_right(m, n);
  
  for(long long i = 0; i < num; i++){
    if(!find_string_row(s[i], m, n, v))
      if(!find_string_col(s[i], m, n, v))
        if(!find_string_left(s[i], m, n, v))
          if(!find_string_right(s[i], m, n, v))
            cout << "NO\n";
  }

  return 0;
}
