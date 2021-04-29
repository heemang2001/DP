#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M; // 1 <= N <= 100 // 1 <= M <= 10000
vector<int> Money;

int main()
{ 
	cin >> N >> M; // N���� ������ ȭ�� 

	for (int i = 0; i < N; i++)
	{
		int nTemp = 0;
		cin >> nTemp;
		Money.push_back(nTemp);
	}

	vector<int> DP(M + 1, 10001); // DP���̺� �ʱ�ȭ
	
	// ���̳��� ���α׷��� ����(���Ҿ�)
	DP[0] = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = Money[i]; j <= M; j++)
		{
			// (i-k)���� ����� ����� �����ϴ� ���
			if (DP[j - Money[i]] != 10001)
			{
				DP[j] = min(DP[j], DP[j - Money[i]] + 1);
			}
		}
	}

	if (DP[M] == 10001)
	{
		cout << -1 << '\n';
	}

	else
	{
		cout << DP[M] << '\n';
	}



	return 0;
}
