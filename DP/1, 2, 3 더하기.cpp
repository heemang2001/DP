#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int T;
int DP[11];

int main()
{
	DP[1] = 1;
	DP[2] = 2;
	DP[3] = 4;

	for (int i = 4; i <= 10; i++)
	{
		DP[i] = DP[i - 1] + DP[i - 2] + DP[i - 3];
	}

	cin >> T;

	vector<int> vecAnswer;

	for (int i = 0; i < T; i++)
	{
		int nTemp;
		cin >> nTemp;
		vecAnswer.push_back(DP[nTemp]);
	}

	for (int i = 0; i < vecAnswer.size(); i++)
	{
		cout << vecAnswer[i] << '\n';
	}

	return 0;
}