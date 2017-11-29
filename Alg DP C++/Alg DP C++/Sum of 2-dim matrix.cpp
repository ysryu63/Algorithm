#include <iostream>

using namespace std;

long long d[300][300];
long long A[300][300];
int main()
{
	int i, j, x, y;

	int n, m;

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> A[i][j];
		}
	}
	int t;
	cin >> t;

	while (t--) {
		int sum = 0;
		cin >> i >> j >> x >> y;

		for (int k = i; k <= x; k++) {
			for (int l = j; l <= y; l++) {
				sum += A[k][l];
			}
		}
		cout << sum << endl;
	}
	return 0;
}
