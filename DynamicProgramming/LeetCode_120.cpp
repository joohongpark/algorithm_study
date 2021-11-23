#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

class Solution
{
public:
	int getMinPath(vector<vector<int>> &triangle, int depth)
	{
		if (depth < 0)
			return (triangle[0][0]);
		for (int i = 0; i < triangle[depth].size(); i++)
		{
			triangle[depth][i] = triangle[depth][i] + min(triangle[depth + 1][i], triangle[depth + 1][i + 1]);
		}
		return (getMinPath(triangle, depth - 1));
	}

	int minimumTotal(vector<vector<int>> &triangle)
	{
		return (getMinPath(triangle, triangle.size() - 2));
	}
};
