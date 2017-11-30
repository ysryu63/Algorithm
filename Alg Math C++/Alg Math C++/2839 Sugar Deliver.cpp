#include <iostream>

using namespace std;
#define SIZE 99999999
int main()
{
	int n;

	cin >> n;

	int x, y;	//x = 3kg ºÀÁö °¹¼ö, y = 5kg ºÀÁö °¹¼ö
	int min = SIZE;
	for (int i = 0; i <= n; i += 3) {
		for (int j = 0; j <= n; j += 5) {
			if (i + j == n) {
				if (min > i / 3 + j / 5)
					min = i / 3 + j / 5;
				break;
			}
		}
	}
	if (min == SIZE)
		min = -1;

	cout << min << endl;

	return 0;
}