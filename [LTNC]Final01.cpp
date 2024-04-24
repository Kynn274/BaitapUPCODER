#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

long long factorial(int n){
  if(n==1 || n==0) return 1;
  else return n*factorial(n-1);
}

double tinh_sin(double x, int n){
  if(n==0) return (double) x;
  else{
    return (double) (pow(-1,n)*pow(x,2*n+1))/factorial(2*n+1) + tinh_sin(x,n-1);
  }
}

double tinh_cos(double x, int n){
  if(n==0) return (double) 1;
  else{
    return (double) (pow(-1,n)*pow(x,2*n))/factorial(2*n) + tinh_cos(x,n-1);
  }
}
int main(){
  double x;
  cin>>x;
  
  cout<<roundf(tinh_sin(x,10)*100)/100<<endl;
  cout<<roundf(tinh_cos(x,10)*100)/100;
}
