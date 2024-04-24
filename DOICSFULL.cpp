#include <iostream>
#include <string.h>
#include <algorithm>
#include <stack>
#include <stdio.h>
using namespace std;

void coso2(long long n, stack<string> &s){
  if(n!=0){
    s.push(to_string(n%2));
    return coso2(n/2, s);
  }
}

void coso8(long long n, stack<string> &s){
  if(n!=0){
    s.push(to_string(n%8));
    return coso8(n/8, s);
  }
}

void coso16(long long n, stack<string> &s){
  if(n!=0){
    if(n%16<=9){
      s.push(to_string(n%16));
    }else{
      switch(n%16){
        case 10: s.push("A");
          break;
        case 11: s.push("B");
          break;
        case 12: s.push("C");
          break;
        case 13: s.push("D");
          break;
        case 14: s.push("E");
          break;
        case 15: s.push("F");
      }
    }
    return coso16(n/16, s);
  }
}

stack<string> chuyenCoSo(long long n, long long k){
  stack<string> s;
  switch(k){
    case 0: coso2(n,s);
      break;
    case 1: coso8(n,s);
      break;
    case 2: coso16(n,s);
      break;
  }
  return s;
}

stack<string> chuyenCoSo(long long n){
  stack<string> s;
  coso2(n,s);
  return s;
}


int main(){
  string tmp;
  getline(cin,tmp);
  int iC=0, vt=-1, n, k;
  stack<string> s;

  for(int i=0; i<tmp.size(); i++) 
    if(tmp[i]==' '){
      iC++;
      vt=i;
    }
  
  //cout<<vt<<' '<<iC<<endl;
  
  if(iC!=0){
    n=stoi(tmp.substr(0,vt));
    k=stoi(tmp.substr(vt+1, tmp.size()-vt-1));
    s=chuyenCoSo(n,k);
    //cout<<"YES"<<endl;
  }else{
    n=stoi(tmp);
    s=chuyenCoSo(n);
  }
  
  while(!s.empty()){
    cout<<s.top();
    s.pop();
  }
  return 0;
}
