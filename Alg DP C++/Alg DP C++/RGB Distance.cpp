#include <iostream>

using namespace std;

int p[1001][4];
int d[1001][4];

int min(int x, int y) {
	return (x < y) ? x : y;
}

int main()
{
	int n;

	int r, g, b;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> p[i][1] >> p[i][2] >> p[i][3];
	}

	for (int i = 1; i <= n; i++) {
		d[i][1] = p[i][1] + min(d[i - 1][2], d[i - 1][3]);
		d[i][2] = p[i][2] + min(d[i - 1][1], d[i - 1][3]);
		d[i][3] = p[i][3] + min(d[i - 1][1], d[i - 1][2]);
	}

	int result = min(min(d[n][1], d[n][2]), d[n][3]);

	printf("%d", result);

	return 0;
}
