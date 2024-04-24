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
  if(n==0) return k;
  else{
    return (double)(pow(-1,n)*pow(k,2*n+1))/factorial(2*n+1)+xuly(k,n-1);
  }
}

int main(){
  long long n;
  double k;
  cin>>n>>k;
  
  cout<<roundf(xuly(k,n)*1000)/1000 ;
}


