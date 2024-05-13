#include <bits/stdc++.h>
#define fmax 1002
#define ll long long
using namespace std;

ll n;
ll f[10];
bool check = 0;

void xuly(ll i, vector<bool> b){
  if(i > n){
    for(ll j = 1; j <= n; j++)
      cout << f[j];
    cout << '\n';
  }else{
    for(ll j = 1; j <= n; j++){
      if(abs(f[i - 1] - j) > 1 && b[j] == 0){
        f[i] = j;
        b[j] = 1;
        xuly(i + 1, b);
        b[j] = 0;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  vector<bool> b(10, 0);
  
  cin >> n;
  f[0] = -1;
  xuly(1, b);
  
  return 0;
}

