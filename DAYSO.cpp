#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

vector<long long> v;

void find_max(int n, int k){
  if(k<=n){
    if(k%2==0) v[k]=v[k/2];
    else{
      v[k]=v[(k-1)/2]+v[(k-1)/2+1];
    }
    find_max(n,k+1);
  }
}
int main(){
  int n;
  
  cin>>n;
  for(int i=0; i<=n ; i++) v.push_back(-1);
  v[0]=0;
  v[1]=1;
  
  find_max(n,2);
  long long _max=-1e9;
  for(int i=0; i<=n ; i++)
    if(v[i]>_max) _max=v[i];
    
  cout<<_max;
}
