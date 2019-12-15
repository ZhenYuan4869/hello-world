#Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        x=0
        y=1
        length = len(points)
        if length < 3: 
            return length
        
        for i in range length:
            for j in range (i,length)：

