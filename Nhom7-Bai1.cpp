#include <iostream>
using namespace std;

int main(){
  int n;
  long long fibo[100];
  
  cin >> n;
  fibo[0] = fibo[1] = 1;
  for(int i = 2; i < n; i++)
    fibo[i] = fibo[i - 1] + fibo[i - 2];
    
  for(int i = 0; i < n; i++)
    cout << "F[" << i + 1 << "] = " << fibo[i] << endl;
  
  return 0;
}
