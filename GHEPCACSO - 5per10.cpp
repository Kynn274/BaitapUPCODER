#include <bits/stdc++.h>
#define ll long long
#define fmax 102
using namespace std;

string s;
vector<string> v;

bool ss_lon(string a, string b){
  if(a.size() == b.size())
    return a > b;
  
  ll len = min(a.size(), b.size());
  
  for(ll i = 0; i < len; i++)
    if(b[i] > a[i]) return 0;
    else if(a[i] > b[i]) return 1;
    
  if(a.size() > b.size()){
    if(a[len] >= a[0]) return 1;
    else return 0;
  }else{
    if(b[len] < b[0]) return 1;
    else return 0;
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  string m;
  cin >> s;
  
  ll i = 0;
  while(i != s.size()){
    if('0' <= s[i] && s[i] <= '9')
      m += s[i];
    else
      if(m.size() != 0){
        v.push_back(m);
        m.clear();
      }
    i++;
  }
  
  if(m.size() != 0) v.push_back(m);
  
  ll len = v.size();
  for(ll i = 0; i < len; i++){
    while(v[i][0] == '0' && v[i].size() != 1) v[i].erase(0,1);
  }
  
  for(ll i = 0; i < len - 1; i++)
    for(ll j = i + 1; j < len; j++)
      if(ss_lon(v[j], v[i])) swap(v[i], v[j]);
  
  if(v.size() == 0) cout << 0;
  else{
    string s1;
    for(ll i = 0; i < len; i++)
      s1 += v[i];
    while(s1[0] == '0' && s1.size() != 1)
      s1.erase(0,1);
    cout << s1;
  }
  return 0;
}
/*Đúng 5/10
#######################
Thông tin chi tiết
test 1 :	0.006894s 			0 MB		 [đúng]
test 2 :	0.009778s 			0 MB		 [đúng]
test 3 :	0.129780s 			0 MB		'[sai]'
test 4 :	0.172260s 			0 MB		'[sai]'
test 5 :	0.200398s 			0 MB		'[sai]'
test 6 :	0.007425s 			0 MB		 [đúng]
test 7 :	0.009060s 			0 MB		 [đúng]
test 8 :	0.014964s 			0 MB		 [đúng]
test 9 :	0.110647s 			0 MB		'[sai]'
test 10 :	0.107036s 			0 MB		'[sai]'*/
