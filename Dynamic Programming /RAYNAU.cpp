#include <iostream>
#include <vector>
using namespace std;

int m, n;                                                                                                          // Kích thước ma trận 
void xuly(vector<vector<int> > land){
  int dem = 1;                                                                                                     // Biến đánh dấu thứ tự cụm liên tiếp
  vector<vector<int> > lan1(m + 1, vector<int> (n + 1, 0));                                                        // Ma trận đánh dấu cụm liên tiếp theo số thứ tự
  for(int i = 1; i <= m; i++)
    for(int j = 1; j <= n; j++)
      if(land[i][j] == 1){
        if(lan1[i - 1][j] != 0 || lan1[i][j - 1] != 0) lan1[i][j] = max(lan1[i - 1][j], lan1[i][j - 1]);           // Nếu có rầy, kiểm tra xung quanh có rầy không, nếu có thì đánh theo thứ tự cái trước đó, hoặc đánh thứ tự mới nhất
        else lan1[i][j] = dem ++;
      }

  vector<int> lan2(dem, 0);                                                                                        // Mảng đếm số lượng từng cụm có bao nhiêu ô có rầy
  int tong = 0;                                                                                                    // Đếm tổng số lượng ô có rầy
  for(int i = 1; i <= m; i++)
    for(int j = 1; j <= n; j++){
      lan2[lan1[i][j]] ++;
      if(lan1[i][j] != 0) tong++;
    }
      
  vector<vector<int> > x(dem);                                                                                      // Vị trí dòng những ô có rầy từng cụm
  vector<vector<int> > y(dem);                                                                                      // Vị trí cột những ô có rầy từng cụm
  for(int i = 1; i <= m; i++)
    for(int j = 1; j <= n; j++){
      x[lan1[i][j]].push_back(i);
      y[lan1[i][j]].push_back(j);
    }

  cout << tong << endl;                                                                                             // Xuất tổng số lượng ô có rầy
  for(int i = 1; i < dem; i++){
    cout << lan2[i] << ' ';                                                                                         // Xuất số lượng từng cụm có rầy
    for(int j = 0; j < x[i].size() - 1; j++)                                                                        // Xuất vị trí các ô có rầy
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
