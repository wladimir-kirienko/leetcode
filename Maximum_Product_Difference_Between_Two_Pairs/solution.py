import sys
from typing import List

class Solution:
    def maxProductDifference(self, nums: List[int]) -> int:
        """ Sort IntuitionTime: O(n⋅log⁡n) Space: O(n)"""
        nums.sort()
        return nums[-1]*nums[-2] - nums[0]*nums[1]

    def maxProductDifference2(self, nums: List[int]) -> int:
        """ Track the Two Biggest and the Two Smallest Elements Time: O(n) Space: O(1)"""
        max1, max2 = 0,0
        min1, min2 = sys.maxsize, sys.maxsize
        
        for el in nums:
            if el > max1:
                max2 = max1
                max1 = el
            elif el > max2:
                max2 = el
            if el < min1:
                min2 = min1
                min1 = el
            elif el < min2:
                min2 = el
        
        return max1 * max2 - min1 * min2
s = Solution()

print( 34 == s.maxProductDifference([5,6,2,7,4]) )
print( 64 == s.maxProductDifference([4,2,5,9,7,4,8]) )

print( 34 == s.maxProductDifference2([5,6,2,7,4]) )
print( 64 == s.maxProductDifference2([4,2,5,9,7,4,8]) )

