#include <iostream>
#include <vector>
using namespace std;

void triagle(int n){
  if(n == 1){
    cout << "*" << endl;
  }else{
    triagle(n - 1);
    for(int i = 0; i < n; i++) 
      cout << "*";
    cout << endl;
  }
}
int main(){
  int n;
  cin >> n;
  
  triagle(n);
  return 0;
}
