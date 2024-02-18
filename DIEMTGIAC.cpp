#include <iostream>
#include <cmath>
using namespace std;

struct Diem{
	int x,y;
};

istream & operator>>(istream & is, Diem&p){
	is>>p.x>>p.y;
	return is;
}
ostream & operator<<(ostream & os, Diem p){
	os<<'('<<p.x<<','<<p.y<<')';
	return os;
}

double tinh_d(Diem a, Diem b){
	double d=0;
	d=double(sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)));
	return d;
}

bool operator==(Diem a, Diem b){
	return a.x==b.x && a.y==b.y;
}

double CV(Diem a, Diem b, Diem c){
	return double(tinh_d(a,b)+tinh_d(a,c)+tinh_d(b,c));
}

bool same_tgiac(Diem a, Diem b, Diem c, Diem _a, Diem _b, Diem _c){
	if(a==_a || a==_b || a==_c){
		if(a==_a){
			if(b==_b||b==_c){
				if(b==_b){
					if(c==_c) return true;
				}
				else if(b==_c){
					if(c==_b) return true;
				}
			}
		}else if(a==_b){
			if(b==_a||b==_c){
				if(b==_a){
					if(c==_c) return true;
				}
				else if(b==_c){
					if(c==_a) return true;
				}
			}
		}else if(a==_c){
			if(b==_a||b==_b){
				if(b==_a){
					if(c==_b) return true;
				}
				else if(b==_b){
					if(c==_a) return true;
				}
			}
		}
	}else if(b==_a || b==_b || b==_c){
		if(b==_a){
			if(a==_b||a==_c){
				if(a==_b){
					if(c==_c) return true;
				}
				else if(b==_c){
					if(c==_b) return true;
				}
			}
		}else if(b==_b){
			if(a==_a||a==_c){
				if(a==_a){
					if(c==_c) return true;
				}
				else if(a==_c){
					if(c==_a) return true;
				}
			}
		}else if(b==_c){
			if(a==_a||a==_b){
				if(a==_a){
					if(c==_b) return true;
				}
				else if(a==_b){
					if(c==_a) return true;
				}
			}
		}
	}else if(c==_a || c==_b || c==_c){
		if(c==_a){
			if(b==_b||b==_c){
				if(b==_b){
					if(a==_c) return true;
				}
				else if(b==_c){
					if(a==_b) return true;
				}
			}
		}else if(c==_b){
			if(b==_a||b==_c){
				if(b==_a){
					if(a==_c) return true;
				}
				else if(b==_c){
					if(a==_a) return true;
				}
			}
		}else if(c==_c){
			if(b==_a||b==_b){
				if(b==_a){
					if(a==_b) return true;
				}
				else if(b==_b){
					if(a==_a) return true;
				}
			}
		}
	}
	return false;
}
int main(){
	Diem a,b,c;
	Diem _a,_b,_c;
	cin>>a>>b>>c>>_a>>_b>>_c;
	cout<<a<<b<<c<<endl;
	cout<<_a<<_b<<_c<<endl;
	if(CV(a,b,c)<CV(_a,_b,_c)) cout<<"TRUE"<<endl;
	else cout<<"FALSE"<<endl;
	if(same_tgiac(a,b,c,_a,_b,_c)) cout<<"TRUE";
	else cout<<"FALSE";
}
