#include <bits/stdc++.h>
using namespace std;

string max(string a, string b){
  while(a[0] == '0') a.erase(0, 1);
  while(b[0] == '0') b.erase(0, 1);
  
  if(a.size() > b.size()) return a;
  if(a.size() < b.size()) return b;
  
  long long i = 0;
  while(a[i] == b[i]) i++;
  
  if(a[i] > b[i]) return a;
  return b;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    string s;
    string a;
    string m;
    cin >> s;
    
    long long i = 0;
    
    while(i < s.size()){
        if('0' <= s[i]  && s[i] <= '9')
            a += s[i];
        else
            if(m.size() == 0){
                if(a.size() != 0){
                    m = a;
                    a.clear();
                }
            }else{
                if(a.size() != 0){
                    m = max(m, a);
                    a.clear();
                }
            }
        i++;
    }
    
    if(m.size() == 0){
      if(a.size() != 0) m = a;
    }
    else{
      if(a.size() != 0) m = max(m, a);
    }
    
    while(m[0] == '0')  m.erase(0, 1);
    cout << m;
    
    return 0;
}
/*
Đúng 10/10
#######################
Thông tin chi tiết
test 1 :	0.007524s 			0 MB		 [đúng]
test 2 :	0.008383s 			0 MB		 [đúng]
test 3 :	0.008333s 			0 MB		 [đúng]
test 4 :	0.008173s 			0 MB		 [đúng]
test 5 :	0.007318s 			0 MB		 [đúng]
test 6 :	0.007407s 			0 MB		 [đúng]
test 7 :	0.006717s 			0 MB		 [đúng]
test 8 :	0.007786s 			0 MB		 [đúng]
test 9 :	0.006314s 			0 MB		 [đúng]
test 10 :	0.007794s 			0 MB		 [đúng]
*/
