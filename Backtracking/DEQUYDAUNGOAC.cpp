#include <bits/stdc++.h>
#define ll long long
#define fmax 102
using namespace std;

ll n;
ll storage[fmax];
string letShow;
char kiTu[] = {'(', ')', '[', ']', '{', '}'};

void xuLy(ll p){
  if(p == n){
    ll storage1[fmax];                          // Sử dụng mảng thay cho stack 
    ll p1(0);
    
    for(ll i = 0; i < n; i++)
      if(p1 == 0)
        storage1[p1++] = storage[i];
      else
        if(storage[i] == storage1[p1 - 1] + 1 && storage[i] % 2 != 0)
          p1--;
        else
          storage1[p1++] = storage[i];
    
    if(p1 == 0){
      for(ll i = 0; i < n; i++)
        cout << kiTu[storage[i]];
      cout << '\n';
    }
  }else
    for(ll i = 0; i < 6; i++){
      storage[p] = i;
      xuLy(p + 1);
    }
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  cin >> n;
  if(n % 2 != 0) cout << -1;
  else xuLy(0);
  return 0;
}
/*
Đúng 8/8
#######################
Thông tin chi tiết
test 1 :	0.010172s 			0 MB		 [đúng]
test 2 :	0.011670s 			0 MB		 [đúng]
test 3 :	0.011067s 			0 MB		 [đúng]
test 4 :	0.011690s 			0 MB		 [đúng]
test 5 :	0.014753s 			0 MB		 [đúng]
test 6 :	0.010951s 			0 MB		 [đúng]
test 7 :	0.160828s 			0 MB		 [đúng]
test 8 :	0.010935s 			0 MB		 [đúng]
*/
