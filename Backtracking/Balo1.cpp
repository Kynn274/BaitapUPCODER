#include <iostream>
#include <vector>
using namespace std;

int n, w;
int Smax = -1e9;
vector<int> result;

void balo(vector<int> v, vector<int> p, int k){
  if(k >= n){
    int s (0);
    for(int i = 0; i < p.size(); i++)
      s += v[p[i]];
    if(s > Smax && s <= w){
      Smax = s;
      result.clear();
      for(int i = 0; i < p.size(); i++)
        result.push_back(p[i]);
    }
  }else{
    p.push_back(k);
    balo(v, p, k + 1);
    p.pop_back();
    balo(v, p, k + 1);
  }
}

int main(){
  cin >> n >> w;
  
  vector<int> v(n);
  for(int i = 0; i < n; i++) cin >> v[i];
  
  vector<int> p;
  balo(v, p, 0);
  
  cout << Smax << endl;
  for(int i = 0; i < result.size(); i++) cout << result[i] << ' ';
  return 0;
}
