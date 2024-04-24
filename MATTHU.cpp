#include <iostream>
#include <string.h>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
  int n,len;
  string s;
  vector<int> point;
  vector<bool> check;
  vector<string> ans;
  
  cin>>n;
  cin>>s;
  
  len=s.size();
  
  for(int i=0; i<len; i++){
    if(s[i]=='1'){
      point.push_back(i);
      check.push_back(true);
    }
    if(s[i]=='2'){
      point.push_back(i);
      check.push_back(false);
    }
  }
  
  len=point.size();
  string tmp;
  for(int i=1; i<len; i++){
    tmp=s.substr(point[i-1]+1, point[i]-point[i-1]-1);
    if(check[i-1]==false) reverse(tmp.begin(), tmp.end());
    //cout
    ans.push_back(tmp);
  }
  
  tmp=s.substr(point[len-1]+1, s.size()-point[len-1]-1);
  if(check[len-1]==false) reverse(tmp.begin(), tmp.end());
  ans.push_back(tmp);
  
  for(int i=0; i<ans.size(); i++){
    cout<<ans[i]<<' ';
  }
  return 0;
}

