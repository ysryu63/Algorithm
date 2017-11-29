#include <iostream>
#include <time.h>

using namespace std;

#define SIZE 1000003

/*int MAX(int x, int y) { return x > y ? x : y; }
int MIN(int x, int y) { return x < y ? x : y; }
*/
int isPrime[SIZE];
//bool is_prime(int x) {
//	if (x < 2)
//		return false;
//	else {
//		for (int i = 2; i*i <= x; i++) {
//			if (x%i == 0)
//				return false;
//		}
//	}
//	return true;
//}

void eratosthenes() {
	for (int i = 2; i*i < SIZE; i++)
		if (!isPrime[i])
			for (int j = i*i; j < SIZE; j += i)
				isPrime[j] = 1;
	isPrime[1] = 1;
}

int main()
{
	int n;
	eratosthenes();
	while (1) {

		clock_t begin, end, time;
		begin = clock();

		cin >> n;
		if (n == 0) break;
		//int t = n;
		//int m = n >> 1;
		//int max = 0, min = 0;
		bool flag = false;

		for (int i = 3; i <= n; i += 2) {
			if (!isPrime[i] && !isPrime[n - i]) {
				cout << n << " = " << i << " + " << n - i << endl;
				flag = true;
				break;
			}
		}

		/*if (flag)
		cout << n << " = " << min << " + " << max << endl;
		else
		cout << "Goldbach's conjecture is wrong." << endl;
		*/
		if (!flag)
			cout << "Goldbach's conjecture is wrong." << endl;

		//end = clock();
		//time = float((end - begin) / CLOCKS_PER_SEC);

		//cout << "Spend time = " << time << endl;
	}
	return 0;
}