#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 1. X가 5로 나누어 떨어지면, 5로 나눔
// 2. X가 3으로 나우어 떨어지면, 3으로 나눔
// 3. X가 2로 나누어 떨어지면, 2로 나눔
// 4. X에서 1을 뺌

// 앞서 계산된 결과를 저장하기 위한 DP테이블 초기화
int DP[30001];

int main()
{	
	int X;

	cin >> X; // 1 <= X <= 30000
	
	// i = 현재숫자
	// 다이나믹 프로그래밍 진행 (바텀업)
	for (int i = 2; i <= X; i++)
	{
		// 현재의 수에서 1을 빼는 경우
		DP[i] = DP[i - 1] + 1;

		// 현재의 수가 2로 나누어 떨어지는 경우
		if (i % 2 == 0)
		{
			DP[i] = min(DP[i], DP[i / 2] + 1);
		}

		// 현재의 수가 3으로 나누어 떨어지는 경우
		if (i % 3 == 0)
		{
			DP[i] = min(DP[i], DP[i / 3] + 1);
		}

		// 현재의 수가 5로 나누어 떨어지는 경우
		if (i % 5 == 0)
		{
			DP[i] = min(DP[i], DP[i / 5] + 1);
		}
	}

	cout << DP[X] << '\n';	

	return 0;
}
