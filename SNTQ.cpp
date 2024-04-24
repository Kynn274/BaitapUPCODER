#include <iostream>
using namespace std;

bool snt(int n){
  if(n == 2 || n == 3 || n == 5 || n == 7) return true;
  return false;
}

int main(){
  string n;
  int q;
  bool check[10];
  
  for(int i = 0; i <= 9; i++) check[i] = 0;
  cin >> n >> q;
  
  string tmp;
  for(int i = 0; i < n.size(); i++){
    tmp = tmp + n[i];
    check[stoi(tmp)] = 1;
    tmp.clear();
  }
    
  int i = 0, j = 0;
  while(i != q && j <= 9){
    if(check[j] == 1) i++;
    j++;
  }
  
  if(i == q){
    if(snt(j - 1)) cout << j - 1 << " Yes";
    else cout << j - 1 << " No";
  }else cout << -1;
  
  return 0;
}
