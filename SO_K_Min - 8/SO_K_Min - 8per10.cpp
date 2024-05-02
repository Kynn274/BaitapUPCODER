#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
  long long n;
  cin >> n;
  
  vector<long long> v(n);
  vector<bool> b(n, 0);
  long long result (1e9), result1 (-1e9), dem (0);
  
  for(long long i = 0; i < n; i++)
    cin >> v[i];
  
  for(long long i = 0; i < n; i++){
    if(b[i] == 0){
      result1 = i + 1;
      for(long long j = i + 1; j < n; j++){
        if(v[j]   == v[i]){
          result1 = max(result1, dem + 1);
          b[j]    = 1;
          dem = 0;
        }
        else dem++;
      }
      result1 = max(result1, dem + 1);
      b[i]   = 1;
      result = min (result, result1);
      dem = 0;
    }
  }
  
  cout << result;
  return 0;
}
