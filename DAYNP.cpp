#include <iostream>
#include <cmath>
#include <string.h>
#include <stdio.h>
#include <vector>
using namespace std;

vector<string> v;

void xuly(int n, int k, string s){
  if(k==n){
    v.push_back(s);
  }else{
    for(int i=0; i<=1; i++){
      s=s+to_string(i);
      k++;
      xuly(n,k,s);
      k--;
      s.erase(k,1);
    }
  }
}

int main(){
  long long n;
  string s="";
  cin>>n;
  
  xuly(n,0,s);
  for(int i=0; i<v.size(); i++)
    cout<<v[i]<<endl;
  cin>>n;
}


