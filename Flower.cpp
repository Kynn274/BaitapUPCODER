#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  long long n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  
  int date(-1e9);
  for(int i = 0; i < n; i++)
    date = max(date, a[i] + i + 1);
  cout << date;
  
  return 0;
}
