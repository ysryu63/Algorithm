#pragma warning (disable : 4996)
#include <iostream>
#include <algorithm>

using namespace std;
#define SIZE 5000000
//int arr[SIZE];

int main()
{
	int n;
	int k;

	//cin >> n;
	scanf("%d %d", &n, &k);

	//cin >> k;

	int *arr = (int *)malloc(sizeof(int)*n);

	for (int i = 0; i < n; i++) {
		//cin >> arr[i];
		scanf("%d", &arr[i]);
	}

	sort(&arr[0], &arr[n]);
		
	/*for (int i = 0; i < n; i++) {
	cout << arr[i];
	}*/

	//cout << arr[k - 1];
	printf("%d", arr[k - 1]);

	return 0;
}

