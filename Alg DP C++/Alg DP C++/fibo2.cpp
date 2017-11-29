#include <iostream>

using namespace std;

int d[40][2];

int main()
{
	int n;
	int t;
	cin >> t;

	d[0][0] = 1;
	d[0][1] = 0;

	d[1][0] = 0;
	d[1][1] = 1;
	while (t--) {
		cin >> n;
		if (n == 0 || n == 1) {
			cout << d[n][0] << " " << d[n][1] << endl;
		}
		else {
			int i = 2;
			while (1) {
				d[i][0] = d[i - 1][0] + d[i - 2][0];
				d[i][1] = d[i - 1][1] + d[i - 2][1];
				i++;
				if (d[n][0] != 0 && d[n][1] != 0) {
					cout << d[n][0] << " " << d[n][1] << endl;
					break;
				}
			}

		}
	}


	return 0;
}