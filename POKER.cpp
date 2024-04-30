#include <iostream>
#include <vector>
#define J 11;
#define Q 12;
#define K 13;
using namespace std;

// 1. Dùng queue và stack
int main(){
  long long n;
  cin >> n;                                                // Nhập số lượng lá bài
  
  vector<string> v(n);
  for(long long i = 0; i < n ; i++)
    cin >> v[i];                                           // Nhập các lá bài được chọn
  
  vector<int> L;
  vector<int> N;
  long long i = 0;
  int tmp;
  while(i < n){                                            // Lấy giá trị các lá bài, chia cho Lan và Ngọc
    if(v[i] == "1" ) tmp = 1;
    if(v[i] == "2" ) tmp = 2;
    if(v[i] == "3" ) tmp = 3;
    if(v[i] == "4" ) tmp = 4;
    if(v[i] == "5" ) tmp = 5;
    if(v[i] == "6" ) tmp = 6;
    if(v[i] == "7" ) tmp = 7;
    if(v[i] == "8" ) tmp = 8;
    if(v[i] == "9" ) tmp = 9;
    if(v[i] == "10") tmp = 10;
    if(v[i] == "J" ) tmp = J;
    if(v[i] == "Q" ) tmp = Q;
    if(v[i] == "K" ) tmp = K;
    if(i % 2 == 0) L.push_back(tmp);                       // Lấy bài cho Lan
    if(i % 2 != 0) N.push_back(tmp);                       // Lấy bài cho Ngọc
    i++;
  }
  
  int dem = N.size();                                      // biến đếm số lượng lá bài còn lại của Ngọc
  int _min = 15;
  int vt;
  vector<bool> c_N(n / 2, 1);
  for(int i = 0; i < n / 2; i++){
    for(int j = 0; j < n / 2; j++){
      if(c_N[j] == 1 && N[j] >= L[i] && N[j] < _min){      // Tìm trong những lá bài chưa được chọn lá nhỏ nhất lớn hơn lá bài của Lan
        _min = N[j];                                       // Gán giá trị nhỏ nhất
        vt = j;                                            // Gán vị trí lá bài
      }
    }
    if(_min != 15){
      c_N[vt] = 0;                                         // Đánh dấu lá bài được chọn
      dem--;                                               // Trừ số lượng lá bài còn lại
    }
    _min = 15;
  }
  
  cout << dem;
  return 0;
}
