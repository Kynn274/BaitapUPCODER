#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

long long tinh(long long n){
  if(n==0) return 0;
  else {
    return n%10 + tinh(n/10);
  }
}

int xuly(long long n){
  if(n<= 9) return n;
  else{
    n=tinh(n);
    return xuly(n);
  }
}

int main(){
  long long n;
  cin>>n;
  
  cout<<xuly(n);
  
}
