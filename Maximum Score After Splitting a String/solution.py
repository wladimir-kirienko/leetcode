import unittest

class Solution:
    def maxScore(self, s: str) -> int:
        """ Brute force time: O(n^2) space: O(1) """
        ans = 0
        for i in range(1, len(s) - 1):
            su = 0
            for j in range(len(s)):
                n = '0' if j < i else '1'
                if s[j] == n:
                    su += 1 
            ans = max(ans, su)
        return ans

    def maxScore2(self, s: str) -> int:
        """ Count Left Zeros and Right Ones time: O(n) space: O(1) """
        ans = 0
        ones = s.count('1')
        zeros = 0
        for i in range(len(s) - 1):
            if s[i] == '1':
                ones -= 1
            else:
                zeros += 1
            ans = max(ans, zeros + ones)
        return ans

    def maxScore3(self, s: str) -> int:
        """ One Pass time: O(n) space: O(1) """
        ones = 0
        zeros = 0
        best = -inf;
        
        for i in range(len(s) - 1):
            if s[i] == '1':
                ones += 1
            else:
                zeros += 1
            best = max(best, zeros - ones)
        
        if s[-1] == '1':
            ones += 1 

        return best + ones 

