#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
  long long n;
  cin >> n;
  
  vector<long long> v(n);
  for(long long i = 0; i < n; i++) 
    cin >> v[i];
  
  vector<long long> xuoi (n, 0);
  vector<long long> nguoc(n, 0);
  
  xuoi [0] = v[0];
  for(long long i = 1; i < n; i++)
    xuoi[i] = xuoi[i - 1] + v[i];
  nguoc[n - 1] = v[n - 1];
  for(long long i = n - 2; i >= 0; i--)
    nguoc[i] = nguoc[i + 1] + v[i];
  
  long long dem(0);
  for(long long i = 1; i < n; i++){
    //cout << xuoi[i - 1] << ' ' << nguoc[i + 1] << endl;
    if(xuoi[i - 1] % 2 == 0 && nguoc[i + 1] % 2 == 0)
      dem++;
  }
  cout << dem;
  return 0;
}
