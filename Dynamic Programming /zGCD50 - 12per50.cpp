#include <bits/stdc++.h>
#define MOD 1000000007
#define fmax 1000006
#define ll long long
using namespace std;

ll n, q;
ll a[fmax], b[fmax];
ll minucln, maxbcnn;
ll minpoint, maxpoint;
ll iC;

ll gcd(ll a, ll b){
  ll r;
  while(b != 0){
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}

ll biendoi(ll n, ll i){
  ll ucln1 = gcd(n, a[i]);
  ll ucln2 = gcd(ucln1, b[i]);
  return ucln1 * b[i] / ucln2;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> q;
  for(ll i = 0; i < q; i++) cin >> a[i] >> b[i];
  
  iC = q;
  while(iC){
    maxbcnn = -1e9;
    ll tmp;
    for(ll i = 0; i < q; i++)
      if(a[i] != -1){
        tmp = maxbcnn;
        maxbcnn = max(maxbcnn, biendoi(n, i));
        if(maxbcnn != tmp)
          maxpoint = i;
      }
    
    if(maxbcnn <= n) break;
    else n = max(maxbcnn, n);
    a[maxpoint] = -1;
    iC--;
  }
  cout << n;
  return 0;
}
