#include <bits/stdc++.h>
#define ll long long
#define fmax 1003
using namespace std;

ll n;
ll tong(0);
ll f[fmax][fmax];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    vector<ll> a(n);
    for(auto & x : a){
        cin >> x;
        tong += x;
    }
    f[0] = 1;
    for(ll i = 0; i < n; i++)
        for(ll j = tong; j >= a[i]; j--){
            f[i][j] = f[j - a[i]][i - 1];
    
    vector<ll> item;
    for(ll i = 1; i <= tong; i++)
        if(f[i] != 0) item.push_back(f[i]);
    

    return 0;
}