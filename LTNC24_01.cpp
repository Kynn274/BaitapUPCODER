#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct PhanSo{
  int tu, mau;
  void operator = (PhanSo p){
    tu = p.tu;
    mau = p.mau;
  }
};

int ucln(PhanSo p){
  int r;
  while(p.mau != 0){
    r = p.tu % p.mau;
    p.tu = p.mau;
    p.mau = r;
  }
  return p.tu;
}

void rg (PhanSo & p){
  int u = ucln(p);
  p.tu /= u;
  p.mau /= u;
}

istream & operator>>(istream & is, PhanSo & p){
  is >> p.tu >> p.mau;
  return is;
}

ostream & operator<<(ostream & os, PhanSo p){
  rg(p);
  if(p.mau < 0) os << -1 * p.tu << '/' << -1 * p.mau;
  else os << p.tu << '/' << p.mau;
  return os;
}

PhanSo operator+(PhanSo a, PhanSo b){
  PhanSo p;
  p.mau = a.mau * b.mau;
  p.tu  = a.mau * b.tu + a.tu * b.mau;
  return p;
}

PhanSo operator-(PhanSo a, PhanSo b){
  PhanSo p;
  p.mau = a.mau * b.mau;
  p.tu  = b.mau * a.tu - b.tu * a.mau;
  return p;
}

PhanSo operator*(PhanSo a, PhanSo b){
  PhanSo p;
  p.mau = a.mau * b.mau;
  p.tu  = b.tu  * a.tu ;
  return p;
}

PhanSo operator/(PhanSo a, PhanSo b){
  PhanSo p;
  p.mau = a.mau * b.tu ;
  p.tu  = a.tu  * b.mau;
  return p;
}



int main(){
  PhanSo a[1000];
  int n = 0;
  
  while(cin >> a[n]) n++;
  PhanSo tong = a[0];
  PhanSo hieu = a[0];
  PhanSo tich = a[0];
  PhanSo thuong = a[0];
  
  for(int i = 0; i < n - 1; i++){
    cout << a[i] << ' ';
    tong   = tong   + a[i + 1];
    hieu   = hieu   - a[i + 1];
    tich   = tich   * a[i + 1];
    thuong = thuong / a[i + 1];
    rg(tong);
    rg(hieu);
    rg(tich);
    rg(thuong);
  }
  cout << a[n - 1] << endl << tong << endl << hieu << endl << tich << endl << thuong;
  return 0;
}
