class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:

        sum_list = sum(nums)
        return sum_list%k
        
