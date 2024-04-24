#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

struct item{
  long long len;
  long long point;
  vector<long long> v;
};

istream & operator>>(istream & is, item & p){
  string s;
  is >> s;
  
  for(long long i = 0; i < s.size(); i++)
    if(s[i] == '#') s[i] = ' ';
  
  stringstream ss;
  ss << s;
  
  ss >> p.len >> p.point;
  
  long long tmp;
  for(long long i = 0; i < p.len; i++){
    ss >> tmp;
    p.v.push_back(tmp);
  }
  
  return is;
}

int main() {
  string s;
  cin >> s;
  
  for(long long i = 0; i < s.size(); i++)
    if(s[i] == '#') s[i] = ' ';
  
  stringstream ss;
  ss << s;
  
  long long n, lech;
  ss >> n >> lech;
  
  item a[n + 1];
  vector<long long> ans(n + 1);
  
  for(long long i = 0; i < n; i++){
    cin >> a[i];
    ans[i] = a[i].v[a[i].point];
  }
  
  for(long long i = 0; i < n; i++){
    long long tmp = ans[i] - lech;
    while(tmp > 26) tmp -= 26;
    while(tmp < 1) tmp += 26;
    cout << char(tmp + 64);
  }
  
  return 0;
}
