#include <bits/stdc++.h>
#define ll long long
#define fmax 1000006 
using namespace std;

ll n;
ll a[fmax];
ll f[fmax];
ll iC(0);

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(auto & x : a) cin >> x;
    for(ll i = 0; i < n; i++)
        a[i] < 0 ? f[i] = f[i - 1] + 1 : f[i] = f[i - 1];
    ll i(0), j(0);
    while(i < n && j < n){
        if(i == j) j++;
        if(f[j] - f[i] == 3)
            f[j] != f[j - 1] ? iC = max(iC, j - i) : i = i + 1;
        else if(f[j] - f[i] < 3) j++;
    }
    cout << iC;
    return 0;
}
