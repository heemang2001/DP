#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// �ռ� ���� ����� �����ϱ� ���� DP���̺� �ʱ�ȭ
long long d[100];

int main()
{
	// ù ��° �Ǻ���ġ ���� �� ��° �Ǻ���ġ ���� 1
	d[1] = 1;
	d[2] = 1;
	int n = 50; // 50��° �Ǻ���ġ ���� ���

	// �Ǻ���ġ �Լ�(Fibonacci Function) �ݺ������� ����(���Ҿ� ���̳��� ���α׷���)
	for (int i = 3; i <= n; i++)
	{
		d[i] = d[i - 1] + d[i - 2];
	}

	cout << d[n] << '\n';

	return 0;
}
