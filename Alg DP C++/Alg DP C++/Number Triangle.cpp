#include <iostream>
#include <vector>

using namespace std;

long long p[501][501];
long long d[501][501];

int max(int x, int y) { return (x > y) ? x : y; }

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> p[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			d[i][j] = p[i][j] + max(d[i - 1][j - 1], d[i - 1][j]);
		}
	}


	int max = 0;
	for (int i = 1; i <= n; i++) {
		if (max < d[n][i])
			max = d[n][i];
	}

	cout << max << endl;

	return 0;
}