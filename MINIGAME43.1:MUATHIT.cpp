#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  long long n, q, h, s, d;
  cin >> q >> h >> s >> d >> n;
  
  long long m1, m2, m3, m4;
  m4 = d;
  m4 = min (m4, s * 2);
  m4 = min (m4, h * 4);
  m4 = min (m4, q * 8);
  
  m3 = s;
  m3 = min (m3, h * 2);
  m3 = min (m3, q * 4);
  
  long long money = 0;
  money += m4 * (long long) (n/2);
  n %= 2;
  money += m3 * n;
  
  cout << money;
  return 0;
}
