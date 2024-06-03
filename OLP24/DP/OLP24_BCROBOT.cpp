#include <bits/stdc++.h>
#define ll long long
#define fmax 1000006
using namespace std;

ll n; 
ll rb1x, rb1y, rb2x, rb2y;
ll customerx[fmax], customery[fmax];



int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> rb1x >> rb1y >> rb2x >> rb2y;
    for(ll i = 0; i < n; i++)
        cin >> customerx[i] >> customery[i];
    
    return 0;
}