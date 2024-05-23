#include <bits/stdc++.h>
#define MOD 1000000007
#define fmax 1003
#define ll long long
using namespace std;

ll n, m;
ll a[fmax][fmax];
ll b2[fmax][fmax];
ll b5[fmax][fmax];
ll f2[fmax][fmax];
ll f5[fmax][fmax];
bool checkzero[fmax][fmax];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  cin >> n >> m;
  for(ll i = 0; i < n; i++)
    for(ll j = 0; j < m; j++)
      cin >> a[i][j];
  
  for(ll i = 0; i < m; i++)
    if(a[0][i] == 0) checkzero[0][i] = 1;
    else checkzero[0][i] = checkzero[0][i - 1];
  
  for(ll i = 1; i < n; i++)
    if(a[i][0] == 0) checkzero[i][0] = 1;
    else checkzero[i][0] = checkzero[i - 1][0];
    
    
  for(ll i = 1; i < n; i++)
    for(ll j = 1; j < m; j++)
      if(a[i][j] == 0) checkzero[i][j] = 1;
      else checkzero[i][j] = max(checkzero[i - 1][j], checkzero[i][j - 1]);
  
  if(checkzero[0][0] == 1){
    cout << 1;
    return 0;
  }
  
  for(ll i = 0; i < n; i++)
    for(ll j = 0; j < m; j++){
      if(a[i][j] != 0){
        ll tmp = a[i][j];
        while(tmp % 10 == 0){
          b2[i][j]++;
          b5[i][j]++;
          tmp /= 10;
        }
        while(tmp % 2 == 0){
          b2[i][j]++;
          tmp /= 2;
        }
        while(tmp % 5 == 0){
          b5[i][j]++;
          tmp /= 5;
        }
      }
    }
  
  f2[0][0] = b2[0][0];
  f5[0][0] = b5[0][0];
  
  for(ll i = 1; i < n; i++){
    if(checkzero[i][0] == 1){
      if(a[i][0] == 0){
        f2[i][0] = 1;
        f5[i][0] = 1;
      }else{
        f2[i][0] = min(f2[i - 1][0] + b2[i][0], (long long) 1);
        f5[i][0] = min(f5[i - 1][0] + b5[i][0], (long long) 1);
      }
    }else{
      f2[i][0] = f2[i - 1][0] + b2[i][0];
      f5[i][0] = f5[i - 1][0] + b5[i][0];
    }
    
  }
  
  for(ll i = 1; i < m; i++){
    if(checkzero[0][i] == 1){
      if(a[0][i] == 0){
        f2[0][i] = 1;
        f5[0][i] = 1;
      }else{
        f2[0][i] = min(f2[0][i - 1] + b2[0][i], (long long) 1);
        f5[0][i] = min(f5[0][i - 1] + b5[0][i], (long long) 1);
      }
    }else{
      f2[0][i] = f2[0][i - 1] + b2[0][i];
      f5[0][i] = f5[0][i - 1] + b5[0][i];
    }
    
  }
  
  for(ll i = 1; i < n; i++)
    for(ll j = 1; j < m; j++){
      if(checkzero[i][j] == 1){
        if(a[i][j] == 0){
          f2[i][j] = 1;
          f5[i][j] = 1;
        }else{
          f2[i][j] = min(min(f2[i - 1][j], f2[i][j - 1]) + b2[i][j], (long long) 1);
          f5[i][j] = min(min(f5[i - 1][j], f5[i][j - 1]) + b5[i][j], (long long) 1);
        }
      }else{
        f2[i][j] = min(f2[i - 1][j], f2[i][j - 1]) + b2[i][j];
        f5[i][j] = min(f5[i - 1][j], f5[i][j - 1]) + b5[i][j];
      }
    }

  cout << min(f2[n - 1][m - 1], f5[n - 1][m - 1]);
  return 0;
}
/*
Đúng 20/20
#######################
Thông tin chi tiết
test 1 :	0.006974s 			0 MB		 [đúng]
test 2 :	0.007111s 			0 MB		 [đúng]
test 3 :	0.006994s 			0 MB		 [đúng]
test 4 :	0.006921s 			0 MB		 [đúng]
test 5 :	0.007722s 			0 MB		 [đúng]
test 6 :	0.006935s 			0 MB		 [đúng]
test 7 :	0.006776s 			0 MB		 [đúng]
test 8 :	0.007647s 			0 MB		 [đúng]
test 9 :	0.006753s 			0 MB		 [đúng]
test 10 :	0.007320s 			0 MB		 [đúng]
test 11 :	0.007504s 			0 MB		 [đúng]
test 12 :	0.008752s 			0 MB		 [đúng]
test 13 :	0.007049s 			0 MB		 [đúng]
test 14 :	0.006789s 			0 MB		 [đúng]
test 15 :	0.472639s 			0 MB		 [đúng]
test 16 :	0.296889s 			0 MB		 [đúng]
test 17 :	0.053345s 			0 MB		 [đúng]
test 18 :	0.198508s 			0 MB		 [đúng]
test 19 :	0.029145s 			0 MB		 [đúng]
test 20 :	0.331884s 			0 MB		 [đúng]
*/
