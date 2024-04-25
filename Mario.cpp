#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  string _stt;
  int t, stt, money;
  cin >> t >> _stt >> money;
  
  if(_stt == "Small") stt = 0;
  else if(_stt == "Big") stt = 1;
  else if(_stt == "Gun") stt = 2;
  else if(_stt == "Death") stt = -1;
  
  int event[1000];
  for(int i = 0; i < t; i++) cin >> event[i];
  
  int dem = 0;
  while(t != 0 && stt != -1){
    if(event[dem] == 1)
      if(stt < 2) stt++;
    if(event[dem] == 2) money++;
    if(event[dem] == 3) stt--;
    dem++;
    t--;
  }
  
  cout << t << ' ';
  if(stt == -1) cout << "Death ";
  else if(stt == 0) cout << "Small ";
  else if(stt == 1) cout << "Big ";
  else if(stt == 2) cout << "Gun ";
  if(stt == -1) cout << 0;
  else cout << money;
  return 0;
}
