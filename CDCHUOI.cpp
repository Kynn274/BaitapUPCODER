#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stack>
#include <vector>
using namespace std;

int main(){
  vector<string> v;
  string s;
  
  cin >> s;
  
  int i = 0;
  int len = s.size();
  while(i < len){
    if(s[i] == '9'){
      v.push_back(s.substr(i, 2));
      i += 2;
    }
    if(s[i] == '1'){
      v.push_back(s.substr(i, 3));
      i += 3;
    }
  }
  
  for(i = 0; i < v.size(); i++){
    cout << char(stoi(v[i]));
  }
  return 0;
}
