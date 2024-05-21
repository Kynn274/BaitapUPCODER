#include <bits/stdc++.h>
#define MOD 1000007 
#define fmax 1000006
#define ll long long
using namespace std;

ll n, k;
vector<ll> a;
unsigned long long f[fmax];

void merge(vector<ll> a1, vector<ll> a2, vector<ll> & a){
  ll m = a1.size();
  ll n = a2.size();
  ll i = 0, j = 0;
  a.clear();
  
  while(i < m && j < n)
    if(a1[i] < a2[j])
      a.push_back(a1[i++]);
    else 
      a.push_back(a2[j++]);
      
  while(i < m) a.push_back(a1[i++]);
  while(j < n) a.push_back(a2[j++]);
}

void mergeSort(vector<ll> & a){
  ll s = 0, e = a.size(), m = (s + e) / 2;
  
  if(m != s){
    vector<ll> a1;
    vector<ll> a2;
    for(ll i = s; i < m; i++) a1.push_back(a[i]);
    for(ll i = m; i < e; i++) a2.push_back(a[i]);
    
    mergeSort(a1);
    mergeSort(a2);
    merge(a1, a2, a);
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  ll x;
  cin >> n >> k;
  for(ll i = 0; i < n; i++){
    cin >> x;
    a.push_back(x);
  }
  mergeSort(a);
  
  f[0] = a[0];
  for(ll i = 1; i < n; i++)
    f[i] = f[i - 1] + a[i];
  if(k <= n - k) cout << f[n - 1] - f[k - 1] - f[k - 1];
  else cout << f[n - 1] - f[n - k - 1] - f[n - k - 1];
  return 0;
}
/*
Đúng 7/7
#######################
Thông tin chi tiết
test 1 :	0.006178s 			0 MB		 [đúng]
test 2 :	0.009160s 			0 MB		 [đúng]
test 3 :	0.011074s 			0 MB		 [đúng]
test 4 :	0.050542s 			0 MB		 [đúng]
test 5 :	0.450834s 			0 MB		 [đúng]
test 6 :	0.448898s 			0 MB		 [đúng]
test 7 :	0.433160s 			0 MB		 [đúng]
*/
