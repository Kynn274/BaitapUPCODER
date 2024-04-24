#include <iostream>
#include <cmath>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <map>
using namespace std;

bool kt(string s, string k){
  if(s.size()!=0){
  for(int i=0; i<s.size(); i++){
    string h="";
    h=h+s[i];
    if(k==h) return false;
  }
  }
  return true;
}

void xuly(int k, int n, string s){
  //cout<<s<<endl;
  for(int i=1; i<=n; i++){
    string tmp=to_string(i);
    if(kt(s,tmp)){
      s=s+tmp;
      if(s.size()>=k){
        cout<<s<<endl;
      }else{
        xuly(k,n,s);
      }
      s.resize(s.size()-1);
    }
  }
}

int main(){
  long long n, k;
  string s="";
  cin>>k>>n;
  
  xuly(k,n,s);
}


