#include <iostream>
#include <cmath>
#include <map>
#include <vector>
using namespace std;

long long ucln(long long a, long long b){
  long long r;
  while(b!=0){
    r=a%b;
    a=b;
    b=r;
  }
  return a;
}

long long tinh(vector<long long> a, vector<long long> b){
  int i=0;
  int j=0;
  int len1=a.size();
  int len2=b.size();
  
  while(i<len1&&j<len2){
    long long u=ucln(a[i],b[j]);
    if(u==b[j]){
      b[j]=1;
      j++;
      a[i]/=u;
      i=0;
    }else{
      a[i]/=u;
      b[j]/=u;
      i++;
    }
  }
  
  long long tich=1;
  for(i=0; i<len1; i++){
    tich*=a[i];
  }
  return tich;
}

int main(){
  long long n;
  vector<long long> v;
  
  while(cin>>n){
    v.push_back(n);
  }
  
  long long len=v.size();
  for(int i=0; i<len; i++){
    vector<long long> a;
    vector<long long> b;
    
    for(int j=v[i]+2; j<=2*v[i]; j++) a.push_back(j);
    for(int j=2;  j<=v[i]; j++) b.push_back(j);
    cout<<tinh(a,b)<<endl;
  }
  
  
}
