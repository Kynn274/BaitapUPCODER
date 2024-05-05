#include <bits/stdc++.h>
#define fmax 1000006
using namespace std;

vector<vector<long long> > t(fmax);
vector<long long> f(fmax);
vector<long long> a(fmax);
long long n, w;

void xuat(long long ans){
  if(ans != 0)
    for(long long i = 0; i < t[ans].size(); i++)
      if(t[ans][i] == 0 && i % 2 != 0 || t[ans][i] != 0){
        if(i % 2 == 0) xuat(t[ans][i]);
        else cout << t[ans][i] << ' ';
      }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  long long ans = 0;
  
  cin >> n >> w;
  for(long long i = 0; i < n; i++)
    cin >> a[i];
  
  f[0] = 1;
  for(long long i = 0 ; i < n; i++){
    for(long long j = a[i]; j <= w; j++){
      if(a[i] <= j)
        if(j - a[i] != a[i]){
          f[j] += f[j - a[i]];
          if(f[j] != 0 && f[j - a[i]] != 0){
            t[j].push_back(j - a[i]);
            t[j].push_back(i);
          }
        }
      if(f[j] != 0) 
        ans = max(ans, j);
    }
  }
  
  cout << ans << endl;
  xuat(ans);
  return 0;
}
