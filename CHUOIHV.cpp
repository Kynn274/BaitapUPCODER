#include <bits/stdc++.h>
#define fmax 102
#define ll long long
using namespace std;

string a, b;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  cin >> a >> b;
  ll m = a.size(); 
  ll n = b.size();
  
  if(m != n){
    cout << "False";
    return 0;
  }else{
    map <char, ll> a1;
    map <char, ll> b1;
    
    for(ll i = 0; i < n; i++){
      if(b1.count(b[i]) == 0)         // Đếm phần tử của b
        b1[b[i]] = 1;
      else 
        b1[b[i]] ++;
        
      if(a1.count(a[i]) == 0)         // Đếm phần tử của a
        a1[a[i]] = 1;
      else 
        a1[a[i]] ++;
    }
    for(ll i = 0; i < n; i++)
      if(b1[a[i]] != a1[a[i]]){
        cout << "False";
        return 0;
      }
    
    cout << "True";
  }
  
  return 0;
}

/*
Đúng 5/5
#######################
Thông tin chi tiết
test 1 :	0.007586s 			0 MB		 [đúng]
test 2 :	0.011449s 			0 MB		 [đúng]
test 3 :	0.008309s 			0 MB		 [đúng]
test 4 :	0.007196s 			0 MB		 [đúng]
test 5 :	0.007459s 			0 MB		 [đúng]
*/
