from typing import List

class Solution:
    """Brute Force time O(n2) space O(1)"""
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        ans = []
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                if nums[i] + nums[j] == target:
                    ans = [i,j]
                    break
        return ans
    
    def twoSum2(self, nums: List[int], target: int) -> List[int]:
        """Two-pass Hash Table time O(n) space O(n)"""
        d = {}
        for i in range(len(nums)):
            d[nums[i]] = i
        for i in range(len(nums)):
            complement = target - nums[i]
            if complement in d and d[complement] != i:
                return [i,d[complement]]

    def twoSum3(self, nums: List[int], target: int) -> List[int]:
        """One-pass Hash Table time O(n) space O(n)"""
        d = {}
        for i in range(len(nums)):
            complement = target - nums[i]
            if complement in d:
                return [i, d[complement]]
            d[nums[i]] = i
            

s = Solution() 
print( [0,1] == s.twoSum([2,7,11,15],9) )
print( [1,2] == s.twoSum([3,2,4],6) )
print( [0,1] == s.twoSum([3,3],6) )

print( [0,1] == s.twoSum2([2,7,11,15],9) )
print( [1,2] == s.twoSum2([3,2,4],6) )
print( [0,1] == s.twoSum2([3,3],6) )

print( [0,1] == sorted(s.twoSum3([2,7,11,15],9)) )
print( [1,2] == sorted(s.twoSum3([3,2,4],6)) )
print( [0,1] == sorted(s.twoSum3([3,3],6)) )

