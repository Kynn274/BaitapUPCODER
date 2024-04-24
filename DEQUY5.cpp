#include <iostream>
#include <cmath>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <map>
using namespace std;

long long factorial(long long n){
  if(n==1 || n==0) return 1;
  else{
    return n*factorial(n-1);
  }
}
double xuly(double k, long long n){
  if(n==1) return k;
  else{
    return (double) pow(k,n)/factorial(n)+xuly(k,n-2);
  }
}

int main(){
  long long n;
  double k;
  cin>>n>>k;
  
  cout<<roundf(xuly(k,n*2+1)*1000)/1000 + 1;
}


