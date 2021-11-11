#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N;
float Answer;
float DP[10001][10001];

int main()
{
	cin >> N;

	vector<float> vecTemp;

	for (int i = 0; i < N; i++)
	{
		float fTemp;
		cin >> fTemp;	
		vecTemp.push_back(fTemp);
	}	

	for (int i = 0; i < vecTemp.size(); i++)
	{
		DP[i][0] = vecTemp[i];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 1; j < N-i; j++)
		{
			DP[i][j] = DP[i][j - 1] * vecTemp[j];
		}
	}

	cout << Answer << '\n';

	return 0;
}