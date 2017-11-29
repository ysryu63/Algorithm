#include <iostream>

using namespace std;

int min(int x, int y) {
	return x < y ? x : y;
}

int main()
{
	int x, y, w, h;

	cin >> x >> y >> w >> h;

	int result = min(min(x, y), min(w - x, h - y));

	cout << result;

	return 0;
}