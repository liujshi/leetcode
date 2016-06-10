#include "Common.h"
#include "Profiler.h"
using namespace std;
using namespace Profiler;
class Solution {
public:
	static bool isVowels(char c)
	{
		return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I'\
			|| c == 'O' || c == 'U';
	}
	static string reverseVowels(string s) 
	{
		int len = s.size();
		if (len < 1) return s;
		int i = 0;
		int j = s.size() - 1;
		while (i < j)
		{
			while (!isVowels(s[i]) && i < j) ++i;
			while (!isVowels(s[j]) && i < j) --j;
			swap(s[i++], s[j--]);
		}
		return s;
	}
};

//int main()
//{
//	cout << Solution::reverseVowels("leetcode") << endl;
//}