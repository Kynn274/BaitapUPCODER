#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool palindrom (string s, int i, int j){
  if(i>j || i==j){
    return true;
  }else{
    if(s[i]==s[j]) return palindrom(s,i+1,j-1);
    else return false;
  }
}

int main(){
  int n;
  string s;
  vector<string> v;
  
  cin>>n;
  for(int i=0; i<n; i++){
    cin>>s;
    v.push_back(s);
  }
  
  for(int i=0; i<n; i++){
    if(palindrom(v[i],0,v[i].size()-1)) cout<<v[i]<<' ';
  }
  
  
  return 0;
}
