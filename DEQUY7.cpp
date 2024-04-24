#include <iostream>
#include <cmath>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <map>
using namespace std;


void xuly(vector<long long> &fibo, long long n){
  fibo.push_back(1);
  fibo.push_back(1);
  for(long long i= 2; i<n; i++){
    fibo.push_back(fibo[i-2]+fibo[i-1]);
  }
}

int main(){
  long long n;
  cin>>n;
  vector<long long> fibo;
  xuly(fibo,n);
  for(long long i=0; i<n; i++) cout<<fibo[i]<<' ';
}


