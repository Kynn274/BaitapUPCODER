#include <bits/stdc++.h>
#define ll long long
#define fmax 1000006
using namespace std;

ll n, P, L;
ll w[fmax], v[fmax];
ll fw[fmax], fv[fmax];
bool flag (0);
double distance(ll x1, ll y1, ll x2, ll y2){
    return (double) sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> P >> L;
    for(ll i = 0; i < n; i++) cin >> w[i] >> v[i];
    for(ll i = 0; i < n; i++)
        if(fw[i - 1] + w[i] <= P)
            if(v[i] <= fv[i - 1]){
                fv[i] = v[i];
                fw[i] = w[i];
            }else{
                fv[i] = fv[i - 1];
                fw[i] = fw[i - 1] + w[i];
            }
        else{
            fv[i] = v[i];
            fw[i] = w[i];
        }
    vector<ll> p;
    double tgian(0);
    for(ll i = 0; i < n; i++){
        if(fv[i] != fv[i + 1]){
            tgian += (double) L / fv[i];
            p.push_back(i + 1);
        }
    }
    cout << fixed << setprecision(2) << tgian << '\n';
    for(auto x : p) cout << x << ' ';
    return 0;
}