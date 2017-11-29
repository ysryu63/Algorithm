#include <iostream>

using namespace std;

int coin[10001];

int dp[101];

int main()
{
	int n, k;

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}
	dp[0] = 1;		//0원을 만드는 경우 모두0개를 쓰면 항상 성립하기 때문에 초기값 1
	for (int i = 0; i < n; i++) {

		for (int j = 0; j <= k; j++) {		//합이 0~k 모두 다 해야하므로 j<=k 
			if (j >= coin[i]) {
				dp[j] += dp[j - coin[i]];
			}
		}
	}

	cout << dp[k] << endl;

	return 0;
}