#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:

    vector<int> twoSum(vector<int>& nums, int target) {
        /* Brute Force time O(n^2) space O(1) */
        for (auto i = 0; i < nums.size(); i++)
            for (auto j = i + 1; j < nums.size(); j++)
                if (nums[i] + nums[j] == target)
                    return {i, j};
        return {};
    }

    vector<int> twoSum2(vector<int>& nums, int target) {
        /* Two-pass Hash Table time O(n) space O(n) */
        unordered_map<int,int> d;
        for (auto i = 0; i < nums.size(); i++)
            d[nums[i]] = i;

        for (auto i = 0; i < nums.size(); i++) {
            auto complement = target - nums[i];
            if (d.find(complement) != end(d) && d[complement] != i){
                return {d[complement],i};
            }
            d[nums[i]] = i;
        }

        return {};
    }

    vector<int> twoSum3(vector<int>& nums, int target) {
        /* One-pass Hash Table time O(n) space O(n) */
        unordered_map<int, int> d;
        for (auto i = 0; i < nums.size(); i++) {
            auto complement = target - nums[i];
            if (d.find(complement) != end(d)) {
                return {d[complement],i};
            }
            d[nums[i]] = i;
        }
        return {};
    }
};

bool checkResult(const vector<int>& result, const vector<int>& expected) {
    return result == expected;
}

int main() {
    Solution solution;

    // Test Case 1
    std::vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    std::vector<int> result1 = solution.twoSum(nums1, target1);
    std::vector<int> expected1 = {0, 1};
    std::cout << "Two Sum Test Case 1 Result: " << (checkResult(result1, expected1) ? "true" : "false") << std::endl;

    std::vector<int> result1_2 = solution.twoSum2(nums1, target1);
    std::cout << "Two Sum 2 Test Case 1 Result: " << (checkResult(result1_2, expected1) ? "true" : "false") << std::endl;

    std::vector<int> result1_3 = solution.twoSum3(nums1, target1);
    std::cout << "Two Sum 3 Test Case 1 Result: " << (checkResult(result1_3, expected1) ? "true" : "false") << std::endl;

	// Test Case 2
	std::vector<int> nums2 = {3, 2, 4};
	int target2 = 6;
	std::vector<int> result2 = solution.twoSum(nums2, target2);
	std::vector<int> expected = {1, 2};
	std::cout << "Two Sum Test Case 2 Result: " << (checkResult(result2, expected) ? "true" : "false") << std::endl;

	std::vector<int> result2_2 = solution.twoSum2(nums2, target2);
	sort(result2_2.begin(), result2_2.end()); 
	std::cout << "Two Sum 2 Test Case 2 Result: " << (checkResult(result2_2, expected) ? "true" : "false") << std::endl;

	std::vector<int> result2_3 = solution.twoSum3(nums2, target2);
	std::cout << "Two Sum 3 Test Case 2 Result: " << (checkResult(result2_3, expected) ? "true" : "false") << std::endl;
    
	// Test Case 3
    std::vector<int> nums3 = {3, 3};
    int target3 = 6;
    std::vector<int> result3 = solution.twoSum(nums3, target3);
    std::vector<int> expected3 = {0, 1};
    std::cout << "Two Sum Test Case 3 Result: " << (checkResult(result3, expected3) ? "true" : "false") << std::endl;

    std::vector<int> result3_2 = solution.twoSum2(nums3, target3);
    std::cout << "Two Sum 2 Test Case 3 Result: " << (checkResult(result3_2, expected3) ? "true" : "false") << std::endl;

    std::vector<int> result3_3 = solution.twoSum3(nums3, target3);
    std::cout << "Two Sum 3 Test Case 3 Result: " << (checkResult(result3_3, expected3) ? "true" : "false") << std::endl;

    // Additional Test Cases...

    return 0;
}