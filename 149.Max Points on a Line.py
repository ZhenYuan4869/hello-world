#Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
class Solution:
    def gcd(self, x, y):
        return x if y == 0 else self.gcd(y, x % y)

    def maxPoints(self, points: List[List[int]]) -> int:
        x=0
        y=1
        length = len(points)
        res = 0
        if length < 3: 
            return length
        
        for i in range (length):
            lines = collections.defaultdict(int) // 定义了一个类，相当于可以将key由自己定义的一个dict
            deplicated = 1  //重复的点
            for j in range (i+1,length):
                if (points[i][x] == points[j][x] & points[i][y] == points[j][y]): //只要考虑后面的点就好了，因为不会超过前面的
                    deplicated += 1
                

                
                

