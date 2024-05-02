#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Khach{
  string name;
  int number;
};

istream& operator>>(istream & is, Khach & p){
  is >> p.name >> p.number;
  return is;
}

void binary_search(vector<Khach> v, long s, long e, long number, string &str){
  int m = (s + e) / 2;
  
  if(m != s){
    binary_search(v, s, m, number, str);
    binary_search(v, m, e, number, str);
  }else{
    if(v[m].number == number) str = v[m].name;
  }

}

int main() {
  int n, number;
  cin >> n >> number;
  
  vector<Khach> v(n);
  for(int i = 0; i < n; i++) cin >> v[i];
  
  string s = "NO";
  binary_search(v, 0, n, number, s);
  cout << s;
  
  return 0;
}
