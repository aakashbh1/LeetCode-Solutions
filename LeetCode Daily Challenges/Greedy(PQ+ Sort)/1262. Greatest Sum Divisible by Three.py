# Greedy


class Solution:
    def maxSumDivThree(self, nums: List[int]) -> int:
        r1, r2  = [], []
        total = 0

        for x in nums:
            total +=x
            if x%3==1:
                r1.append(x)
            elif x%3==2:
                r2.append(x)

        if total %3 == 0:
            return total
        
        r1.sort()
        r2.sort()

        rem = total%3

        if rem == 1:
            op1 = total - r1[0] if len(r1)>=1 else 0
            op2 = total - r2[0] - r2[1] if len(r2)>=1 else 0
        else:
            op1 =  total - r2[0] if len(r2)>=1 else 0
            op2 =  total -r1[0]- r1[1] if len(r1)>=2 else 0 

        return max(op1,op2)


# DP
