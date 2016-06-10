#include "Common.h"
#include "Profiler.h"
using namespace std;
using namespace Profiler;
class Solution {
public:
	static vector<int> topKFrequent(vector<int>& nums, int k) 
	{
		int nums_len = nums.size();
		vector<int> result;
		if (nums_len < 1) return result;
		unordered_map<int, int> nums_map;
		for (auto e:nums)
		{
			nums_map[e]++;
		}
		vector<pair<int, int>> helper;

		for (auto e:nums_map)
		{
			helper.push_back(e);
		}

		sort(helper.begin(), helper.end(), [](const pair<int, int>& x, const pair<int, int>& y){return x.second > y.second; });

		for (int i = 0; i < k; ++i)
		{
			result.push_back(helper[i].first);
		}
		return result;
	}

	static vector<string> topKFrequent1(vector<string>& nums, int k)
	{
		int nums_len = nums.size();
		vector<string> result;
		if (nums_len < 1) return result;
		unordered_map<string, int> nums_map;
		for (auto e : nums)
		{
			nums_map[e]++;
		}
		vector<pair<string, int>*> helper;

		for (pair<string, int> e : nums_map)
		{
			helper.push_back(&e);
		}

		cout << helper.size()*sizeof(helper[0])<<endl;

		sort(helper.begin(), helper.end(), [](const pair<string, int>* x, const pair<string, int>* y){return x->second > y->second; });

		for (int i = 0; i < k; ++i)
		{
			result.push_back(helper[i]->first);
		}
		cout << Profiler::ProfilerInstance::memory(KB_mu) << endl;
		return result;
	}
	static vector<string> topKFrequent2(vector<string>& nums, int k)
	{
		int nums_len = nums.size();
		vector<string> result;
		if (nums_len < 1) return result;
		unordered_map<string, int> nums_map;
		for (auto e : nums)
		{
			nums_map[e]++;
		}
		vector<pair<string, int>> helper;

		for (pair<string, int> e : nums_map)
		{
			helper.push_back(e);
		}
		cout << helper.size()*sizeof(helper[0]) << endl;
		sort(helper.begin(), helper.end(), [](const pair<string, int> x, const pair<string, int> y){return x.second > y.second; });

		for (int i = 0; i < k; ++i)
		{
			result.push_back(helper[i].first);
		}
		cout << Profiler::ProfilerInstance::memory(KB_mu) << endl;
		return result;
	}
};

int main1()
{
	/*vector<int> p(100000, 1); p.push_back(2);
	Profiler::ProfilerInstance::start();
	vector<int> q = Solution::topKFrequent(p, 2);
	Profiler::ProfilerInstance::finish();
	Profiler::ProfilerInstance::dumpDuringTime();
	for (auto e:q)
	{
		printf("%d  ", e);
		printf("\n");
	}*/

	vector<string> p(100000, string(1000, 'q')); p.push_back("IHateYou");
	//for (int i = 0; i < 100000; ++i)
	//{
	//	p[i][0] = rand()%256;
	//}
	
	Profiler::ProfilerInstance::start();
	vector<string> q = Solution::topKFrequent1(p, 2);
	Profiler::ProfilerInstance::finish();
	Profiler::ProfilerInstance::dumpDuringTime();

	cout << "-----------------------------------" << endl;
	
	Profiler::ProfilerInstance::start();
	vector<string> r = Solution::topKFrequent2(p, 2);
	Profiler::ProfilerInstance::finish();
	Profiler::ProfilerInstance::dumpDuringTime();

	return 0;
}