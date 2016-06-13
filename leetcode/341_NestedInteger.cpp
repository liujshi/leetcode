#include "Common.h"
#include "Profiler.h"
#include <stack>
using namespace std;

/**
* // This is the interface that allows for creating nested lists.
* // You should not implement it, or speculate about its implementation
* class NestedInteger {
*   public:
*     // Return true if this NestedInteger holds a single integer, rather than a nested list.
*     bool isInteger() const;
*
*     // Return the single integer that this NestedInteger holds, if it holds a single integer
*     // The result is undefined if this NestedInteger holds a nested list
*     int getInteger() const;
*
*     // Return the nested list that this NestedInteger holds, if it holds a nested list
*     // The result is undefined if this NestedInteger holds a single integer
*     const vector<NestedInteger> &getList() const;
* };
*/
class NestedInteger{
private:
	vector<NestedInteger> data;
public:
	bool isInteger() const
	{
		return true;
	}
	int getInteger() const
	{
		return 0;
	}
	const vector<NestedInteger> &getList() const
	{
		return data;
	}
};
class NestedIterator {
private:
	int index = -1;
	vector<int> result;
	void process(const vector<NestedInteger>& nestedList, vector<int>& result)
	{
		for (auto e : nestedList)
		{
			if (e.isInteger())
				result.push_back(e.getInteger());
			else
				process(e.getList(), result);
		}
	}


public:

	NestedIterator(vector<NestedInteger> &nestedList) {
		process(nestedList, result);
		if (result.size()>0)
			index = 0;
	}

	int next() {
		return result[index++];
	}

	bool hasNext() {
		return index < result.size();
	}
};

class NestedIterator1 {
private:
	stack<NestedInteger> helper;
	NestedInteger tmp;

public:

	NestedIterator1(vector<NestedInteger> &nestedList) {
		int len = nestedList.size();
		for (int i = len - 1; i >= 0; --i)
		{
			helper.push(nestedList[i]);
		}
		while (!helper.empty() && !helper.top.isInteger())
		{
			tmp = helper.top();
			helper.pop();
			int len1 = tmp.getList().size();
			for (int i = len1 - 1; i >= 0; --i)
			{
				helper.push(tmp.getList()[i]);
			}
		}
	}

	int next() {
		int ret = helper.top().getInteger();
		helper.pop();
		return ret;

	}

	bool hasNext() {
		while (!helper.empty() && !helper.top.isInteger())
		{
			tmp = helper.top();
			helper.pop();
			int len1 = tmp.getList().size();
			for (int i = len1 - 1; i >= 0; --i)
			{
				helper.push(tmp.getList()[i]);
			}
		}
		return !helper.empty();
	}
};


/**
* Your NestedIterator object will be instantiated and called as such:
* NestedIterator i(nestedList);
* while (i.hasNext()) cout << i.next();
*/