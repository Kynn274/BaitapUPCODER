#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Mang{
  int a[1000];
  int n;
  int& operator[](int x){
    return a[x];
  }
  void operator=(Mang p){
    n = p.n;
    for(int i = 0; i < n; i++)
      a[i] = p[i];
  }
};

istream & operator>>(istream & is, Mang & p){
  is >> p.n;
  for(int i = 0; i < p.n; i++) is >> p[i];
  return is;
}

ostream & operator<<(ostream & os, Mang p){
  for(int i = 0; i < p.n; i++) os << p[i] << ' ';
  return os;
}

void add(int n, Mang & p){
  while(p.n < n){
    p[p.n] = 0;
    p.n ++;
  }
}

Mang operator+(Mang a, Mang b){
  Mang p;
  if(a.n < b.n) add(b.n, a);
  else if(b.n < a.n) add(a.n, b);
  
  p.n = a.n;
  for(int i = 0; i < p.n; i++)
    p[i] = a[i] + b[i];
  
  return p;
}

Mang operator-(int k, Mang p){
  for(int i = 0; i < p.n; i++)
    p[i] = k - p[i];
  return p;
}
int main(){
  Mang a, b;
  cin >> a >> b;
  
  Mang _a = a, _b = b;
  cout << _a +  _b << endl;
  
  a = 0 - a;
  b = 0 - b;
  cout << a << endl << b << endl;
  cout << a + b;
  
  return 0;
}
