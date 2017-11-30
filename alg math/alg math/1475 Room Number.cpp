#include <iostream>

using namespace std;

int num[10];

int main()
{
	int n;
	cin >> n;

	int i = 0;
	while (n > 0) {
		int l = n % 10;
		if (l == 9) {
			num[6]++;
		}
		else
			num[l]++;
		n = n / 10;
	}
	num[6] = num[6] / 2 + num[6] % 2;
	int max = 0;
	for (int p = 0; p <= 8; p++) {
		if (max < num[p])
			max = num[p];
	}

	cout << max << endl;

	return 0;
}