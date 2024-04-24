#include <iostream>
using namespace std;

int n, w;
int a[100];
int c[100];
int chon[100];
int _max = 0, tong = 0, m=0;

void Try(int t, int tong, int m) {
	if (t <= n+1) {
		if (_max < tong) {
			_max=tong;
		}
	}
	
	for (int i = t; i <= n; i++) {
		if (m + a[i] <= w) {
			chon[i] = 1;
			Try(i + 1, tong + c[i], m + a[i]);
			chon[i] = 0;
		}
	}
}

void do_it(int t, int _max) {
	for (int i = t; i <= n; i++) {
		if (_max - c[i] == 0) {
			chon[i] = 1;
			for (int j = 1; j <= n-1; j++) {
				cout << chon[j] << ' ';
			}
			cout <<chon[n]<< endl;
		}
		else {
			if (_max - c[i] > 0) {
				_max -= c[i];
				chon[i] = 1;
				do_it(i + 1, _max);
				chon[i] = 0;
				_max += c[i];

			}
		}
	}
}

int main() {
	cin >> n >> w;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		chon[i] = 0;
	}
	Try(1, 0, 0);
	cout << _max << endl;
	do_it(1, _max);

}
