#include <iostream>

using namespace std;

int d[40];

int fibonacci(int n) {
	d[1] = 1;
	d[0] = 0;
	if (n == 0 || n == 1) {
		return n;
	}
	else {
		int i = 2;

		while (1) {
			d[i] = d[i - 1] + d[i - 2];
			i++;
			if (d[n] != 0) {
				break;
			}
		}
	}
	return d[n];
}

int main()
{
	int n;
	int t;
	cin >> t;

	while (t--) {
		cin >> n;
		fibonacci(n);
		printf("%d %d\n", d[n - 1], d[n - 2]);
	}
	//printf("%d", fibonacci(n));

	return 0;
}