#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

long long chuyendoi(string s, int len, int k){
  if(k==len){
    if(s[k]=='1') return 1;
  }else{
    if(s[k]=='1'){
      return pow(2,len-k)+chuyendoi(s,len,k+1);
    }else{
      return chuyendoi(s,len,k+1);
    }
  }
}


int main(){
  string s;
  cin>>s;
  
  int len=s.size();
  
  cout<<chuyendoi(s,len-1,0);
  
}
