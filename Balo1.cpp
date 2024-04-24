#include <iostream>
using namespace std;

int n, w;
int a[100];
int _max = 0, tong;

void Try(int t, int tong) {
	if (t<= n) {
		if (_max < tong) {
			_max = tong;
		}
	}
	for (int i = t; i < n; i++) {
			if (tong + a[i] <= w) {
				Try(t + 1, tong + a[i]);
			}
		}
	
	
}

int temp[100];
int dem = 0;

void do_it(int t, int _max) {
	for (int i = t; i < n; i++) {
		if (_max - a[i] == 0) {
			temp[dem] = i;
			dem++;
			for (int j = 0; j < dem; j++) {
				cout << temp[j] << ' ';
			}
			cout << endl;
			dem--;
		}
		else {
			if (_max - a[i] > 0) {
				_max -= a[i];
				temp[dem] = i;
				dem++;
				do_it(i + 1, _max);
				dem--;
				_max += a[i];
			}
		}
	}
}

int main() {
	cin >> n >> w;
	int t = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	Try(0,0);
	cout << _max << endl;
	do_it(0, _max);
}


