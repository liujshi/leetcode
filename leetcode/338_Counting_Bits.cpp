#include "Common.h"
#include "Profiler.h"
#include <stack>
using namespace std;


class Solution {
public:
	vector<int> countBits(int num) {
		vector<int> result(num + 1, 0);
		int bucket_index = 0, bucket_range = 1, num_index = 1;
		while (num_index <= num){
			for (int index = bucket_range; index < 2 * bucket_range && num_index <= num; ++index){
				result[num_index] = result[index - bucket_range] + 1;
				num_index++;
			}
			bucket_range <<= 1;
		}
		return result;
	}
};