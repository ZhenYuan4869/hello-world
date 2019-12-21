#Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
#python 3
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
            lines = collections.defaultdict(int) # 定义了一个类，相当于可以将key由自己定义的一个dict
            duplicated = 1  #重复的点
            for j in range (i+1,length):
                if (points[i][0] == points[j][0] and points[i][1] == points[j][1]): #只要考虑后面的点就好了，因为不会超过前面的
                    duplicated += 1
                    continue #加一之后不用进行其他的操作了
                dx = points[i][0] - points[j][0]
                dy = points[i][1] - points[j][1]
                delta = self.gcd(dx, dy) 
                if delta == 0:
                    lines[1] += 1
                else:
                    lines[(dx / delta, dy / delta)] += 1
            res = max(res, (max(lines.values()) if lines else 0) + duplicated) # 最大的res和最新的作比较
        return res

                
                

                
                

