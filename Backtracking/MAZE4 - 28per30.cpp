#include <bits/stdc++.h>
#define ll long long
#define fmax 102
using namespace std;

ll n, m;
char duLieu[fmax][fmax];
bool unavai[fmax][fmax];
bool accepted = 0;
ll dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
ll dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
string s;

vector< vector<ll> > sr;
vector< vector<ll> > sc;

void xuLy(ll p, ll stt){
  if(p == s.size()){
    accepted = 1;
    return;
  }else{
    for(ll i = 0; i < sr[p].size(); i++){
      if(abs(sr[p][i] - sr[p - 1][stt]) <= 1 && abs(sc[p][i] - sc[p - 1][stt]) <= 1 && unavai[sr[p][i]][sc[p][i]] == 0){
        unavai[sr[p][i]][sc[p][i]] = 1;
        xuLy(p + 1, i);
        unavai[sr[p][i]][sc[p][i]] = 0;
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  for(ll i = 0; i < n; i++)
    for(ll j = 0; j < m; j++)
      cin >> duLieu[i][j];
  cin >> s;
  
  ll len = s.size();
  sr.resize(len);
  sc.resize(len);
  
  for(ll p = 0; p < len; p++)
    for(ll i = 0; i < n; i++)
      for(ll j = 0; j < m; j++)
        if(duLieu[i][j] == s[p]){
          sr[p].push_back(i);
          sc[p].push_back(j);
        }
        
  for(ll p = 0; p < len; p++)
    if(sr[p].size() == 0){
      cout << "NO";
      return 0;
    }
    
  for(ll i = 0; i < sr[0].size(); i++){
    if(accepted == 0){
      unavai[sr[0][i]][sc[0][i]] = 1;
      xuLy(1, i);
      unavai[sr[0][i]][sc[0][i]] = 0;
    }else break;
  }
    
  accepted == 1 ? cout << "YES" : cout << "NO";
  return 0;
}

/**
Đúng 28/30
#######################
Thông tin chi tiết
test 1 :	0.005913s 			0 MB		 [đúng]
test 2 :	0.009554s 			0 MB		 [đúng]
test 3 :	0.007242s 			0 MB		 [đúng]
test 4 :	0.007383s 			0 MB		 [đúng]
test 5 :	0.008657s 			0 MB		 [đúng]
test 6 :	0.007709s 			0 MB		 [đúng]
test 7 :	0.007088s 			0 MB		 [đúng]
test 8 :	0.007117s 			0 MB		 [đúng]
test 9 :	0.006910s 			0 MB		 [đúng]
test 10 :	0.007344s 			0 MB		 [đúng]
test 11 :	0.008343s 			0 MB		 [đúng]
test 12 :	0.008185s 			0 MB		 [đúng]
test 13 :	0.007775s 			0 MB		 [đúng]
test 14 :	0.007253s 			0 MB		 [đúng]
test 15 :	0.007488s 			0 MB		 [đúng]
test 16 :	0.006408s 			0 MB		 [đúng]
test 17 :	0.015328s 			0 MB		 [đúng]
test 18 :	0.007701s 			0 MB		 [đúng]
test 19 :	0.007620s 			0 MB		 [đúng]
test 20 :	0.006847s 			0 MB		 [đúng]
test 21 :	0.006562s 			0 MB		 [đúng]
test 22 :	0.006469s 			0 MB		 [đúng]
test 23 :	0.007903s 			0 MB		 [đúng]
test 24 :	0.006589s 			0 MB		 [đúng]
test 25 :	0.007085s 			0 MB		 [đúng]
test 26 :	0.007431s 			0 MB		 [đúng]
test 27 :	0.006998s 			0 MB		 [đúng]
test 28 :	0.006782s 			0 MB		 [đúng]
test 29 :	TLE     			0 MB		'[Time limit exceeded]'
test 30 :	TLE     			0 MB		'[Time limit exceeded]'
*/
