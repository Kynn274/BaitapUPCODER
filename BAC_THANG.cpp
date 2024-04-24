#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int ucln(int a, int b){
  int r;
  while(b!=0){
    r=a%b;
    a=b;
    b=r;
  }
  return a;
}

long long hoanvi(int sl1 , int sl2){
  vector<int> big;
  vector<int> b;
  for(int i=sl1+1; i<=sl2+sl1; i++)
    big.push_back(i);
  for(int i=1; i<=sl2; i++)
    b.push_back(i);
  
  int len1=b.size();
  int len2=big.size();
  int i=0, j=0;
  while(i<len1 && j<len2){
    int u=ucln(b[i], big[j]);
    if(u==b[i]){
      b[i]=1;
      i++;
      big[j]/=u;
      j=0;
    }else{
      b[i]/=u;
      big[j]/=u;
      j++;
    }
  }
  
  long long tich=1;
  for(i=0; i<len2; i++){
    tich*=big[i];
  }
  return tich;
}


long long xuly(int sl1, int sl2, int n){
  if(sl1==n) return 1;
  else{
    long long tmp=hoanvi(sl1, sl2);
    return tmp+xuly(sl1+2,sl2-1,n);
  }
}

int main(){
  int n;
  int sl2;
  int sl1;

  cin>>n;
  sl2=n/2;
  if(n%2==0)sl1=0;
  else sl1=1;

  cout<<xuly(sl1,sl2,n);

  
  return 0;
}
