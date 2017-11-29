#include <iostream>

using namespace std;

long long p[101];

int main()
{
	int t;

	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		for (int i = 1; i <= n; i++) {
			if (i <= 3) {
				p[i] = 1;
			}
			else if (i == 4) {
				p[i] = 2;
			}
			else {
				p[i] = p[i - 1] + p[i - 5];
			}
		}
		cout << p[n] << endl;
	}
	return 0;
}