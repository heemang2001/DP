#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//int N; // 1 <= N <= 2000 
//vector<int> vecPower; // 각 병사의 전투력은 10,000,000보다 작거나 같은 자연수
//int DP[2000];
//
//int main()
//{
//	cin >> N;
//
//	for (int i = 0; i < N; i++)
//	{
//		int nTemp = 0;
//
//		cin >> nTemp;
//
//		vecPower.push_back(nTemp);
//	}
//	
//	DP[0] = 0;
//
//	for (int i = 1; i < N; i++)
//	{
//		if (vecPower[i] < vecPower[i - 1])
//		{
//			DP[i] = DP[i - 1];
//		}
//
//		else
//		{
//			DP[i] = DP[i - 1] + 1;
//		}
//	}
//
//	cout << DP[N - 1] << '\n';
//
//	return 0;
//}

int n;
vector<int> v;

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}

	// 순서를 뒤집어 '최장 증가 부분 수열' 문제로 변환
	reverse(v.begin(), v.end());

	// 다이나믹 프로그래밍을 위한 1차원 DP테이블 초기화
	int dp[2000];
	for (int i = 0; i < n; i++)
	{
		dp[i] = 1;
	}

	// 가장 긴 증가하는 부분 수열(LIS) 알고리즘 수행
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (v[j] < v[i])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}				
		}
	}

	// 열외해야 하는 병사의 최소 수를 출력
	int maxValue = 0;

	for (int i = 0; i < n; i++)
	{
		maxValue = max(maxValue, dp[i]);
	}

	cout << n - maxValue << '\n';
}
