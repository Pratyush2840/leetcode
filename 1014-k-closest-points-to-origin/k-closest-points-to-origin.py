import heapq
class Solution:
    def kClosest(self, points: list[list[int]], k: int) -> list[list[int]]:
        heap =[]
        for obj in points:
            x= pow(obj[0] , 2)
            y = pow(obj[1] ,2)
            dis = math.sqrt(x + y) * -1
            heapq.heappush(heap,(dis , (obj[0] , obj[1])))
            if(len(heap) >k):
                heapq.heappop(heap)
        ans =[]
        while(len(heap) >0):
            dis,(x,y)= heapq.heappop(heap)
            ans.append((x,y))
        return ans