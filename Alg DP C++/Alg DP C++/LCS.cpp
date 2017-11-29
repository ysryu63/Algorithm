#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

long long d[1001][1001];
char x[1000], y[1000];

int max(int x, int y) {
	return x>y ? x : y;
}

int main()
{
	clock_t begin, end, time;
	begin = clock();

	int lx, ly;

	cin >> x >> y;

	lx = strlen(x);
	ly = strlen(y);

	for (int i = 1; i <= lx; i++) {
		for (int j = 1; j <= ly; j++) {
			if (x[i - 1] == y[j - 1]) {
				d[i][j] = d[i - 1][j - 1] + 1;
			}
			else {
				d[i][j] = max(d[i - 1][j], d[i][j - 1]);
			}
		}
	}

	cout << d[lx][ly] << endl;

	end = clock();
	time = (end - begin) / CLOCKS_PER_SEC;

	cout << "Spend time = " << time << endl;

	return 0;
}