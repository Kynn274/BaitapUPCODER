#include <bits/stdc++.h>
#define ll long long
#define fmax 1000006 
using namespace std;

ll T;
ll A, B, K;
ll k(0);

ll sumDigits(ll a){
    ll sum(0);
    while(a > 0){
        sum += a % 10;
        a /= 10;
    }
    return sum;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> T;
    while(T--){
        k++;
        ll iC(0);
        cin >> A >> B >> K;
        if(K > 81) cout << "case " << k << ": " << 0 << '\n';
        else{
            ll a, b;
            if(A % K != 0) a = A / K - 1;
            else a = A / K;
        }
    }
    return 0;
}
