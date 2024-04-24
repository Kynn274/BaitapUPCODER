#include <iostream>
#include <cmath>
#include <string.h>
#include <stdio.h>
#include <vector>
using namespace std;

vector<string> v;

void sx(vector<string> &v){
  for(int i=0; i<v.size()-1; i++)
    for(int j=i+1; j<v.size(); j++)
      if(v[j]<v[i]) swap(v[i],v[j]);
}

void xuly(int b, int e, string s){
  //cout<<s<<' '<<b<<endl;
  if(e<b){
    v.push_back(s);
  }else{
    for(int i=b; i<=e; i++){
      swap(s[i], s[b]);
      xuly(b+1, e, s);
      swap(s[i], s[b]);
    }
  }
}

int main(){
  long long n;
  string s="";
  cin>>n;
  
  for(int i=1; i<=n; i++){
    s=s+to_string(i);
  }
  xuly(0,n-1, s);
  sx(v);
  cout<<v.size()<<endl;
  for(int i=0; i<v.size(); i++){
    cout<<v[i]<<endl;
  }
  
}


