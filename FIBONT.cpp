#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool ktsnt(long long n){
  if(n<2 ) return false;
  if(n==2||n==3||n==5) return true;
  for(int i=2; i<=sqrt(n); i++)
    if(n%i==0) return false;
  return true;
}

int main(){
  vector<long long> v;
  long long n;
  
  v.push_back(1);
  v.push_back(1);
  cin>>n;
  
  long long i=2;
  while(v[i-1]<n){
    v.push_back(v[i-1]+v[i-2]);
    i++;
  }
  
  for(long long j=0; j<i; j++){
    if(ktsnt(v[j]) && v[j]<=n) cout<<v[j]<<endl;
  }
}
