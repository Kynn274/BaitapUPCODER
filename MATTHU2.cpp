#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
  string s;
  getline(cin, s);
  
  int id = 0;
  string tmp = "";
  
  for(int i = 0; i < s.size(); i++){
    if(s[i] <= '9' && s[i] >= '0'){
      tmp  = tmp + s[i];
      id  += stoi(tmp);
      tmp.clear();
    }
  }
  
  cout << id << ' ';
  for(int i = 0; i < s.size(); i++){
    if(s[i] == ' '){
      reverse(tmp.begin(), tmp.end());
      cout << tmp << ' ';
      tmp.clear();
    }else{
      if(!(s[i] <= '9' && s[i] >= '0'))
        tmp = tmp + s[i];
    }
  }
  
  reverse(tmp.begin(), tmp.end());
  cout << tmp << ' ';
}
