#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

class Solution {
public:

    int maxProductDifference(vector<int>& nums) {
        /* Sort Time: O(nlogn) Space: O(logn)*/
		sort(begin(nums), end(nums));
		return nums[nums.size() - 2] * nums[nums.size() - 1] - nums[0] * nums[1];
    }

    int maxProductDifference2(vector<int>& nums){
		/* Track the Two Biggest and the Two Smallest Elements 
		Time: O(n) Space: O(1)*/
		auto max1 = 0, max2 = 0;
		auto min1 = INT_MAX, min2 = INT_MAX;

		for (auto el: nums){

			if (el > max1) {
				max2 = max1;
				max1 = el;
			} else if (el > max2) {
				max2 = el;
			}

			if (el < min1) {
				min2 = min1;
				min1 = el;
			} else if (el < min2) {
				min2 = el;
			}
		
		}

		return max1 * max2 - min1 * min2;
    }
};

bool checkResult(const vector<int>& result, const vector<int>& expected) {
    return result == expected;
}

int main() {
    Solution solution;

    // Test Case 1
    std::vector<int> nums1 = {5, 6, 2, 7, 4};
	auto expected1 = 34;
	std::cout << "Test Case 1 Result: " << std::boolalpha <<
		bool(expected1 == solution.maxProductDifference(nums1)) << std::endl;
	std::cout << "Test Case 1 Result: " << std::boolalpha <<
		bool(expected1 == solution.maxProductDifference2(nums1)) << std::endl;
	
	// Test Case 2
    std::vector<int> nums2 = {4, 2, 5, 9, 7, 4, 8};
    auto expected2 = 64;
	std::cout << "Test Case 2 Result: " << std::boolalpha <<
		bool(expected2 == solution.maxProductDifference(nums2)) << std::endl;
	std::cout << "Test Case 2 Result: " << std::boolalpha <<
		bool(expected2 == solution.maxProductDifference2(nums2)) << std::endl;
	

    return 0;
}