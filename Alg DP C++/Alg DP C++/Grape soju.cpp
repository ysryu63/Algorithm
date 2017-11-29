#include <iostream>

using namespace std;

int d[10001];
int p[10001];

int max(int x, int y) {
	return (x > y) ? x : y;
}

int main()
{
	int n;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}
	d[1] = p[1];
	d[2] = p[1] + p[2];
	for (int i = 3; i <= n; i++) {
		d[i] = max(d[i - 1], max(p[i] + p[i - 1] + d[i - 3], p[i] + d[i - 2]));
	}

	cout << d[n];

	return 0;
}