class Solution:
    def merge(self, intervals: list[list[int]]) -> list[list[int]]:
        intervals.sort()
        ans = []
        for it in range(len(intervals)):
            if(it == 0):
                ans.append(intervals[it])
            elif(intervals[it][0] <= ans[-1][1]):
                ans[-1][1] = max(intervals[it][1] , ans[-1][1])
            else:
                ans.append(intervals[it])
        return ans

