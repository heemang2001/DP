#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int DP[100];

int main()
{
	int N; // 3 <= N <= 100 // 식량창고의 개수
	vector<int> vecFood; // 각 식량창고에 저장된 식량의 개수 K (0 <= K <= 1000)

	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		int nTemp = 0;

		cin >> nTemp;

		vecFood.push_back(nTemp);
	}

	DP[0] = vecFood[0];
	DP[1] = max(vecFood[0], vecFood[1]);

	// 바텀업 방식
	for (int i = 2; i < N; i++)
	{
		DP[i] = max(DP[i - 1], DP[i - 2] + vecFood[i]);
	}

	cout << DP[N - 1] << '\n';

	return 0;
}
