#include <bits/stdc++.h>
#define MOD 10000007 
#define fmax 10000007
#define ll long long
using namespace std;

string s;
ll f[fmax];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> s;
  for(ll i = 0; i < s.size(); i++)
    if('A' > s[i] || s[i] > 'Z'){
      s.erase(i, 1);
      i--;
    }
  
  ll ans(0);
  for(ll i = 0; i < s.size(); i++){
    f[i] = 1;
    for(ll j = 0; j < i; j++)
      if(s[j] < s[i])
        f[i] = max(f[i], f[j] + 1);
    ans = max(ans, f[i]);
  }
  cout << ans;
  return 0;
}
/*
Đúng 100/100
#######################
Thông tin chi tiết
test 1 :	0.006737s 			0 MB		 [đúng]
test 2 :	0.010612s 			0 MB		 [đúng]
test 3 :	0.009771s 			0 MB		 [đúng]
test 4 :	0.016531s 			0 MB		 [đúng]
test 5 :	0.007610s 			0 MB		 [đúng]
test 6 :	0.008102s 			0 MB		 [đúng]
test 7 :	0.011293s 			0 MB		 [đúng]
test 8 :	0.013376s 			0 MB		 [đúng]
test 9 :	0.007562s 			0 MB		 [đúng]
test 10 :	0.007664s 			0 MB		 [đúng]
test 11 :	0.008506s 			0 MB		 [đúng]
test 12 :	0.008055s 			0 MB		 [đúng]
test 13 :	0.007304s 			0 MB		 [đúng]
test 14 :	0.007894s 			0 MB		 [đúng]
test 15 :	0.007269s 			0 MB		 [đúng]
test 16 :	0.010298s 			0 MB		 [đúng]
test 17 :	0.009047s 			0 MB		 [đúng]
test 18 :	0.009228s 			0 MB		 [đúng]
test 19 :	0.009067s 			0 MB		 [đúng]
test 20 :	0.009557s 			0 MB		 [đúng]
test 21 :	0.007800s 			0 MB		 [đúng]
test 22 :	0.008590s 			0 MB		 [đúng]
test 23 :	0.008927s 			0 MB		 [đúng]
test 24 :	0.008133s 			0 MB		 [đúng]
test 25 :	0.007239s 			0 MB		 [đúng]
test 26 :	0.010295s 			0 MB		 [đúng]
test 27 :	0.007544s 			0 MB		 [đúng]
test 28 :	0.007519s 			0 MB		 [đúng]
test 29 :	0.007931s 			0 MB		 [đúng]
test 30 :	0.008150s 			0 MB		 [đúng]
test 31 :	0.007649s 			0 MB		 [đúng]
test 32 :	0.008766s 			0 MB		 [đúng]
test 33 :	0.009718s 			0 MB		 [đúng]
test 34 :	0.008130s 			0 MB		 [đúng]
test 35 :	0.008275s 			0 MB		 [đúng]
test 36 :	0.007436s 			0 MB		 [đúng]
test 37 :	0.007903s 			0 MB		 [đúng]
test 38 :	0.009114s 			0 MB		 [đúng]
test 39 :	0.010622s 			0 MB		 [đúng]
test 40 :	0.008980s 			0 MB		 [đúng]
test 41 :	0.010141s 			0 MB		 [đúng]
test 42 :	0.010548s 			0 MB		 [đúng]
test 43 :	0.009609s 			0 MB		 [đúng]
test 44 :	0.008981s 			0 MB		 [đúng]
test 45 :	0.011449s 			0 MB		 [đúng]
test 46 :	0.009480s 			0 MB		 [đúng]
test 47 :	0.007665s 			0 MB		 [đúng]
test 48 :	0.010139s 			0 MB		 [đúng]
test 49 :	0.020985s 			0 MB		 [đúng]
test 50 :	0.017216s 			0 MB		 [đúng]
test 51 :	0.015902s 			0 MB		 [đúng]
test 52 :	0.019603s 			0 MB		 [đúng]
test 53 :	0.015962s 			0 MB		 [đúng]
test 54 :	0.016389s 			0 MB		 [đúng]
test 55 :	0.017154s 			0 MB		 [đúng]
test 56 :	0.015653s 			0 MB		 [đúng]
test 57 :	0.016306s 			0 MB		 [đúng]
test 58 :	0.006259s 			0 MB		 [đúng]
test 59 :	0.016805s 			0 MB		 [đúng]
test 60 :	0.016074s 			0 MB		 [đúng]
test 61 :	0.017929s 			0 MB		 [đúng]
test 62 :	0.015873s 			0 MB		 [đúng]
test 63 :	0.016077s 			0 MB		 [đúng]
test 64 :	0.016052s 			0 MB		 [đúng]
test 65 :	0.015804s 			0 MB		 [đúng]
test 66 :	0.017405s 			0 MB		 [đúng]
test 67 :	0.019696s 			0 MB		 [đúng]
test 68 :	0.015840s 			0 MB		 [đúng]
test 69 :	0.007676s 			0 MB		 [đúng]
test 70 :	0.020036s 			0 MB		 [đúng]
test 71 :	0.015646s 			0 MB		 [đúng]
test 72 :	0.017511s 			0 MB		 [đúng]
test 73 :	0.015421s 			0 MB		 [đúng]
test 74 :	0.016024s 			0 MB		 [đúng]
test 75 :	0.016148s 			0 MB		 [đúng]
test 76 :	0.019529s 			0 MB		 [đúng]
test 77 :	0.015995s 			0 MB		 [đúng]
test 78 :	0.016485s 			0 MB		 [đúng]
test 79 :	0.019652s 			0 MB		 [đúng]
test 80 :	0.008566s 			0 MB		 [đúng]
test 81 :	0.018328s 			0 MB		 [đúng]
test 82 :	0.015997s 			0 MB		 [đúng]
test 83 :	0.016335s 			0 MB		 [đúng]
test 84 :	0.018152s 			0 MB		 [đúng]
test 85 :	0.016476s 			0 MB		 [đúng]
test 86 :	0.018826s 			0 MB		 [đúng]
test 87 :	0.015832s 			0 MB		 [đúng]
test 88 :	0.016529s 			0 MB		 [đúng]
test 89 :	0.017023s 			0 MB		 [đúng]
test 90 :	0.016399s 			0 MB		 [đúng]
test 91 :	0.007057s 			0 MB		 [đúng]
test 92 :	0.015879s 			0 MB		 [đúng]
test 93 :	0.017963s 			0 MB		 [đúng]
test 94 :	0.015698s 			0 MB		 [đúng]
test 95 :	0.019618s 			0 MB		 [đúng]
test 96 :	0.015674s 			0 MB		 [đúng]
test 97 :	0.016038s 			0 MB		 [đúng]
test 98 :	0.015823s 			0 MB		 [đúng]
test 99 :	0.007275s 			0 MB		 [đúng]
test 100 :	0.006994s 			0 MB		 [đúng]

*/
