#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool kt_hop_le(vector<vector<char> > banco){
  bool check = true;
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++)
      if(banco[i][j] != 'X' && banco[i][j] != 'O' && banco[i][j] != '.')
        check = false;
  
  if(check == false) return false;
  
  int iC_X(0);
  int iC_O(0);
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++){
      if(banco[i][j] == 'O') iC_O++;
      if(banco[i][j] == 'X') iC_X++;
    }
  
  if(iC_X - iC_O >= 2 || iC_O > iC_X) return false;
  return true;
}

int find_winner(vector<vector<char> > banco){
  int stplayer = 0;
  int ndplayer = 0;
  int dem;
  
  // Kiem tra theo dong
  for(int i = 0; i < 3; i++){
    dem = 1;
    for(int j = 1; j < 3; j++){
      if(banco[i][j - 1] == banco[i][j]) dem++;
      else break;
    }
    if(dem == 3 && banco[i][0] == 'X') stplayer = 1;
    if(dem == 3 && banco[i][0] == 'O') ndplayer = 1;
  } 
  
  // Kiem tra theo cot
  for(int i = 0; i < 3; i++){
    dem = 1;
    for(int j = 1; j < 3; j++){
      if(banco[j - 1][i] == banco[j][i]) dem++;
      else break;
    }
    if(dem == 3 && banco[0][i] == 'X') stplayer = 1;
    if(dem == 3 && banco[0][i] == 'O') ndplayer = 1;
  } 
  
  int i = 0;
  dem = 1;
  // Kiem tra cheo trai
  while(i < 2){
    if(banco[i][i] == banco[i + 1][i + 1]) dem++;
    else break;
    i++;
  }
  if(dem == 3 && banco[0][0] == 'X') stplayer = 1;
  if(dem == 3 && banco[0][0] == 'O') ndplayer = 1;

  i   = 2;
  dem = 1;
  // Kiem tra cheo phai
  while(i >= 1){
    if(banco[i][2 - i] == banco[i - 1][2 - i + 1]) dem++;
    else break;
    i--;
  }
  if(dem == 3 && banco[2][0] == 'X') stplayer = 1;
  if(dem == 3 && banco[2][0] == 'O') ndplayer = 1;
  
  if(stplayer == 1 && ndplayer == 1) return 3;
  if(stplayer == 1 && ndplayer == 0) return 1;
  if(stplayer == 0 && ndplayer == 1) return 2;
  
  return 0;
}

int find_nextturn(vector<vector<char> > banco){
  int iC_X(0);
  int iC_O(0);
  int iC_p(0);
  
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++){
      if(banco[i][j] == '.') iC_p++;
      if(banco[i][j] == 'X') iC_X++;
      if(banco[i][j] == 'O') iC_O++;
    }
  
  if(iC_p ==    0) return 0;
  if(iC_X >  iC_O) return 2;
  if(iC_X == iC_O) return 1;
} 
int main() {
  vector<vector<char> > banco(3, vector<char> (3));
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++)
      cin >> banco[i][j];
      
  if(kt_hop_le(banco)){
    int tmp = find_winner(banco);
    if(tmp == 0){
      int tmp1 = find_nextturn(banco);
      if(tmp1 == 0) cout << "draw";
      if(tmp1 == 1) cout << "first";
      if(tmp1 == 2) cout << "second"; 
    }
    else if(tmp == 1) cout << "the first player won";
    else if(tmp == 2) cout << "the second player won";
    else if(tmp == 3) cout << "illegal";
  } 
  else 
    cout << "illegal";
      
  return 0;
}
