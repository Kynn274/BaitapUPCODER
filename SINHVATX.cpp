#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;


int main(){
  vector<long long> duc;
  vector<long long> cai;
  
  duc.push_back(1);
  cai.push_back(0);
  
  int n;
  cin >> n;
  
  for(int i = 1; i < n; i++){
    duc.push_back(cai[i-1]);
    cai.push_back(duc[i-1] + cai[i-1]);
  }
  
  cout << duc[n-1] + cai[n-1] << endl;
  cout << duc[n-1];
}
