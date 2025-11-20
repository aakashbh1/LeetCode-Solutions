class Solution:
    def intersectionSizeTwo(self, intervals: List[List[int]]) -> int:
        res = 0
        intervals.sort(key = lambda i : (i[1], -i[0]))
        p1,p2 = -1,-1

        for left, right in intervals:
            if p2<left:
                res +=2
                p1, p2 = right-1, right
            elif p1< left:
                res+=1
                p1,p2=p2,right
        return res
