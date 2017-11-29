#include <iostream>

using namespace std;

int arr[50];

int main()
{
	int n;

	cin >> n;

	int min = 1000001, max = 0;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (min > arr[i]) min = arr[i];
		if (max < arr[i]) max = arr[i];
	}

	int result = min*max;

	cout << result;

	return 0;
}