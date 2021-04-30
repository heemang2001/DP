#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T; // 1 <= T <= 1000
int n, m; // 1 <= n,m <= 20 // n x m개의 위치가 매장된 금의개수가 공백으로 구분되어 입력 ( 1 <= 각 위치의 매장된 금의 개수 <= 100)

int arr[20][20];
int DP[20][20]; // 최적의 해값
vector<int> vecResult;

int main()
{
	cin >> T; // 테스트 케이스 입력	

	for (int tc = 0; tc < T; tc++)
	{
		// 금광 정보 입력
		cin >> n >> m;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> arr[i][j];
			}
		}

		// 다이나믹 프로그래밍을 위한 2차원 DP테이블 초기화
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				DP[i][j] = arr[i][j];
			}
		}

		// 다이나믹 프로그래밍 진행
		for (int j = 1; j < m; j++) // 열
		{
			for (int i = 0; i < n; i++) // 행
			{
				int leftUp, leftDown, left;

				// 왼쪽 위에서 오는 경우
				if (i == 0)
				{
					leftUp = 0;
				}

				else
				{
					leftUp = DP[i - 1][j - 1];
				}

				// 왼쪽 아래에서 오는 경우
				if (i == n - 1)
				{
					leftDown = 0;
				}

				else
				{
					leftDown = DP[i + 1][j - 1];
				}

				// 왼쪽에서 오는 경우
				left = DP[i][j - 1];

				DP[i][j] = DP[i][j] + max(leftUp, max(leftDown, left));
			}
		}

		int result = 0;

		for (int i = 0; i < n; i++)
		{
			result = max(result, DP[i][m - 1]);
		}

		// 최대크기값들 저장
		vecResult.push_back(result);
	}

	for (int i = 0; i < vecResult.size(); i++)
	{
		cout << vecResult[i] << '\n';
	}

	

	return 0;
}