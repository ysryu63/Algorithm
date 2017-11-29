#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

int A[1001];
int d[1001];

int main()
{
	int n;

	int cnt;
	d[0] = 0;
	int min;

	cin >> n;
	int max = 0;

	for (int i = 1; i <= n; i++) {
		cin >> A[i];
	}

	//d[1] = 1;
	for (int i = 1; i <= n; i++) {
		min = 0;
		for (int j = 0; j <= i; j++) {
			if (A[i] > A[j]) {
				if (min < d[j])
					min = d[j];
			}
		}
		d[i] = min + 1;
		if (max < d[i])
			max = d[i];
	}
	cout << max;

	return 0;
}