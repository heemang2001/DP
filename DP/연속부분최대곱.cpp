#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N;
double DP[10001];
double Answer;

int main()
{
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		double dTemp;
		cin >> dTemp;
		DP[i] = dTemp;
	}

	Answer = DP[1];

	for (int i = 2; i <= N; i++)
	{
		if (DP[i] * DP[i - 1] >= DP[i])
		{
			DP[i] = DP[i - 1] * DP[i];
		}

		Answer = max(Answer, DP[i]);
	}

	cout << fixed;
	cout.precision(3);
	cout << Answer << '\n';

	return 0;
}

// 메모리 초과
//int N;
//float Answer;
//float DP[10001][10001];
//
//int main()
//{
//	cin >> N;
//
//	vector<float> vecTemp;
//
//	for (int i = 0; i < N; i++)
//	{
//		float fTemp;
//		cin >> fTemp;	
//		vecTemp.push_back(fTemp);
//	}	
//
//	for (int i = 0; i < vecTemp.size(); i++)
//	{
//		DP[i][0] = vecTemp[i];
//		Answer = max(Answer, DP[i][0]);
//	}
//
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 1; j < N-i; j++)
//		{
//			DP[i][j] = DP[i][j - 1] * vecTemp[j+i];
//			Answer = max(Answer, DP[i][j]);
//		}
//	}
//
//	cout << fixed;
//	cout.precision(3);
//
//	cout << Answer << '\n';
//
//	return 0;
//}