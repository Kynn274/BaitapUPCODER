#include <bits/stdc++.h>
using namespace std;

class milktea{
  string name;
  long  price;
  long number;
  string thph;
  string  hsd;
public:
  milktea (string _name = "", long _price = 0, long _number = 0, string _thph = "", string _hsd = ""){
    name = _name;
    price = _price;
    number = _number;
    thph = _thph;
    hsd = _hsd;
  }
  milktea (const milktea & a){
    name = a.name;
    price = a.price;
    number = a.number;
    thph = a.thph;
    hsd = a.hsd;
  }
  friend istream & operator >> (istream & is, milktea & p){
    getline(is, p.name);
    is >> p.price >> p.number;
    is.ignore();
    getline(is, p.thph);
    is >> p.hsd;
    is.ignore();
    return is;
  }
  friend ostream & operator << (ostream & os, milktea p){
    string s = p.name;
    transform(s.begin(), s.end(), s.begin(), :: tolower);
    os << "Thong tin cua " << s << ":\n";
    os << "Ten: " << p.name << endl;
    os << "Gia: " << p.price << endl;
    os << "So luong: " << p.number << endl;
    os << "Thanh phan: " << p.thph << endl;
    os << "Han su dung: " << p.hsd << endl << endl;
    return os;
  }
  long operator + (long tong){
    return price * number + tong;
  }
  string get_name(){
    return name;
  }
};

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  milktea a[1000];
  long n = 0;
  while(cin >> a[n]){
    n++;
  }
  for(long i = 0; i < n; i++)
    cout << a[i];
  
  long tong1 = 0, tong2 = 0, tong3 = 0;
  string s;
  for(long i = 0; i < n; i++){
    s = a[i].get_name();
    while(s[s.size() - 1] == ' ') 
        s.erase(s.size() - 1, 1);
    if(s == "Tra sua tran chau")
      tong1 = a[i] + tong1;
    if(s == "Tra sua socola")
      tong2 = a[i] + tong2;
    if(s == "Tra sua dau")
      tong3 = a[i] + tong3;
  }
  cout << "Tong tien cua tra sua tran chau: " << tong1 << endl;
  cout << "Tong tien cua tra sua socola: " << tong2 << endl;
  cout << "Tong tien cua tra sua dau: " << tong3;
  return 0;
}
