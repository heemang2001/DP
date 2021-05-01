#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//int N; // 1 <= N <= 2000 
//vector<int> vecPower; // �� ������ �������� 10,000,000���� �۰ų� ���� �ڿ���
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

	// ������ ������ '���� ���� �κ� ����' ������ ��ȯ
	reverse(v.begin(), v.end());

	// ���̳��� ���α׷����� ���� 1���� DP���̺� �ʱ�ȭ
	int dp[2000];
	for (int i = 0; i < n; i++)
	{
		dp[i] = 1;
	}

	// ���� �� �����ϴ� �κ� ����(LIS) �˰��� ����
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

	// �����ؾ� �ϴ� ������ �ּ� ���� ���
	int maxValue = 0;

	for (int i = 0; i < n; i++)
	{
		maxValue = max(maxValue, dp[i]);
	}

	cout << n - maxValue << '\n';
}
