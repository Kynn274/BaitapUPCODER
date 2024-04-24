#include <iostream>
#include <fstream>

using namespace std;

int n, sx, sy, dx, dy;
bool check = false;
int mx[] = { -1, 0, 1, 0 };
int my[] = { 0,1,0,-1 };
int tick[100][100];
int a[100][100];

void Try(int x, int y) {
	if (x == dx && y == dy) {
		check = true;
	}
	else {
		for (int i = 0; i < 4; i++) {
			int newx = x + mx[i];
			int newy = y + my[i];
			if (1 <= newx && newx <= n && 1 <= newy && newy <= n && a[newy][newx] == 0) {
				a[newy][newx] = 1;
				Try(newx, newy);
				a[newy][newx] = 0;
			}
		}
	}
}

int main() {
	ifstream ip("LINE.inp");
	ofstream op("LINE.out");

    ip >> n >> sy >> sx >> dy >> dx;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ip >> a[i][j];
			tick[i][j] = 0;
		}
	}
	Try(sx, sy);
	if (check == true) {
		op << "YES";
	}
	else {
		op << "NO";
	}
    
    
	ip.close();
	op.close();
}
