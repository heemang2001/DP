#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int answer = 9999999;

void dfs(int N, int number, int count, int currentNumber)
{
	if (count >= 9)
	{
		return;
	}

	if (currentNumber == number)
	{
		answer = min(answer, count);
		return;
	}

	int nTemp = 0;

	// 최대 N의 사용횟수는 9번
	for (int i = 0; i + count < 9; i++)
	{
		// N부터 NN, NNN, NNNN .......
		nTemp = nTemp * 10 + N;

		dfs(N, number, count + 1 + i, currentNumber + nTemp);
		dfs(N, number, count + 1 + i, currentNumber - nTemp);
		dfs(N, number, count + 1 + i, currentNumber * nTemp);
		dfs(N, number, count + 1 + i, currentNumber / nTemp);
	}
}

int solution(int N, int number)
{
	dfs(N, number, 0, 0);

	if (answer > 8)
	{
		return -1;
	}

	return answer;
}

int main()
{
	cout << solution(5, 12) << '\n'; // 4
	cout << solution(2, 11) << '\n'; // 3
	cout << solution(2, 2) << '\n';  // 1

	return 0;
}