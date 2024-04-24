#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

bool xuly (string s){
  stack <char> check;
  int len = s.size();
  
  for(int i = 0; i < len; i++){
    if(check.empty()) check.push(s[i]);
    else{
      if(s[i] != check.top()) check.push(s[i]);
      else check.pop();
    }
  }
  
  if(check.empty()) return true;
  return false;
}

int main(){
  int n;
  string a[1000];
  
  cin >> n;
  for(int i=0; i<n; i++)
    cin >> a[i];
  
  vector<string> v;
  int iC=0;
  
  for(int i=0; i<n; i++)
    if(xuly(a[i])){
      iC++;
      v.push_back(a[i]);
    }
  
  cout << iC << endl;
  for(int i=0; i<iC; i++)
    cout << v[i] << endl;
  
}
