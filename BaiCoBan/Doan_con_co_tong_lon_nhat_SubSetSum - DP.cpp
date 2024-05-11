#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Tìm chuỗi con liên tiếp có tổng lớn nhất, xuất kết quả tổng

void subsetsum(long long n, vector<long long> v){
  long long _max = v[0];
  vector<long long> result(n);
  result[0] = v[0];
  
  for(long long i = 1; i < n; i++){
    result[i] = max(v[i], v[i] + result[i - 1]);
    _max = max(result[i], _max);
  }
  
  cout << _max << endl;
}

int main() {
  long long n;
  cin >> n;
  
  vector<long long> v(n);
  for(long long i = 0; i < n; i++) cin >> v[i];
  
  subsetsum(n, v);
  return 0;
}
