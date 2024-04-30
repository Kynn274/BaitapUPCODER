#include <iostream>
#include <vector>
using namespace std;

int m, n;
void xuly(vector<vector<int> > land){
  int dem = 1;
  vector<vector<int> > lan1(m + 1, vector<int> (n + 1, 0));
  for(int i = 1; i <= m; i++)
    for(int j = 1; j <= n; j++)
      if(land[i][j] == 1){
        if(lan1[i - 1][j] != 0 || lan1[i][j - 1] != 0) lan1[i][j] = max(lan1[i - 1][j], lan1[i][j - 1]);
        else lan1[i][j] = dem ++;
      }

  vector<int> lan2(dem, 0);
  int tong = 0;
  for(int i = 1; i <= m; i++)
    for(int j = 1; j <= n; j++){
      lan2[lan1[i][j]] ++;
      if(lan1[i][j] != 0) tong++;
    }
      
  vector<vector<int> > x(dem);
  vector<vector<int> > y(dem);
  for(int i = 1; i <= m; i++)
    for(int j = 1; j <= n; j++){
      x[lan1[i][j]].push_back(i);
      y[lan1[i][j]].push_back(j);
    }

  cout << tong << endl;
  for(int i = 1; i < dem; i++){
    cout << lan2[i] << ' ';
    for(int j = 0; j < x[i].size() - 1; j++)
      cout << '[' << x[i][j] << ',' << y[i][j] << "], ";
    cout << '[' << x[i][x[i].size() - 1] << ',' << y[i][x[i].size() - 1] << "]\n";
  }
}

int main(){
  cin >> m >> n;
  vector<vector<int> > land(m + 1, vector<int> (n + 1, 0));
  for(int i = 1; i <= m; i++)
    for(int j = 1; j <= n; j++)
      cin >> land[i][j];
  
  xuly(land);
  return 0;
}
