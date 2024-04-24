#include <string>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class customer;
class book{
  friend customer;
protected:
  string id;
  int tgian;
  double cost;
  int number;
  double tiencoc;
  double tienmuon;
public:
  book(string _id = "", int _tgian = 0, double _cost = 0, int _number = 0){
    // kh?i t?o mã sách
    id = _id;
    // kh?i t?o t?ng th?i gian mu?n sách
    tgian = _tgian;
    // kh?i t?o giá sách
    cost = _cost;
    // kh?i t?o s? lu?ng sách
    number = _number;
    // kh?i t?o giá ti?n
    if(id == "SGK"){
      tiencoc = 30000;
      tienmuon = 1000;
    }
    if(id == "SGT"){
      tiencoc = 35000;
      tienmuon = 1100;
    }
    if(id == "SPL"){
      tiencoc = 35000;
      tienmuon = 1500;
    }
    if(id == "SCI"){
      tiencoc = 20000;
      tienmuon = 2000;
    }
    if(id == "EB"){
      tiencoc = 40000;
      tienmuon = 3000;
    }
  }
  
  book(const book & a){
    id = a.id;
    tgian = a.tgian;
    cost = a.cost;
    number = a.number;
    tiencoc = a.tiencoc;
    tienmuon = a.tienmuon;
  }
  
  friend istream & operator>>(istream & is, book & p){
    is >> p.id >> p.tgian >> p.number;
    if(p.id == "SGK"){
      p.tiencoc = 30000;
      p.tienmuon = 1000;
    }
    if(p.id == "SGT"){
      p.tiencoc = 35000;
      p.tienmuon = 1100;
    }
    if(p.id == "SPL"){
      p.tiencoc = 35000;
      p.tienmuon = 1500;
    }
    if(p.id == "SCI"){
      p.tiencoc = 20000;
      p.tienmuon = 2000;
    }
    if(p.id == "EB"){
      p.tiencoc = 40000;
      p.tienmuon = 3000;
    }
    return is;
  }
  
  friend ostream & operator<<(ostream & os, book p){
    // xu?t id
    if(p.id == "SGK") os << "-Sach Giao Khoa ";
    if(p.id == "SGT") os << "-Sach Giao Trinh ";
    if(p.id == "SPL") os << "-Sach Phap Luat ";
    if(p.id == "SCI") os << "-Tap Chi Khoa Hoc ";
    if(p.id == "EB") os << "-Sach Ngoai Ngu ";
    
    // xu?t ngày mu?n
    os << p.tgian << "-Ngay ";
    
    // xu?t s? lu?ng
    os << p.number << "-Quyen\n";
    return os;
  }
  
  
};
class customer{
protected:
  string type;
  string range;
  string id;
  string name;
  string phonenum;
  double totalcost;
  double tiendua;
  book item[1000];
  int numberitem;
public:
  customer(string _type = "", string _range = "", string _id = "", string _name = "", string _phonenum = ""){
    type     = _type;
    range    = _range;
    id       = _id;
    name     = _name;
    phonenum = _phonenum;
  }
  
  customer(customer & p){
    type       = p.type;
    range      = p.range;
    id         = p.id;
    name       = p.name;
    phonenum   = p.phonenum;
    numberitem = p.numberitem;
    for(int i = 0; i < p.numberitem; i++)
      item[i] = p.item[i];
    tiendua    = p.tiendua;
  }
  
  friend istream & operator>> (istream & is, customer & p){
    is >> p.type >> p.range >> p.id;
    is.ignore();
    getline(is, p.name);
    is >> p.phonenum >> p.numberitem;
    for(int i = 0; i < p.numberitem; i++){
      is >> p.item[i];
    }
    
    is >> p.tiendua;
    return is;
  }
  
  friend ostream & operator<< (ostream & os, customer p){
    // xu?t dòng 1
    if(p.type == "GV") os << "Loai Khach Hang: GiangVien/GiaoVien\n";
    if(p.type == "HS") os << "Loai Khach Hang: HocSinh/SinhVien\n";
    // xu?t dòng 2
    os << "Hang Khach Hang: "    << p.range       << endl;
    // xu?t dòng 3
    os << "Ma So Khach Hang: "   << p.id          << endl;
    // xu?t dòng 4
    os << "Ho va Ten: "          << p.name        << endl;
    // xu?t dòng 5
    os << "So Dien Thoai: "      << p.phonenum    << endl;
    // xu?t dòng 6
    os << "So quyen sach muon: " << p.numberitem << endl;
    // xu?t dòng 7
    os << "Danh Sach Cac Quyen Sach Muon: \n";
    for(int i = 0; i < p.numberitem; i++) 
      os << p.item[i];
    // xu?t dòng 8
    double tmp = p.tinhtien();
    os << "Tong Tien: "    << fixed << tmp << endl;
    // xu?t dòng 9
    os << "Tien Tra Lai: " << fixed << p.tiendua - tmp << endl;
    
    return os;
  }
  
  double tinhtien(){
    double tong = 0;
    double tien = 0;
    int tong_sach = 0;
    if(type == "GV"){
      for(int i = 0; i < numberitem; i++){
        if(item[i].tgian <= 15) tien = 0;
        else if(15 < item[i].tgian && item[i].tgian <= 30) tien = item[i].tienmuon;
        else tien = item[i].tienmuon * pow((1 + 0.03), item[i].tgian) * item[i].number;
        tong += tien;
        tong_sach += item[i].number;
      }
    }else{
      double phi;
      for(int i = 0; i < numberitem; i++){
        phi = item[i].tiencoc * item[i].number;
        if(item[i].tgian <= 15) tien = item[i].tienmuon * item[i].number;
        else tien = item[i].tienmuon * pow((1 + 0.05), item[i].tgian) * item[i].number;
        tong += (tien + phi);
      }
    }
    
    if(tong_sach >= 10) tong *= (1 - 0.5);
    if(range == "Vang") tong *= (1 - 0.3);
    if(range == "Bac")  tong *= (1 - 0.2);
    if(range == "Dong") tong *= (1 - 0.1);
    return tong;
  }
};


int main(){
  int n;
  cin >> n;
  
  vector<customer> a(n);
  for(int i = 0; i < n; i++) cin  >> a[i];
  for(int i = 0; i < n; i++) cout << a[i] << endl;

}
