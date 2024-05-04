#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

/*
1. class Vector
	2.  Vector::Vector()
	3.  Vector::Vector(int px, int py, int pz)
	4.  Vector::Vector(const Vector& pu)
	5.  int Vector::getX()
	6.  int Vector::getY()
	7.  int Vector::getZ()
	8.  void Vector::setX(int px)
	9.  void Vector::setY(int py)
	10.  void Vector::setZ(int pz)
	11.  double Vector::F()
	12.  Vector Vector::operator+(Vector pv)
	13.  istream& operator >> (istream& cin, Vector& pu)
	14.  ostream& operator << (ostream& cout, Vector& pu)
	15.  Vector Vector::operator - ( Vector pv)
*/
class vector{
  int x, y, z;
public:
  vector(int _x = 0, int _y = 0, int _z = 0){
    x = _x;
    y = _y;
    z = _z;
  }
  vector(const vector & a){
    x = a.x;
    y = a.y;
    z = a.z;
  }
  double length(){
    return (double) sqrt(x * x + y * y + z * z);
  }
  vector operator+(vector a){
    vector u;
    u.x = x + a.x;
    u.y = y + a.y;
    u.z = z + a.z;
    return u;
  }
  vector operator-(vector a){
    vector u;
    u.x = x - a.x;
    u.y = y - a.y;
    u.z = z - a.z;
    return u;
  }
  friend istream & operator>>(istream & is, vector & p){
    is >> p.x >> p.y >> p.z;
    return is;
  }
  friend ostream & operator<<(ostream & os, vector p){
    os << '(' << p.x << ',' << p.y << ',' << p.z << ')';
    return os;
  }
};
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  vector a, b;
  cin >> a >> b;
  
  cout << a << endl;
  cout << roundf(a.length() * 100) / 100 << endl;
  cout << b << endl;
  cout << roundf(b.length() * 100) / 100 << endl;
  cout << a + b << endl;
  cout << a - b << endl;
  return 0;
}
