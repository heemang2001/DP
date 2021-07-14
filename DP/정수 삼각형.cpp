#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int answer = -1;

int solution(vector<vector<int>> triangle)
{
	vector<vector<int>> vecSum(triangle);

	for (int i = 1; i < triangle.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			vecSum[i][j] = max(vecSum[i][j], vecSum[i - 1][j] + triangle[i][j]);
			vecSum[i][j+1] = max(vecSum[i][j+1], vecSum[i - 1][j] + triangle[i][j+1]);
		}
	}

	answer = *max_element(vecSum[triangle.size()-1].begin(), vecSum[triangle.size() - 1].end());

	return answer;
}

int main()
{
	cout << solution({ {7} ,{3, 8},{8, 1, 0},{2, 7, 4, 4},{4, 5, 2, 6, 5} }) << '\n';

	return 0;
}

//// DFS방식은 효율성 문제에 걸림
//void DFS(vector<vector<int>>& triangle, int num, int cnt, int sum)
//{
//	if (cnt == triangle.size() - 1)
//	{
//		answer = max(answer, sum);
//		return;
//	}
//
//	int index = find(triangle[cnt].begin(), triangle[cnt].end(), num) - triangle[cnt].begin();
//
//	DFS(triangle, triangle[cnt + 1][index], cnt + 1, sum + triangle[cnt + 1][index]);
//	DFS(triangle, triangle[cnt + 1][index + 1], cnt + 1, sum + triangle[cnt + 1][index + 1]);
//}
//
//int solution(vector<vector<int>> triangle)
//{
//	DFS(triangle, triangle[0][0], 0, triangle[0][0]);
//
//	return answer;
//}