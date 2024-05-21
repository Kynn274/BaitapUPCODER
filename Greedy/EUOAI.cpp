#include <bits/stdc++.h>
#define MOD 1000007 
#define fmax 1000006
#define ll long long
using namespace std;

string a, b;
string a1, a2;
string b1, b2;
bool flaga(0), flagb(0);

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  cin >> a >> b;
    a1 = a2 = a;
    b1 = b2 = b;
      
    for(ll i = 0; i < a.size(); i++){
        if(a1[i] == '5')  a1[i] = '4';
        if(a2[i] == '4')  a2[i] = '5';
    }
  
    for(ll i = 0; i < b.size(); i++){
        if(b1[i] == '5')  b1[i] = '4';
        if(b2[i] == '4')  b2[i] = '5';
    }
    cout << stoll(a2) + stoll(b2) << ' ' << stoll(a1) + stoll(b1);
  return 0;
}
