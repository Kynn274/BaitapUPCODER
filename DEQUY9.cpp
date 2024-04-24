#include <cmath>
#include <iostream>
using namespace std;

long long cong(int n){
  if(n==1) return 1;
  else{
    return n + cong(n-1);
  }
}

long long multi(int n){
  if(n==1) return 1;
  else{
    return n*multi(n-1);
  }
}

long long xuly_plus(int n){
  if(n==1) return 1;
  else{
    return cong(n)+xuly_plus(n-1);
  }
}

long long xuly_multi(int n){
  if(n==1) return 1;
  else{
    return multi(n)+xuly_multi(n-1);
  }
}

int main(){
  int n;
  
  cin>>n;
  cout<<"S("<<n<<") = "<<xuly_plus(n)<<endl;
  cout<<"P("<<n<<") = "<<xuly_multi(n);

}
