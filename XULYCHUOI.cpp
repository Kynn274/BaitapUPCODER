#include <bits/stdc++.h>
#define fmax 1006
#define MOD 1000000007
#define ll long long
using namespace std;

struct person{
  string full_in4;
  ll money;
};

istream & operator>>(istream & is, person & p){
  getline(is, p.full_in4);
  ll v;
  ll len = p.full_in4.size();
  for(ll i = len - 1; i >= 0; i--)
    if(p.full_in4[i] == ' '){
      v = i;
      break;
    }
  p.money = stoll(p.full_in4.substr(v + 1, len - v - 1));
  return is;
}

ostream & operator<<(ostream & os, person p){
  os << p.full_in4;
  return os;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  ll n, iC(0);
  person a[fmax];
  person tmp;
  cin >> n;
  cin.ignore();
  
  for(ll i = 0; i < n; i++){
    cin >> a[i];
    if(a[i].money >= 0)
      iC ++;
  }
  
  cout << iC << '\n';
  tmp = a[0];
  for(ll i = 1; i < n; i++)
    if(a[i].money > tmp.money)
      tmp = a[i];
  cout << tmp;
 
  return 0;
}
