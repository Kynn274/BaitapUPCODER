#include <bits/stdc++.h>
#define ll long long
#define fmax 102
using namespace std;

// Sai 4 testcase
string L[fmax][fmax][fmax];

string longestString(string a, string b){
  if(a.size() >= b.size()) return a;
  return b;
}

string LCS(string s1, string s2, string s3){
  int m = s1.size(), n = s2.size(), t = s3.size();

  for(int i = 0; i <= m; i++)
    for(int j = 0; j <= n; j++)
      for(int k = 0; k <= t; k++)
        if(i == 0 || j == 0 || k == 0)
          L[i][j][k] = "";
        
  for(int i = 1; i <= m; i++)
    for(int j = 1; j <= n; j++)
      for(int k = 1; k <= t; k++)
        if(s1[i - 1] == s2[j - 1] && s1[i - 1] == s3[k - 1])
          L[i][j][k] = L[i - 1][j - 1][k - 1] + s1[i - 1];
        else 
          L[i][j][k] = longestString(L[i - 1][j][k], longestString(L[i][j - 1][k], L[i][j][k - 1]));
  
  return L[m][n][t];
}

int main(){
  string s1, s2, s3;
  cin >> s1 >> s2 >> s3;
  
  string ans;
  ans = LCS(s1, s2, s3);
  
  cout << ans;
  return 0;
}
