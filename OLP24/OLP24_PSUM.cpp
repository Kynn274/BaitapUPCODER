#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    unsigned long long a, b, n, m;
    cin >> a >> b >> n >> m;
    unsigned long long _a, _b, _n;
    _n = n % m;
    _a = a % m;
    _b = b % m;
    unsigned long long s1, s2;
    s1 = pow(_a, _n);
    s2 = pow(_b, _n);
    cout << (s1 % m + s2 % m) % m;
    return 0;
}