#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int n;
  cin >> n;
  
  string s, tmp, tmp1;
  for(int i = 0; i < n; i++){
    cin >> s;
    if(s.size() % 2 != 0) cout << "NO\n";
    else{
      tmp = s.substr(s.size() / 2, s.size() / 2);
      tmp1 = s.substr(0, s.size() / 2);
      if(tmp == tmp1) cout << "YES\n";
      else cout << "NO\n";
    }
  }
  
  return 0;
}
