#include <iostream>

using namespace std;

#define SIZE 100000

int d[SIZE];
int num[SIZE];

int max(int x, int y) {
	return x > y ? x : y;
}

int main()
{
	int n;
	int r = -1000;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> num[i];
	}
	d[1] = num[1];
	for (int i = 2; i <= n; i++) {
		d[i] = max(d[i - 1] + num[i], num[i]);
		r = max(r, d[i]);
	}

	r = max(r, d[1]);

	cout << r;

	return 0;
}