#include <iostream>
#include <cmath>
#include <string.h>
#include <stdio.h>
using namespace std;


long long xuly(long long k, long long n){
  if(n==0) return 1;
  else{
    return pow(k,n)+xuly(k,n-1);
  }
}

int main(){
  long long n;
  long long k;
  cin>>n>>k;
  
  cout<<xuly(k,n);
}


