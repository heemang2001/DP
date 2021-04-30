#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T; // 1 <= T <= 1000
int n, m; // 1 <= n,m <= 20 // n x m���� ��ġ�� ����� ���ǰ����� �������� ���еǾ� �Է� ( 1 <= �� ��ġ�� ����� ���� ���� <= 100)

int arr[20][20];
int DP[20][20]; // ������ �ذ�
vector<int> vecResult;

int main()
{
	cin >> T; // �׽�Ʈ ���̽� �Է�	

	for (int tc = 0; tc < T; tc++)
	{
		// �ݱ� ���� �Է�
		cin >> n >> m;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> arr[i][j];
			}
		}

		// ���̳��� ���α׷����� ���� 2���� DP���̺� �ʱ�ȭ
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				DP[i][j] = arr[i][j];
			}
		}

		// ���̳��� ���α׷��� ����
		for (int j = 1; j < m; j++) // ��
		{
			for (int i = 0; i < n; i++) // ��
			{
				int leftUp, leftDown, left;

				// ���� ������ ���� ���
				if (i == 0)
				{
					leftUp = 0;
				}

				else
				{
					leftUp = DP[i - 1][j - 1];
				}

				// ���� �Ʒ����� ���� ���
				if (i == n - 1)
				{
					leftDown = 0;
				}

				else
				{
					leftDown = DP[i + 1][j - 1];
				}

				// ���ʿ��� ���� ���
				left = DP[i][j - 1];

				DP[i][j] = DP[i][j] + max(leftUp, max(leftDown, left));
			}
		}

		int result = 0;

		for (int i = 0; i < n; i++)
		{
			result = max(result, DP[i][m - 1]);
		}

		// �ִ�ũ�Ⱚ�� ����
		vecResult.push_back(result);
	}

	for (int i = 0; i < vecResult.size(); i++)
	{
		cout << vecResult[i] << '\n';
	}

	

	return 0;
}