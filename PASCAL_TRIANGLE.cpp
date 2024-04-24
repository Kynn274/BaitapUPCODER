#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
  long long n, a[100][100];
  cin >> n;
  
  for(long long i = 0; i < n; i++){
    a[i][0] = a[i][i] = 1;
    for(long long j = 1; j < i; j++)  a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
    for(long long j = 0; j <= i; j++)  cout << a[i][j] << ' ';
    cout << endl;
  }
  return 0;
}
