#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
class Solution
{
private:
	int memoization[45] = {0};

public:
	void init()
	{
		memset(memoization, -1, sizeof(memoization));
	}

	int climbCount(int n, int depth)
	{
		if (n == depth + 1)
			return (1);
		if (n == depth + 2)
			return (2);
		int &rtn = memoization[depth];
		if (rtn != -1)
			return (rtn);
		rtn = climbCount(n, depth + 1) + climbCount(n, depth + 2);
		return (rtn);
	}

	int climbStairs(int n)
	{
		init();
		return(climbCount(n, 0));
	}
};
