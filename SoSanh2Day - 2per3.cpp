#include <bits/stdc++.h>
#define fmax 1002
#define ll long long
using namespace std;

string a, b;
ll f[fmax][fmax];
ll a1[fmax];
ll b1[fmax];
bool c1[fmax];
ll n1(0), m1(0);

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  getline(cin, a);
  getline(cin, b);
  
  ll m = a.size(); 
  ll n = b.size();
  ll _min = 100000;
  bool tick = 0;
  
  for(ll i = 0; i < m; i++)
    if(a[i] == ',') a[i] = ' ';
  
  for(ll i = 0; i < n; i++)
    if(b[i] == ',') b[i] = ' ';
  
  stringstream ss;
  ss << a;
  while(ss >> a1[m1]){
    m1++;
  }
  
  ss.clear();
  ss << b;
  while(ss >> b1[n1]){
    n1++;
  }
  
  for(ll i = 1; i <= n1; i++)
    for(ll j = 1; j <= m1; j++){
      if(a1[j - 1] == b1[i - 1]) f[i][j] = 1;
      else f[i][j] = 0;
      f[i][j] = max(f[i - 1][j], f[i][j]);
    }
    
  for(ll j = 1; j <= m1; j++)
    if(f[n1][j] == 0){
      _min = min (_min, a1[j - 1]);
      tick = 1;
    }

  if(tick == 0) 
    cout << "khong co\n";
  else 
    cout << _min << '\n';
  
  string s = "";
  ll danhdau = 0;
  ll iC = 0;
  
  for(ll j = 1; j <= m1; j++)
    if(f[n1][j] == 1 && c1[a1[j - 1]] == 0){
      s += to_string(a1[j - 1]) + ",";
      danhdau = j + 1;
      c1[a1[j - 1]] = 1;
      iC ++;
    }
    
  if(iC == 0) cout << "khong co";
  else{
    s.resize(s.size() - 1);
    cout << iC << '\n';
    cout << s << '\n';
  }
  return 0;
}

