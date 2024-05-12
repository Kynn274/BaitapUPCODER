#include <bits/stdc++.h>
#define fmax 1000006
#define MOD 1000000007
#define ll long long
using namespace std;

string a;
vector<double> v;
stringstream ss;
double tmp;
double tong(0);

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  while(getline(cin, a)){
    ss << a;
    while(ss >> tmp){
      v.push_back(tmp);
    }
    for(ll i = 0; i < v.size(); i++)
      tong += v[i];
    cout << roundf(tong * 1000)/1000 << '\n';
    ss.clear();
    v.clear();
    tong = 0;
  }
  
  return 0;
}
