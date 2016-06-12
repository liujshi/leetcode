#include "Common.h"
#include "Profiler.h"
using namespace std;
using namespace Profiler;
class Solution {
public:
	static int integerBreak(int n) {
		if (n <= 2)
		{
			return n;
		}
		vector<int> helper(n+1, 1);
		helper[2] = 2;
		helper[3] = 3;

		for (int i = 4; i <= n; ++i)
		{
			for (int j = 2; j <= i/2;++j)
			{
				int tmp = j * helper[i - j];
				helper[i] = tmp > helper[i] ? tmp : helper[i];
			}
		}
		return helper[n];
	}
	static int integerBreak1(int n)
	{
		if (n == 2) return 1;
		else if (n == 3) return 2;
		else if (n % 3 == 0) return pow(3, n / 3);
		else if (n % 3 == 1) return 4 * pow(3, (n - 4) / 3);
		else return 2 * pow(3, (n - 2) / 3);
	}
};

//int main()
//{
//	cout << Solution::integerBreak1(8) << endl;
//}