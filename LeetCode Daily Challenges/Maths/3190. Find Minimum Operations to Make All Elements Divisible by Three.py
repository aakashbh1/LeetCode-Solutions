class Solution:
    def minimumOperations(self, nums: List[int]) -> int:

        count =0
        for num in nums:
            if num < 3:
                count+= min(num-0, 3-num)
            elif num%3!=0:
                count+=1
            else:
                count+=0
        return count
        
