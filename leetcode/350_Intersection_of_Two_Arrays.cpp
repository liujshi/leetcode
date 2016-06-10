#include "Common.h"
#include "Profiler.h"
using namespace std;

class Solution
{
public:
	static vector<int> intersect1(vector<int>& nums1, vector<int>& nums2)
	{
		int nums1_len = nums1.size();
		int nums2_len = nums2.size();
		vector<int> result;
		vector<int> nums1_mark(nums1_len, 0);
		vector<int> nums2_mark(nums2_len, 0);
		for (int i = 0; i < nums1_len; ++i)
		{
			for (int j = 0; j < nums2_len; ++j)
			{
				if (!nums2_mark[j] && !nums1_mark[i] && nums1[i] == nums2[j])
				{
					result.push_back(nums1[i]);
					nums1_mark[i] = 1;
					nums2_mark[j] = 1;
				}
			}
		}
		return result;
	}

	static vector<int> intersect2(vector<int>& nums1, vector<int>& nums2)
	{
		int nums1_len = nums1.size();
		int nums2_len = nums2.size();
		vector<int> result;
		result.reserve(min(nums1_len, nums2_len));
		if (nums1_len < 1 || nums2_len < 1) return result;
		unordered_map<int, int> nums1_map;
		for (auto e: nums1)
		{
			nums1_map[e]++;
		}

		for (auto e : nums2)
		{
			auto r = nums1_map.find(e);
			if (r!=nums1_map.end() && r->second > 0)
			{
				result.push_back(e);
				(r->second)--;
			}
		}
		return result;
	}
	static vector<int> intersect3(vector<int>& nums1, vector<int>& nums2)
	{
		vector<int> result;
		int nums1_len = nums1.size();
		int nums2_len = nums2.size();
		result.reserve(min(nums1_len, nums2_len));
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());

		int i1 = 0, i2 = 0;
		while (i1 < nums1_len && i2 < nums2_len)
		{
			if (nums1[i1] == nums2[i2])
			{
				result.push_back(nums1[i1]);
				++i1; ++i2;
			}
			else if (nums1[i1] < nums2[i2])
			{
				++i1;
			}
			else
			{
				++i2;
			}
		}
		return result;
	}
};


int main()
{
	vector<int> p(100000,0);
	vector<int> q(100000,1);
	p.push_back(1); 
	q.push_back(0);

	Profiler::ProfilerInstance::start();
	vector<int> r = Solution::intersect2(p, q);
	Profiler::ProfilerInstance::finish();
	Profiler::ProfilerInstance::dumpDuringTime();
	for (int e:r)
	{
		printf("%d  ", e);
		printf("\n");
	}

	Profiler::ProfilerInstance::start();
	vector<int> r1 = Solution::intersect3(p, q);
	Profiler::ProfilerInstance::finish();
	Profiler::ProfilerInstance::dumpDuringTime();


	for (int e : r1)
	{
		printf("%d  ", e);
		printf("\n");
	}

}