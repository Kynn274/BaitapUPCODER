#include <bits/stdc++.h>
using namespace std;

bool snt(int n){
  if(n < 2) return 0;
  if(n == 2 || n == 3) return true;
  for(int i = 2; i <= sqrt(n); i++)
    if(n % 2 == 0) return false;
  return true;
}

int main() {
  int s;
  int tong(0);
  cin >> s;
  while(s){
    if(!snt(s % 10)){
      cout << "YESNOT";
      return 0;
    }
    tong += s % 10;
    s /= 10;
  }
  
  snt(tong) ? cout << "YES" : cout << "YESNOT";
    
  return 0;
}
/*
Đúng 7/7
#######################
Thông tin chi tiết
test 1 :	0.007889s 			0 MB		 [đúng]
test 2 :	0.007379s 			0 MB		 [đúng]
test 3 :	0.008025s 			0 MB		 [đúng]
test 4 :	0.007806s 			0 MB		 [đúng]
test 5 :	0.007491s 			0 MB		 [đúng]
test 6 :	0.007250s 			0 MB		 [đúng]
test 7 :	0.008862s 			0 MB		 [đúng]
*/
