from typing import List
import unittest

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
class Solution:
    def maxWidthOfVerticalArea(self, points: List[List[int]]) -> int:
        """Sorting time:O(nlogn) space:O(n)"""
        ans = 0
        points.sort()
        for i in range(1, len(points)):
            ans = max(ans, points[i][0] - points[i - 1][0])
        return ans 

class TestSolution(unittest.TestCase):
    def test_example_1(self):
        solution = Solution()
        points = [[8, 7], [9, 9], [7, 4], [9, 7]]
        result = solution.maxWidthOfVerticalArea(points)
        self.assertEqual(result, 1)

    def test_example_2(self):
        solution = Solution()
        points = [[3, 1], [9, 0], [1, 0], [1, 4], [5, 3], [8, 8]]
        result = solution.maxWidthOfVerticalArea(points)
        self.assertEqual(result, 3)

if __name__ == '__main__':
    unittest.main()

