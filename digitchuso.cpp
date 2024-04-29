#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  string s;
  cin >> s;
  for(int i = 0; i < s.size() - 1; i++)
    for(int j = i + 1; j < s.size(); j++)
      if(s[i] > s[j]) swap(s[i], s[j]);
  
  string s1 = "";
  string s2 = "";
  int len = s.size();
  if(len % 2 == 0){
    for(int i = 0; i < len; i++){
      s1 = s1 + s[i++];
      s2 = s2 + s[i];
    }
  }else{
    for(int i = 0; i < (len - 1); i++){
      s1 = s1 + s[i++];
      s2 = s2 + s[i];
    }
    s1 = s1 + s[len - 1];
  }
  cout << stoi(s1) + stoi(s2);
  return 0;
}
