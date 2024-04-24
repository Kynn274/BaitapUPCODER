#include <cmath>
#include <iostream>
#include <vector>
#include <stack>
#include <fstream>
using namespace std;

void CoSo2(long long n, stack<int>& s){
  if(n>0){
    s.push(n%2);
    CoSo2(n/2,s);
  }
}

long long CoSo10(string s, int k, int len){
  string tmp="";
  tmp=tmp+s[k];
  if(k==len){
    return stoi(tmp)*pow(8,len-k);
  }else{
    return stoi(tmp)*pow(8,len-k) + CoSo10(s,k+1,len);
  }
}


int main(){
  string s;
  stack<int> s1;
  ifstream ip("coso.inp");
  ofstream op("coso.out");
  
  ip>>s;
  int len=s.size();
  long long m=CoSo10(s,0,len-1);
  CoSo2(m,s1);
  
  while(!s1.empty()){
    op<<s1.top();
    s1.pop();
  }
  
  ip.close();
  op.close();
  return 0;
}
