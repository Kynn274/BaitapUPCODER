#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool ss(long long a, long long b){
  return abs(a)>abs(b);
}

void merge(vector<long long> a, vector<long long> b, vector<long long> &c){
  int i=0,j=0;
  int len1=a.size(), len2=b.size();
  c.clear();
  
  while(i<len1 && j<len2){
    if(a[i]>b[j]) c.push_back(a[i++]);
    else c.push_back(b[j++]);
  }
  
  while(i<len1) c.push_back(a[i++]);
  while(j<len2) c.push_back(b[j++]);
}

void mergeSort(vector<long long> &a){
  long long b=0, e=a.size(), m=(b+e)/2;
  
  if(b!=m){
    vector<long long> a1;
    vector<long long> a2;
    
    for(long long i=b; i<m; i++) a1.push_back(a[i]);
    for(long long i=m; i<e; i++) a2.push_back(a[i]);
    
    mergeSort(a1);
    mergeSort(a2);
    merge(a1,a2,a);
  }
}
int main() {
  long long n,k,tmp;
  vector<long long> v;
  vector<long long> v1;
  
  cin>>n>>k;
  for(long long i=0; i<n; i++){
    cin>>tmp;
    v.push_back(tmp);
  }
  
  for(long long i=1; i<n; i++){
    v1.push_back(v[i]);
  }
  
  mergeSort(v1);
  /*
  for(long long i=0; i<v1.size(); i++) cout<<v1[i]<<' ';
  cout<<endl;
  */
  long long tong=v[0];
  long long i=0;

  while(k>0){
    tong+=v1[i++];
    k--;
  }
  
  for(i; i<v1.size(); i++) tong-=v1[i];

  cout<<tong;
}
