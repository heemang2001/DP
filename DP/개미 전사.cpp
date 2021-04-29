#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int DP[100];

int main()
{
	int N; // 3 <= N <= 100 // �ķ�â���� ����
	vector<int> vecFood; // �� �ķ�â�� ����� �ķ��� ���� K (0 <= K <= 1000)

	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		int nTemp = 0;

		cin >> nTemp;

		vecFood.push_back(nTemp);
	}

	DP[0] = vecFood[0];
	DP[1] = max(vecFood[0], vecFood[1]);

	// ���Ҿ� ���
	for (int i = 2; i < N; i++)
	{
		DP[i] = max(DP[i - 1], DP[i - 2] + vecFood[i]);
	}

	cout << DP[N - 1] << '\n';

	return 0;
}
