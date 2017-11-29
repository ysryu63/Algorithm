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
	dp[0] = 1;		//0���� ����� ��� ���0���� ���� �׻� �����ϱ� ������ �ʱⰪ 1
	for (int i = 0; i < n; i++) {

		for (int j = 0; j <= k; j++) {		//���� 0~k ��� �� �ؾ��ϹǷ� j<=k 
			if (j >= coin[i]) {
				dp[j] += dp[j - coin[i]];
			}
		}
	}

	cout << dp[k] << endl;

	return 0;
}