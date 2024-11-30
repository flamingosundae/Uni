 
'''
You are given two integer arrays of equal length target and arr. In one step, you can select any non-empty subarray of arr and reverse it. You are allowed to make any number of steps.
Return true if you can make arr equal to target or false otherwise.
'''

class Solution(object):
    def canBeEqual(self, target, arr):
        """
        :type target: List[int]
        :type arr: List[int]
        :rtype: bool
        """
        d = {}
        for i in target:
            if i not in d:
                d[i] = 1
            else:
                d[i] += 1
        for i in arr:
            if i not in d:
                return False
            else:
                d[i] -= 1
        for i in d:
            if d[i] != 0:
                return False
        return True