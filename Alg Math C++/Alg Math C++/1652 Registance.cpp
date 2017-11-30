#include <iostream>
#include <string>

using namespace std;

string arr[10] = { "black","brown","red","orange","yellow","green","blue","violet","grey","white" };

int main()
{
	string a, b, c;

	getline(cin, a);
	getline(cin, b);
	getline(cin, c);


	int xa, xb, xc;
	for (int i = 0; i < 10; i++) {
		if (arr[i] == a)
			xa = i;

		if (arr[i] == b)
			xb = i;

		if (arr[i] == c)
			xc = i;
	}

	long long result = xa * 10 + xb;
	for (int j = 0; j < xc; j++) {
		result *= 10;
	}

	cout << result;

	return 0;
}