#include <bits/stdc++.h>
#define ll long long
#define fmax 100005
using namespace std;

ll n;
vector<ll> a, b;
void merge(vector<ll> a1, vector<ll> a2, vector<ll> & a){
    ll m(a1.size()), n(a2.size()), i(0), j(0);
    a.clear();
    
    while(i < m && j < n)
      a1[i] < a2[j] ? a.push_back(a1[i++]) : a.push_back(a2[j++]);
    while(i < m) a.push_back(a1[i++]);
    while(j < n) a.push_back(a2[j++]);
    
}
void mergeSort(vector<ll> &a){
    ll s(0), e(a.size()), m = (s + e) / 2;
    if(m != s){
        vector<ll> a1;
        vector<ll> a2;
        for(ll i = s; i < m; i++) a1.push_back(a[i]);
        for(ll i = m; i < e; i++) a2.push_back(a[i]);
        mergeSort(a1);
        mergeSort(a2);
        merge(a1, a2, a);
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    a.resize(n);
    b.resize(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 0; i < n; i++) cin >> b[i];
    mergeSort(a);
    mergeSort(b);
    
    ll i(0), j(0), iC(0);
    while(i < n && j < n){
        if(b[j] > a[i]){
            iC++;
            j++;
            i++;
        }
        else j++;
    }
    cout << iC;
    return 0;
}
/*
Đúng 17/17
#######################
Thông tin chi tiết
test 1 :	0.007203s 			0 MB		 [đúng]
test 2 :	0.006814s 			0 MB		 [đúng]
test 3 :	0.006065s 			0 MB		 [đúng]
test 4 :	0.007182s 			0 MB		 [đúng]
test 5 :	0.007355s 			0 MB		 [đúng]
test 6 :	0.006462s 			0 MB		 [đúng]
test 7 :	0.006433s 			0 MB		 [đúng]
test 8 :	0.007227s 			0 MB		 [đúng]
test 9 :	0.006908s 			0 MB		 [đúng]
test 10 :	0.007761s 			0 MB		 [đúng]
test 11 :	0.006435s 			0 MB		 [đúng]
test 12 :	0.006590s 			0 MB		 [đúng]
test 13 :	0.006812s 			0 MB		 [đúng]
test 14 :	0.007238s 			0 MB		 [đúng]
test 15 :	0.006524s 			0 MB		 [đúng]
test 16 :	0.006819s 			0 MB		 [đúng]
test 17 :	0.006762s 			0 MB		 [đúng]
*/