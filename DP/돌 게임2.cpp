#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N;
bool DP[1001];
string Answer;

int main()
{
	cin >> N;

	DP[1] = false;
	DP[2] = true;
	DP[3] = false;

	for (int i = 4; i <= N; i++)
	{
		DP[i] = !DP[i - 1];
	}

	if (DP[N] == true)
	{
		Answer = "SK";
	}

	else
	{
		Answer = "CY";
	}

	cout << Answer << '\n';

	return 0;
}